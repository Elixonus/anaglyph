#include <stdio.h>
#include <stdlib.h>

struct image
{
	int size[2];
	double ***data;
};

int icreateb(struct image *image)
{
	image->data = malloc(image->size[0] * sizeof(double **));
	if(image->data == nullptr) return 1;
	for(int x = 0; x < image->size[0]; x++)
	{
		image->data[x] = malloc(image->size[1] * sizeof(double *));
		if(image->data[x] == nullptr) return 1;
		for(int y = 0; y < image->size[1]; y++)
		{
			image->data[x][y] = malloc(3 * sizeof(double));
			if(image->data[x][y] == nullptr) return 1;
		}
	}
	return 0;
}

void idestroyb(struct image *image)
{
	for(int x = 0; x < image->size[0]; x++)
	{
		for(int y = 0; y < image->size[1]; y++)
			free(image->data[x][y]);
		free(image->data[x]);
	}
	free(image->data);
}

int iencodeh(struct image *image, FILE *file)
{
	if(fwrite(image->size, sizeof(int), 2, file) != 2) return 1;
	return 0;
}

int idecodeh(struct image *image, FILE *file)
{
	if(fread(image->size, sizeof(int), 2, file) != 2) return 1;
	return 0;
}

int iencodeb(struct image *image, FILE *file)
{
	for(int x = 0; x < image->size[0]; x++)
		for(int y = 0; y < image->size[1]; y++)
			if(fwrite(image->data[x][y], sizeof(double), 3, file) != 3) return 1;
	return 0;
}

int idecodeb(struct image *image, FILE *file)
{
	for(int x = 0; x < image->size[0]; x++)
		for(int y = 0; y < image->size[1]; y++)
			if(fread(image->data[x][y], sizeof(double), 3, file) != 3) return 1;
	return 0;
}
