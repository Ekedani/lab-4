#include "Header.h"
#include "Body.h"

class Picture {
private:
    Header header;
    Body body;
public:
    Picture(string address);

    void EnlargeImage(int coef);

    void writeToFile(string address);

};