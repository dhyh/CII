
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */

#ifndef _QUEUE_H_INCLUDED_
#define _QUEUE_H_INCLUDED_


typedef struct queue_s  queue_t;

struct queue_s {
    void  *prev;
    void  *next;
};


#define queue_init(q)                                                     \
    (q)->ptr  = NULL;                                                            \
    (q)->prev = q;                                                            \
    (q)->next = q


#define queue_empty(h)                                                    \
    (h == (h)->prev)


#define queue_insert_head(h, x)                                           \
    (x)->next = (h)->next;                                                    \
    (x)->next->prev = x;                                                      \
    (x)->prev = h;                                                            \
    (h)->next = x


#define queue_insert_after   queue_insert_head


#define queue_insert_tail(h, x)                                           \
    (x)->prev = (h)->prev;                                                    \
    (x)->prev->next = x;                                                      \
    (x)->next = h;                                                            \
    (h)->prev = x


#define queue_head(h)                                                     \
    (h)->next


#define queue_last(h)                                                     \
    (h)->prev


#define queue_sentinel(h)                                                 \
    (h)


#define queue_next(q)                                                     \
    (q)->next


#define queue_prev(q)                                                     \
    (q)->prev


#define queue_remove(x)                                                   \
    (x)->next->prev = (x)->prev;                                              \
    (x)->prev->next = (x)->next;                                              \
    (x)->prev = NULL;                                                         \
    (x)->next = NULL

#define queue_data(q, type, link)                                         \
    (type *) ((u_char *) q - offsetof(type, link))

#endif /* QUEUE_H_INCLUDED_ */
