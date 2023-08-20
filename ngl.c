#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb/stb_image.h"
#include "stb/stb_image_write.h"

int main(int argc, char* argv[])
{
    char* nam = "";
    char* nam1 = "";
    char* nam2 = "";

    int dx = 0;
    int dy = 0;

    double cr1 = 0.5;
    double cr2 = 0.5;

    double cg1 = 0.5;
    double cg2 = 0.5;

    double cb1 = 0.5;
    double cb2 = 0.5;

    for(int a = 1; a < argc - 1; a++)
    {
        if(strcmp(argv[a], "-ii") == 0)
        {
            nam = argv[++a];
        }

        else if(strcmp(argv[a], "-i1") == 0)
        {
            nam1 = argv[++a];
        }

        else if(strcmp(argv[a], "-i2") == 0)
        {
            nam2 = argv[++a];
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
            if(sscanf(argv[++a], "%lf", &cr1) == 0)
            {
                fprintf(stderr, "bad argument: %s (%d)\n", argv[a], a);
                return 0;
            }
        }

        else if(strcmp(argv[a], "-r2") == 0)
        {
            if(sscanf(argv[++a], "%lf", &cr2) == 0)
            {
                fprintf(stderr, "bad argument: %s (%d)\n", argv[a], a);
                return 0;
            }
        }

        else if(strcmp(argv[a], "-g1") == 0)
        {
            if(sscanf(argv[++a], "%lf", &cg1) == 0)
            {
                fprintf(stderr, "bad argument: %s (%d)\n", argv[a], a);
                return 0;
            }
        }

        else if(strcmp(argv[a], "-g2") == 0)
        {
            if(sscanf(argv[++a], "%lf", &cg2) == 0)
            {
                fprintf(stderr, "bad argument: %s (%d)\n", argv[a], a);
                return 0;
            }
        }

        else if(strcmp(argv[a], "-b1") == 0)
        {
            if(sscanf(argv[++a], "%lf", &cb1) == 0)
            {
                fprintf(stderr, "bad argument: %s (%d)\n", argv[a], a);
                return 0;
            }
        }

        else if(strcmp(argv[a], "-b2") == 0)
        {
            if(sscanf(argv[++a], "%lf", &cb2) == 0)
            {
                fprintf(stderr, "bad argument: %s (%d)\n", argv[a], a);
                return 0;
            }
        }
    }

    printf("name:%s\n", nam);
    printf("name1:%s\n", nam1);
    printf("name2:%s\n", nam2);
    printf("dx:%d\n", dx);
    printf("dy:%d\n", dy);
    printf("cr1:%f\n", cr1);
    printf("cr2:%f\n", cr2);
    printf("cg1:%f\n", cg1);
    printf("cg2:%f\n", cg2);
    printf("cb1:%f\n", cb1);
    printf("cb2:%f\n", cb2);

    int dx1, dx2;
    int dy1, dy2;

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

    int lx;
    int ly;

    int lx1;
    int ly1;

    int lx2;
    int ly2;

    unsigned char* stb1 = stbi_load(nam1, &lx1, &ly1, NULL, 3);
    unsigned char* stb2 = stbi_load(nam2, &lx2, &ly2, NULL, 3);

    if(stb1 == NULL)
    {
        fprintf(stderr, "bad filename: %s\n", nam1);
        return 0;
    }

    if(stb2 == NULL)
    {
        fprintf(stderr, "bad filename: %s\n", nam2);
        return 0;
    }

    printf("lx1:%d\n", lx1);
    printf("ly1:%d\n", ly1);
    printf("lx2:%d\n", lx2);
    printf("ly2:%d\n", ly2);

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

    double buf[lx][ly][3];
    double buf1[lx1][ly1][3];
    double buf2[lx2][ly2][3];

    int bruh = 0;

    int t = 0;

    for(int x1 = 0; x1 < lx1; x1++)
    {
        for(int y1 = 0; y1 < ly1; y1++)
        {
            for(int c1 = 0; c1 < 3; c1++)
            {
                buf1[x1][y1][c1] = ((double) stb1[t++]) / 255;
                // printf("%lf", buf1[x1][y1][c1]);
            }
        }
    }

    t = 0;

    for(int x2 = 0; x2 < lx2; x2++)
    {
        for(int y2 = 0; y2 < ly2; y2++)
        {
            for(int c2 = 0; c2 < 3; c2++)
            {
                buf1[x2][y2][c2] = ((double) stb2[t++]) / 255;
                // printf("%lf", buf1[x1][y1][c1]);
            }
        }
    }

    for(int x = 0; x < lx; x++)
    {
        for(int y = 0; y < ly; y++)
        {
            int x1 = x - dx1;
            int y1 = y - dx1;

            int x2 = x - dx2;
            int y2 = y - dy2;

            double r1;
            double g1;
            double b1;

            if(x1 >= 0 && y1 >= 0 && x1 < lx1 && y1 < ly1)
            {
                r1 = buf1[x1][y1][0];
                g1 = buf1[x1][y1][1];
                b1 = buf1[x1][y1][2];
            }

            else
            {
                r1 = 0;
                g1 = 0;
                b1 = 0;
            }

            double r2;
            double g2;
            double b2;

            if(x2 >= 0 && y2 >= 0 && x2 < lx2 && y2 < ly2)
            {
                r2 = buf2[x2][y2][0];
                g2 = buf2[x2][y2][1];
                b2 = buf2[x2][y2][2];
            }

            else
            {
                r2 = 0;
                g2 = 0;
                b2 = 0;
            }

            double r = r1 * cr1 + r2 * cr2;
            double g = g1 * cg1 + g2 * cg2;
            double b = b1 * cb1 + b2 * cb2;


            buf[0][0][0] = r;
            buf[0][0][1] = g;
            buf[0][0][2] = b;
        }
    }
    /*
    for(int x = 0; x < lx; x++)
    {
        for(int y = 0; y < ly; y++)
        {
            for(int c = 0; c < 3; c++)
            {
                printf("%lf;", buf[x][y][c]);
            }
        }
    }*/

    unsigned char stb[lx * ly * 3];

    t = 0;
    for(int x = 0; x < lx; x++)
    {
        for(int y = 0; y < ly; y++)
        {
            for(int c = 0; c < 3; c++)
            {
                stb[t++] = (buf[x][y][c] * 255.0);
                // stb[t++] = (unsigned char) ((double) (x) / lx * 255);
            }
        }
    }

    stbi_write_jpg(nam, lx, ly, 3, stb, 95);
}
