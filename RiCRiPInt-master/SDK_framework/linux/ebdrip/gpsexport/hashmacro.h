/***** -*- C -*- **************************************
 * $Id: hashmacro.h,v 1.1 2006/03/09 05:38:49 senda Exp $
 *
 * Copyright (C) 1999 Ricoh Company, Ltd.  All Rights Reserved.
 *   ORDER           : gwipc hash table manip macro
 *   PROGRAM NAME    : libgwipc
 *   FILE NAME       : hashmacro.h
 *   VERSION         : $Revision: 1.1 $
 *   DESIGNER        : SENDA Shigeya
 *   AUTHOR          : SENDA Shigeya
 *-----------------------------------------------------
 *       HISTORY
 *	 senda - 14 May 1999: Created.
 *	 $Log: hashmacro.h,v $
 *	 Revision 1.1  2006/03/09 05:38:49  senda
 *	 first comit to LPUX2.0
 *	
 *	 Revision 1.1.1.1  2001/09/30 04:00:19  hyuki
 *	 imported from mips version GWIPC_20010919
 *	
 *	 Revision 1.8  2000/06/14 10:37:59  senda
 *	 bugfix : delq replace error.
 *	
 *	 Revision 1.7  2000/06/14 05:33:09  senda
 *	 keep same NM##hash_tbl_t size.
 *	
 *	 Revision 1.6  2000/06/13 04:35:47  senda
 *	 ending functions added for memory leak checking.
 *	
 *	 Revision 1.5  2000/01/22 09:57:22  senda
 *	 STATISTICS/ITRON_DUMP feature.
 *	
 *	 Revision 1.4  1999/08/19 09:32:30  senda
 *	 gwipc_timer.c : fix unlock miss
 *	 hashmacro.h   : fix NULL setting of queue next member
 *	
 *	 Revision 1.3  1999/08/18 01:17:59  senda
 *	 hashmacro : fixed un-initialized next member on malloced queue element
 *	 *.h : fix compile problems
 *	
 *	 Revision 1.2  1999/08/17 06:05:02  senda
 *	 use malloc if delq is exhausted.
 *	
 *	 Revision 1.1.1.1  1999/06/10 11:01:34  senda
 *	 GWIPC
 *	
 ******************************************************/

#ifndef __HASHMACRO_H__
#define __HASHMACRO_H__

/*
 *  hash table�̃e�[�u����`�A���[�`����������������}�N���B
 *	key   : id
 *	value : void pointer
 *
 *	�}�N��:
 *		MakeHashDefs( PREFIX, TSIZE, ESIZE );
 *		- PREFIX : ��`�ɂ��閼�O�̐擪��
 *		- TSIZE  : hash�e�[�u���T�C�Y�B
 *		- ESIZE  : �o�^����v�f�̍ő吔�B
 *			   ���̎����ł͗v�f���Œ�̈�ŊǗ����Ă���B
 *			   ���̗v�f���������̈�����炩���ߏ����B
 *
 *	��`�����֐�:
 *
 *	void NM##hash_tbl_init( NM##hash_tbl_p tblp );
 *	  - �e�[�u���̏������Bhash_tbl_t�͎g�p�҂��ϐ��\���̂��m�ۂ���B
 *
 *      int  NM##hash_tbl_register( NM##hash_tbl_p tblp,
 *		       long hash_key, long id, void *value );
 *        - �e�[�u���ւ̓o�^�Bhash_key��hash�֐������[�U���O���ŗ^����
 *          ���̒l�������Bid������̕������ɓo�^�ς̏ꍇ�Avalue���X�V�����B
 *
 *	void* NM##hash_tbl_find( NM##hash_tbl_p tblp, long hash_key, long id );
 *        - �����Bhash_key, id�ɊY������v�f��value��ԋp����B
 *          null�͌����������ʂ��Ȃ��������Ƃ������B
 *
 *	void NM##hash_tbl_iter( NM##hash_tbl_p tblp,
 *				void (*printval)(long id, void *val) );
 *	  - �o�^���e�̑S���T���B�o�^�v�f���ׂĂɑ΂��A�֐�������
 *	    printval(id, val)���Ăяo�����B
 *
 *	�g�p�@:
 *		MakeHashDefs( TEST_, 128, 64 ); // TEST_xxx����`�����B
 *		long hash_func(long id) {....}
 *			// �߂�l�� 0�ȏ�ATSIZE-1�ȉ��ł��邱��
 *		....
 *		TEST_hash_tbl_t tbl; 		// �ϐ��錾
 *		....
 *		TEST_hash_tbl_init( &tbl );	// ������
 *		....
 *		TEST_hash_tbl_register(&tbl, hash_func(id), id, value);
 *		....
 *		value = TEST_hash_tbl_find(&tbl, hash_func(id), id);
 */

#define MakeHashDefs( NM, TSIZE, ESIZE )                             \
       								     \
typedef struct NM##_hash_e {					     \
    struct NM##_hash_e *	next;				     \
    long			id;				     \
    void *			value;				     \
} NM##hash_elm_t;						     \
								     \
typedef NM##hash_elm_t *  NM##hash_elm_p;			     \
								     \
