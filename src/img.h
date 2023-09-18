#include <stdio.h>

int ench(int w, int h, FILE* file);
int dech(int* w, int* h, FILE* file);
int encb(int w, int h, float img[w][h][3], FILE* file);
int decb(int w, int h, float img[w][h][3], FILE* file);
