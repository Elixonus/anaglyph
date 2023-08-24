#include <stdio.h>

int ench(int lx, int ly, FILE* file)
{
    fwrite(&lx, sizeof(int), 1, file);
    fwrite(&ly, sizeof(int), 1, file);
    return 0;
}

int dech(FILE* file, int* lx, int* ly)
{
    fread(lx, sizeof(int), 1, file);
    fread(ly, sizeof(int), 1, file);
    return 0;
}

int encb(int lx, int ly, float img[lx][ly][3], FILE* file)
{
    fwrite(img, sizeof(float), lx * ly * 3, file);
    return 0;
}

int decb(FILE* file, int lx, int ly, float img[lx][ly][3])
{
    fread(img, sizeof(float), lx * ly * 3, file);
    return 0;
}
