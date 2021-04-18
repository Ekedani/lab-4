#include "Picture.h"

Picture::Picture(string address){
    header.readHeader(address);
    body.setWidth(header.getWidth());
    body.setDepth(header.getDepth());
    body.header_size = header.getHeadersize();
    body.readFromFile(address);
}

void Picture::EnlargeImage(int coef) {
    header.enlargeImage(coef);
    body.enlargeImage(coef);
}

void Picture::writeToFile(string address) {
    header.writeHeader(address);
    body.writeToFile(address);
}