#ifndef _LIST_H
#define _LIST_h

#include <stdbool.h>

typedef int elem_t;
typedef struct s_list * list;

list list_empty();
/*
 * DESC: Creates an empty list.
 *
 * l = list_empty();
 * 
 * POS: {l -> []}
 */

list list_add_left(elem_t e, list l);
/*
 * DESC: Adds an element to the list, prepending it to the start.
 *
 * list_add_left(e, l);
 */

list list_add_right(elem_t e, list l);
/*
 * DESC: Adds an element to the list, pushing it to the end.
 *
 * list_add_right(e, l);
 */

bool list_is_empty(list l);
/*
 * DESC: Returns `true` if the list is empty.
 *
 * b = list_is_empty(l);
 */

elem_t list_head(list l);
/*
 * DESC: Returns the first element of the list.
 *
 * PRE: !list_is_empty(l);
 * 
 * head = list_head(l);
 */

list list_tail(list l);
/*
 * DESC: Discards the first element of the list.
 *
 * PRE: !list_is_empty(l);
 * 
 * list_tail(l);
 */

int list_length(list l);
/*
 * DESC: Returns the length of the list.
 *
 * length = list_length(l);
 */

list list_concat(list l, list k);
/*
 * DESC: Adds elements from list k to the end of list l, in the same order.
 *
 * list_concat(l, k); 
 */

elem_t list_index(list l, int n);
/*
 * DESC: Returns the n element of the list;
 * 
 * PRE: list_length(l) > n;
 * 
 * e = list_index(l, n); 
 */

list list_take(list l, int n);
/*
 * DESC: Keeps the first n elements in the list, discarding the rest.
 * 
 * PRE: list_length(l) >= n;
 * 
 * list_take(l, n);
 */

list list_drop(list l, int n);
/*
 * DESC: Discards the first n elements in the list, keeping the rest.
 *
 * PRE: list_length(l) >= n;
 * 
 * list_drop(l, n);
 */

list list_copy(list l);
/*
 * DESC: Returns a copy of the list.
 *
 * k = list_copy(l);
 */

list list_destroy(list l);
/*
 * DESC: Free memory if neccessary.
 *
 * list_destroy(l);
 */

#endif