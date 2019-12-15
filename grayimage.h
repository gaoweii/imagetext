#ifndef GRAYIMAGE_H
#define GRAYIMAGE_H

#include "binarization.h"
#include <QVector>

class GrayImage: public binarization
{
public:
    GrayImage(QString imgPath);
    void transform ();
    void imageCreate ();
    void weightedAverageCalculate ();
private:
    QVector<QVector<char>> img;
    int weightedAverage;
};

#endif // GRAYIMAGE_H
