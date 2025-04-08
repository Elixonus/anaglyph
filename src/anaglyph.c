#include <stdio.h>
#include "image.h"

struct image image;
struct image image1;
struct image image2;
FILE *file;
FILE *file1;
FILE *file2;
char filename[1001];
char filename1[1001];
char filename2[1001];
double filter1[3];
double filter2[3];

int main(int argc, char **argv)
{
	if(argc != 6) return 1;
	if(sscanf(argv[1], "%1000s", filename) != 1) return 1;
	if(sscanf(argv[2], "image1=%1000s", filename1) != 1) return 1;
	if(sscanf(argv[3], "image2=%1000s", filename2) != 1) return 1;
	file1 = fopen(filename1, "rb");
	if(!file1) return 1;
	if(idecodeh(&image1, file1) != 0) return 1;
	if(icreateb(&image1) != 0) return 1;
	if(idecodeb(&image1, file1) != 0) return 1;
	if(fclose(file1) != 0) return 1;
	file2 = fopen(filename2, "rb");
	if(!file2) return 1;
	if(idecodeh(&image2, file2) != 0) return 1;
	if(icreateb(&image2) != 0) return 1;
	if(idecodeb(&image2, file2) != 0) return 1;
	if(fclose(file2) != 0) return 1;
	for(int a = 0; a < 2; a++)
	{
		if(image1.size[a] > image2.size[a])
			image.size[a] = image1.size[a];
		else
			image.size[a] = image2.size[a];
	}
	if(icreateb(&image) != 0) return 1;
	if(sscanf(argv[4], "filter1=<%lf %lf %lf>", &filter1[0], &filter1[1], &filter1[2]) != 3) return 1;
	if(sscanf(argv[5], "filter2=<%lf %lf %lf>", &filter2[0], &filter2[1], &filter2[2]) != 3) return 1;
	for(int x = 0; x < image.size[0]; x++)
	{
		for(int y = 0; y < image.size[1]; y++)
		{
			double color1[3];
			if(x < image1.size[0] && y < image1.size[1]) for(int c = 0; c < 3; c++)
					color1[c] = image1.data[x][y][c];
			double color2[3];
			if(x < image2.size[0] && y < image2.size[1]) for(int c = 0; c < 3; c++)
					color2[c] = image2.data[x][y][c];
			double color[3];
			for(int c = 0; c < 3; c++)
			{
				color[c] = filter1[c] * color1[c] + filter2[c] * color2[c];
				color[c] = color[c] > 0.0 ? (color[c] < 1.0 ? color[c] : 1.0) : 0.0;
				image.data[x][y][c] = color[c];
			}
		}
	}
	idestroyb(&image1);
	idestroyb(&image2);
	file = fopen(filename, "wb");
	if(!file) return 1;
	if(iencodeh(&image, file) != 0) return 1;
	if(iencodeb(&image, file) != 0) return 1;
	idestroyb(&image);
	if(fclose(file) != 0) return 1;
	return 0;
}
