#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }

    // Create a buffer for a block data
    uint8_t buffer[512];

    // Variables to keep track of JPEGs
    FILE *img = NULL;
    char filename[8];
    int file_count = 0;
    bool found_jpeg = false;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Check if the block indicates the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If already found a JPEG, close the previous file
            if (found_jpeg)
            {
                fclose(img);
            }
            else
            {
                found_jpeg = true;
            }

            // Create a new file for the JPEG
            sprintf(filename, "%03i.jpg", file_count);
            img = fopen(filename, "w");
            file_count++;
        }

        // If currently recovering a JPEG, write the buffer to the file
        if (found_jpeg)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // Close any remaining files
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(card);
    return 0;
}