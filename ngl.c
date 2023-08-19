#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <png.h>

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

    FILE* fil;
    FILE* fil1;
    FILE* fil2;

    fil = fopen(nam, "w");
    fil1 = fopen(nam1, "r");
    fil2 = fopen(nam2, "r");

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

    lx1 = 100;
    ly1 = 120;

    lx2 = 90;
    ly2 = 110;

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

    double buf[lx][ly][3];
    double buf1[lx1][ly1][3];
    double buf2[lx2][ly2][3];

    for(int x = 0; x < lx; x++)
    {
        for(int y = 0; y < ly; y++)
        {
            int x1 = x - dx1;
            int y1 = y - dx1;

            int x2 = x - dx2;
            int y2 = y - dy2;

            double r1 = buf1[x1][y1][0];
            double g1 = buf1[x1][y1][1];
            double b1 = buf1[x1][y1][2];

            double r2 = buf2[x2][y2][0];
            double g2 = buf2[x2][y2][1];
            double b2 = buf2[x2][y2][2];

            double r = r1 * cr1 + r2 * cr2;
            double g = g1 * cg1 + g2 * cg2;
            double b = b1 * cb1 + b2 * cb2;

            buf[x][y][0] = r;
            buf[x][y][1] = g;
            buf[x][y][2] = b;
        }
    }

    /*
    FILE* file1 = fopen(name1, "r");
    FILE* file2 = fopen(name2, "r");
    png_structp image1 = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    */
}
