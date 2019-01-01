#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"

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

int *arr1,*arr2,i=0,n,j=0,flag=0;
QImage image(410,410, QImage::Format_RGB888);
QRgb value;

void MainWindow::on_pushButton_clicked()
{
    int r,g,b;
    r = ui->textEdit->toPlainText().toUInt();
    g = ui->textEdit_2->toPlainText().toUInt();
    b = ui->textEdit_3->toPlainText().toUInt();
    value = qRgb(r,g,b);
    arr1 = new int[10*2+2];
    arr2 = new int[10*2+2];
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::mousePressEvent(QMouseEvent *evt)
{
    if(evt->buttons()==Qt::LeftButton)
    {
        QString x = QString::number(evt->x());
        QString y = QString::number(evt->y());
        int x1,y1;
        x1 = x.toUInt();
        y1 = y.toUInt();
        arr1[i] = x1;
        arr2[i] = y1;
    }
    else
    {
        dda(arr1[0],arr2[0],arr1[i-1],arr2[i-1]);
        ui->label->setPixmap(QPixmap::fromImage(image));
        flag = 1;
    }
    if(i>=1 && flag==0)
    {
        dda(arr1[i-1],arr2[i-1],arr1[i],arr2[i]);
        ui->label->setPixmap(QPixmap::fromImage(image));
    }
    i++;
    emit(clicked());
}

void MainWindow::dda(int x1,int y1,int x2,int y2)
{
    int dx,dy;
    float x,y,xinc,yinc,len;
    dx = x2-x1;
    dy = y2-y1;
    if(abs(dx)>abs(dy))
        len = abs(dx);
    else
        len = abs(dy);
    xinc = (float)(dx/len);
    yinc = (float)(dy/len);
    x = x1;
    y = y1;
    image.setPixel(x,y,value);
    for(int i=0;i<len;i++)
    {
        x = x + xinc;
        y = y + yinc;
        image.setPixel(x,y,value);
    }
}










/*void MainWindow::on_pushButton_clicked()
{
    int r,g,b;
    r = ui->textEdit->toPlainText().toInt();
    g = ui->textEdit_2->toPlainText().toInt();
    b = ui->textEdit_3->toPlainText().toInt();
    value = qRgb(r,g,b);
    arr1=new int[2*10+2];
    arr2=new int[2*10+2];
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::mousePressEvent(QMouseEvent *m)
{
    if(m->buttons()==Qt::LeftButton)
    {
        QString x = QString::number(m->x());
        QString y = QString::number(m->y());
        int x1,y1;
        x1=x.toUInt();
        y1=y.toUInt();
        arr1[i]=x1;
        arr2[i]=y1;
    }
    else
    {
        dda(arr1[0],arr2[0],arr1[i-1],arr2[i-1],image,value);
        ui->label->setPixmap(QPixmap::fromImage(image));
        flag=1;
    }
    if(i>=1 && flag==0)
    {
        dda(arr1[i-1],arr2[i-1],arr1[i],arr2[i],image,value);
        ui->label->setPixmap(QPixmap::fromImage(image));
    }
    i++;
    emit(clicked());
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
}*/
