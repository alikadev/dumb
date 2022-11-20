#ifndef DUMB_LIST_H
#define DUMB_LIST_H

#include <stdio.h>

/*

    +===================+
    | Author: Alikadev  |
    | Version: 0.1      |
    +===================+

	[ Deduplicating Utils & Media Bundle List ]
    The DUMB implementation of a dynamic array or list

*/


/// Represent a dynamic array or ~list~
typedef struct
{
	void *ptr;
	size_t length;
	size_t m_cur_length;
	size_t m_sizeof;
} dumb_list;


/// Allocate struct
/// You NEED to alloc start the struct with that
dumb_list *dumb_list_init(dumb_list *list, size_t sizeofElem, size_t nbElem);

/// Free struct
void dumb_list_free(dumb_list *list);

/// Realloc 1 element
dumb_list *dumb_list_push(dumb_list *list);

/// Realloc N element
dumb_list *dumb_list_push_n(dumb_list *list, size_t nbElem);

/// Decrement the size of the list
dumb_list *dumb_list_pop(dumb_list *list);

/// Free 1 element
dumb_list *dumb_list_del(dumb_list *list);

/// Decrement by N the size of the list
dumb_list *dumb_list_pop_n(dumb_list *list, size_t nbElem);

/// Free N Elements
dumb_list *dumb_list_del_n(dumb_list *list, size_t nbElem);

/* Not already implemented! */

/// Shift left each element
/// Will remove the first element
void dumb_list_shl(dumb_list *list);

/// shift right each element
/// Will remove the last element
void dumb_list_shr(dumb_list *list);

/// roll left list
void dumb_list_rol(dumb_list *list);

/// roll right list
void dumb_list_ror(dumb_list *list);

/// shift left from start to struct end
/// start index will be free
/// Will remove the last element
void dumb_list_shl_part(dumb_list *list, size_t end);

/// shift right from struct start to end
/// end will be free
/// Will remove the first element
void dumb_list_shr_part(dumb_list *list, size_t start);

#ifdef USE_DUMB_LIST_QUICK_NAME

#define dl_init 	dumb_list_init
#define dl_free 	dumb_list_free
#define dl_pop 		dumb_list_pop
#define dl_popn 	dumb_list_pop_n
#define dl_del 		dumb_list_del
#define dl_deln 	dumb_list_del_n
#define dl_push 	dumb_list_push
#define dl_pushn 	dumb_list_push_n
#define dl_shr 		dumb_list_shr
#define dl_shrp 	dumb_list_shr_part
#define dl_shl 		dumb_list_shl
#define dl_shlp 	dumb_list_shl_part
#define dl_ror 		dumb_list_ror
#define dl_rol 		dumb_list_rol

#endif

#endif