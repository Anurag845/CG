#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

QImage image(400,400,QImage::Format_RGB888);

QRgb val1 = qRgb(255,0,0);
QRgb val2 = qRgb(0,0,255);

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
    int r,x,y;
    r=ui->textEdit->toPlainText().toUInt();
    x=ui->textEdit_2->toPlainText().toUInt();
    y=ui->textEdit_3->toPlainText().toUInt();
    dda(r,x,y);
}

void MainWindow::on_pushButton_2_clicked()
{
    int r,x,y;
    r=ui->textEdit->toPlainText().toUInt();
    x=ui->textEdit_2->toPlainText().toUInt();
    y=ui->textEdit_3->toPlainText().toUInt();
    bresenham(r,x,y);
}

void MainWindow::dda(int r,int x,int y)
{
    float x1,y1,startx,starty,e ;
    x1 = r*cos(0);
    y1 = r*sin(0);
    startx = x1;
    starty = y1;
    int i = 0,val = 0;
    do
    {
        val = pow(2,i);
        i++;
    }while(val<r);
    e = 1/pow(2,i-1);
    do
    {
        float x2,y2;
        x2 = x1 + y1*e;
        y2 = y1 - x2*e;
        image.setPixel(x+x2,y+y2,val1);
        x1=x2;
        y1=y2;
    }while((y1-starty)<e || (startx-x1)>e);
    ui->label_4->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::bresenham(int r,int x,int y)
{
    int x1,y1,h;
    x1 = 0;
    y1 = r;
    h = 3-2*r;
    draw_circle(x1,y1,x,y);
    while(y1>x1)
    {
        if(h<0)
        {
            h = h+4*x1+6;
        }
        else
        {
            h = h+4*(x1-y1)+10;
            y1--;
        }
        x1++;
        draw_circle(x1,y1,x,y);
    }
    ui->label_4->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::draw_circle(int x1,int y1,int x,int y)
{
    image.setPixel(x+x1,y+y1,val2);
    image.setPixel(x+x1,y-y1,val2);
    image.setPixel(x-x1,y+y1,val2);
    image.setPixel(x-x1,y-y1,val2);
    image.setPixel(x+y1,y+x1,val2);
    image.setPixel(x+y1,y-x1,val2);
    image.setPixel(x-y1,y+x1,val2);
    image.setPixel(x-y1,y-x1,val2);
}
