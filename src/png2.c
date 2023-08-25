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
        if(strlen(argv[a]) > 0 && argv[a][0] == '-')
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
                fprintf(stderr, "bad argument: unrecognized flagged argument: %s (%d)\n", argv[a], a);
                return 0;
            }
        }

        else
        {
            fprintf(stderr, "bad argument: unexpected unflagged argument: %s (%d)\n", argv[a], a);
            return 0;
        }
    }

    if(strlen(namei) == 0)
    {
        fprintf(stderr, "bad filename: unprovided argument: -i\n");
        return 0;
    }

    if(strlen(nameo) == 0)
    {
        fprintf(stderr, "bad filename: unprovided argument: -o\n");
        return 0;
    }

    FILE* fileo = fopen(nameo, "wb");

    if(fileo == NULL)
    {
        fprintf(stderr, "bad filename: unable to open file for writing: %s (-i)\n", nameo);
        return 0;
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

    if(ench(lx, ly, fileo) != 0)
    {
        fprintf(stderr, "bad filename: unable to write image head: %s (-o)\n", nameo);
        return 0;
    }

    if(encb(lx, ly, img, fileo) != 0)
    {
        fprintf(stderr, "bad filename: unable to write image body: %s (-o)\n", nameo);
        return 0;
    }

    return 0;
}
