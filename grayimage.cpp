#include "grayimage.h"
#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include "binarization.h"
#include <algorithm>

GrayImage::GrayImage(QString imgPath):binarization (imgPath) {}
void GrayImage::transform ()
{
    grayScaleImg();
    histogramCount();
    weightedAverageCalculate();
    int left = weightedAverage / 6;
    int right = (255 - weightedAverage) / 6;
    for (int i = 0; i < width; ++i)
    {
        img.push_back(QVector<char>());
        for (int j = 0; j < height; ++j)
        {
            if (grayImg[i][j] < left)
                img[i].push_back('@');
            else if (grayImg[i][j] < left * 2)
                img[i].push_back('D');
            else if (grayImg[i][j] < left * 3)
                img[i].push_back('O');
            else if (grayImg[i][j] < left * 4)
                img[i].push_back('o');
            else if (grayImg[i][j] < left * 5)
                img[i].push_back('r');
            else if (grayImg[i][j] > 255 - right)
                img[i].push_back(' ');
            else if (grayImg[i][j] > 255 - right * 2)
                img[i].push_back(',');
            else if (grayImg[i][j] > 255 - right * 3)
                img[i].push_back('-');
            else if (grayImg[i][j] > 255 - right * 4)
                img[i].push_back('+');
            else if (grayImg[i][j] > 255 - right * 5)
                img[i].push_back('^');
            else {
                img[i].push_back('*');
            }
         }
    }
}

void GrayImage::weightedAverageCalculate()
{
    int Sum = 0;
    for (int i = 0; i < 256; ++i)
        Sum += Histogram[i] * i;
    weightedAverage = Sum / (width * height);
}

void GrayImage::imageCreate()
{
    transform();
    QFile myfile("C:\\Users\\Public\\Pictures\\output.txt");
    myfile.open (QIODevice::WriteOnly|QFile::Truncate);
    QTextStream txtOutPut(&myfile);
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
           txtOutPut << img[j][i];
        }
        txtOutPut << "\n";
    }
}

