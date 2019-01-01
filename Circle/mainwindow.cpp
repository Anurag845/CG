#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

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
    ui->label_4->clear();
    QImage image(400, 400, QImage::Format_RGB888);
    QRgb value;
    int x,y,r,r1,r2;
    r=ui->plainTextEdit->toPlainText().toUInt();
    x=ui->plainTextEdit_2->toPlainText().toUInt();
    y=ui->plainTextEdit_3->toPlainText().toUInt();
    value=qRgb(150,200,100);
    circle(r,x,y,image,value);
    r1=r/2;
    r2=sqrt(3)*r/2;
    DDA_circle(r1,x,y,image,value);
    dda(x,y-r,x-r2,y+r1,image,value);
    dda(x,y-r,x+r2,y+r1,image,value);
    dda(x+r2,y+r1,x-r2,y+r1,image,value);
    ui->label_4->setPixmap(QPixmap::fromImage(image));
}


void MainWindow::circle(int r,int x, int y,QImage &image, QRgb &value)
{
    int x1,y1,h;
    x1=0;
    y1=r;
    h=1-r;
    draw_circle(x1,y1,x,y,image,value);
    while(y1>x1)
    {
        if(h<0)
        {
            h=h+2*x1+3;
        }
        else
        {
            h=h+2*(x1-y1)+5;
            y1=y1-1;
        }
        x1=x1+1;
        draw_circle(x1,y1,x,y,image,value);
    }
}
void MainWindow::draw_circle(int x1, int y1, int x, int y, QImage &image, QRgb &value)
{
    image.setPixel(x+x1,y+y1,value);
    image.setPixel(x-x1,y+y1,value);
    image.setPixel(x+x1,y-y1,value);
    image.setPixel(x-x1,y-y1,value);
    image.setPixel(x+y1,y+x1,value);
    image.setPixel(x-y1,y+x1,value);
    image.setPixel(x+y1,y-x1,value);
    image.setPixel(x-y1,y-x1,value);
}
void MainWindow::dda(int x1,int y1,int x2,int y2,QImage &image,QRgb &value)
{
    int dx,dy,i;
    float len,xi,yi,x,y;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>=abs(dy))
    {
        len=abs(dx);
    }
    else
    {
        len=abs(dy);
    }
    xi=float(dx/len);
    yi=float(dy/len);
    x=x1;
    y=y1;
    image.setPixel(x,y,value);
    for(i=1;i<len;i++)
    {
        x=x+xi;
        y=y+yi;
        image.setPixel(x,y,value);
    }
}
void MainWindow::DDA_circle(int r, int x, int y, QImage &image, QRgb &value)
{
    float x1,y1,startx,starty;
    x1=r*cos(0);
    y1=r*sin(0);
    startx=x1;
    starty=y1;
    int i=0;
    int val;
    do
    {
        val=pow(2,i);
        i++;
    }while(val<r);
    float e;
    e=1/pow(2,i-1);
    do
    {
        float x2,y2;
        x2=x1+y1*e;
        y2=y1-x2*e;
        image.setPixel(x+x2,y+y2,value);
        x1=x2;
        y1=y2;
    }while((y1-starty)<e || (startx-x1)>e);
}
