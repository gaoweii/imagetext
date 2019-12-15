#ifndef BINARIZATION_H
#define BINARIZATION_H

#include <QImage>
#include <QColor>
#include <QVector>

class binarization
{
public:
    binarization(QString imgPath);
    void grayScaleImg ();
    void print ();
    void Otsu ();
    void histogramCount ();
    int threshold;
    bool isLoaded ();
protected:
    QVector<QVector<int>> grayImg;
    QVector<QVector<char>> binarizationImg;
    QVector<int> Histogram;
    QImage* _img;
    int height, width;
};

#endif // BINARIZATION_H
