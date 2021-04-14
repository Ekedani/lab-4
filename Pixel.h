#include <cstdint>
using namespace std;

class Pixel {
private:
    int8_t redComponent;
    int8_t greenComponent;
    int8_t blueComponent;
public:
    Pixel(int8_t redComponent, int8_t greenComponent, int8_t blueComponent);

    int8_t getRedComponent() const;

    void setRedComponent(int8_t redComponent);

    int8_t getGreenComponent() const;

    void setGreenComponent(int8_t greenComponent);

    int8_t getBlueComponent() const;

    void setBlueComponent(int8_t blueComponent);
};
