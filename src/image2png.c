#include <stdio.h>
#include "image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

struct image imagef;
unsigned char *imaget;
FILE *filef;
char filenamef[1001];
char filenamet[1001];

int main(int argc, char **argv)
{
	if(argc != 3) return 1;
	if(sscanf(argv[1], "%1000s", filenamef) != 1) return 1;
	if(sscanf(argv[2], "%1000s", filenamet) != 1) return 1;
	filef = fopen(filenamef, "rb");
	if(!filef) return 1;
	if(idecodeh(&imagef, filef) != 0) return 1;
	if(icreateb(&imagef) != 0) return 1;
	if(idecodeb(&imagef, filef) != 0) return 1;
	if(fclose(filef) != 0) return 1;
	imaget = malloc(imagef.size[0] * imagef.size[1] * 3 * sizeof(unsigned char));
	if(!imaget) return 1;
	int indext = 0;
	for(int y = imagef.size[1] - 1; y >= 0; y--)
		for(int x = 0; x < imagef.size[0]; x++)
			for(int c = 0; c < 3; c++)
				imaget[indext++] = (int) (255 * imagef.data[x][y][c]);
	if(stbi_write_png(filenamet, imagef.size[0], imagef.size[1], 3, imaget, 3 * imagef.size[0]) != 0) return 1;
	free(imaget);
	return 0;
}
