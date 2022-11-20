#include <dumb/string.h>
#include <stdlib.h>

static char buff[TOKENS_MAX_LENGTH] = {0};

#if defined LINUX

char *strdup(const char *ptr)
{
	char *result = (char *)malloc(strlen(ptr)+1);
	strcpy(result, ptr);
	return result;
}

#endif

bool streq(const char *s1, const char *s2)
{
	return strcmp(s1, s2) == 0;
}

// Will init the dumb_list, need to free by hand!
int strtokc(dumb_list *tokens, const char *src, const char delim)
{
	if(!dumb_list_init(tokens, sizeof *src, TOKENS_PREALLOC))
		return -1;

	tokens->length = 0;

	int i=0;

	while(*src != 0){
		if(*src == delim){
			if(!dumb_list_push(tokens))
				return -1;
			((char**)tokens->ptr)[tokens->length-1] = strdup(buff);
			for(int j=0; j<i; j++)
				buff[j]=0;
			i=0;
		} else {
			buff[i++] = *src;
		}
		src++;
	}

	if(!dumb_list_push(tokens))
		return -1;
	((char**)tokens->ptr)[tokens->length-1] = strdup(buff);
	return 0;
}

void strtok_free(dumb_list *list)
{
	for (int i = 0; i < list->length; ++i) {
		free(((char**)list->ptr)[i]);
	}
	dumb_list_free(list);
}

int strtokspace(dumb_list *tokens, const char src){
	return -1;
}