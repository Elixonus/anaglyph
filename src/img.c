#include <stdio.h>

int ench(int lx, int ly, FILE* file)
{
    if(lx < 1 || ly < 1)
    {
        return 1;
    }

    if(fwrite(&lx, sizeof(int), 1, file) < 1)
    {
        return 1;
    }

    if(fwrite(&ly, sizeof(int), 1, file) < 1)
    {
        return 1;
    }

    return 0;
}

int dech(FILE* file, int* lx, int* ly)
{
    if(fread(lx, sizeof(int), 1, file) < 1)
    {
        return 1;
    }

    if(fread(ly, sizeof(int), 1, file) < 1)
    {
        return 1;
    }

    if(*lx < 1 || *ly < 1)
    {
        return 1;
    }

    return 0;
}

int encb(int lx, int ly, float img[lx][ly][3], FILE* file)
{
    if(lx < 1 || ly < 1)
    {
        return 1;
    }

    if(fwrite(img, sizeof(float), lx * ly * 3, file) < lx * ly * 3)
    {
        return 1;
    }

    return 0;
}

int decb(FILE* file, int lx, int ly, float img[lx][ly][3])
{
    if(lx < 1 || ly < 1)
    {
        return 1;
    }

    if(fread(img, sizeof(float), lx * ly * 3, file) < lx * ly * 3)
    {
        return 1;
    }

    return 0;
}
