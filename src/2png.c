#include <stdio.h>
#include <string.h>
#include "img.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

int main(int argc, char* argv[])
{
    char* namei;
    char* namep;

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
                namep = argv[++a];
            }

            else
            {
                fprintf(stderr, "bad argument: can't recognize flagged argument: \"%s\" (%d)\n", argv[a], a);
                return 1;
            }
        }

        else
        {
            fprintf(stderr, "bad argument: was expecting flagged argument: \"%s\" (%d)\n", argv[a], a);
            return 1;
        }
    }

    if(strlen(namei) == 0)
    {
        fprintf(stderr, "need argument: was expecting flagged argument: -i\n");
        return 1;
    }

    if(strlen(namep) == 0)
    {
        fprintf(stderr, "need argument: was expecting flagged argument: -o\n");
        return 1;
    }

    FILE* filei = fopen(namei, "rb");

    if(filei == NULL)
    {
        fprintf(stderr, "bad file: can't open input file: \"%s\"\n", namei);
        return 1;
    }

    int wdt;
    int hgt;

    if(dech(&wdt, &hgt, filei) != 0)
    {
        fprintf(stderr, "bad image: can't read input image head: \"%s\"\n", namei);
        return 1;
    }

    float img[wdt][hgt][3];

    if(decb(wdt, hgt, img, filei) != 0)
    {
        fprintf(stderr, "bad image: can't read input image body: \"%s\"\n", namei);
        return 1;
    }

    if(fclose(filei) != 0)
    {
        fprintf(stderr, "bad file: can't close input file: \"%s\"\n", namei);
        return 1;
    }

    unsigned char stb[wdt * hgt * 3];

    int p = 0;

    for(int y = 0; y < hgt; y++)
    {
        for(int x = 0; x < wdt; x++)
        {
            stb[p++] = (int) (255 * img[x][y][0]);
            stb[p++] = (int) (255 * img[x][y][1]);
            stb[p++] = (int) (255 * img[x][y][2]);
        }
    }

    stbi_write_png(namep, wdt, hgt, 3, stb, wdt * 3);

    return 0;
}
