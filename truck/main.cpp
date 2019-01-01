#include "mainwindow.h"
#include<QApplication>
#include<QLabel>
#include<QtGui>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QImage image(800,800, QImage::Format_RGB888);
    QRgb value;
    value=qRgb(255,0,0);   //set color of pixel as green
    for(int i=100;i<200;i++)
    {
        image.setPixel(i,400,value);
    }
    for(float i=200;i<230;i+=0.01)
    {
        image.setPixel(i,(-3)*i+1000,value);
    }
    for(int i=230;i<350;i++)
    {
        image.setPixel(i,310,value);
    }
    for(int i=310;i<500;i++)
    {
        image.setPixel(350,i,value);
    }
    for(int i=100;i<200;i++)
    {
        image.setPixel(i,100,value);
    }
    for(int i=400;i<500;i++)
    {
        image.setPixel(100,i,value);
    }
    for(int i=100;i<600;i++)
    {
        image.setPixel(i,500,value);
    }
    for(int i=350;i<600;i++)
    {
        image.setPixel(i,400,value);
    }
    for(int i=400;i<500;i++)
    {
        image.setPixel(600,i,value);
    }

    for(float x=160;x<=240;x+=0.0002)
    {
        float y1 = 540+sqrt(1600-(x-200)*(x-200));
        float y2 = 540-sqrt(1600-(x-200)*(x-200));
        image.setPixel(x,y1,value);
        image.setPixel(x,y2,value);
    }

    for(float x=460;x<=540;x+=0.0002)
    {
        float y1 = 540+sqrt(1600-(x-500)*(x-500));
        float y2 = 540-sqrt(1600-(x-500)*(x-500));
        image.setPixel(x,y1,value);
        image.setPixel(x,y2,value);
    }

    QLabel l;                              //shows pixel on screen
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    return a.exec();
}
