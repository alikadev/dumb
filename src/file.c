#include <dumb/file.h>
#include <stdlib.h>
#include <string.h>

char *dumb_file_read(FILE *file)
{
	// malloc memory
	fseek(file, 0, SEEK_END);
	char *data = (char*) malloc(ftell(file)+1);
	rewind(file);

	// read file
	int c;
	int i = 0;
	while ((c = fgetc(file)) != EOF) {
		data[i++] = (char) c;
	}
	data[i] = 0; // null terminated

	return data;
}

void dumb_file_read_lines(dumb_list *list, FILE *file)
{
	dumb_list_init(list, sizeof (char*), 0);
	char *content = dumb_file_read(file);
	char *last = content;
	while(*content != 0) {
		if(*content == '\n'){
			// terminate list
			*content = 0;
			// add string start to list
			dumb_list_push(list);
			((char**)list->ptr)[list->length-1] = last;
			// increment last & start
			last = ++content;
			continue;
		}
		content++;
	}
}

void dumb_file_free_lines(dumb_list *list)
{
	free(*(char**)list->ptr);
	dumb_list_free(list);
}