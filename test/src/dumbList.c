#include "dumbtest.h"
#include <dumb/list.h>


void trace_list(const char *txt, const dumb_list *list)
{
	sprintf(trace, RES "%s%s\n" BLU "  %p\n  len:%ld\n  real:%ld\n  sizeof:%ld\n" RES, 
		trace, txt,
		list->ptr, list->length, 
		list->m_cur_length, list->m_sizeof);
}

int main(void)
{
	dumb_list list;
	void * state;

	state = dumb_list_init(&list, sizeof (int), 5000);
	trace_list("dumb_list_init 5000", &list);
	if(!state || list.m_cur_length != 5000){
		print_state("dumb_list_init", FAILURE);
		return -1;
	}
	print_state("dumb_list_init", SUCCESS);


	// REM 2000 ELEM
	state = dumb_list_pop_n(&list, 2000);
	trace_list("dumb_list_pop_n 2000", &list);
	if(!state || list.m_cur_length != 5000 || list.length != 3000){
		print_state("dumb_list_pop_n", FAILURE);
		dumb_list_free(&list);
		return 1;
	}
	print_state("dumb_list_pop_n", SUCCESS);


	// DEL 1000 ELEM
	state = dumb_list_del_n(&list, 1000);
	trace_list("dumb_list_del_n 1000", &list);
	if(!state || list.length != 2000 || list.m_cur_length != list.length){
		print_state("dumb_list_del_n", FAILURE);
		dumb_list_free(&list);
		return 1;
	}
	print_state("dumb_list_del_n", SUCCESS);


	// ADD 1000 ELEM
	state = dumb_list_push_n(&list, 1000);
	trace_list("dumb_list_push_n 1000", &list);
	if(!state || list.length != 3000 && list.m_cur_length != 2000){
		print_state("dumb_list_push_n", FAILURE);
		dumb_list_free(&list);
		return 1;
	}
	print_state("dumb_list_push_n", SUCCESS);


	// FREE STRUCT
	dumb_list_free(&list);
	print_state("dumb_list_pop", EXPECTED);
	print_state("dumb_list_del", EXPECTED);
	print_state("dumb_list_push", EXPECTED);
	print_state("dumb_list_free", EXPECTED);
	print_state("dumb_list_shl", NOT_IMPLEMENTED);
	print_state("dumb_list_shr", NOT_IMPLEMENTED);
	print_state("dumb_list_rol", NOT_IMPLEMENTED);
	print_state("dumb_list_ror", NOT_IMPLEMENTED);
	print_state("dumb_list_shl_part", NOT_IMPLEMENTED);
	print_state("dumb_list_shr_part", NOT_IMPLEMENTED);
	printf(RES);
}