#include "Pixel.h"
#include <string>
#include <fstream>

class Body {
private:
    //Атрибуты
    Pixel *data;
    int32_t width;
    int32_t depth;

    //Методы
    long getNumberOfPixels() const;

    void readAline(ifstream &file, long &proceeded_pixels, int delta);

    void createADataArray();

    void enlargeLine(int coef, long &proceeded_pixels, Pixel *new_data);

    void writeLine(ofstream &file, long &proceeded_pixels);
public:
    Body(int32_t width, int32_t depth){
        Body::width = width;
        Body::depth = depth;
    }

    void readFromFile(string address);

    void enlargeImage(int coef);

    void writeToFile(const string& address) const;

};

