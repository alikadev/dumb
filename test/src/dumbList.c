#include <dumb/list.h>
#include <stdio.h>

typedef struct {
	char *ptr;
	char *name;
	unsigned int data;
	char c;
} stuff_t;

void trace_dumb_list(dumb_list *list);
int test_alloc();

int main(void)
{
	if(test_alloc() != 0){
		printf("Allocation failed!\n");
		return 1;
	}
}

int test_alloc(){
	dumb_list list;
	void * state;

	/* Init list with 5000 element */
	state = dumb_list_init(&list, sizeof (stuff_t), 5000);
	if(!state || list.m_cur_length != 5000){
		printf("Fail to alloc 5000 elem\n");
		return -1;
	}

	printf("\nList init, 5000 elem\n");
	trace_dumb_list(&list);


	// REM 2000 ELEM
	state = dumb_list_pop_n(&list, 2000);
	if(!state || list.m_cur_length != 5000 || list.length != 3000){
		printf("\nFail to pop 2000 elem\n");
		dumb_list_free(&list);
		return 1;
	}
	printf("\nRemove 2000 elem\n");
	trace_dumb_list(&list);


	// DEL 1000 ELEM
	state = dumb_list_del_n(&list, 1000);
	if(!state || list.length != 2000 || list.m_cur_length != list.length){
		printf("\nFail to delete 1000 elem\n");
		dumb_list_free(&list);
		return 1;
	}
	printf("\nDelete 1000 elem\n");
	trace_dumb_list(&list);


	// ADD 1000 ELEM
	state = dumb_list_push_n(&list, 1000);
	if(!state || list.length != 3000 && list.m_cur_length != 2000){
		printf("\nFail to add 1000 elem\n");
		dumb_list_free(&list);
		return 1;
	}
	printf("\nAdd 1000 elem\n");
	trace_dumb_list(&list);


	// FREE STRUCT
	dumb_list_free(&list);
	printf("\nFree struct\n");
	trace_dumb_list(&list);

	return 0;
}

void trace_dumb_list(dumb_list *list)
{
	printf("  %p\n  len:%ld\n  real:%ld\n  sizeof:%ld\n", 
		list->ptr, list->length, 
		list->m_cur_length, list->m_sizeof);
}