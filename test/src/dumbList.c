#include "dumbtest.h"
#include <dumb/list.h>

void trace_list(const char *txt, const dumb_list *list)
{
	sprintf(trace, RES "%s%s\n" BLU "  %p\n  len:%ld\n  real:%ld\n  sizeof:%ld\n" RES, 
		trace, txt,
		list->ptr, list->length, 
		list->m_cur_length, list->m_sizeof);
}

void trace_list_all(const char *txt, const dumb_list *list)
{
	sprintf(trace, RES "%s%s\n" BLU "  %p\n  len:%ld\n  real:%ld\n  sizeof:%ld\n", 
		trace, txt,
		list->ptr, list->length, 
		list->m_cur_length, list->m_sizeof);

	for(int i=0; i<list->length; i++){
		sprintf(trace, "%s  - 0x", trace);
		for (int j = 0; j < list->m_sizeof; ++j)
		{
			sprintf(trace, "%s%.2x", trace, *((char*)list->ptr + list->m_sizeof * i + j));
		}
		sprintf(trace, "%s\n", trace);
	}
	printf(RES);
}

void set_values(dumb_list *list);

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
	print_state("dumb_list_pop", EXPECTED);

	// DEL 1000 ELEM
	state = dumb_list_del_n(&list, 1000);
	trace_list("dumb_list_del_n 1000", &list);
	if(!state || list.length != 2000 || list.m_cur_length != list.length){
		print_state("dumb_list_del_n", FAILURE);
		dumb_list_free(&list);
		return 1;
	}
	print_state("dumb_list_del_n", SUCCESS);
	print_state("dumb_list_del", EXPECTED);


	// ADD 1000 ELEM
	state = dumb_list_push_n(&list, 1000);
	trace_list("dumb_list_push_n 1000", &list);
	if(!state || list.length != 3000 && list.m_cur_length != 2000){
		print_state("dumb_list_push_n", FAILURE);
		dumb_list_free(&list);
		return 1;
	}
	print_state("dumb_list_push_n", SUCCESS);
	print_state("dumb_list_push", EXPECTED);


	// FREE STRUCT
	trace_list("dumb_list_free", &list);
	dumb_list_free(&list);
		// CHECKED WITH VALGRIND
	print_state("dumb_list_free", SUCCESS);


	// SHIFT RIGHT PART
	set_values(&list);
	dumb_list_shr_part(&list, 3);
	trace_list_all("dumb_list_shr_part 3", &list);
	char *ptr = (char*)list.ptr;
	if(ptr[0] != 0 || ptr[1] != 1 || ptr[3] != 2 || ptr[4] != 3) {
		print_state("dumb_list_shr_part", FAILURE);
		dumb_list_free(&list);
		return 1;
	}
	print_state("dumb_list_shr_part", SUCCESS);
	dumb_list_free(&list);


	// SHIFT RIGHT ALL
	set_values(&list);
	dumb_list_shr(&list);
	trace_list_all("dumb_list_shr 3", &list);
	ptr = (char*)list.ptr;
	if(ptr[1] != 0 || ptr[2] != 1 || ptr[3] != 2 || ptr[4] != 3) {
		print_state("dumb_list_shr", FAILURE);
		dumb_list_free(&list);
		return 1;
	}
	print_state("dumb_list_shr", SUCCESS);
	dumb_list_free(&list);


	print_state("dumb_list_shl_part", NOT_IMPLEMENTED);
	print_state("dumb_list_shl", NOT_IMPLEMENTED);
	print_state("dumb_list_rol", NOT_IMPLEMENTED);
	print_state("dumb_list_ror", NOT_IMPLEMENTED);
	printf(RES);
}

void set_values(dumb_list *list)
{
	dumb_list_init(list, sizeof (char), 5);
	trace_list("dumb_list_init char 5", list);
	((char*)list->ptr)[0]=0;
	((char*)list->ptr)[1]=1;
	((char*)list->ptr)[2]=2;
	((char*)list->ptr)[3]=3;
	((char*)list->ptr)[4]=4;
	trace_list_all("set values", list);
}