#include "Pixel.h"
#include <string>
#include <fstream>


class Body {
private:
    //Атрибуты

    int32_t width;
    int32_t depth;


    //Методы
    long getNumberOfPixels() const;

    void readAline(ifstream &file, long &proceeded_pixels, int delta, long &global_count);

    void createADataArray();

    void enlargeLine(int coef, long &proceeded_pixels, long &new_proceeded_pixels, Pixel *new_data);

    void writeLine(ofstream &file, long &proceeded_pixels) const;
public:
    int32_t header_size;
    Pixel *data;
    Body(int32_t width, int32_t depth){
        Body::width = width;
        Body::depth = depth;
    }

    void readFromFile(string address);

    void enlargeImage(int coef);

    void writeToFile(const string& address) const;

};

