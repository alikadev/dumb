#include "dumbtest.h"
#include <dumb/file.h>
#include <string.h>

int main(void)
{
	FILE *file = fopen("res/example.txt", "rb");
	if(!file) return 1;
	dumb_list list;


	// DUMB_FILE_READ_ALL
	char *content = dumb_file_read(file);
	if(!content || strlen(content) == 0){
		print_state("dumb_file_read", FAILURE);
		free(content);
		return 1;
	}
	print_state("dumb_file_read", SUCCESS);
	free(content);
	

	// DUMB_FILE_READ_LINES
	dumb_file_read_lines(&list, file);
	if(!list.ptr || list.length==0){
		print_state("dumb_file_read_lines", FAILURE);
		dumb_file_free_lines(&list);
		return 1;
	}
	print_state("dumb_file_read_lines", SUCCESS);
	dumb_file_free_lines(&list);
	
	fclose(file);
	printf(RES);
	return 0;
}