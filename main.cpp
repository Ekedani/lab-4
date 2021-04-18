#include <iostream>
#include <string>
#include "Picture.h"
using namespace std;
//C:\Users\koziu\Desktop\lab-4\cmake-build-debug\lab_4.exe
int main(int argc, char *argv[]) {

    if(argc!=4) {
        cout << "There should be exactly 3 arguments" << endl;
        return 0;
    }
    string input = argv[1];
    string output = argv[2];
    int coef = *argv[3] - '0';

    Picture test_image(input);
    cout << "Enlarging image " << coef << " times...";
    test_image.EnlargeImage(coef);
    cout << "Done." << endl;
    test_image.writeToFile(output);
    cout << "Result is written to " << output;
    return 0;
}
