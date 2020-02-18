#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image_name");
        return 1;
    }

    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Cannot open input file!");
        return 2;
    }

    BYTE buffer[512];

    char filename[8];
    int count = 0, found = 0, val = 0;
    FILE *outptr;
    do
    {
        //read file
        val = fread(buffer, 512, 1, inptr);

        //recognize file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // start the next file until another header is found
            if (found == 1)
            {
                fclose(outptr);
                count++;
            }
            else
            {
                found = 1;
            }

            sprintf(filename, "%03i.jpg", count);
            outptr = fopen(filename, "w");
            if (outptr == NULL)
            {
                fprintf(stderr, "Cannot open output file!");
                return 3;
            }
        }

        // if already found the header, go on until the file ends
        if (found == 1 && val == 1)
        {
            fwrite(buffer, 512, 1, outptr);
        }

    }
    while (val == 1);
    fclose(outptr);

    return 0;
}