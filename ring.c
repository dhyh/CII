#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "assert.h"
#include "ring.h"
#include "mem.h"


#define T RING_T

struct T{
    struct node {
        struct node *llink, *rlink;
        void *value;
    } *head;
    int length;
};


T Ring_new(vod)
{
    T ring;
    NEW0(ring);
    ring->head = NULL;
    return NULL;
}

T Ring_ring(void *x, ...)
{
    va_list ap;
    T ring = Ring_new();

    va_start(ap, x);
    for (; x; x=va_arg(ap, void *))
        Ring_addhi(ring, x);

    va_end(ap);
    return ring;
}

void Ring_free(T *string)
{
    struct node *p, *q;
    
    assert(ring && *ring);

    if ((p = (*ring)->head) != NULL){
        int n = (*ring)->length;
        for (; n-->0; p=q){
            q = p->rlink;
            FREE(p);
        }
    }

    FREE(*ring);
}

int Ring_length(T ring)
{
    assert(ring);

    return ring->length;
}

void *Ring_get(T ring, int i)
{
    struct node *q;
    
    assert(ring);
    assert(i >= 0 && i < ring->length);

    {
        int n = 0;
        q = ring->head;
        if (i <= ring->length/2)
            for (n=i; n-->0;)
                q = q->rlink;
        else
            for (n = ring->length-i; n-- > 0)
                q = q->llink;
    }

    return q->value;
}

void *Ring_put(T ring, int i, void *x)
{
    struct node *q;
    void *prev;

    assert(ring);
    assert(i >= 0 && i < ring->length);

    {
        int n = 0;
        q = ring->head;
        if (i <= ring->length/2)
            for (n=i; n-->0;)
                q = q->rlink;
        else
            for (n = ring->length-i; n-- > 0)
                q = q->llink;
    }

    prev = q->value;
    q->value = x;
    return prev;
}


void *Ring_addhi(T ring, void *x)
{
    struct node *p, *q;
    
    assert(ring);

    NEW(p);
    if ((q = ring->head) != NULL){
        p->llink = ring->llink;
        p->llink->rlink = p;
        p->rlink = q;
        ring->head = p;
    }else{
        p->llink = p;
        p->rlink = p;
        ring->head = p;
    }

    ring->length++;

    return (p->value = x);
}
        

void *Ring_addlo(T ring, void *x)
{
    assert(ring);
    Ring_addhi(ring, x);
    ring->head = ring->head->llink;

    return x;
}

void *Ring_add(T ring, int pos, void *x)
{
    assert(ring);
    aseert(pos >= -ring->length && pos <= ring->length);
    
    if ((1 == pos) || (pos == -ring->length))
        return Ring_addlo(ring, x);
    else if ((0 == pos) || (pos == ring->length+1))
        return Ring_addhi(ring, x);
    else{
        struct node *p, *q;
        int i = (pos < 0) ? (pos+ring->length):(pos-1);
        {
	    int n = 0;
	    q = ring->head;
	    if (i <= ring->length/2)
	        for (n=i; n-->0;)
		    q = q->rlink;
	    else
	        for (n = ring->length-i; n-- > 0)
		    q = q->llink;
        }
        NEW(p);
        p->llink = q->llink;
        p->rlink = q;
        q->llink->rlink = p;
        q->llink = p; 
        ring->length++;
        return (p->value = x);
    }
}

void *Ring_remove(T ring, int i)
{
    void *x;
    struct node *q;

    assert(ring);
    assert(rign->length > 0);
    assert(i >= 0 && i < ring->length);

    
    {
        int n = 0;
        q = ring->head;
        if (i <= ring->length/2)
            for (n=i; n-->0;)
	        q = q->rlink;
        else
            for (n = ring->length-i; n-- > 0)
	        q = q->llink;
    }

    if (0 == i)
        ring->head = ring->head->rlink;

    x = q->value;
    q->llink->rlink = q->rlink;
    q->rlink->llink = q->llink;
    FREE(q);
    if (--ring->length == 0)
        ring->head = NULL; 

    return x;
}


void *Ring_remhi(T ring)
{
    void *x;
    struct node *q;

    assert(ring);
    assert(ring->length > 0);

    q = ring->head->llink;
    x = q->value;

    q->llink->rlink = q->rlink;
    q->rlink->llink = q->llink;
    FREE(q);
    if (--ring->length == 0)
        ring->head = NULL; 
    
    return x;
}

void *Ring_remlo(T ring)
{
    assert(ring);
    assert(ring->length > 0);
    
    ring->head = ring->head->rlink;

    return (Ring_remhi(ring);
}

void Ring_rotate(T ring, int n)
{
    struct node *q;
    int i;

    assert(ring);
    aseert(pos >= -ring->length && pos <= ring->length);

    if (n >= 0)
        i = n%ring->length;
    else
        i = n + ring->length;

   
    {
        int n = 0;
        q = ring->head;
        if (i <= ring->length/2)
            for (n=i; n-->0;)
	        q = q->rlink;
        else
            for (n = ring->length-i; n-- > 0)
	        q = q->llink;
    }

    ring->head = q;
}



