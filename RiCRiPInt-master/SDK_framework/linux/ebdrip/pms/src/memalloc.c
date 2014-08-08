#include "memalloc.h"

BLK FL = NULL;
BLK AL = NULL; 
long memcount=0;
long sz=ALLOCSZ;
/*static long memFreed=0;
static long memAlloc=0; */

int minit()
{
    FL = (BLK) malloc(ALLOCSZ);
    if(FL!=NULL)
    {
        FL->next =  NULL;
        FL->msize = ALLOCSZ - sizeof(struct memblk);
    }
    else
    {
        printf(" malloc failed \n");
        exit(1);
    }
}

void *mmalloc(int size)
{
    if(!FL)
    {
	minit();
    }

    BLK q, p, newfreepacket, nextfreepacket;
    int mreq =  size + sizeof(struct memblk);
    if(size <= 0)
    {
        return NULL;
    }
    memcount++;
    q = p = FL;
    while((p->msize < mreq) && p->next)
    {
        q = p;
        p = p->next;
    }
    if( p->msize >=  mreq )
    {
        nextfreepacket = p->next;
        if(p->msize > mreq)
        {

            newfreepacket = (BLK) &(p->addr[size]);
            newfreepacket->msize = p->msize - mreq;
            newfreepacket->next = nextfreepacket;

            if( p == q )
            {
                FL =  newfreepacket;
            }
            else
            {
                q->next =  newfreepacket;
            }
        }
        else
        {

            if( p ==  q )
            {
                FL = nextfreepacket;
            }
            else
            {
                q->next = nextfreepacket;
            }
        }

        p->msize = size;

        if( AL )
        {
            p->next = AL;
            AL = p;
        }
        else
        {
            AL = p;
        }
        
        return p->addr;
    }
    else
    {
        return NULL;
    }
}
/*int sort()
{
	BLK temp1, temp2;
	int count, swapped, check;
	if(!FL || !FL->next)
		return 0;
	do
	{
		count=0;
		swapped=0;
		
		temp1=FL;
		while(temp1->next)
		{
			temp2=temp1->next;
			check=0;
			count++;
			if(temp1->addr>temp2->addr)
			{
				temp1->next=temp2->next;
				temp2->next=temp1;
				swapped=1;
				check=1;
				if(count==1)
					FL=temp2;
			}
			else
			{
				check=0;
			}
		}
		if(!check)
			temp1=temp1->next;
	}while(swapped)
}*/

void coalesce(void)
{

    BLK p, q, cur;
    /*sort();*/
    p = FL;
    while(p)
    {
        q = p;
        p = p->next;
        if(p)
        {
            cur = (BLK) &(q->addr[q->msize]);

            if( cur == p )
            {
                q->msize +=  p->msize + sizeof(struct memblk);
                q->next = p->next;

                p = q;
            }
        }
    }
  /*  p=FL;
    while(p)
    {
	co++;
        p=p->next;
    }
	printf("\nFL count after = %d and addr = %p , %p\n", co, FL, p->addr);*/
}
void mfree(void *ret)
{
  /*  int ao=0; */
    BLK p, q, temp, temp1;

    if( ret == NULL)
        return;

    coalesce();
    q = p = AL;
    while(p && (p->addr != ret))
    {
        q = p;
        p = p->next;
    }
    if(p)
    {

        if( q == p)
        {
            AL =  p->next;
        }

        else
        {
            q->next = p->next;
        }

        temp=FL;
	while(temp)
	{
		
		if(p->addr < temp->addr && temp == FL)
		{
			p->next=FL;
			FL = p;
			break;
		}
		else if(p->addr < temp->addr)
		{
			p->next=temp;
			temp1->next=p;
			break;
		}
		temp1=temp;
		temp=temp->next;
	}
   }
	
	/*p=AL;
	while(p)
	{
		ao++;
		printf("\nAL count = %d\n", ao);
		p=p->next;
	}*/
 }
