#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>

#define ALLOCSZ ((12 * 1024 * 1024))

struct memblk {
    struct memblk *next;
    long  msize;
    char addr[0];
};

typedef struct memblk* BLK;

int meminit();
void *mmalloc(int count);
void mdefrag(void);
void mfree(void *r);
