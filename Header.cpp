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