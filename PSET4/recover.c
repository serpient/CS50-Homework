#include "bmp.h"

int main(int argc, string argv[])
{
    if (argc !== 2)
    {
        fprintf(stderr, "This function takes one command line argument");
        return 1;
    }

    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");

    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    int counter = 0;

    char* buffer;
    for (int i = 0; i < 4; i ++)
    {
        fread(&buffer, sizeof(BYTE), 1, inptr);
    }
    

    // once it finds the header of a jpeg.
    if (buffer[0] == 0xff &&
        buffer[1] == 0xd8 && 
        buffer[2] == 0xff &&
        (buffer[3] & 0xf0) == 0xe0)
    {
        BYTE byte;

        // read at 512 bytes at a time
        fread(&byte, sizeof(BYTE), 512, inptr);

        // if its the end of the file, close inptr file. return function

        // create a new jpeg file with the sequential naming counter + 1;
        sprintf(filename, "%03i.jpg", counter);
        FILE *img = fopen(filename, "w");

        // once we reach the first 512 bytes block for jpeg, we continue reading and writing until another JPEG start
        
        fwrite(inptr, sizeof(BYTE), 512, img)

        // once it detects the end of the jpeg file, you close the new jpeg file
        // end is when its less than 512 bytes before a new header
    }

    // finish function

}