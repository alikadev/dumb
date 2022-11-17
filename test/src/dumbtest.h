#ifndef DUMBTEST_H
#define DUMBTEST_H

#include <dumb/color.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef TRACE_LEN
#define TRACE_LEN 32000
#endif

/// test state
typedef enum {
	SUCCESS,
	FAILURE,
	EXPECTED,
	NOT_IMPLEMENTED
} state_t;

/// current test trace, print in it!
static char trace[TRACE_LEN] = {0};

/// Do not use it!
void print_error(const char *txt)
{
	printf(	RED "%-24s: Failure\n" RES "\nTRACES:\n", txt);
	printf("%s\n",trace);
}

/// Print state: USE THIS
void print_state(const char *txt, const state_t state)
{
	switch(state){
	case SUCCESS:
		printf(GRN);
		break;
	case EXPECTED:
		printf(YEL);
		break;
	case FAILURE:
		print_error(txt);
		exit(1);
		break;
	case NOT_IMPLEMENTED:
		printf(RED);
	}
	printf("%-24s", txt);
	switch(state){
	case SUCCESS:
		printf(": Success\n");
		break;
	case EXPECTED:
		printf(": Expected\n");
		break;
	case NOT_IMPLEMENTED:
		printf(": Not already implemented!\n");
	default:
		break;
	}
}

#endif