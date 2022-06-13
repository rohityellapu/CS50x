#include <stdio.h>
#include <stdlib.h>

typdef uint8_t BYTE;
#define BLOCK 512

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
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    char recoverd_image[8];

    BYTE *buffer = malloc(BLOCK * sizeof(BYTE));
    if (buffer = NULL)
    {
        printf("No enough memort to store image.\n");
        return 3;
    }

    FILE *jpg = NULL;
    int jpg_count = 0;

    while (fread(buffer, sizeof(buffer), 1, input) == 1)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == )
        sprintf(recovered_image, "%.3i.jpg", jpg_count);


    }
}