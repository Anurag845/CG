#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
using namespace std;

QImage image(300,300,QImage::Format_RGB888);

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
    ddaline(x1,y1,x2,y2);
}

void MainWindow::on_pushButton_2_clicked()
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    bresenham(x1,y1,x2,y2);
}

void MainWindow :: ddaline(int x1,int y1,int x2,int y2)
{
    QRgb value;
    value=qRgb(255,0,0);

    int dx=x2-x1,dy=y2-y1;
    int len;
    //QApplication a(argc, argv);
    //MainWindow w;

    if(abs(dx)>abs(dy))
        len=abs(dx);
    else
        len=abs(dy);

    float xinc=dx/(float)len;
    float yinc=dy/(float)len;

    float x=x1+0.5;//*(sign(x2,x1));
    float y=y1+0.5;//*(sign(y2,y1));

    for(int i=0;i<=len;i++)
    {
        x=x+xinc;
        y=y+yinc;
        image.setPixel(x,y,value);
    }
    //QLabel l;
    ui->label_5->setPixmap(QPixmap::fromImage(image));
}

void MainWindow :: bresenham(int x1,int y1,int x2,int y2)
{
    QRgb value;
    value=qRgb(0,255,0);

    int s1,s2,x,y,i,exchange;
    float dx,dy,g;
    dx=abs(x2-x1);
    dy=abs(y2-y1);

    x=x1;
    y=y1;

    s1=sign(x2-x1);
    s2=sign(y2-y1);

    if(dy>dx)
    {
        swap(dx,dy);
        exchange=1;
    }
    else
        exchange=0;
    g=2*dy-dx;
    i=1;

    while(i<=dx)
    {
        image.setPixel(x,y,value);
        while(g>=0)
        {
            if(exchange==1)
                x=x+x1;
            else
            {
                y=y+s2;
                g=g+2*dy-2*dx;
            }
        }
        if(exchange==1)
            y=y+s2;
        else
        {
            x=x+s1;
            g=g+2*dy;
        }
        i++;
    }
    ui->label_5->setPixmap(QPixmap::fromImage(image));
}


int MainWindow :: sign(float arg)
{
    if(arg<0)
        return -1;
    else if(arg==0)
        return 0;
    else
        return 1;
}

