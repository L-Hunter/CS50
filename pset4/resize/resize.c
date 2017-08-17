/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int padding;
int resized_padding;
int n;

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    n = atoi(argv[1]);
    
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

    //BITMAPFILEHEADER resized_bf = bf;   
    BITMAPINFOHEADER resized_bi = bi; 
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    // ?? bfSize  (imcludes pixels, padding, and headers) - NOT mentioned in walkthrough
    // ..? bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) - Mentioned in walkthrough
    
    resized_bi.biWidth = bi.biWidth * n;
    resized_bi.biHeight *= n;
    resized_bi.biSizeImage = ((sizeof(RGBTRIPLE) + bi.biWidth) + padding) * abs(bi.biHeight);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    // ?? bi.biWidth *= n; - Mentioned in walkthrough
    // ?? bi.biHeight *= n; - Mentioned in walkthrough
    // ?? biSizeImage (pixels and padding) - NOT mentioned in walkthrough
    // ...? bi.biSizeImage = ((sizeof(RGBTRIPLE) + biWidth) + padding) * abs(bi.biHeight); - Mentioned in walkthrough

    // determine padding for scanlines
    padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    resized_padding = (4 - (resized_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    // ..? per walkthrough: - says might have to keep track of both new and old padding
    // fputc(0x00, outptr)
    
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            // ?? write above N times? (rewrite method)
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
        // ?? do entire line N times
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
