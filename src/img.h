#include <stdio.h>

int enc(int lx, int ly, float img[lx][ly][3], FILE* file);

int dec(FILE* file, int* lx, int* ly, float img[*lx][*ly][3]);
