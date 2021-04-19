//
// Created by name on 14.04.2021.
//

#include "Pixel.h"

uint8_t Pixel::getRedComponent() const {
    return redComponent;
}

void Pixel::setRedComponent(uint8_t redComponent) {
    Pixel::redComponent = redComponent;
}

uint8_t Pixel::getGreenComponent() const {
    return greenComponent;
}

void Pixel::setGreenComponent(uint8_t greenComponent) {
    Pixel::greenComponent = greenComponent;
}

uint8_t Pixel::getBlueComponent() const {
    return blueComponent;
}

void Pixel::setBlueComponent(uint8_t blueComponent) {
    Pixel::blueComponent = blueComponent;
}

Pixel::Pixel() {}

Pixel::Pixel(uint8_t redComponent, uint8_t greenComponent, uint8_t blueComponent) : redComponent(redComponent),
                                                                                    greenComponent(greenComponent),
                                                                                    blueComponent(blueComponent) {}
