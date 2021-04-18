#include <iostream>
#include <string>
#include "Picture.h"
using namespace std;

int main() {
    string s;
    cout << "Enter some path to file: ";
    cin >> s;
    //s = "E:\\my-repos\\lab-4\\thumbnail (1).bmp";
    //s = "C:\\Users\\koziu\\Downloads\\bmp.bmp";
    Picture test_image(s);
    test_image.EnlargeImage(3);
    test_image.writeToFile("hhh.bmp");
    return 0;
}
