#include <stdio.h>

int ench(int wdt, int hgt, FILE* file)
{
    if(wdt < 1 || hgt < 1)
    {
        return 1;
    }

    if(fwrite(&wdt, sizeof(int), 1, file) < 1)
    {
        return 1;
    }

    if(fwrite(&hgt, sizeof(int), 1, file) < 1)
    {
        return 1;
    }

    return 0;
}

int dech(int* wdt, int* hgt, FILE* file)
{
    if(fread(wdt, sizeof(int), 1, file) < 1)
    {
        return 1;
    }

    if(fread(hgt, sizeof(int), 1, file) < 1)
    {
        return 1;
    }

    if(*wdt < 1 || *hgt < 1)
    {
        return 1;
    }

    return 0;
}

int encb(int wdt, int hgt, float img[wdt][hgt][3], FILE* file)
{
    if(wdt < 1 || hgt < 1)
    {
        return 1;
    }

    if(fwrite(img, sizeof(float), wdt * hgt * 3, file) < wdt * hgt * 3)
    {
        return 1;
    }

    return 0;
}

int decb(int wdt, int hgt, float img[wdt][hgt][3], FILE* file)
{
    if(wdt < 1 || hgt < 1)
    {
        return 1;
    }

    if(fread(img, sizeof(float), wdt * hgt * 3, file) < wdt * hgt * 3)
    {
        return 1;
    }

    return 0;
}
