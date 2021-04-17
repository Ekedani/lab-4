#include "Header.h"

//Конструктор по умолчанию
Header::Header() {}

//Конструктор копирования
Header::Header(const Header &h) {
    id[0] = h.id[0];
    id[1] = h.id[1];
    filesize = h.filesize;
    reserved[0] = h.reserved[0];
    reserved[1] = h.reserved[1];
    headersize = h.headersize;
    infoSize = h.infoSize;
    width = h.width;
    depth = h.depth;
    biPlanes = h.biPlanes;
    bits = h.bits;
    biCompression = h.biCompression;
    biSizeImage = h.biSizeImage;
    biXPelsPerMeter = h.biXPelsPerMeter;
    biYPelsPerMeter = h.biYPelsPerMeter;
    biClrUsed = h.biClrUsed;
    biClrImportant = h.biClrImportant;
}

int32_t Header::getFilesize() const {
    return filesize;
}

void Header::setFilesize(int32_t filesize) {
    Header::filesize = filesize;
}

int32_t Header::getWidth() const {
    return width;
}

void Header::setWidth(int32_t width) {
    Header::width = width;
}

int32_t Header::getDepth() const {
    return depth;
}

void Header::setDepth(int32_t depth) {
    Header::depth = depth;
}

void Header::enlargeImage(int coef) {
    depth *= coef;
    width *= coef;
    int delta = 4 - (width % 4);
    //TODO: написать filesize = 54 +
}

void Header::readHeader(string address){
    ifstream file (address, ios::in | ios::binary);
    file.read((char*)&id, sizeof(id));
    file.read((char*)&filesize, sizeof(filesize));
    file.read((char*)&reserved, sizeof(reserved));
    file.read((char*)&headersize, sizeof(headersize));
    file.read((char*)&infoSize, sizeof(infoSize));
    file.read((char*)&width, sizeof(width));
    file.read((char*)&depth, sizeof(depth));
    file.read((char*)&biPlanes, sizeof(biPlanes));
    file.read((char*)&bits, sizeof(bits));
    file.read((char*)&biCompression, sizeof(biCompression));
    file.read((char*)&biSizeImage, sizeof(biSizeImage));
    file.read((char*)&biXPelsPerMeter, sizeof(biXPelsPerMeter));
    file.read((char*)&biYPelsPerMeter, sizeof(biYPelsPerMeter));
    file.read((char*)&biClrUsed, sizeof(biClrUsed));
    file.read((char*)&biClrImportant, sizeof(biClrImportant));
    file.close();
}

void Header::writeHeader(string address){
    ofstream file (address, ios::out | ios::binary);
    file.write((char*)&id, sizeof(id));
    file.write((char*)&filesize, sizeof(filesize));
    file.write((char*)&reserved, sizeof(reserved));
    file.write((char*)&headersize, sizeof(headersize));
    file.write((char*)&infoSize, sizeof(infoSize));
    file.write((char*)&width, sizeof(width));
    file.write((char*)&depth, sizeof(depth));
    file.write((char*)&biPlanes, sizeof(biPlanes));
    file.write((char*)&bits, sizeof(bits));
    file.write((char*)&biCompression, sizeof(biCompression));
    file.write((char*)&biSizeImage, sizeof(biSizeImage));
    file.write((char*)&biXPelsPerMeter, sizeof(biXPelsPerMeter));
    file.write((char*)&biYPelsPerMeter, sizeof(biYPelsPerMeter));
    file.write((char*)&biClrUsed, sizeof(biClrUsed));
    file.write((char*)&biClrImportant, sizeof(biClrImportant));
    file.close();
}

