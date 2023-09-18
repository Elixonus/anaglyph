#include <stdio.h>

int ench(int w, int h, FILE* file)
{
    if(fwrite(&w, sizeof(int), 1, file) < 1)
    {
        return 1;
    }

    if(fwrite(&h, sizeof(int), 1, file) < 1)
    {
        return 1;
    }

    return 0;
}

int dech(int* w, int* h, FILE* file)
{
    if(fread(w, sizeof(int), 1, file) < 1)
    {
        return 1;
    }

    if(fread(h, sizeof(int), 1, file) < 1)
    {
        return 1;
    }

    return 0;
}

int encb(int w, int h, float img[w][h][3], FILE* file)
{
    if(fwrite(img, sizeof(float), w * h * 3, file) < w * h * 3)
    {
        return 1;
    }

    return 0;
}

int decb(int w, int h, float img[w][h][3], FILE* file)
{
    if(fread(img, sizeof(float), w * h * 3, file) < w * h * 3)
    {
        return 1;
    }

    return 0;
}
