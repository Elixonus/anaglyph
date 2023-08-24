#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "img.h"

int main(int argc, char* argv[])
{
    char* name;
    char* name1;
    char* name2;

    int dx = 0;
    int dy = 0;

    float cr1 = 0.5;
    float cr2 = 0.5;

    float cg1 = 0.5;
    float cg2 = 0.5;

    float cb1 = 0.5;
    float cb2 = 0.5;

    for(int a = 1; a < argc - 1; a++)
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
            if(sscanf(argv[++a], "%d", &dx) == 0)
            {
                fprintf(stderr, "bad argument: %s (%d)\n", argv[a], a);
                return 0;
            }
        }

        else if(strcmp(argv[a], "-dy") == 0)
        {
            if(sscanf(argv[++a], "%d", &dy) == 0)
            {
                fprintf(stderr, "bad argument: %s (%d)\n", argv[a], a);
                return 0;
            }
        }

        else if(strcmp(argv[a], "-r1") == 0)
        {
            if(sscanf(argv[++a], "%f", &cr1) == 0)
            {
                fprintf(stderr, "bad argument: %s (%d)\n", argv[a], a);
                return 0;
            }
        }

        else if(strcmp(argv[a], "-r2") == 0)
        {
            if(sscanf(argv[++a], "%f", &cr2) == 0)
            {
                fprintf(stderr, "bad argument: %s (%d)\n", argv[a], a);
                return 0;
            }
        }

        else if(strcmp(argv[a], "-g1") == 0)
        {
            if(sscanf(argv[++a], "%f", &cg1) == 0)
            {
                fprintf(stderr, "bad argument: %s (%d)\n", argv[a], a);
                return 0;
            }
        }

        else if(strcmp(argv[a], "-g2") == 0)
        {
            if(sscanf(argv[++a], "%f", &cg2) == 0)
            {
                fprintf(stderr, "bad argument: %s (%d)\n", argv[a], a);
                return 0;
            }
        }

        else if(strcmp(argv[a], "-b1") == 0)
        {
            if(sscanf(argv[++a], "%f", &cb1) == 0)
            {
                fprintf(stderr, "bad argument: %s (%d)\n", argv[a], a);
                return 0;
            }
        }

        else if(strcmp(argv[a], "-b2") == 0)
        {
            if(sscanf(argv[++a], "%f", &cb2) == 0)
            {
                fprintf(stderr, "bad argument: %s (%d)\n", argv[a], a);
                return 0;
            }
        }
    }

    printf("name:%s\n", name);
    printf("name1:%s\n", name1);
    printf("name2:%s\n", name2);
    printf("dx:%d\n", dx);
    printf("dy:%d\n", dy);
    printf("cr1:%f\n", cr1);
    printf("cr2:%f\n", cr2);
    printf("cg1:%f\n", cg1);
    printf("cg2:%f\n", cg2);
    printf("cb1:%f\n", cb1);
    printf("cb2:%f\n", cb2);

    FILE* file1 = fopen(name1, "rb");
    FILE* file2 = fopen(name2, "rb");

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

    printf("dx1:%d\n", dx1);
    printf("dy1:%d\n", dy1);
    printf("dx2:%d\n", dx2);
    printf("dy2:%d\n", dy2);

    int lx1;
    int ly1;

    int lx2;
    int ly2;

    dech(file1, &lx1, &ly1);
    dech(file2, &lx2, &ly2);

    printf("lx1:%d\n", lx1);
    printf("ly1:%d\n", ly1);
    printf("lx2:%d\n", lx2);
    printf("ly2:%d\n", ly2);

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

    printf("lx:%d\n", lx);
    printf("ly:%d\n", ly);

    float img[lx][ly][3];
    float img1[lx1][ly1][3];
    float img2[lx2][ly2][3];

    decb(file1, lx1, ly1, img1);
    decb(file2, lx2, ly2, img2);

    fclose(file1);
    fclose(file2);

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

    ench(lx, ly, file);
    encb(lx, ly, img, file);

    fclose(file);
}