typedef struct NM##_hash_tbl {					     \
    NM##hash_elm_p		delq;				     \
    NM##hash_elm_p		tbl[ TSIZE ];			     \
    NM##hash_elm_t		elm[ ESIZE ];			     \
} NM##hash_tbl_t;						     \
								     \
typedef NM##hash_tbl_t *  NM##hash_tbl_p;			     \
								     \
/*								     \
 * hash�e�[�u��������						     \
 */								     \
static __inline void						     \
NM##hash_tbl_init( NM##hash_tbl_p tblp )			     \
{								     \
    int i;							     \
    NM##hash_elm_p * ip;					     \
    								     \
    for( i=0; i < TSIZE; i++ ) {				     \
	tblp->tbl[i] = 0;					     \
    }								     \
    ip = &(tblp->delq);						     \
    for( i=1; i < ESIZE; i++ ) { /* �ŏ��̗v�f�̓����N�p */	     \
	*ip = &(tblp->elm[i]);					     \
	ip = &(tblp->elm[i].next);				     \
    }								     \
    *ip = NULL;							     \
    tblp->elm->next = 0;					     \
    return;							     \
}								     \
								     \
/*								     \
 * hash�̋�v�f�̕�[ (delq == 0������)				     \
 */								     \
static __inline void						     \
NM##hash_new_delq( NM##hash_tbl_p tblp )			     \
{								     \
    int i;							     \
    NM##hash_elm_p e;						     \
    NM##hash_elm_p * ip;					     \
								     \
    e = (NM##hash_elm_p) calloc( ESIZE, sizeof(*e) );		     \
    if( e == 0 ) return;					     \
    ip = &(tblp->delq);						     \
    for( i=1; i < ESIZE; i++ ) {				     \
	*ip = &(e[i]);						     \
	ip = &(e[i].next);					     \
    }								     \
    *ip = NULL;							     \
    /* �ŏ��̗v�f��calloc�G���A�̃����N�ێ� */			     \
    e->next = tblp->elm->next;					     \
    tblp->elm->next = e;					     \
    return;							     \
}								     \
								     \
/*								     \
 * hash�o�^							     \
 *	id�d���͋����Ȃ��B					     \
 *	���̊֐��̊O��hash�֐��ɂ��hash_key�����߂邱�ƁB	     \
 */								     \
static __inline int						     \
NM##hash_tbl_register( NM##hash_tbl_p tblp,			     \
		       long hash_key, long id, void *value )	     \
{								     \
    NM##hash_elm_p e;						     \
    NM##hash_elm_p *ip;						     \
    								     \
    ip = &(tblp->tbl[hash_key]);				     \
    while( (*ip) != NULL ) {					     \
	if( (*ip)->id == id ) {					     \
	    (*ip)->value = value;	/* �X�V */		     \
	    return 2;						     \
	}							     \
	ip = &((*ip)->next);	/* ����hash�̋󂫂��`�F�b�N */     \
    }								     \
    e = tblp->delq;						     \
    if( e == 0 ) {						     \
	NM##hash_new_delq(tblp);				     \
	e = tblp->delq;						     \
	if( e == 0 ) return 0;				             \
    }								     \
    tblp->delq = e->next;	/* �폜queue����P�Ƃ��Ă��� */    \
								     \
    e->id = id;							     \
    e->value = value;						     \
    e->next = NULL;						     \
    *ip = e;							     \
    return 1;							     \
}								     \
								     \
/*								     \
 * hash����							     \
 */								     \
static __inline void *						     \
NM##hash_tbl_find( NM##hash_tbl_p tblp, long hash_key, long id )     \
{								     \
    NM##hash_elm_p p;						     \
								     \
    p = tblp->tbl[hash_key];					     \
    while( p != NULL ) {					     \
	if( p->id == id ) {					     \
	    return p->value;					     \
	}							     \
	p = p->next;	/* ����hash�̋󂫂��`�F�b�N */	     \
    }								     \
    return 0;							     \
}								     \
								     \
/*								     \
 * hash�̑S���T��						     \
 */								     \
static __inline void						     \
NM##hash_tbl_iter( NM##hash_tbl_p tblp,				     \
		    void (*printval)(long id, void *val) )	     \
{								     \
    int i;							     \
    NM##hash_elm_p	ip;					     \
								     \
    for( i=0; i<TSIZE; i++ ) {					     \
	ip = tblp->tbl[i];					     \
	if( ip != 0 ) {						     \
	    for(; ip != 0; ip = ip->next) {			     \
		printval( ip->id, ip->value );			     \
	    }							     \
	}							     \
    }								     \
    return;							     \
}								     \
								     \
/*								     \
 * hash�e�[�u���̔j��	(calloc�G���A�̉��)			     \
 */								     \
static __inline void						     \
NM##hash_tbl_destroy( NM##hash_tbl_p tblp )			     \
{								     \
    register NM##hash_elm_p e = tblp->elm->next;		     \
    while(e) {							     \
	register NM##hash_elm_p f = e;				     \
	e = e->next;						     \
	free(f);						     \
    }								     \
    return;							     \
}								     \

/*
 * hash�폜�Ȃǂ͂Ƃ肠�����K�v�Ȃ��̂ō���ĂȂ��B
 */

#endif /* __HASHMACRO_H__ */
/*
 * Local Variables:
 * c-basic-offset: 4
 * End:
 */
