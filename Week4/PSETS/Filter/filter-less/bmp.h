// BMP-related data types based on Microsoft's own

#include <stdint.h>

// These data types are essentially aliases for C/C++ primitive data types.
// Adapted from http://msdn.microsoft.com/en-us/library/cc230309.aspx.
// See https://en.wikipedia.org/wiki/C_data_types#stdint.h for more on stdint.h.

typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

// The BITMAPFILEHEADER structure contains information about the type, size,
// and layout of a file that contains a DIB [device-independent bitmap].
// Adapted from http://msdn.microsoft.com/en-us/library/dd183374(VS.85).aspx.

typedef struct
{
    WORD   bfType;
    DWORD  bfSize;
    WORD   bfReserved1;
    WORD   bfReserved2;
    DWORD  bfOffBits;
} __attribute__((__packed__))
BITMAPFILEHEADER;

// The BITMAPINFOHEADER structure contains information about the
// dimensions and color format of a DIB [device-independent bitmap].
// Adapted from http://msdn.microsoft.com/en-us/library/dd183376(VS.85).aspx.

typedef struct
{
    DWORD  biSize;
    LONG   biWidth;
    LONG   biHeight;
    WORD   biPlanes;
    WORD   biBitCount;
    DWORD  biCompression;
    DWORD  biSizeImage;
    LONG   biXPelsPerMeter;
    LONG   biYPelsPerMeter;
    DWORD  biClrUsed;
    DWORD  biClrImportant;
} __attribute__((__packed__))
BITMAPINFOHEADER;

// The RGBTRIPLE structure describes a color consisting of relative intensities of
// red, green, and blue. Adapted from http://msdn.microsoft.com/en-us/library/aa922590.aspx.

typedef struct
{
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;


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
            red += pixel[i][j].rgbtRed;
            green += pixel[i][j].rgbtGreen;
            blue += pixel[i][j].rgbtBlue;
            count++;
            // Check if pixel exists directly above the current pixel
            if (i - 1 >= 0 && j >= 0)
            {
                red += pixel[i - 1][j].rgbtRed;
                green += pixel[i - 1][j].rgbtGreen;
                blue += pixel[i - 1][j].rgbtBlue;
                count++;
            }
            // Check if pixel exists directly below the current pixel
            if (i + 1 < height && j >= 0)
            {
                red += pixel[i + 1][j].rgbtRed;
                green += pixel[i + 1][j].rgbtGreen;
                blue += pixel[i + 1][j].rgbtBlue;
                count++;
            }
            // Check if pixel exists directly left the current pixel
            if (j - 1 >= 0)
            {
                red += pixel[i][j - 1].rgbtRed;
                green += pixel[i][j - 1].rgbtGreen;
                blue += pixel[i][j - 1].rgbtBlue;
                count++;
            }
            // Check if pixel exists directly right the current pixel
            if (j + 1 < width)
            {
                red += pixel[i][j + 1].rgbtRed;
                green += pixel[i][j + 1].rgbtGreen;
                blue += pixel[i][j + 1].rgbtBlue;
                count++;
            }
            // Check if pixel exists diagnally left above the current pixel

            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red += pixel[i - 1][j - 1].rgbtRed;
                green += pixel[i - 1][j - 1].rgbtGreen;
                blue += pixel[i - 1][j - 1].rgbtBlue;
                count++;
            }
            // Check if pixel exists diagnally right above the current pixel
            if (i - 1 >= 0 && j + 1 < width)
            {
                red += pixel[i - 1][j + 1].rgbtRed;
                green += pixel[i - 1][j + 1].rgbtGreen;
                blue += pixel[i - 1][j + 1].rgbtBlue;
                count++;
            }

            // Check if pixel exists diagnally left below the current pixel
            if (j - 1 >= 0 && i + 1 < height)
            {
                red += pixel[i + 1][j - 1].rgbtRed;
                green += pixel[i + 1][j - 1].rgbtGreen;
                blue += pixel[i + 1][j - 1].rgbtBlue;
                count++;
            }
            // Check if pixel exists diagnally right below the current pixel
            if (j + 1 < width && i + 1 < height)
            {
                red += pixel[i + 1][j + 1].rgbtRed;
                green += pixel[i + 1][j + 1].rgbtGreen;
                blue += pixel[i + 1][j + 1].rgbtBlue;
                count++;
            }

            // Average the pixel with surrounded neighbhor pixels
            image[i][j].rgbtRed = round(red / count * 1.0);
            image[i][j].rgbtGreen = round(green / count * 1.0);
            image[i][j].rgbtBlue = round(blue / count * 1.0);
        }