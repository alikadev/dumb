#ifndef DUMB_FILE_H
#define DUMB_FILE_H

#include <stdio.h>
#include <dumb/list.h>

/// Need to free the memory
/// The file need to be open
char *dumb_file_read(FILE *file);

/// Free the first element to free all the list
/// The file need to be open
void dumb_file_read_lines(dumb_list *list, FILE *file);
void dumb_file_free_lines(dumb_list *list);


#ifdef USE_DUMB_FILE_QUICK_NAME

#define df_read 		dumb_file_read
#define df_read_lines 	dumb_file_read_lines
#define df_free_lines 	dumb_file_free_lines

#endif // USE_DUMB_FILE_QUICK_NAME

#endif // DUMB_FILE_H