#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    avg = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round((avg + image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) /
                        3.0);

            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
            avg = 0;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed, originalGreen, originalBlue, sepiaRed, sepiaBlue, sepiaGreen;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            sepiaRed = round((.393 * originalRed) + (.769 * originalGreen) + (.189 * originalBlue));
            sepiaGreen =
                round((.349 * originalRed) + (.686 * originalGreen) + (.168 * originalBlue));
            sepiaBlue =
                round((.272 * originalRed) + (.534 * originalGreen) + (.131 * originalBlue));

            if (sepiaRed > 255)
                image[i][j].rgbtRed = 255;
            else
                image[i][j].rgbtRed = sepiaRed;
            if (sepiaGreen > 255)
                image[i][j].rgbtGreen = 255;
            else
                image[i][j].rgbtGreen = sepiaGreen;
            if (sepiaBlue > 255)
                image[i][j].rgbtBlue = 255;
            else
                image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int totalRed = 0, totalGreen = 0, totalBlue = 0, current_x, current_y;
    float counter;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            totalRed = 0, totalGreen = 0, totalBlue = 0;
            counter = 0.00;
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    current_x = i + x;
                    current_y = j + y;

                    if (current_x < 0 || current_x > (height) -1 || current_y < 0 ||
                        current_y > (width - 1))
                        continue;
                    totalRed += image[current_x][current_y].rgbtRed;
                    totalGreen += image[current_x][current_y].rgbtGreen;
                    totalBlue += image[current_x][current_y].rgbtBlue;
                    counter++;
                }
            }

            copy[i][j].rgbtRed = round(totalRed / counter);
            copy[i][j].rgbtGreen = round(totalGreen / counter);
            copy[i][j].rgbtBlue = round(totalBlue / counter);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
