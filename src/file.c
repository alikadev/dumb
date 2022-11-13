#include <dumb/file.h>
#include <stdlib.h>

char *file_read_all(FILE *file)
{
	// malloc memory
	fseek(file, 0, SEEK_END);
	size_t size = ftell(file);
	char *data = (char *) malloc(size);
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