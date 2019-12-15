#include "transform.h"
#include "ui_transform.h"
#include <QString>
#include <QFileDialog>
#include "binarization.h"
#include <QMessageBox>
#include "grayimage.h"

transform::transform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::transform)
{
    ui->setupUi(this);
}

transform::~transform()
{
    delete ui;
}

void transform::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("jpgfile(*.jpg)"));
    binarization Create (fileName);
    if (Create.isLoaded() == false)
    {
        QMessageBox msg;
        msg.setWindowTitle("Message");
        msg.setText("Open failed!!");
        msg.setButtonText(QMessageBox::Ok, QString ("OK"));
    }
    else {
        QMessageBox msg;
        msg.setWindowTitle("Message");
        msg.setText("Creating...");
        msg.setButtonText(QMessageBox::Ok, QString ("OK"));
        Create.print();
    }
}

void transform::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("jpgfile(*.jpg)"));
    if (fileName.size () != 0)
    {
        GrayImage img(fileName);
        if (img.isLoaded() == false)
        {
            QMessageBox msg;
            msg.setWindowTitle("Message");
            msg.setText("Open failed!!");
            msg.setButtonText(QMessageBox::Ok, QString ("OK"));
        }
        else {
            QMessageBox msg;
            msg.setWindowTitle("Message");
            msg.setText("Creating...");
            msg.setButtonText(QMessageBox::Ok, QString ("OK"));
            img.imageCreate();
        }
    }

}
