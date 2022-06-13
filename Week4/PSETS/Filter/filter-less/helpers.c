#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // for every row
    for (int i = 0; i < height; i++)
    {
        // for every column
        for (int j = 0; j < width; j++)
        {
            // for every pixel

            // Get the average of RGB values.
            int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            // Put the RGB values to average value in the pixel
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Using Sepia algorithm, get new RGB values.
            int blue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            int green = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int red = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);

            if (red > 255)
            {
                red = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            // Put the new Sepia RGB values in the pixel.
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int n = width;
        int end = width - 1;
        for (int j = 0; j < n / 2; j++)
        {
            // create a temporary RGBTRIPLE type pixel.
            RGBTRIPLE tmp;
            // swap the front pixel value with end pixel vice-versa.
            tmp = image[i][end];
            image[i][end] = image[i][j];
            image[i][j] = tmp;
            end--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // // Make a copy of the image
    RGBTRIPLE pixel[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pixel[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0, red = 0, green = 0, blue = 0;
            // for current pixel.
            red += image[i][j].rgbtRed;
            green += image[i][j].rgbtGreen;
            blue += image[i][j].rgbtBlue;
            count++;
            // Check if pixel exists directly above the current pixel
            if (i - 1 >= 0 j >= 0)
            {
                red += image[i - 1][j].rgbtRed;
                green += image[i - 1][j].rgbtGreen;
                blue += image[i - 1][j].rgbtBlue;
                count++;
            }
            // Check if pixel exists directly below the current pixel
            if (i + 1 < height)
            {
                red += image[i + 1][j].rgbtRed;
                green += image[i + 1][j].rgbtGreen;
                blue += image[i + 1][j].rgbtBlue;
                count++;
            }
            // Check if pixel exists directly left the current pixel
            if (j - 1 >= 0 j >= 0)
            {
                red += image[i][j - 1].rgbtRed;
                green += image[i][j - 1].rgbtGreen;
                blue += image[i][j - 1].rgbtBlue;
                count++;
            }
            // Check if pixel exists directly right the current pixel
            if (j + 1 < width)
            {
                red += image[i][j + 1].rgbtRed;
                green += image[i][j + 1].rgbtGreen;
                blue += image[i][j + 1].rgbtBlue;
                count++;
            }
            // Check if pixel exists diagnally left above the current pixel

            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red += image[i - 1][j - 1].rgbtRed;
                green += image[i - 1][j - 1].rgbtGreen;
                blue += image[i - 1][j - 1].rgbtBlue;
                count++;
            }
            // Check if pixel exists diagnally right above the current pixel
            if (i - 1 >= 0 && j + 1 < width)
            {
                red += image[i - 1][j + 1].rgbtRed;
                green += image[i - 1][j + 1].rgbtGreen;
                blue += image[i - 1][j + 1].rgbtBlue;
                count++;
            }

            // Check if pixel exists diagnally left below the current pixel
            if (j - 1 >= 0 && i + 1 < height)
            {
                red += image[i + 1][j - 1].rgbtRed;
                green += image[i + 1][j - 1].rgbtGreen;
                blue += image[i + 1][j - 1].rgbtBlue;
                count++;
            }
            // Check if pixel exists diagnally right below the current pixel
            if (j + 1 < width && i + 1 < height)
            {
                red += image[i + 1][j + 1].rgbtRed;
                green += image[i + 1][j + 1].rgbtGreen;
                blue += image[i + 1][j + 1].rgbtBlue;
                count++;
            }

            // Average the pixel with surrounded neighbhor pixels
            image[i][j].rgbtRed = round(red / (count * 1.0));
            image[i][j].rgbtGreen = round(green / (count * 1.0));
            image[i][j].rgbtBlue = round(blue / (count * 1.0));

        }
    }
    return;
}
