#include <stdio.h>
#include <string.h>
#include "img.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

int main(int argc, char* argv[])
{
    char* namei;
    char* namep;

    for(int a = 1; a < argc; a++)
    {
        if(strlen(argv[a]) > 0 && argv[a][0] == '-' && a < argc - 1)
        {
            if(strcmp(argv[a], "-im") == 0)
            {
                namei = argv[++a];
            }

            else if(strcmp(argv[a], "-pg") == 0)
            {
                namep = argv[++a];
            }

            else
            {
                fprintf(stderr, "error: argument not recognized: \"%s\" (%d)\n", argv[a], a);
                return 1;
            }
        }

        else
        {
            fprintf(stderr, "error: argument not expected: \"%s\" (%d)\n", argv[a], a);
            return 1;
        }
    }

    if(strlen(namei) == 0)
    {
        fprintf(stderr, "error: argument not provided: -im\n");
        return 1;
    }

    if(strlen(namep) == 0)
    {
        fprintf(stderr, "error: argument not provided: -pg\n");
        return 1;
    }

    FILE* filei = fopen(namei, "rb");

    if(filei == NULL)
    {
        fprintf(stderr, "error: file cannot be opened: \"%s\"\n", namei);
        return 1;
    }

    int w;
    int h;

    if(dech(&w, &h, filei) != 0)
    {
        fprintf(stderr, "error: image head cannot be read: \"%s\"\n", namei);
        return 1;
    }

    float img[w][h][3];

    if(decb(w, h, img, filei) != 0)
    {
        fprintf(stderr, "error: image body cannot be read: \"%s\"\n", namei);
        return 1;
    }

    if(fclose(filei) != 0)
    {
        fprintf(stderr, "error: file cannot be closed: \"%s\"\n", namei);
        return 1;
    }

    unsigned char stb[w * h * 3];

    int p = 0;

    for(int y = h - 1; y >= 0; y--)
    {
        for(int x = 0; x < w; x++)
        {
            stb[p++] = (int) (255 * img[x][y][0]);
            stb[p++] = (int) (255 * img[x][y][1]);
            stb[p++] = (int) (255 * img[x][y][2]);
        }
    }

    stbi_write_png(namep, w, h, 3, stb, w * 3);

    return 0;
}
