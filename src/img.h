#include <stdio.h>

int ench(int lx, int ly, FILE* file);

int dech(FILE* file, int* lx, int* ly);

int encb(int lx, int ly, float img[lx][ly][3], FILE* file);

int decb(FILE* file, int lx, int ly, float img[lx][ly][3]);
