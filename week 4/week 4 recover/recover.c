#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Can not open the file");
        return 1;
    }
    BYTE buffer[BLOCK_SIZE];
    FILE *image = NULL;
    char filename[8];
    int counter = 0;
    while (fread(&buffer, BLOCK_SIZE, 1, input))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter)
            {
                fclose(image);
            }
            sprintf(filename, "%03i.jpg", counter);
            image = fopen(filename, "w");
            counter++;
        }
        if (counter)
        {
            fwrite(&buffer, BLOCK_SIZE, 1, image);
        }
    }
    fclose(input);
    fclose(image);
    return 0;
}