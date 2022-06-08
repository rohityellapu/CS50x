#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE *pixel = &image[i][j];
            int avg = round(((*pixel).rgbtBlue + (*pixel).rgbtGreen + (*pixel).rgbtRed) / 3.0);

            (*pixel).rgbtBlue = avg;
            (*pixel).rgbtGreen = avg;
            (*pixel).rgbtRed = avg;
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
            // RGBTRIPLE *pixel = &image[i][j];
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
            // // RGBTRIPLE *pixel = &image[i][j];
            image[i][j].rgbtBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            image[i][j].rgbtGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            image[i][j].rgbtRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);

            if (image[i][j].rgbtBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            if (image[i][j].rgbtGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            if (image[i][j].rgbtRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
