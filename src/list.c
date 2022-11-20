#include <dumb/list.h>
#include <stdlib.h>
#include <string.h>

dumb_list *dumb_list_init(
		dumb_list *list,
		size_t sizeofElem, 
		size_t nbElem)
{
	list->ptr = malloc(sizeofElem * nbElem);
	if(!list->ptr)
		return NULL;
	list->length = nbElem;
	list->m_cur_length = nbElem;
	list->m_sizeof = sizeofElem;
	return list;
}

void dumb_list_free(dumb_list *list)
{
	free(list->ptr);
	list->length = 0;
	list->m_cur_length = 0;
	list->m_sizeof = 0;
}

dumb_list *dumb_list_push(dumb_list *list)
{
	return dumb_list_push_n(list, 1);
}

dumb_list *dumb_list_push_n(dumb_list *list, size_t n)
{
	list->length+=n;
	// check current alloc is large enouth
	if(list->m_cur_length >= list->length){
		return list;
	}

	// reallocate memory
	void *newAddr = realloc(list->ptr, list->length * list->m_sizeof);
	if(!newAddr) {
		return NULL;
	}
	list->m_cur_length = list->length;
	list->ptr = newAddr;

	return list;
}

dumb_list *dumb_list_del_n(dumb_list *list, size_t nbElem)
{
	list->length -= nbElem;
	if(list->m_cur_length - nbElem < 0){
		list->length = list->m_cur_length; 
		return NULL;
	}

	void *newAddr = realloc(list->ptr, list->length * list->m_sizeof);
	if(!newAddr){
		return NULL;
	}
	list->m_cur_length = list->length;
	list->ptr = newAddr;

	return list;
}

dumb_list *dumb_list_del(dumb_list *list)
{
	if(list->m_cur_length - 1 < 0)
		return NULL;
	return dumb_list_del_n(list, 1);
}

dumb_list *dumb_list_pop_n(dumb_list *list, size_t nbElem)
{
	if(list->m_cur_length - nbElem < 0)
		return NULL;
	list->length -= nbElem;
	return list;
}

dumb_list *dumb_list_pop(dumb_list *list)
{
	return dumb_list_pop_n(list, 1);
}

void dumb_list_shr_part(dumb_list *list, size_t start)
{
	if(start==0) start=1;
	for(int i=list->length; i >= start; i--){
		memcpy(
			list->ptr+i*list->m_sizeof,
			list->ptr+(i-1)*list->m_sizeof,
			list->m_sizeof);
	}
}

void dumb_list_shr(dumb_list *list)
{
	dumb_list_shr_part(list, 1);
}


