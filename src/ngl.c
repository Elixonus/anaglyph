#include <stdio.h>
#include <string.h>
#include "img.h"

int main(int argc, char* argv[argc])
{
    char* name = "";
    char* name1 = "";
    char* name2 = "";

    int dx = 0;
    int dy = 0;

    float cr1 = 0.5f;
    float cr2 = 0.5f;

    float cg1 = 0.5f;
    float cg2 = 0.5f;

    float cb1 = 0.5f;
    float cb2 = 0.5f;

    for(int a = 1; a < argc; a++)
    {
        if(strlen(argv[a]) > 0 && argv[a][0] == '-' && a < argc - 1)
        {
            if(strcmp(argv[a], "-ii") == 0)
            {
                name = argv[++a];
            }

            else if(strcmp(argv[a], "-i1") == 0)
            {
                name1 = argv[++a];
            }

            else if(strcmp(argv[a], "-i2") == 0)
            {
                name2 = argv[++a];
            }

            else if(strcmp(argv[a], "-dx") == 0)
            {
                sscanf(argv[++a], "%d", &dx);
            }

            else if(strcmp(argv[a], "-dy") == 0)
            {
                sscanf(argv[++a], "%d", &dy);
            }

            else if(strcmp(argv[a], "-r1") == 0)
            {
                sscanf(argv[++a], "%f", &cr1);
            }

            else if(strcmp(argv[a], "-r2") == 0)
            {
                sscanf(argv[++a], "%f", &cr2);
            }

            else if(strcmp(argv[a], "-g1") == 0)
            {
                sscanf(argv[++a], "%f", &cg1);
            }

            else if(strcmp(argv[a], "-g2") == 0)
            {
                sscanf(argv[++a], "%f", &cg2);
            }

            else if(strcmp(argv[a], "-b1") == 0)
            {
                sscanf(argv[++a], "%f", &cb1);
            }

            else if(strcmp(argv[a], "-b2") == 0)
            {
                sscanf(argv[++a], "%f", &cb2);
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

    if(strlen(name) == 0)
    {
        fprintf(stderr, "error: argument not provided: -ii\n");
        return 1;
    }

    if(strlen(name1) == 0)
    {
        fprintf(stderr, "error: argument not provided: -i1\n");
        return 1;
    }

    if(strlen(name2) == 0)
    {
        fprintf(stderr, "error: argument not provided: -i2\n");
        return 1;
    }

    FILE* file1 = fopen(name1, "rb");
    FILE* file2 = fopen(name2, "rb");

    if(file1 == NULL)
    {
        fprintf(stderr, "error: can't open input image file 1: \"%s\"\n", name1);
        return 1;
    }

    if(file2 == NULL)
    {
        fprintf(stderr, "error: can't open input image file 2: \"%s\"\n", name2);
        return 1;
    }

    int dx1;
    int dy1;

    int dx2;
    int dy2;

    if(dx > 0)
    {
        dx1 = 0;
        dx2 = dx;
    }

    else
    {
        dx1 = -dx;
        dx2 = 0;
    }

    if(dy > 0)
    {
        dy1 = 0;
        dy2 = dy;
    }

    else
    {
        dy1 = -dy;
        dy2 = 0;
    }

    int lx1;
    int ly1;

    int lx2;
    int ly2;

    if(dech(&lx1, &ly1, file1) != 0)
    {
        fprintf(stderr, "error: can't read input image 1 head: \"%s\"\n", name1);
        return 1;
    }

    if(dech(&lx2, &ly2, file2) != 0)
    {
        fprintf(stderr, "error: can't read input image 2 head: \"%s\"\n", name2);
        return 1;
    }

    int lx;
    int ly;

    if(lx1 + dx1 > lx2 + dx2)
    {
        lx = lx1 + dx1;
    }

    else
    {
        lx = lx2 + dx2;
    }

    if(ly1 + dy1 > ly2 + dy2)
    {
        ly = ly1 + dy1;
    }

    else
    {
        ly = ly2 + dy2;
    }

    float img[lx][ly][3];
    float img1[lx1][ly1][3];
    float img2[lx2][ly2][3];

    if(decb(lx1, ly1, img1, file1) != 0)
    {
        fprintf(stderr, "error: can't read input image 1 body: \"%s\"\n", name1);
        return 1;
    }

    if(decb(lx2, ly2, img2, file2) != 0)
    {
        fprintf(stderr, "error: can't read input image 2 body: \"%s\"\n", name2);
        return 1;
    }

    if(fclose(file1) != 0)
    {
        fprintf(stderr, "error: can't close input file 1: \"%s\"\n", name1);
        return 1;
    }

    if(fclose(file2) != 0)
    {
        fprintf(stderr, "error: can't close input file 2: \"%s\"\n", name2);
        return 1;
    }

    for(int x = 0; x < lx; x++)
    {
        for(int y = 0; y < ly; y++)
        {
            int x1 = x - dx1;
            int y1 = y - dy1;

            int x2 = x - dx2;
            int y2 = y - dy2;

            float r1;
            float g1;
            float b1;

            float r2;
            float g2;
            float b2;

            if(x1 >= 0 && y1 >= 0 && x1 < lx1 && y1 < ly1)
            {
                r1 = img1[x1][y1][0];
                g1 = img1[x1][y1][1];
                b1 = img1[x1][y1][2];
            }

            else
            {
                r1 = 0.0f;
                g1 = 0.0f;
                b1 = 0.0f;
            }

            if(x2 >= 0 && y2 >= 0 && x2 < lx2 && y2 < ly2)
            {
                r2 = img2[x2][y2][0];
                g2 = img2[x2][y2][1];
                b2 = img2[x2][y2][2];
            }

            else
            {
                r2 = 0.0f;
                g2 = 0.0f;
                b2 = 0.0f;
            }

            float r = r1 * cr1 + r2 * cr2;
            float g = g1 * cg1 + g2 * cg2;
            float b = b1 * cb1 + b2 * cb2;

            img[x][y][0] = r;
            img[x][y][1] = g;
            img[x][y][2] = b;
        }
    }

    FILE* file = fopen(name, "wb");

    if(file == NULL)
    {
        fprintf(stderr, "error: can't open output file: \"%s\"\n", name);
        return 1;
    }

    if(ench(lx, ly, file) != 0)
    {
        fprintf(stderr, "error: can't write output image head: \"%s\"\n", name);
        return 1;
    }

    if(encb(lx, ly, img, file) != 0)
    {
        fprintf(stderr, "error: can't write output image body: \"%s\"\n", name);
        return 1;
    }

    if(fclose(file) != 0)
    {
        fprintf(stderr, "error: can't close output file: \"%s\"\n", name);
        return 1;
    }

    return 0;
}
