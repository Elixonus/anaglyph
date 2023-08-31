#include <stdio.h>

int ench(int lx, int ly, FILE* file);

int dech(int* lx, int* ly, FILE* file);

int encb(int lx, int ly, float img[lx][ly][3], FILE* file);

int decb(int lx, int ly, float img[lx][ly][3], FILE* file);
