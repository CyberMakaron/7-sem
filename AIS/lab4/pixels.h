#ifndef PIXELS_H
#define PIXELS_H

#include <QVector>
#include <QPushButton>

class Pixels{
private:
    QVector<QPushButton*> pixels;
    QVector<bool> pix_is_black;
    int h, w, size;
    QString size_css;
    int convertIndex(int i, int j);
public:
    Pixels(int h, int w, int size);
    QPushButton *getPixel(int i, int j);
    QPushButton *getPixel(int i);
    void inversePixel(int i, int j);
    void inversePixel(int i);
    void setPixelWhite(int i, int j);
    void setPixelWhite(int i);
    void setPixelBlack(int i, int j);
    void setPixelBlack(int i);
    void setImage(double* pixmap);
    void clear();
    void getImage(double* arr);
};

#endif // PIXELS_H
