#include <stdio.h>

struct pxl {
    double r;
    double g;
    double b;
};

int enc(struct pxl** img, int lx, int ly, FILE* file)
{
    fwrite(lx)

    return 0;
}

int dec(FILE* file, struct pxl** img, int* plx, int* ply)
{
    fread(plx, 4, 1, file);
    fread(ply, 4, 1, file);

    for(int x = 0; x < *plx; x++)
    {
        fread(img[x], sizeof(struct pxl), *ply, file);
    }

    return 0;
}

int main(int argc, char* argv[])
{
    printf("Hello");
    return 0;
}
