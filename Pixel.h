#include <cstdint>
using namespace std;

class Pixel {
private:
    uint8_t redComponent;
    uint8_t greenComponent;
    uint8_t blueComponent;
public:
    Pixel();
    Pixel(uint8_t redComponent, uint8_t greenComponent, uint8_t blueComponent);

    uint8_t getRedComponent() const;

    void setRedComponent(uint8_t redComponent);

    uint8_t getGreenComponent() const;

    void setGreenComponent(uint8_t greenComponent);

    uint8_t getBlueComponent() const;

    void setBlueComponent(uint8_t blueComponent);
};
