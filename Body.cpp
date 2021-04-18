#include "Body.h"
#include <iostream>

using namespace std;
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
    long global_count = 54;
    int delta = 4 - (width % 4);
    for (int counter = 0; counter < depth; ++counter) {
        this->readAline(file, proceeded_pixels, delta, global_count);
    }

    //Закрытие файла
    file.close();
}

//TODO: Возможно, стоит обьединить с readAFile
void Body::readAline(ifstream &file, long &proceeded_pixels, int delta, long &global_count){
    for (int counter = 0; counter < width; ++counter) {
        //Все выводы дебажные, мы на дебажной ветке в конце концов

        //Чтение цвета пикселя
        cout << "Pixel is " << proceeded_pixels << endl;
        cout << "Char number " << global_count << endl;
        int8_t red;
        file.read((char*)&red, sizeof(int8_t));
        cout << "Red is "<< int(red) << endl;
        global_count++;

        int8_t green;
        file.read((char*)&green, sizeof(int8_t));
        cout << "Char number " << global_count << endl;
        cout << "Green is "<< int(green) << endl;
        global_count++;

        int8_t blue;
        file.read((char*)&blue, sizeof(int8_t));
        cout << "Char number " << global_count << endl;
        cout << "Blue is "<< int(blue) << endl;
        cout << "---------------" << endl;
        global_count++;
        //Запись информации о пикселе в массив
        data[proceeded_pixels] = Pixel(red, green, blue);
        proceeded_pixels++;
    }
    //Эта штука снизу всё портит
    //file.seekg(delta, ios::cur);
}

//Увеличение массива пикселей в заданное ЦЕЛОЕ количество раз
void Body::enlargeImage(int coef) {
    int32_t new_depth = depth * coef;
    int32_t new_width = width * coef;
    int32_t new_nop = new_depth * new_width;
    Pixel *new_data = new Pixel[new_nop];
    long proceeded_pixels = 0;
    for (int i = 0; i < depth; ++i) {
        for (int j = 0; j < coef; ++j) {
            enlargeLine(coef, proceeded_pixels, new_data);
        }
    }
    width = new_width;
    depth = new_depth;
    data = new_data;
}

void Body::enlargeLine(int coef, long &proceeded_pixels, Pixel *new_data) {
    long new_proceeded_pixels = proceeded_pixels * coef;
    for (int i = proceeded_pixels; i < proceeded_pixels + width; ++i) {
        //TODO: конструктор копирования пикселей
        for (int j = 0; j < coef; ++j) {
            new_data[new_proceeded_pixels] = data[i];
            new_proceeded_pixels++;
        }
    }
    proceeded_pixels += width;
}

void Body::writeToFile(const string& address) const {
    ofstream file (address, ios::out | ios::binary | ios::app);
    long proceeded_pixels = 0;
    for(int i = 0; i < depth; i++){
        this->writeLine(file, proceeded_pixels);
    }
    file.close();
}

void Body::writeLine(ofstream &file, long &proceeded_pixels) const{
    for (int counter = 0; counter < width; ++counter) {
        //Запись цвета пикселя
        int8_t red = data[proceeded_pixels].getRedComponent();
        file.write((char*)&red, sizeof(int8_t));
        int8_t green = data[proceeded_pixels].getGreenComponent();
        file.write((char*)&green, sizeof(int8_t));
        int8_t blue = data[proceeded_pixels].getBlueComponent();
        file.write((char*)&blue, sizeof(int8_t));
        proceeded_pixels++;
    }
}
