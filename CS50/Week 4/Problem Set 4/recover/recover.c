#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Size of each memory block
const int MEMORY_CARD_SIZE = 512;

int main(int argc, char *argv[])
{

    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open files
    FILE *card = fopen(argv[1], "r");

    FILE *img = NULL;

    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Initialize variables
    int writing = 0;

    int counter = -1;

    char filename[8];

    // Initialize buffer
    uint8_t buffer[MEMORY_CARD_SIZE];

    // Loop through each memory block
    while (fread(buffer, sizeof(uint8_t), MEMORY_CARD_SIZE, card) == 512)
    {
        // Check if the block is the start of a jpeg file
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF &&
            ((buffer[3] & 0xF0) == 0xE0))
        {
            // Increment counter by 1 for the filename
            counter++;

            // Create filenames e.g 000.jpg, 001.jpg
            sprintf(filename, "%03i.jpg", counter);

            // If a jpeg file hasn't been opened, open a new file and write to it
            if (writing == 0)
            {
                img = fopen(filename, "w");

                fwrite(buffer, sizeof(uint8_t), 512, img);

                writing = 1;
            }
            else
            {
                // If a jpeg file is already opened close the existing one and open a new one and
                // write to it
                fclose(img);

                img = fopen(filename, "w");

                fwrite(buffer, sizeof(uint8_t), 512, img);
            }
        }
        else if (writing == 1)
        {
            fwrite(buffer, sizeof(uint8_t), 512, img);
        }
    }

    // Close files
    fclose(card);
    fclose(img);
}
