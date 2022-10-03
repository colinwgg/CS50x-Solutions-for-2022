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
    int row, col;
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer[height][width];
    int row, col;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double gxr = 0, gxg = 0, gxb = 0, gyr = 0, gyg = 0, gyb = 0;
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
                    if (col == 0)
                    {
                        gxr += 2 * row * image[i + col][j + row].rgbtRed;
                        gxg += 2 * row * image[i + col][j + row].rgbtGreen;
                        gxb += 2 * row * image[i + col][j + row].rgbtBlue;
                    }
                    else
                    {
                        gxr += row * image[i + col][j + row].rgbtRed;
                        gxg += row * image[i + col][j + row].rgbtGreen;
                        gxb += row * image[i + col][j + row].rgbtBlue;
                    }
                    if (row == 0)
                    {
                        gyr += 2 * col * image[i + col][j + row].rgbtRed;
                        gyg += 2 * col * image[i + col][j + row].rgbtGreen;
                        gyb += 2 * col * image[i + col][j + row].rgbtBlue;
                    }
                    else
                    {
                        gyr += col * image[i + col][j + row].rgbtRed;
                        gyg += col * image[i + col][j + row].rgbtGreen;
                        gyb += col * image[i + col][j + row].rgbtBlue;
                    }
                }
            }
            buffer[i][j].rgbtRed = round(sqrt(gxr * gxr + gyr * gyr) > 255 ? 255 : sqrt(gxr * gxr + gyr * gyr));
            buffer[i][j].rgbtGreen = round(sqrt(gxg * gxg + gyg * gyg) > 255 ? 255 : sqrt(gxg * gxg + gyg * gyg));
            buffer[i][j].rgbtBlue = round(sqrt(gxb * gxb + gyb * gyb) > 255 ? 255 : sqrt(gxb * gxb + gyb * gyb));
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
