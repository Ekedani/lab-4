#include <iostream>
#include <string>
#include "Header.h"
#include "Body.h"
using namespace std;

int main() {
    string s;
    //cin >> s;
    s = "E:\\my-repos\\lab-4\\thumbnail (1).bmp";
    Header h;
    h.readHeader(s);
    Body b(h.getWidth(),h.getDepth());
    b.header_size = h.getHeadersize();
    b.readFromFile(s);
    h.enlargeImage(3);
    b.enlargeImage(3);
    cout << endl;
    cout << int(b.data[4181].getRedComponent()) << " ";
    cout << int (b.data[4181].getGreenComponent()) << " ";
    cout << int(b.data[4181].getBlueComponent()) << " ";
    h.writeHeader("hhh.bmp");
    b.writeToFile("hhh.bmp");
    return 0;
}

//C:\Users\koziu\Downloads\bmp.bmp
