#include <iostream>
#include <fstream>
#include <stdio.h>
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



int main() {

    ifstream file("test.bmp");

}
