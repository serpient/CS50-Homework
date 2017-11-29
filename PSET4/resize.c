// whodunit

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // remember filenames
    float f = strtof(argv[1], NULL);
    char *infile = argv[2];
    char *outfile = argv[3];

    // checking that argv[1] is an int
    if (!f)
    {
        return 1;
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    int oldBiWidth = bi.biWidth;
    int oldBiHeight = bi.biHeight;

    // update BITMAPINFOHEADER bi info with new dimensions (width and height does not include padding)
    bi.biWidth = bi.biWidth * f;
    bi.biHeight = bi.biHeight * f;

    // determine padding for new file scanlines
    int newFilePadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    bi.biSizeImage = abs(bi.biHeight) * (bi.biWidth * sizeof(RGBTRIPLE) + newFilePadding); // includes padding

    // update BITMAPFILEHEADER bf info.
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER); // bfSize includes pixels, padding, and headers

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    if (f < 1.0)
    {
        // for example, of f = 0.5, print every odd pixel (1 out of 2 pixels)
        // print every odd vertical line
        for (int a = 0, abiHeight = abs(oldBiHeight); a < abiHeight; a = a + 2)
        {
                // iterate over pixels in scanline
                for (int b = 0; b < oldBiWidth; b = b + 2)
                {
                    // temporary storage
                    RGBTRIPLE triple;

                    // read RGB triple from infile
                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                    // write RGB triple to outfile, sizeof(RGBTRIPLE) * f number of bytes
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

                    // change cursor to skip the next set
                    fseek(inptr, sizeof(RGBTRIPLE), SEEK_CUR);
                }

                fseek(inptr, padding, SEEK_CUR);

                // then add it back (to demonstrate how)
                for (int c = 0; c < newFilePadding; c++)
                {
                    fputc(0x00, outptr);
                }

                if (a != abiHeight - 1)
                {
                    fseek(inptr, oldBiWidth * sizeof(RGBTRIPLE) + padding, SEEK_CUR);
                }
        }
    }
    else
    {
        // iterate over infile's scanlines
        for (int i = 0, biHeight = abs(oldBiHeight); i < biHeight; i++)
        {
            // this loop works if f is 1 or greater.
            for (int m = 0; m < f; m++)
            {
                // iterate over pixels in scanline
                for (int j = 0; j < oldBiWidth; j++)
                {
                    // temporary storage
                    RGBTRIPLE triple;

                    // read RGB triple from infile
                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                    // write RGB triple to outfile, sizeof(RGBTRIPLE) * f number of bytes
                    // RGBTRIPLE triple[f]
                    for (int count = 0; count < f; count++)
                    {
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    }

                }

                // then add it back (to demonstrate how)
                for (int k = 0; k < newFilePadding; k++)
                {
                    fputc(0x00, outptr);
                }

                if (m < f - 1)
                {
                    fseek(inptr, -oldBiWidth * sizeof(RGBTRIPLE), SEEK_CUR);
                }
                else
                {
                    // skip over padding, if any
                    fseek(inptr, padding, SEEK_CUR);
                }
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
