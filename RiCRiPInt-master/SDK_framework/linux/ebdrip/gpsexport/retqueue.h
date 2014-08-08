/***** -*- C -*- **************************************
 * $Id: retqueue.h,v 1.1 2006/03/09 05:38:49 senda Exp $
 *
 * Copyright (C) 1999 Ricoh Company, Ltd.  All Rights Reserved.
 *   ORDER           : 
 *   PROGRAM NAME    : 
 *   FILE NAME       : retqueue.h
 *   VERSION         : $Revision: 1.1 $
 *   DESIGNER        : SENDA Shigeya
 *   AUTHOR          : SENDA Shigeya
 *-----------------------------------------------------
 *       HISTORY
 *	 senda - 11 May 1999: Created.
 *	 $Log: retqueue.h,v $
 *	 Revision 1.1  2006/03/09 05:38:49  senda
 *	 first comit to LPUX2.0
 *	
 *	 Revision 1.3  2003/04/14 04:04:35  senda
 *	 bugfix: mutex range miss.
 *	
 *	 Revision 1.2  2002/12/09 04:40:50  senda
 *	 cast warning on g++
 *	
 *	 Revision 1.1.1.1  2001/09/30 04:00:19  hyuki
 *	 imported from mips version GWIPC_20010919
 *	
 *	 Revision 1.8  2001/09/19 00:38:43  senda
 *	 add thread locking at funcall if retqueue is full.
 *	
 *	 Revision 1.7  2000/06/27 08:41:46  senda
 *	 bugfix: retqueue_init() initialize head to 0.
 *	
 ******************************************************/

#ifndef __RETQUEUE_H__
#define __RETQUEUE_H__

#define	RETQUEUESIZE	8

typedef struct _rq_elm {
    struct _rq_elm *	next;
    pthread_cond_t	cond;	/* �҂����킹�ꏊ */
    long		fid;	/* �҂��Ă���func��fid */
    void *		data;
} rq_elm_t;

typedef rq_elm_t * rq_elm_p;

typedef struct _retqueue {
    pthread_mutex_t	mutex;	/* queue�̔r������ */
    rq_elm_p		head;
    rq_elm_p		delq;
#if defined(USE_NEWVAR)
    rq_elm_p		ehead;
    size_t		esize;
#endif
} retqueue_t;

#if !defined(USE_NO_WAIT)
/*
 * 2001/08/24  :  Adonis-P3 ���i�e�X�g�Ŕ��o(��Q�Ή�)
 *
 * �֐��܂��s��: retqueue���ӂ���G���[�Ƃ��Ȃ��ŁA�Ăяo��thread���E�G�C�g
 * ������悤�ɕύX����B
 *
 * �փb�_�̒�`��ς��Ȃ��ŏ����ϐ����m�ۂ������̎�i���Ƃ��Ă���B
 * client�\���̏�ŁAretqueue_t�Ɨv�f�̗̈悪����ł��鎖���𗘗p���āA
 * elm�̍ŏ��̗v�f��queue�̋�҂��̏����ϐ��Ƃ��ē]�p����B
 */
typedef struct _retqueue_ex {
    retqueue_t		retqueue;
    rq_elm_t		elm[RETQUEUESIZE];
} retqueue_ex_t;

static __inline rq_elm_p
get_ret_elm(retqueue_t *q)
{
    retqueue_ex_t *qq = (retqueue_ex_t *)q;
    return &(qq->elm[0]);	/* �ŏ���elm��delq�҂��ɓ]�p���� */
}
#endif

