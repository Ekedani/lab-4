//
// Created by name on 14.04.2021.
//

#include "Pixel.h"

int8_t Pixel::getRedComponent() const {
    return redComponent;
}

void Pixel::setRedComponent(int8_t redComponent) {
    Pixel::redComponent = redComponent;
}

int8_t Pixel::getGreenComponent() const {
    return greenComponent;
}

void Pixel::setGreenComponent(int8_t greenComponent) {
    Pixel::greenComponent = greenComponent;
}

int8_t Pixel::getBlueComponent() const {
    return blueComponent;
}

void Pixel::setBlueComponent(int8_t blueComponent) {
    Pixel::blueComponent = blueComponent;
}

Pixel::Pixel() {}

Pixel::Pixel(int8_t redComponent, int8_t greenComponent, int8_t blueComponent) : redComponent(redComponent),
                                                                                 greenComponent(greenComponent),
                                                                                 blueComponent(blueComponent) {}
