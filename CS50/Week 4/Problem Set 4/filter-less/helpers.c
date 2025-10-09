#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green and blue
            int average =
                round(((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0));

            // Update pixels
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int original_red = image[i][j].rgbtRed;
            int original_green = image[i][j].rgbtGreen;
            int original_blue = image[i][j].rgbtBlue;

            // Compute sepia values
            int sepia_red =
                round(.393 * original_red + .769 * original_green + .189 * original_blue);
            int sepia_green =
                round(.349 * original_red + .686 * original_green + .168 * original_blue);
            int sepia_blue =
                round(.272 * original_red + .534 * original_green + .131 * original_blue);

            if (sepia_red > 255)
            {
                sepia_red = 255;
            }
            if (sepia_green > 255)
            {
                sepia_green = 255;
            }
            if (sepia_blue > 255)
            {
                sepia_blue = 255;
            }

            // Update pixel with sepia values
            image[i][j].rgbtRed = sepia_red;
            image[i][j].rgbtGreen = sepia_green;
            image[i][j].rgbtBlue = sepia_blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels
            RGBTRIPLE temp = image[i][j];

            image[i][j] = image[i][width - 1 - j];

            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];

    // Loop through pixels to create a copy of image
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

            // Initialize variables
            int total_red = 0;
            int total_green = 0;
            int total_blue = 0;

            int average_red = 0;
            int average_green = 0;
            int average_blue = 0;

            int count = 0;

            // Loop through pixel neighbours
            for (int ni = -1; ni <= 1; ni++)
            {
                for (int nj = -1; nj <= 1; nj++)
                {
                    if ((i + ni >= 0 && i + ni < height) && (j + nj >= 0 && j + nj < width))
                    {
                        total_red += copy[i + ni][j + nj].rgbtRed;
                        total_green += copy[i + ni][j + nj].rgbtGreen;
                        total_blue += copy[i + ni][j + nj].rgbtBlue;

                        count++;
                    }
                }
            }

            // Calculate average of each red green blue values
            average_red = round(total_red / (float) count);
            average_green = round(total_green / (float) count);
            average_blue = round(total_blue / (float) count);

            // Apply blur filter to each pixel
            image[i][j].rgbtRed = average_red;
            image[i][j].rgbtGreen = average_green;
            image[i][j].rgbtBlue = average_blue;
        }
    }
    return;
}
