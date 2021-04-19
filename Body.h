#include "Pixel.h"
#include <string>
#include <fstream>
#include <cmath>
#include <iostream>


class Body {
private:
    //Атрибуты

    int32_t width;
    int32_t depth;
    Pixel *data;

    //Методы
    long getNumberOfPixels() const;

    void readAline(ifstream &file, long &proceeded_pixels, int delta);

    void createADataArray();

    void enlargeLine(int coef, long &proceeded_pixels, long &new_proceeded_pixels, Pixel *new_data);

    void writeLine(ofstream &file, long &proceeded_pixels) const;

public:
    int32_t header_size;

    Body();

    Body(int32_t width, int32_t depth) {
        Body::width = width;
        Body::depth = depth;
    }

    void readFromFile(string address);

    void enlargeImage(int coef);

    void writeToFile(const string &address) const;

    void setWidth(int32_t width);

    void setDepth(int32_t depth);

    void enlargeBImage(double coef);
};
