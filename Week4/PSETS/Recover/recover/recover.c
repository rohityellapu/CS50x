#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover <forensic_image>\n");
        return 1;
    }

    char *image = argv[1];

    FILE *input = fopen(image, "r");

    if (input == NULL)
    {
        printf("Could not open %s.\n", image);
        return 2;
    }
    



}