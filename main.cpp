#include <iostream>
#include <string>
#include "Picture.h"
using namespace std;

int main(int argc, char *argv[]) {

    if(argc!=4) {
        cout << "There should be exactly 3 arguments" << endl;
        return 0;
    }

    string input = argv[1];
    string output = argv[2];
    string coef = argv[3];

    Picture new_image(input);
    new_image.EnlargeImageInterpolation(stod(coef));
    new_image.writeToFile(output);

    return 0;
}
