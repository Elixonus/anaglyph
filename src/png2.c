#include <stdio.h>
#include <string.h>
#include "img.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

int main(int argc, char* argv[])
{
    char* namep;
    char* namei;

    for(int a = 1; a < argc - 1; a++)
    {
        if(strlen(argv[a]) > 0 && argv[a][0] == '-')
        {
            if(strcmp(argv[a], "-i") == 0)
            {
                namep = argv[++a];
            }

            else if(strcmp(argv[a], "-o") == 0)
            {
                namei = argv[++a];
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

    if(strlen(namep) == 0)
    {
        fprintf(stderr, "need argument: was expecting flagged argument: -i\n");
        return 1;
    }

    if(strlen(namei) == 0)
    {
        fprintf(stderr, "need argument: was expecting flagged argument: -o\n");
        return 1;
    }

    FILE* filei = fopen(namei, "wb");

    if(filei == NULL)
    {
        fprintf(stderr, "bad file: can't open output file: \"%s\"\n", namei);
        return 1;
    }

    int wdt;
    int hgt;

    unsigned char* stb = stbi_load(namep, &wdt, &hgt, NULL, 3);

    float img[wdt][hgt][3];

    int p = 0;

    for(int y = 0; y < hgt; y++)
    {
        for(int x = 0; x < wdt; x++)
        {
            img[x][y][0] = ((float) stb[p++]) / 255;
            img[x][y][1] = ((float) stb[p++]) / 255;
            img[x][y][2] = ((float) stb[p++]) / 255;
        }
    }

    if(ench(wdt, hgt, filei) != 0)
    {
        fprintf(stderr, "bad image: can't write output image head: \"%s\"\n", namei);
        return 1;
    }

    if(encb(wdt, hgt, img, filei) != 0)
    {
        fprintf(stderr, "bad image: can't write output image body: \"%s\"\n", namei);
        return 1;
    }

    if(fclose(filei) != 0)
    {
        fprintf(stderr, "bad file: can't close output file: \"%s\"\n", namei);
        return 1;
    }

    return 0;
}
