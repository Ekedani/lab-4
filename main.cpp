#include <iostream>
#include <string>
#include "Header.h"
#include "Body.h"
using namespace std;

int main() {
    string s;
    cin >> s;
    Header h;
    h.readHeader(s);
    h.writeHeader("hhh.txt");
    Body b(h.getWidth(),h.getDepth());
    b.readFromFile(s);
    cout << endl;
    cout << int(b.data[4181].getRedComponent()) << " ";
    cout << int (b.data[4181].getGreenComponent()) << " ";
    cout << int(b.data[4181].getBlueComponent()) << " ";
    b.writeToFile("hhh.txt");
    return 0;
}

//C:\Users\koziu\Downloads\bmp.bmp
