#include <stdio.h>

int enc(int lx, int ly, float img[lx][ly][3], FILE* file)
{
    fwrite(&lx, sizeof(int), 1, file);
    fwrite(&ly, sizeof(int), 1, file);

    fwrite(img, sizeof(float), lx * ly * 3, file);

    return 0;
}

int dec(FILE* file, int* lx, int* ly, float img[*lx][*ly][3])
{
    fread(lx, sizeof(int), 1, file);
    fread(ly, sizeof(int), 1, file);

    fread(img, sizeof(float), (*lx) * (*ly) * 3, file);

    return 0;
}

int main(int argc, char* argv[])
{
    printf("Hello World!");

    float img[2][2][3] = {{{0.0f, 1.1f, 2.2f}, {3.3f, 4.4f, 5.5f}}, {{6.6f, 7.7f, 8.8f}, {9.9f, 9.1f, 9.2f}}};
    FILE* file = fopen("testw.b", "wb");
    enc(2, 2, img, file);
    fclose(file);

    return 0;
}
