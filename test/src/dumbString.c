#include "dumbtest.h"
#include <dumb/str.h>

#define STR1 "This is a string!"
#define STR1C 'i'
#define STR1S "is"

#define STR2 "This is a string!"
#define STR3 "This is a string!\ncool!"

void trace_tokens(char *msg, dumb_list *list)
{
	sprintf(trace, RES "%s%s\n" BLU "  len = %zu\n  real = %ld\n  tokens:\n",
		trace, msg, list->length, list->m_cur_length);

	for (int i = 0; i < list->length; ++i) {
		sprintf(trace, "%s    \"%s\"\n", 
			trace, ((char**)list->ptr)[i]);
	}

	sprintf(trace, "%s" RES, trace);
}

int main(void)
{
	dumb_list tokens;
	int state;

	// STREQ
	bool bstate = streq(STR1, STR2);
	sprintf(trace, RES "%sstreq\n" BLU "  str1 = \"%s\"\n  str2 = \"%s\"\n" RES, 
			trace, STR1, STR2);
	if(!bstate){
		print_state("streq", FAILURE);
		return 1;
	}
	print_state("streq", SUCCESS);


	// STRTOKC
	state = strtokc(&tokens, STR1, STR1C);
	trace_tokens("strtokc", &tokens);
	if(state != 0 || tokens.length != 4){
		print_state("strtokc", FAILURE);
		strtok_free(&tokens);
		return 1;
	}
	print_state("strtokc", SUCCESS);
	strtok_free(&tokens);
	return 0;
}