#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// define new BYTE type
typedef uint8_t BYTE;

#define BLOCK 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        // Check for the correct input usage
        printf("Usage: ./recover <forensic_image>\n");
        return 1;
    }

    // Open input file
    FILE *input = fopen(argv[1], "r");

    // Check if the input is not null
    if (input == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    // declare name of the image
    char recovered_image[8];

    // allocate storage for buffer in the memory
    BYTE *buffer = malloc(BLOCK * sizeof(BYTE));

    // End program if there isn't enough memory
    if (buffer == NULL)
    {
        printf("No enough memort to store image.\n");
        return 3;
    }

    // Point the image address to NULL
    FILE *jpg = NULL;
    int jpg_count = 0;

    
    while (fread(buffer, sizeof(buffer), 1, input) == 1)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            if (jpg_count > 0)
            {
                fclose(jpg);

            }

            sprintf(recovered_image, "%.3i.jpg", jpg_count);

            jpg = fopen(recovered_image, "w");

            fwrite(buffer, sizeof(buffer), 1, jpg);

            jpg_count++;
        }
        else if (jpg_count > 0)
        {
            fwrite(buffer, sizeof(buffer), 1, jpg);
        }
    }

    free(buffer);

    fclose(input);

    fclose(jpg);
}