/** avoid warning (-Wunused) ***/
static __inline void 
retqueue_init( retqueue_t * q, rq_elm_p e, size_t sz )
__attribute__ ((unused));
static __inline void 
retqueue_destroy( retqueue_t * q )
__attribute__ ((unused));
static __inline rq_elm_p
retqueue_getnew( retqueue_t * q )
__attribute__ ((unused));
static __inline void
retqueue_delete( retqueue_t * q, rq_elm_p e )
__attribute__ ((unused));
static __inline void *
retqueue_wait( retqueue_t * q, long fid )
__attribute__ ((unused));
static __inline rq_elm_p
retqueue_pre_wait( retqueue_t * q, long fid )
__attribute__ ((unused));
static __inline void
retqueue_unwait( retqueue_t * q, rq_elm_p e )
__attribute__ ((unused));
static __inline void *
retqueue_real_wait( retqueue_t * q, rq_elm_p e, long fid )
__attribute__ ((unused));
static __inline rq_elm_p
retqueue_search( retqueue_t * q, long fid )
__attribute__ ((unused));
static __inline int
retqueue_signal( retqueue_t * q, long fid, void *data )
__attribute__ ((unused));

static __inline void 
retqueue_init( retqueue_t * q, rq_elm_p e, size_t sz )
{
    unsigned int		i;
    rq_elm_p *	ip = &(q->delq);

#if defined(USE_NEWVAR)
    q->ehead = e;
    q->esize = sz;
#endif
    q->head = 0;

    for( i = 0; i < sz; i++ ) {	/* �폜queue�ɓo�^ */
	*ip = &(e[i]);
	pthread_cond_init(&(e[i].cond), NULL);
	ip = &(e[i].next);
    }
    *ip = 0;
    
#if !defined(USE_NO_WAIT)
    q->delq = q->delq->next;	/* ����m�ہB�܂�Adelq�����菜���Ă����B */
    get_ret_elm(q)->fid = 0;	/* retqueue�҂����ɓ]�p����B */
#endif
    pthread_mutex_init( &q->mutex, NULL );
    return;
}

static __inline void 
retqueue_destroy( retqueue_t * q )
{
#if defined(USE_NEWVAR)    
    unsigned int		i;
#endif
    rq_elm_p	e;

    pthread_mutex_lock(&q->mutex);
#if !defined(USE_NO_WAIT)
    e = q->delq; q->delq = get_ret_elm(q); q->delq->next = e;	/* �m�ە��Ԃ� */
#endif
#if defined(USE_NEWVAR)
    e = q->ehead;
    for( i = 0; i < q->esize; i++ ) {
	pthread_cond_destroy( &(e[i].cond) );
    }
#else
    for( e = q->head; e; e = e->next ) {
	e->data = 0;	/* �ߒl�O */
	pthread_cond_signal( &e->cond );
	pthread_cond_destroy( &e->cond );
    }
    for( e = q->delq; e; e = e->next ) {
	pthread_cond_destroy( &e->cond );
    }
#endif
    pthread_mutex_unlock(&q->mutex);
    pthread_mutex_destroy( &q->mutex );
    return;
}

static __inline rq_elm_p
retqueue_getnew( retqueue_t * q )
{    
    rq_elm_p ret, tmp;
    if( q->delq == 0 ) return 0;

/*    pthread_mutex_lock(&q->mutex); */

    ret = q->delq;
    q->delq = ret->next;
    tmp = q->head;
    q->head = ret;
    ret->next = tmp;	/* �폜queue����P�Ƃ��Ă���head�̃��X�g�ɒǉ� */

/*    pthread_mutex_unlock(&q->mutex); */

    return ret;
}

static __inline void
retqueue_delete( retqueue_t * q, rq_elm_p e )
{			
    rq_elm_p	tmp;
    rq_elm_p*	ip;	/* ip��q->head�������N���X�g����next�̃A�h���X */
    

/*    pthread_mutex_lock(&q->mutex); */

    for( ip = &(q->head); ip != NULL && *ip != e; ip = &((*ip)->next) );

    if( ip == 0 || e == 0 ) return;
    *ip = e->next;
    tmp = q->delq;
    q->delq = e;	/* e�̎w���v�f���폜���폜queue�ɓ���� */
    e->next = tmp;

#if !defined(USE_NO_WAIT)
    if( get_ret_elm(q)->fid > 0 ) {
	get_ret_elm(q)->fid--;
	pthread_cond_signal( &(get_ret_elm(q)->cond) );
    }
#endif

/*    pthread_mutex_unlock(&q->mutex); */

    return;
}

