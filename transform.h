#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QMainWindow>

namespace Ui {
class transform;
}

class transform : public QMainWindow
{
    Q_OBJECT

public:
    explicit transform(QWidget *parent = nullptr);
    ~transform();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::transform *ui;
};

#endif // TRANSFORM_H
