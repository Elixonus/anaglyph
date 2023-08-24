#include <stdio.h>
#include <string.h>
#include "img.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

int main(int argc, char* argv[])
{
    char* namei;
    char* nameo;

    for(int a = 1; a < argc - 1; a++)
    {
        if(strcmp(argv[a], "-i") == 0)
        {
            namei = argv[++a];
        }

        else if(strcmp(argv[a], "-o") == 0)
        {
            nameo = argv[++a];
        }

        else
        {
            fprintf(stderr, "bad argument: %s (%d)\n", argv[a], a);
            return 0;
        }
    }

    int lx;
    int ly;

    unsigned char* stb = stbi_load(namei, &lx, &ly, NULL, 3);
    float img[lx][ly][3];

    int p = 0;

    for(int y = 0; y < ly; y++)
    {
        for(int x = 0; x < lx; x++)
        {
            img[x][y][0] = ((float) stb[p++]) / 255;
            img[x][y][1] = ((float) stb[p++]) / 255;
            img[x][y][2] = ((float) stb[p++]) / 255;
        }
    }

    FILE* file = fopen(nameo, "wb");

    ench(lx, ly, file);
    encb(lx, ly, img, file);

    return 0;
}
