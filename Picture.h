#include "Pixel.h"
#include "Header.h"

class Picture {
private:
    Header header;
    Pixel *body = new Pixel[header.getNumberOfPixels()];
};