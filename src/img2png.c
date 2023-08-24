#include <stdio.h>
#include <string.h>
#include "img.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

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

    FILE* file = fopen(namei, "rb");

    int lx;
    int ly;

    dech(file, &lx, &ly);

    float img[lx][ly][3];

    decb(file, lx, ly, img);

    unsigned char stb[lx * ly * 3];

    int p = 0;

    for(int y = 0; y < ly; y++)
    {
        for(int x = 0; x < lx; x++)
        {
            stb[p++] = (int) (255 * img[x][y][0]);
            stb[p++] = (int) (255 * img[x][y][1]);
            stb[p++] = (int) (255 * img[x][y][2]);
        }
    }

    stbi_write_png(nameo, lx, ly, 3, stb, lx * 3);

    return 0;
}
