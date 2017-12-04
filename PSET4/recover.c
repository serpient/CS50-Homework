#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
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

    // array called buffer, of size char (1 byte each) * 512
    unsigned char buffer[512];

    // declare file pointer, set to NULL to show no file has been assigned to it yet.
    FILE *openNewFile = NULL;


    //define filename. declaring an array of characters, length 8
    // to store a string
    char filename[8];

    // while not at end of file, and fread is returning 512 bytes at a time.
    while (fread(&buffer[0], 1, 512, inptr) == 512)
    {
        // once it finds the header of a jpeg. (start of new jpeg)
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // if found a jpeg byte , close current jpeg
            if (openNewFile != NULL)
            {
                // end previous jpeg
                fclose(openNewFile);

                // increment counter
                counter = counter + 1;
            }
            // create a new jpeg file with the sequential naming counter + 1;
            sprintf(filename, "%03i.jpg", counter);

            // assign openNewFile to open jpeg
            openNewFile = fopen(filename, "w");
        }

        // if you are in a jpeg, write to a new jpeg
        if (openNewFile != NULL )
        {
            // write to new jpeg
            fwrite(buffer, 1, 512, openNewFile);
        }

    }
    if (openNewFile == NULL)
    {
        // if at the end of reading through every 512 byte block, it has not found a jpeg header, it should return
        fprintf(stderr, "Could not find a jpeg header");
        return 3;
    }
    else
    {
        // close the inptr file
        fclose(inptr);
        // close previous jpeg file we are writing to
        fclose(openNewFile);
        // close function  (return 0 for success)
        return 0;
    }
}


// null terminator = true 0 , end of strings
// null pointer = points to 0, can be used at end of an array.