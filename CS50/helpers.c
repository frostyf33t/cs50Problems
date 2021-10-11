#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Iterating over height
    for (int i = 0; i < height ; i++)
    {

        //Iterating over width
        for (int j = 0; j < width; j++)
        {

            // Greylevel is the average of the 3 colors.  Rounded to nearest Inr
            int graylevel = rint(rint(image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3);

            //Each color beingr changed to greylevel for each pixel
            image[i][j].rgbtBlue = graylevel;
            image[i][j].rgbtRed = graylevel;
            image[i][j].rgbtGreen = graylevel;

        }
    }
    return;
}

//If value more than 255(max) make value 255
int highest(int number);


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //Iterating over height
    for (int i = 0; i < height ; i++)
    {

        //Iterating over width
        for (int j = 0; j < width; j++)
        {

            RGBTRIPLE pixels = image[i][j];
            int red = pixels.rgbtRed;
            int blue = pixels.rgbtBlue;
            int green = pixels.rgbtGreen;


            //Sepia Equation to change colors
            image[i][j].rgbtBlue = highest(rint(0.272 * red + 0.534 * green + 0.131 * blue));
            image[i][j].rgbtGreen = highest(rint(0.349 * red + 0.686 * green + 0.168 * blue));
            image[i][j].rgbtRed = highest(rint(0.393 * red + 0.769 * green + 0.189 * blue));



        }



    }
}
int highest(int number)
{
    return (number > 255) ? 255 : number;
}

void swap (RGBTRIPLE *A, RGBTRIPLE *B)
{
    RGBTRIPLE temp = *A;
    *A = *B;
    *B = temp;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Create a loop to reflect
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            //Temporary variables
            swap(&image[i][j], &image[i][width - 1 - j]);


        }
    }

}

bool is_valid_pixel(int i, int j, int height, int width)
{
    return i >= 0 && i < height && j >=0 && j < width;
}

RGBTRIPLE get_blurred_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int redValue, blueValue, greenValue; redValue = blueValue = greenValue = 0;
    int numofValidPixels = 0;
    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int new_i = i + di;
            int new_j = j + dj;
            if (is_valid_pixel(new_i, new_j, height, width))
            {
                numofValidPixels++;
                redValue += image[new_i][new_j].rgbtRed;
                blueValue += image[new_i][new_j].rgbtBlue;
                greenValue += image[new_i][new_j].rgbtGreen;
                
            }
        }
    }
    RGBTRIPLE blurred_pixel;
    blurred_pixel.rgbtRed = round((float) redValue / numofValidPixels);
    blurred_pixel.rgbtBlue = round((float) blueValue / numofValidPixels);
    blurred_pixel.rgbtGreen = round((float) greenValue / numofValidPixels);
    return blurred_pixel;
    
}

//Blur image;
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_image[i][j] = get_blurred_pixel(i, j, height, width, image);
            
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
            
        }
    }
}