static __inline void *
retqueue_wait( retqueue_t * q, long fid )
{
    void *	ret = 0;
    rq_elm_p	e;
    
    if( q->delq == 0 ) return 0;

    pthread_mutex_lock(&q->mutex);

    e = retqueue_getnew( q );	/* �҂����킹�ꏊ�m�� */
    if( e == 0 ) {
	pthread_mutex_unlock(&q->mutex);
	return 0;
    }
    e->fid  = fid;
    e->data = 0;
    while( e->data == 0 ) {
	int err;
	err = pthread_cond_wait( &e->cond, &q->mutex );
	if( err ) {
	    retqueue_delete( q, e );	/* �҂����킹�ꏊ�폜 */
	    pthread_mutex_unlock(&q->mutex);
	    return 0;
	}
    }
    ret = e->data;
    retqueue_delete( q, e );	/* �҂����킹�ꏊ�폜 */
    
    pthread_mutex_unlock(&q->mutex);

    return ret;
}

/*
 * retqueue_wait��o�^�Ƒ҂����킹�ɕ������o�[�W����
 *   ex)
 *	rq_elm_p e = retqueue_pre_wait(q, fid);
 *	* �������� ....
 *	* error�� --- retqueue_unwait();
 *	ret = retqueue_real_wait(q, e, fid);
 *
 */
static __inline rq_elm_p
retqueue_pre_wait( retqueue_t * q, long fid )
{
    rq_elm_p	e;
    
#if defined(USE_NO_WAIT)
    if( q->delq == 0 ) return 0;

    pthread_mutex_lock(&q->mutex);

    e = retqueue_getnew( q );	/* �҂����킹�ꏊ�m�� */
    if( e == 0 ) {
	pthread_mutex_unlock(&q->mutex);
	return 0;
    }
#else
    pthread_mutex_lock(&q->mutex);

    while( (e = retqueue_getnew( q )) == 0 ) {    /* �҂����킹�ꏊ�m�� */
	register int err;
	get_ret_elm(q)->fid++;
	err = pthread_cond_wait( &(get_ret_elm(q)->cond), &q->mutex );
	if( err ) {
	    pthread_mutex_unlock(&q->mutex);
	    return 0;
	}
    }
#endif
    e->fid  = fid;
    e->data = 0;

    return e;
}

static __inline void
retqueue_unwait( retqueue_t * q, rq_elm_p e )	/* �҂��Ȃ��ŉ����̂� */
{
    retqueue_delete( q, e );	/* �҂����킹�ꏊ�폜 */
    pthread_mutex_unlock(&q->mutex);
    return;
}

static __inline void *
retqueue_real_wait( retqueue_t * q, rq_elm_p e, long fid )
{
    void *	ret = 0;
    int		err;
    
    while( e->data == 0 ) {
	err = pthread_cond_wait( &e->cond, &q->mutex );
	if( err ) {
	    retqueue_unwait( q, e );
	    return 0;
	}
    }
    ret = e->data;
    retqueue_unwait( q, e );
    return ret;
}

static __inline rq_elm_p
retqueue_search( retqueue_t * q, long fid )
{
    rq_elm_p e = q->head; 	/* ���ӁI ���̊֐���mutex��lock����Ă��邱�Ƃ��O�� */
    for( ; e != 0 ; e = e->next )
	if( e->fid == fid ) break;
    return e;
}

static __inline int
retqueue_signal( retqueue_t * q, long fid, void *data )
{
    int ret = 0;
    rq_elm_p e;

    pthread_mutex_lock(&q->mutex);

    for( e = q->head; e != 0 ; e = e->next )
	if( e->fid == fid ) break;
    if( e != 0 ) {
	ret = 1;	/* �V�O�i���ł��� */
	e->data = data;	/* ��������signal�ł��邱�Ƃ�waiter�ɒm�点�� */
	pthread_cond_signal( &e->cond );
    } else {
	ret = 0;
    }
    pthread_mutex_unlock(&q->mutex);

    return ret;
}

#endif /* __RETQUEUE_H__ */
/* 
 * Local Variables: 
 * c-basic-offset: 4
 * End:
 */
