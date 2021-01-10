#include "pixels.h"


Pixels::Pixels(int h, int w, int size): h(h), w(w), size(size){
    size_css = "width: " + QString::number(size) + "; height: " + QString::number(size);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++){
            QPushButton * but = new QPushButton();
            but->setObjectName(QString::number(i * w + j));
            pixels << but;
            pix_is_black << false;
            setPixelWhite(i, j);
        }
}

QPushButton *Pixels::getPixel(int i, int j){
    return pixels[convertIndex(i, j)];
}

QPushButton *Pixels::getPixel(int i){
    return pixels[i];
}

int Pixels::convertIndex(int i, int j){
    return i * w + j;
}

void Pixels::inversePixel(int i, int j){
    inversePixel(convertIndex(i, j));
}

void Pixels::inversePixel(int i){
    if (pix_is_black[i])
        setPixelWhite(i);
    else setPixelBlack(i);
}

void Pixels::setPixelWhite(int i, int j){
    setPixelWhite(convertIndex(i, j));
}

void Pixels::setPixelWhite(int i){
//    pixels[i]->setStyleSheet("background-color: white; border-style: none; " + size_css);
    pixels[i]->setStyleSheet("background-color: white; border-style: none; border: 1px solid lightgrey; " + size_css);
    pix_is_black[i] = false;
}

void Pixels::setPixelBlack(int i, int j){
    setPixelBlack(convertIndex(i, j));
}

void Pixels::setPixelBlack(int i){
//    pixels[i]->setStyleSheet("background-color: black; border-style: none; " + size_css);
    pixels[i]->setStyleSheet("background-color: black; border: 1px solid lightgrey;  " + size_css);
    pix_is_black[i] = true;
}

void Pixels::setImage(double* pixmap){
    for (int i = 0; i < h * w; i ++)
            if (pixmap[i] == 0)
                setPixelWhite(i);
            else setPixelBlack(i);
}

void Pixels::clear(){
    for (int i = 0; i < h * w; i ++)
        setPixelWhite(i);
}

void Pixels::getImage(double *arr){
    for (int i = 0; i < h * w; i++)
        if (pix_is_black[i])
            arr[i] = 1;
        else arr[i] = 0;
}
