#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

QImage image(400,400,QImage::Format_RGB888);
QRgb val1 = qRgb(255,0,0);

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

void MainWindow::dda_circle(int r,int x,int y)
{
    float x1,y1,e,startx,starty;
    x1 = r*cos(0);
    y1 = r*sin(0);
    startx = x1;
    starty = y1;
    int i = 0,val;
    do
    {
        val = pow(2,i);
        i++;
    }
    while(val<r);
    e = 1/(pow(2,i-1));
    do
    {
        float x2,y2;
        x2 = x1 + y1*e;
        y2 = y1 - x2*e;
        image.setPixel(x+x2,y+y2,val1);
        x1 = x2;
        y1 = y2;
    }
    while((y1-starty)<e || (startx-x1>e));
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::b_circle(int r,int x,int y,char side)
{
    int x1,y1,h;
    x1 = 0;
    y1 = r;
    h = 1-r;
    draw(x,y,x1,y1,side);
    while(y1>x1)
    {
        if(h<0)
        {
            h = h+2*x1+3;
        }
        else
        {
            h = h+2*(x1-y1)+5;
            y1=y1-1;
        }
        x1=x1+1;
        draw(x,y,x1,y1,side);
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::draw(int x,int y,int x1,int y1,char side)
{
    switch(side)
    {
        case 'a':   image.setPixel(x+x1,y+y1,val1);
                    image.setPixel(x-x1,y+y1,val1);
                    image.setPixel(x+y1,y+x1,val1);
                    image.setPixel(x-y1,y+x1,val1);
                    break;
        case 'b':   image.setPixel(x+x1,y-y1,val1);
                    image.setPixel(x-x1,y-y1,val1);
                    image.setPixel(x+y1,y-x1,val1);
                    image.setPixel(x-y1,y-x1,val1);
                    break;
        case 'r':   image.setPixel(x+x1,y+y1,val1);
                    image.setPixel(x+x1,y-y1,val1);
                    image.setPixel(x+y1,y+x1,val1);
                    image.setPixel(x+y1,y-x1,val1);
                    break;
        case 'l':   image.setPixel(x-x1,y+y1,val1);
                    image.setPixel(x-x1,y-y1,val1);
                    image.setPixel(x-y1,y+x1,val1);
                    image.setPixel(x-y1,y-x1,val1);
                    break;
        default:    image.setPixel(x+x1,y+y1,val1);
                    image.setPixel(x+x1,y-y1,val1);
                    image.setPixel(x-x1,y+y1,val1);
                    image.setPixel(x-x1,y-y1,val1);
                    image.setPixel(x+y1,y+x1,val1);
                    image.setPixel(x+y1,y-x1,val1);
                    image.setPixel(x-y1,y+x1,val1);
                    image.setPixel(x-y1,y-x1,val1);
                    break;
    }
}

void MainWindow::dda_line(int x1,int y1,int x2,int y2)
{
    int dx,dy;
    float x,y,len,xinc,yinc;
    dx = x2-x1;
    dy = y2-y1;
    if(abs(dx)>abs(dy))
        len = abs(dx);
    else
        len = abs(dy);
    xinc = (float)(dx/len);
    yinc = (float)(dy/len);

    x=x1+0.5;
    y=y1+0.5;

    image.setPixel(x,y,val1);
    for(int i=0;i<len;i++)
    {
        x=x+xinc;
        y=y+yinc;
        image.setPixel(x,y,val1);
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_clicked()
{
    int x = 200, y = 200;
    float a,b;
    a = sqrt(3)*50.0;
    b = 50*sqrt(3)/2.0;
    //dda_line(200,200,120,150);
    //b_circle(b,200,200,'d');
    dda_line(200,200,120,220);
    dda_line(120,220,100,300);
    dda_line(100,300,180,280);
    dda_line(180,280,200,200);
    dda_line(200,200,280,220);
    dda_line(280,220,300,300);
    dda_line(300,300,220,280);
    dda_line(220,280,200,200);
    dda_line(200,200,157,130);
    dda_line(157,130,200,60);
    dda_line(200,60,242,130);
    dda_line(242,130,200,200);
}
