#include <math.h>
#include "helpers.h"

// Convert (*pixel)ayscale
void grayscale(int height, int width, RGBTRIPLE (*pixel)t][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE *pixel = &(*pixel);
            int avg = round(((*pixel).rgbtBlue + (*pixel).rgbtGreen + (*pixel).rgbtRed) / 3.0);

            (*pixel).rgbtBlue = avg;
            (*pixel).rgbtGreen = avg;
            (*pixel).rgbtRed = avg;
        }
    }
    return;
}

// Convert (*pixel)pia
void sepia(int height, int width, RGBTRIPLE (*pixel)t][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // RGBTRIPLE *pixel = &(*pixel);
            // int sepiaRed = round(0.189 * (*pixel).rgbtBlue + 0.769 * (*pixel).rgbtGreen + 0.393 * (*pixel).rgbtRed);
            // int sepiaGreen = round(0.168 * (*pixel).rgbtBlue + 0.686 * (*pixel).rgbtGreen + 0.349 * (*pixel).rgbtRed);
            // int sepiaBlue = round(0.131 * (*pixel).rgbtBlue + 0.534 * (*pixel).rgbtGreen + 0.272 * (*pixel).rgbtRed);

            // if (sepiaRed > 255)
            // {
            //     sepiaRed = 255;
            // }
            // if (sepiaGreen > 255)
            // {
            //     sepiaGreen = 255;
            // }
            // if (sepiaBlue > 255)
            // {
            //     sepiaBlue = 255;
            // }

            // (*pixel).rgbtBlue = sepiaBlue;
            // (*pixel).rgbtGreen = sepiaGreen;
            // (*pixel).rgbtRed = sepiaRed;
            RGBTRIPLE *pixel = &image[i][j];
            (*pixel).rgbtBlue = round(0.272 * (*pixel).rgbtRed + 0.534 * (*pixel).rgbtGreen + 0.131 * (*pixel).rgbtBlue);
            (*pixel).rgbtGreen = round(0.349 * (*pixel).rgbtRed + 0.686 * (*pixel).rgbtGreen + 0.168 * (*pixel).rgbtBlue);
            (*pixel).rgbtRed = round(0.393 * (*pixel).rgbtRed + 0.769 * (*pixel).rgbtGreen + 0.189 * (*pixel).rgbtBlue);

            if ((*pixel).rgbtBlue > 255)
            {
                (*pixel).rgbtBlue = 255;
            }
            if ((*pixel).rgbtGreen > 255)
            {
                (*pixel).rgbtGreen = 255;
            }
            if ((*pixel).rgbtRed > 255)
            {
                (*pixel).rgbtRed = 255;
            }
        }
    }

    return;
}

// Reflect (*pixel)ontally
void reflect(int height, int width, RGBTRIPLE (*pixel)t][width])
{
    return;
}

// Blur (*pixel)blur(int height, int width, RGBTRIPLE (*pixel)t][width])
{
    return;
}
