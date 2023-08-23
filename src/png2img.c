#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[])
{
    char* namep;
    char* namem;

    for(int a = 1; a < argc - 1; a++)
    {
        if(strcmp(argv[a], "-p") == 0)
        {
            namep = argv[++a];
        }

        else if(strcmp(argv[a], "-m") == 0)
        {
            namem = argv[++a];
        }

        else
        {
            fprintf(stderr, "bad argument: %s (%d)", argv[a], a);
        }
    }

    FILE* filep = fopen(namep, "rb");

    FILE* filem = fopen(namem, "wb");

    return 0;
}
