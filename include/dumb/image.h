#ifndef DUMB_IMAGE_H
#define DUMB_IMAGE_H

#include <stdint.h>

typedef struct {
	union {int width, w;};
	union {int height, h;};
	union {uint32_t *pixels, *p;};
} tex32_t;


int dumb_write_bmp24(const char *path, const tex32_t *tex);


#ifdef USE_DUMB_LIST_QUICK_NAME

#define write_bmp24	dumb_write_bmp24

#endif

#endif