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
    printf("   Rozmiar pliku [B]: %d \n", File.bfSize);

    fread(&File.bfReserved1, sizeof(File.bfReserved1), 1, file);
    printf("   Zarezerwowane I miejsce [B]: %d \n", File.bfReserved1);

    fread(&File.bfReserved2, sizeof(File.bfReserved2), 1, file);
    printf("   Zarezerwowane II miejsce [B]: %d \n", File.bfReserved2);

    fread(&File.bfOffBits, sizeof(File.bfOffBits), 1, file);
    printf("   Offset [B]: %d \n\n", File.bfOffBits);

    cout << "2. Naglowek obrazu\n" << endl;

    fread(&Picture.biSize, sizeof(Picture.biSize), 1, file);
    printf("   Wielkosc naglowka informacyjnego [B]: %d \n", Picture.biSize);

    fread(&Picture.biWidth, sizeof(Picture.biWidth), 1, file);
    printf("   Szerokosc obrazu [px]: %d \n", Picture.biWidth);

    fread(&Picture.biHeight, sizeof(Picture.biHeight), 1, file);
    printf("   Wysokosc obrazu [px]: %d \n", Picture.biHeight);

    fread(&Picture.biPlanes, sizeof(Picture.biPlanes), 1, file);
    printf("   Ilosc warstw koloru: %d \n", Picture.biPlanes);

    fread(&Picture.biBitCount, sizeof(Picture.biBitCount), 1, file);
    printf("   Ilosc bitow / piksel: %d \n", Picture.biBitCount);

    fread(&Picture.biCompression, sizeof(Picture.biCompression), 1, file);
    printf("   Algorytm kompresji: %d \n", Picture.biCompression);

    fread(&Picture.biSizeImage, sizeof(Picture.biSizeImage), 1, file);
    printf("   Rozmiar samego obrazu [B]: %d \n", Picture.biSizeImage);

    fread(&Picture.biXPelsPerMeter, sizeof(Picture.biXPelsPerMeter), 1, file);
    printf("   Rozdzielczosc pozioma [dpi]: %d \n", Picture.biXPelsPerMeter);

    fread(&Picture.biYPelsPerMeter, sizeof(Picture.biYPelsPerMeter), 1, file);
    printf("   Rozdzielczosc pionowa [dpi]: %d \n", Picture.biYPelsPerMeter);

    fread(&Picture.biClrUsed, sizeof(Picture.biClrUsed), 1, file);
    printf("   Ilosc kolorow w palecie: %d \n", Picture.biClrUsed);

    fread(&Picture.biClrImportant, sizeof(Picture.biClrImportant), 1, file);
    printf("   Ilosc waznych kolorow w palecie: %d \n", Picture.biClrImportant);



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
