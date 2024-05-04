#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover.c FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("File couldn't open.\n");
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];
    char filename[8];
    FILE *img;
    // While there's still data left to read from the memory card
    // bool jpgFound = false;
    int counter = 0;
    while (fread(buffer, 1, BLOCK_SIZE, file) == 512)
    {
        // Create JPEGs from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] % 0xf0) == 0xe0){
            if (counter > 0)
            {
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create %s.\n", filename);
                return 1;
            }
            fwrite(buffer, 1, BLOCK_SIZE, img);
            counter++;
        }
        else if (counter > 0){
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }
    fclose(img);
    fclose(file);
    printf("%d\n", counter);
}
