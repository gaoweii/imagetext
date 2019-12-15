#include "binarization.h"
#include <QImage>
#include <QColor>
#include <QFile>
#include <QTextStream>
#include <QVector>

/*  学习一下图像处理的基础算法，写下来总结一下：

1. 灰度图像

    二值化图像的第一步是先将彩色图片转变为灰度图像，灰度图像算法如下：

我们可以通过下面几种方法，将其转换为灰度：
1.浮点算法：Gray=R*0.3+G*0.59+B*0.11
2.整数方法：Gray=(R*30+G*59+B*11)/100
3.移位方法：Gray =(R*76+G*151+B*28)>>8;
4.平均值法：Gray=（R+G+B）/3;
5.仅取绿色：Gray=G；
通过上述任一种方法求得Gray后，将原来的RGB(R,G,B)中的R,G,B统一用Gray替换，形成新的颜色RGB(Gray,Gray,Gray)，用它替换原来的RGB(R,G,B)就是灰度图了。
*以上内容来自百度

2. 图像二值化

    二值化是先设定一个阈值，然后将灰度图像中每个像素的颜色值与阈值相比较，小于阈值的设置为0（黑色），大于等于的则设为255（白色）；这个阈值可以设定为固定值，也可以是像素平均值，我这里使用otsu算法，查找出合适的阈值。
---------------------
作者：永远的魔术1号
来源：CSDN
原文：https://blog.csdn.net/zhango5/article/details/80378923
版权声明：本文为博主原创文章，转载请附上博文链接！
*/

binarization::binarization(QString imgPath): threshold(0)
{
    _img = new QImage ();
    if (nullptr != _img)
        _img ->load(imgPath);
    height = 0;
    width = 0;
    for (int i = 0; i < 256; ++i)
        Histogram.push_back(0);
}
bool binarization::isLoaded()
{
    if (_img == nullptr)
        return false;
    return true;
}

void binarization::grayScaleImg()
{
    if (nullptr == _img)
        return;
    width = _img->width();
    height = _img->height();
    QRgb rgbVal = 0;
    int grayVal = 0;
    for (int i = 0; i < width; ++i)
    {
        grayImg.push_back(QVector<int>());
        for (int j = 0; j < height; ++j)
        {
            rgbVal = _img->pixel(i, j);
            grayVal = qGray(rgbVal);
            grayImg[i].push_back(grayVal);
        }
    }
}

void binarization::histogramCount()
{
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            Histogram[grayImg[i][j]]++;
        }
    }
}

void binarization::Otsu()
{
    int t = 0;
    int foreGroundNum = 0, backGroundNum = 0; //前景， 背景像素个数
    int N = height * width;
    int forGroundGraySum = 0, backGroundGraySum = 0;
    int graySum = 0;
    double w0 = 0;
    double w1 = 0;
    double u0 = 0;
    double u1 = 0;
    double temp = 0;
    double g = 0;
    histogramCount();
    for (int i = 0; i < 256; ++i)
    {
        graySum += Histogram[i] * i;
    }
    for (int i = 0; i < 256; ++i)
    {
        foreGroundNum += Histogram[i];
        backGroundNum = N - foreGroundNum;
        w0 = static_cast<double>(foreGroundNum) / N;
        w1 = static_cast<double>(backGroundNum) / N;
        if (foreGroundNum == 0)
            continue;
        if (backGroundNum == 0)
            break;
        forGroundGraySum += i * Histogram[i];
        u0 = forGroundGraySum / foreGroundNum;
        backGroundGraySum = graySum - forGroundGraySum;
        u1 = backGroundGraySum / backGroundNum;
        g = w0 * w1 * (u0 - u1) * (u0 - u1);
        if (g > temp)
        {
            temp = g;
            t = i;
        }
    }
    for (int i = 0; i < width; ++i)
    {
        binarizationImg.push_back(QVector<char>());
        for (int j = 0; j < height; ++j)
        {
            if (grayImg[i][j] > t)
                binarizationImg[i].push_back('.');
            else {
                binarizationImg[i].push_back('@');
            }
        }
    }
}

void binarization::print()
{
    grayScaleImg();
    Otsu ();
    QFile myfile ("D:\\output.txt");
    myfile.open (QIODevice::WriteOnly|QFile::Truncate);
    QTextStream txtOutPut(&myfile);
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
           txtOutPut << binarizationImg[j][i];
        }
        txtOutPut << "\n";
    }
}

