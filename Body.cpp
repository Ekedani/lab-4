#include "Body.h"

long Body::getNumberOfPixels() const{
    return width*depth;
}

void Body::createADataArray(){
    long size = this->getNumberOfPixels();
    Body::data = new Pixel[size];
}

//Чтение из файла
void Body::readAFile(string address) {
    //Создаем массив, в который будем заносить информацию о пикселях
    this->createADataArray();

    //Открытие файла и пропуск Header'а
    ifstream file (address, ios::in | ios::binary);
    file.seekg(432);

    //Поочередно обрабатываем каждый пиксель
    long proceeded_pixels = 0;
    for (int counter = 0; counter < depth; ++counter) {
        this->readAline(file, proceeded_pixels);
    }
    
    //Закрытие файла
    file.close();
}

//TODO: Возможно, стоит обьединить с readAFile
void Body::readAline(ifstream &file, long &proceeded_pixels){
    for (int counter = 0; counter < width; ++counter) {
        //Чтение цвета пикселя
        int8_t red;
        file.read((char*)&red, sizeof(int8_t));
        int8_t green;
        file.read((char*)&green, sizeof(int8_t));
        int8_t blue;
        file.read((char*)&blue, sizeof(int8_t));

        //Запись информации о пикселе в массив
        data[proceeded_pixels] = Pixel(red, green, blue);
        proceeded_pixels++;
    }
    //TODO: скип нулевых байтов
}

//Увеличение массива пикселей в заданное количество раз
void Body::enlargeImage(int coef) {

}
