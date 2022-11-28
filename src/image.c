#include <dumb/image.h>

#include <stdlib.h>
#include <stdio.h>

int dumb_write_bmp24(
		const char *path, 
		const tex32_t *tex)
{
	FILE *f = fopen(path, "wb");
	if(!f) return 0;

	uint8_t bmpHeader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
	uint8_t infoHeader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
    uint8_t padding[3] = {0, 0, 0};
    int paddingSize = (4 - (tex->w*3) % 4) % 4;
    int stride = (tex->w*3) + paddingSize;
	int filesize = sizeof bmpHeader + sizeof infoHeader + stride * tex->h;

	bmpHeader[ 2] = (filesize    ) & 0xFF;
	bmpHeader[ 3] = (filesize>> 8) & 0xFF;
	bmpHeader[ 4] = (filesize>>16) & 0xFF;
	bmpHeader[ 5] = (filesize>>24) & 0xFF;

	infoHeader[ 4] = (tex->w    ) & 0xFF;
	infoHeader[ 5] = (tex->w>> 8) & 0xFF;
	infoHeader[ 6] = (tex->w>>16) & 0xFF;
	infoHeader[ 7] = (tex->w>>24) & 0xFF;
	infoHeader[ 8] = (tex->h    ) & 0xFF;
	infoHeader[ 9] = (tex->h>> 8) & 0xFF;
	infoHeader[10] = (tex->h>>16) & 0xFF;
	infoHeader[11] = (tex->h>>24) & 0xFF;

	fwrite(bmpHeader,1,14,f);
	fwrite(infoHeader,1,40,f);
	for(int i=0; i<tex->h; i++)
	{
		for (int j = 0; j < tex->w; ++j)
		{
			fputc((tex->p[i]    ) & 0xFF, f);
			fputc((tex->p[i]>> 8) & 0xFF, f);
			fputc((tex->p[i]>>16) & 0xFF, f);
		}
	    fwrite(padding, 1, paddingSize, f);
	}

	fclose(f);

	return 1;
}