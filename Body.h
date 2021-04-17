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

    void readAline(ifstream &file, long &proceeded_pixels);

    void createADataArray();
public:
    Body(int32_t width, int32_t depth){
        Body::width = width;
        Body::depth = depth;
    }

    void readAFile(string address);

    void enlargeImage(int coeff);



};

