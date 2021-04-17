#include <cstdint>
using namespace std;
class Header {
public:
    Header();

    Header(const Header &h);

    int32_t getFilesize() const;

    void setFilesize(int32_t filesize);

    int32_t getWidth() const;

    void setWidth(int32_t width);

    int32_t getDepth() const;

    void setDepth(int32_t depth);

    void enlargeImage(int coef);

private:
    int8_t id[2];            // Завжди дві літери 'B' і 'M'
    int32_t filesize;        // Розмір файла в байтах
    int16_t reserved[2];     // 0, 0
    int32_t headersize;      // 54L для 24-бітних зображень
    int32_t infoSize;        // 40L для 24-бітних зображень
    int32_t width;           // ширина зображення в пікселях
    int32_t depth;           // висота зображення в пікселях
    int16_t biPlanes;        // 1 (для 24-бітних зображень)
    int16_t bits;            // 24 (для 24-бітних зображень)
    int32_t biCompression;   // 0L
    int32_t biSizeImage;     // Можна поставити в 0L для зображень без компрессії (наш варіант)
    int32_t biXPelsPerMeter; // Рекомендована кількість пікселів на метр, можна 0L
    int32_t biYPelsPerMeter; // Те саме, по висоті
    int32_t biClrUsed;       // Для індексованих зображень, можна поставити 0L
    int32_t biClrImportant;
};