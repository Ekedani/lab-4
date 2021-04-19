#include "Body.h"
#include <iostream>

using namespace std;

Body::Body(){};

long Body::getNumberOfPixels() const{
    return width*depth;
}

void Body::createADataArray(){
    long size = this->getNumberOfPixels();
    Body::data = new Pixel[size];
}

//Чтение из файла
void Body::readFromFile(string address) {
    //Создаем массив, в который будем заносить информацию о пикселях
    this->createADataArray();

    //Открытие файла и пропуск Header'а
    ifstream file (address, ios::in | ios::binary);
    file.seekg(54, ios::beg);

    //Поочередно обрабатываем каждый пиксель
    long proceeded_pixels = 0;
    int delta = 4 - ((width * 3) % 4);
    for (int counter = 0; counter < depth; ++counter) {
        this->readAline(file, proceeded_pixels, delta);
    }

    //Закрытие файла
    file.close();
}

//TODO: Возможно, стоит обьединить с readAFile
void Body::readAline(ifstream &file, long &proceeded_pixels, int delta){
    for (int counter = 0; counter < width; ++counter) {

        //Чтение цвета пикселя
        uint8_t red;
        file.read((char*)&red, sizeof(uint8_t));

        uint8_t green;
        file.read((char*)&green, sizeof(uint8_t));

        uint8_t blue;
        file.read((char*)&blue, sizeof(uint8_t));

        //Запись информации о пикселе в массив
        data[proceeded_pixels] = Pixel(red, green, blue);
        proceeded_pixels++;
    }

    long tmp;
    file.read((char*)&tmp, delta);
}

//Увеличение массива пикселей в заданное ЦЕЛОЕ количество раз
void Body::enlargeImage(int coef) {
    int32_t new_depth = depth * coef;
    int32_t new_width = width * coef;
    int32_t new_nop = new_depth * new_width;
    Pixel *new_data = new Pixel[new_nop];
    long proceeded_pixels = 0;
    long new_proceeded_pixels = 0;
    for (int i = 0; i < depth; ++i) {
        for (int j = 0; j < coef; ++j) {
            enlargeLine(coef, proceeded_pixels, new_proceeded_pixels, new_data);
        }
        proceeded_pixels += width;
    }
    width = new_width;
    depth = new_depth;
    data = new_data;
}

void Body::enlargeLine(int coef, long &proceeded_pixels, long &new_proceeded_pixels, Pixel *new_data) {
    for (int i = proceeded_pixels; i < proceeded_pixels + width; ++i) {
        //TODO: конструктор копирования пикселей
        for (int j = 0; j < coef; ++j) {
            new_data[new_proceeded_pixels] = data[i];
            new_proceeded_pixels++;
        }
    }
}

void Body::writeToFile(const string& address) const {
    int delta = 4 - ((width * 3) % 4);
    ofstream file (address, ios::out | ios::binary | ios::app);
    long proceeded_pixels = 0;
    for(int i = 0; i < depth; i++){
        this->writeLine(file, proceeded_pixels);
        for(int j = 0; j < delta; j++){
            uint8_t zero = 0;
            file.write((char*)&zero, sizeof(uint8_t));
        }
    }
    file.close();
}

void Body::writeLine(ofstream &file, long &proceeded_pixels) const{
    for (int counter = 0; counter < width; ++counter) {
        //Запись цвета пикселя
        uint8_t red = data[proceeded_pixels].getRedComponent();
        file.write((char*)&red, sizeof(uint8_t));
        uint8_t green = data[proceeded_pixels].getGreenComponent();
        file.write((char*)&green, sizeof(uint8_t));
        uint8_t blue = data[proceeded_pixels].getBlueComponent();
        file.write((char*)&blue, sizeof(uint8_t));
        proceeded_pixels++;
    }
}

void Body::setWidth(int32_t width) {
    Body::width = width;
}

void Body::setDepth(int32_t depth) {
    Body::depth = depth;
}

void Body::enlargeBImage(double coef) {
    int newWidth = (int) (coef * width);
    int newHeight = (int) (coef * depth);

    Pixel *scaledImage = new Pixel[newWidth * newHeight];
    for (int x = 0; x < newWidth; x++) {
        for (int y = 0; y < newHeight - 1; y++) {
            //TODO:обработка пикселей
        }
    }
    width = newWidth;
    depth = newHeight;
    data = scaledImage;
}
