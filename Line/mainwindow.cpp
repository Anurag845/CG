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

    int dx=x2-x1,dy=y2-y1,len;

    if(abs(dx)>abs(dy))
        len=abs(dx);
    else
        len=abs(dy);

    float xinc=dx/(float)len;
    float yinc=dy/(float)len;

    float x=x1+0.5;
    float y=y1+0.5;

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

    int x,y,dx,dy,p,xend,yend,inc;

    int slope = (float)((y2-y1)*(x2-x1));

    if(slope>0)
        inc=1;
    else
        inc=-1;

    dx=abs(x2-x1);
    dy=abs(y2-y1);
    if(dx>dy)
    {
        p=2*dy-dx;
        if(x1>x2)
        {
            x=x2;
            y=y2;
            xend=x1;
        }
        else
        {
            x=x1;
            y=y1;
            xend=x2;
        }
        while(x<xend)
        {
            x++;
            if(p<0)
            {
                p=p+2*dy;
            }
            else
            {
                p=p+2*dy-2*dx;
                y=y+inc;
            }
            image.setPixel(x,y,value);
        }
    }
    else
    {
        p=2*dx-dy;
        if(y1>y2)
        {
            x=x2;
            y=y2;
            yend=y1;
        }
        else
        {
            x=x1;
            y=y1;
            yend=y2;
        }
        while(y<yend)
        {
            y++;
            if(p<0)
            {
                p=p+2*dx;
            }
            else
            {
                p=p+2*dx-2*dy;
                x=x+inc;
            }
            image.setPixel(x,y,value);
        }
    }
    ui->label_5->setPixmap(QPixmap::fromImage(image));
}
