#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = round(average);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    double sr, sg, sb; //for sepia-red, sepia-green, and sepia-blue
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sr = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            sg = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            sb = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            image[i][j].rgbtRed = sr > 255 ? 255 : sr;
            image[i][j].rgbtGreen = sg > 255 ? 255 : sg;
            image[i][j].rgbtBlue = sb > 255 ? 255 : sb;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            buffer = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer[height][width];
    int  row, col;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double cot = 0, sr = 0, sg = 0, sb = 0;
            for (col = -1; col <= 1; col++)
            {
                for (row = -1; row <= 1; row++)
                {
                    if (i + col < 0 || i + col > height - 1)
                    {
                        continue;
                    }
                    if (j + row < 0 || j + row > width - 1)
                    {
                        continue;
                    }
                    sr += image[i + col][j + row].rgbtRed;
                    sg += image[i + col][j + row].rgbtGreen;
                    sb += image[i + col][j + row].rgbtBlue;
                    cot++;
                }
            }
            buffer[i][j].rgbtRed = round(sr / cot);
            buffer[i][j].rgbtGreen = round(sg / cot);
            buffer[i][j].rgbtBlue = round(sb / cot);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = buffer[i][j];
        }
    }
    return;
}
