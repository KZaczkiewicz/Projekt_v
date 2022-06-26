#include <iostream>
#include <fstream>
#include <stdio.h>
#pragma once
#include <stdlib.h>
#include <limits.h>
using namespace std;

//Nagłówek pliku
struct FileHeader {
    short bfType;
    int bfSize;
    short bfReserved1;
    short bfReserved2;
    int bfOffBits;
} File;

//Nagłówek obrazu
struct BitMapInfoHeader {
    int biSize;
    int biWidth;
    int biHeight;
    short biPlanes;
    short biBitCount;
    int biCompression;
    int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    int biClrUsed;
    int biClrImportant;
} Picture;

//Paleta kolorów
struct RGBColor {
    char R;
    char G;
    char B;
} Rgb;

FILE* file;

int main(int arc, char* argv[]) {

    errno_t err;

    err = fopen_s(&file, "test.bmp", "rb");
    if (err == 0)
    {
        printf("The file was opened\n");
    }
    else
    {
        printf("Fail! The file was not opened\n");
    }






    if (file)
    {
        err = fclose(file);
        if (err == 0)
        {
            printf("The file was closed\n");
        }
        else
        {
            printf("Fail! The file was not closed\n");
        }
    }

}
