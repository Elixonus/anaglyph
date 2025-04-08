#include <stdio.h>
#include "image.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

unsigned char *imagef;
struct image imaget;
FILE *filet;
char filenamef[1001];
char filenamet[1001];

int main(int argc, char **argv)
{
	if(argc != 3) return 1;
	if(sscanf(argv[1], "%1000s", filenamef) != 1) return 1;
	if(sscanf(argv[2], "%1000s", filenamet) != 1) return 1;
	imagef = stbi_load(filenamef, &imaget.size[0], &imaget.size[1], NULL, 3);
	if(!imagef) return 1;
	icreateb(&imaget);
	int indexf = 0;
	for(int y = imaget.size[1] - 1; y >= 0; y--)
		for(int x = 0; x < imaget.size[0]; x++)
			for(int c = 0; c < 3; c++)
				imaget.data[x][y][c] = ((double) imagef[indexf++]) / 255.0;
	filet = fopen(filenamet, "wb");
	if(!filet) return 1;
	if(iencodeh(&imaget, filet) != 0) return 1;
	if(iencodeb(&imaget, filet) != 0) return 1;
	idestroyb(&imaget);
	if(fclose(filet) != 0) return 1;
	return 0;
}
