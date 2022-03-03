#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // declare integer
    int height;
    // Prompt the user to get the height of the mario pyramid
    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8); // Prompt untill valid input
    // Build rows in accordance with the height of the pyramid
    for (int i = 0; i < height; i++)
    {
        // Print # for each row
        // for (int j = height; j > 1; j--)
        for (int j = height - 1; j >= 0; --j)
        {
            // printf("#");
            if (j <= i)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}