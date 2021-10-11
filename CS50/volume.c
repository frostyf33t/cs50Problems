// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE];
    
    //reads and writes the entire header all at once.
    fread(&header, HEADER_SIZE, 1, input);
    fwrite(&header, HEADER_SIZE, 1, output);
    
    
    
    
    
    // Statically creates the buffer so do not need to free later
    int16_t buffer;
    
    //. while it hasnt reached the end it should read 2 bites at a time and multiple the buffer by the factor and then write it.
    while (fread(&buffer, 2, 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, 2, 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
