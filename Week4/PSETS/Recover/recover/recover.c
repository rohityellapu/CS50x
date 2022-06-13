#include <stdio.h>
#include <stdlib.h>

typdef uint8_t BYTE;


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover <forensic_image>\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        printf("Could not open %s.\n", image);
        return 2;
    }

    char recoverd_image[8];


}