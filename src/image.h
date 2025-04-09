#include <stdio.h>
#ifndef IMAGEHEADER
#define IMAGEHEADER

struct image
{
	int size[2];
	double ***data;
};

int icreateb(struct image *image);
void idestroyb(struct image *image);
int iencodeh(struct image *image, FILE *file);
int idecodeh(struct image *image, FILE *file);
int iencodeb(struct image *image, FILE *file);
int idecodeb(struct image *image, FILE *file);

#endif
