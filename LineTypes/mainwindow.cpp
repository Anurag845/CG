#include "mainwindow.h"
#include "ui_mainwindow.h"

QImage image(500,500,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    solid(x1,y1,x2,y2);
}

void MainWindow::on_pushButton_2_clicked()
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    dotted(x1,y1,x2,y2);
}

void MainWindow::on_pushButton_3_clicked()
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    dashed(x1,y1,x2,y2);
}

void MainWindow::on_pushButton_4_clicked()
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    dashdot(x1,y1,x2,y2);
}

void MainWindow::on_pushButton_5_clicked()
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    thick(x1,y1,x2,y2);
}

void MainWindow :: solid(int x1,int y1,int x2,int y2)
{
    QRgb value;
    value=qRgb(255,0,0);

    float len,xinc,yinc,x,y;
    int dx,dy;

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)>abs(dy))
        len=abs(dx);
    else
        len=abs(dy);

    xinc=dx/(float)len;
    yinc=dy/(float)len;

    x=x1+0.5;
    y=y1+0.5;

    for(int i=0;i<=len;i++)
    {
        x=x+xinc;
        y=y+yinc;
        image.setPixel(x,y,value);
    }

    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow :: dotted(int x1,int y1,int x2,int y2)
{
    QRgb value;
    value=qRgb(255,0,0);

    float len,xinc,yinc,x,y;
    int dx,dy;

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)>abs(dy))
        len=abs(dx);
    else
        len=abs(dy);

    xinc=dx/(float)len;
    yinc=dy/(float)len;

    x=x1+0.5;
    y=y1+0.5;

    for(int i=0;i<=len;i++)
    {
        x=x+xinc;
        y=y+yinc;
        if(i%2)
        image.setPixel(x,y,value);
    }

    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow :: dashed(int x1,int y1,int x2,int y2)
{
    QRgb value;
    value=qRgb(255,0,0);

    float len,xinc,yinc,x,y;
    int dx,dy;

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)>abs(dy))
        len=abs(dx);
    else
        len=abs(dy);

    xinc=dx/(float)len;
    yinc=dy/(float)len;

    x=x1+0.5;
    y=y1+0.5;

    for(int i=0;i<=len;i++)
    {
        x=x+xinc;
        y=y+yinc;

        if(i%8)
        image.setPixel(x,y,value);
    }

    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow :: dashdot(int x1,int y1,int x2,int y2)
{
    QRgb value;
    value=qRgb(255,0,0);

    float len,xinc,yinc,x,y;
    int dx,dy;

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)>abs(dy))
        len=abs(dx);
    else
        len=abs(dy);

    xinc=dx/(float)len;
    yinc=dy/(float)len;

    x=x1+0.5;
    y=y1+0.5;

    for(int i=0;i<=len;i++)
    {
        for(int j=0;j<4 && i<=len;j++)
        {
            x=x+xinc;
            y=y+yinc;
            image.setPixel(x,y,value);
            i++;
        }
        x=x+2*xinc;
        y=y+2*yinc;
        i+=2;
        image.setPixel(x,y,value);
        x=x+xinc;
        y=y+yinc;
    }

    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow :: thick(int x1,int y1,int x2,int y2)
{
    QRgb value;
    value=qRgb(255,0,0);

    float len,xinc,yinc,x,y;
    int dx,dy;

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)>abs(dy))
        len=abs(dx);
    else
        len=abs(dy);

    xinc=dx/(float)len;
    yinc=dy/(float)len;

    x=x1+0.5;
    y=y1+0.5;

    for(int i=0;i<=len;i++)
    {
        x=x+xinc;
        y=y+yinc;

        if(dx==0)
        {
            image.setPixel(x-1,y,value);
            image.setPixel(x+1,y,value);
        }
        else
        {
            image.setPixel(x,y-1,value);
            image.setPixel(x,y+1,value);
        }
        image.setPixel(x,y,value);
    }

    ui->label->setPixmap(QPixmap::fromImage(image));
}
