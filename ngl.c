#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <png.h>

int main(int argc, char* argv[])
{
    char *name1, *name2, *name3;

    float r1, r2;
    float g1, g2;
    float b1, b2;

    int ox;
    int oy;

    for(int i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], "-i1") == 0)
        {
            if(i + 1 < argc)
            {
                name1 = argv[i + 1];
                i++;
            }
        }

        else if(strcmp(argv[i], "-i2") == 0)
        {
            if(i + 1 < argc)
            {
                name2 = argv[i + 1];
                i++;
            }
        }

        else if(strcmp(argv[i], "-ii") == 0)
        {
            if(i + 1 < argc)
            {
                name3 = argv[i + 1];
                i++;
            }
        }

        else if(strcmp(argv[i], "-r1") == 0)
        {
            if(i + 1 < argc)
            {
                if(sscanf(argv[i + 1], "%f", &r1) == 1)
                {
                    i++;
                }
            }
        }

        else if(strcmp(argv[i], "-g1") == 0)
        {
            if(i + 1 < argc)
            {
                if(sscanf(argv[i + 1], "%f", &g1) == 1)
                {
                    i++;
                }
            }
        }

        else if(strcmp(argv[i], "-b1") == 0)
        {
            if(i + 1 < argc)
            {
                if(sscanf(argv[i + 1], "%f", &b1) == 1)
                {
                    i++;
                }
            }
        }

        else if(strcmp(argv[i], "-r2") == 0)
        {
            if(i + 1 < argc)
            {
                if(sscanf(argv[i + 1], "%f", &r2) == 1)
                {
                    i++;
                }
            }
        }

        else if(strcmp(argv[i], "-g2") == 0)
        {
            if(i + 1 < argc)
            {
                if(sscanf(argv[i + 1], "%f", &g2) == 1)
                {
                    i++;
                }
            }
        }

        else if(strcmp(argv[i], "-b2") == 0)
        {
            if(i + 1 < argc)
            {
                if(sscanf(argv[i + 1], "%f", &b2) == 1)
                {
                    i++;
                }
            }
        }

        else if(strcmp(argv[i], "-ox") == 0)
        {
            if(i + 1 < argc)
            {
                if(sscanf(argv[i + 1], "%d", &ox) == 1)
                {
                    i++;
                }
            }
        }

        else if(strcmp(argv[i], "-oy") == 0)
        {
            if(i + 1 < argc)
            {
                if(sscanf(argv[i + 1], "%d", &oy) == 1)
                {
                    i++;
                }
            }
        }
    }

    printf("name1:%s\n", name1);
    printf("name2:%s\n", name2);
    printf("name3:%s\n", name3);
    printf("r1:%f\n", r1);
    printf("g1:%f\n", g1);
    printf("b1:%f\n", b1);
    printf("r2:%f\n", r2);
    printf("g2:%f\n", g2);
    printf("b2:%f\n", b2);

    /*
    FILE* file1 = fopen(name1, "r");
    FILE* file2 = fopen(name2, "r");
    png_structp image1 = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    */
}
