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

    FILE* filei = fopen(namei, "rb");

    if(filei == NULL)
    {
        fprintf(stderr, "bad filename: unable to open file for reading: %s (-i)\n", namei);
        return 0;
    }

    int lx;
    int ly;

    if(dech(filei, &lx, &ly) != 0)
    {
        fprintf(stderr, "bad filename: unable to read image head: %s (-i)\n", namei);
        return 0;
    }

    float img[lx][ly][3];

    if(decb(filei, lx, ly, img) != 0)
    {
        fprintf(stderr, "bad filename: unable to read image body: %s (-i)\n", namei);
        return 0;
    }

    if(fclose(filei) != 0)
    {
        fprintf(stderr, "bad filename: unable to close file: %s (-i)\n", namei);
        return 0;
    }

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

    if(stbi_write_png(nameo, lx, ly, 3, stb, lx * 3) != 0)
    {
        fprintf(stderr, "bad filename: unable to write image: %s (-o)\n", nameo);
        return 0;
    }

    return 0;
}
