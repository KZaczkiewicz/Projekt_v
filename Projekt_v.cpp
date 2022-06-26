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

    cout << "\n--- Metadane pliku .bmp ---" << "\n\n";

    cout << "1. Naglowek pliku\n" << endl;
    fread(&File.bfType, sizeof(File.bfType), 1, file);
    printf("   Typ pliku: %x \n", File.bfType);

    fread(&File.bfSize, sizeof(File.bfSize), 1, file);
    printf("   Rozmiar pliku: %d bajtow \n", File.bfSize);

    fread(&File.bfReserved1, sizeof(File.bfReserved1), 1, file);
    printf("   Zarezerwowane I miejsce: %d \n", File.bfReserved1);

    fread(&File.bfReserved2, sizeof(File.bfReserved2), 1, file);
    printf("   Zarezerwowane II miejsce: %d \n", File.bfReserved2);

    fread(&File.bfOffBits, sizeof(File.bfOffBits), 1, file);
    printf("   Offset: %d \n\n", File.bfOffBits);





    if (file)
    {
        err = fclose(file);
        if (err == 0)
        {
            printf("\n\nThe file was closed\n");
        }
        else
        {
            printf("\n\nFail! The file was not closed\n");
        }
    }

}
