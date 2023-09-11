#include <stdio.h>

int ench(int wdt, int hgt, FILE* file);

int dech(int* wdt, int* hgt, FILE* file);

int encb(int wdt, int hgt, float img[wdt][hgt][3], FILE* file);

int decb(int wdt, int hgt, float img[wdt][hgt][3], FILE* file);
