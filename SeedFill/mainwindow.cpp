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

QImage image(450,450,QImage::Format_RGB888);
QRgb f_color,b_color;

void MainWindow::line(int x1,int y1,int x2,int y2)
{
    float x,y,dx,dy,length;
    if(abs(x1-x2)>=abs(y1-y2))
        length=abs(x1-x2);
    else
        length=abs(y1-y2);
    dx=(x1-x2)/length;
    dy=(y1-y2)/length;
    x=x2+0.5;
    y=y2+0.5;
    for(int i=0;i<=length;i++)
    {
        image.setPixel((int)x,(int)y,b_color);
        x=x+dx;
        y=y+dy;
    }
}

void MainWindow::boundaryfill(int x,int y)
{
    QRgb value;
    value=qRgb(0,0,0);
    if(image.pixel(x,y)==value)
    {
        image.setPixel(x,y,f_color);
        boundaryfill(x+1,y);
        boundaryfill(x,y+1);
        boundaryfill(x-1,y);
        boundaryfill(x,y-1);
       // boundaryfill(x+1,y-1);
        //boundaryfill(x+1,y+1);
        //boundaryfill(x-1,y-1);
       // boundaryfill(x-1,y+1);
    }
}

void MainWindow::on_pushButton_clicked()
{
    int r,g,b;
    r = ui->textEdit->toPlainText().toInt();
    g = ui->textEdit_2->toPlainText().toInt();
    b = ui->textEdit_3->toPlainText().toInt();
    b_color=qRgb(255,255,255);
    f_color=qRgb(r,g,b);
  // dda(70,10,10,113.92);
  // dda(10,113.92,130,113.92);
  // dda(70,10,130,113.92);
   ui->label_4->setPixmap(QPixmap::fromImage(image));

}

void MainWindow::on_pushButton_2_clicked()
{
    boundaryfill(70,79);
    ui->label_4->setPixmap(QPixmap::fromImage(image));
}
int i=0;
int x1,y1,x2=0,y2=0,a,b;
int count=4;
int ix,iy,fx,fy;

void MainWindow::mousePressEvent(QMouseEvent *event)
{
   QString x= QString::number(event->x());   //returns string equivalent to number
                                             // (here, x coordinate as clicked)
   QString y= QString::number(event->y());

   a=x.toInt();
   b=y.toInt();

   if(i==0)
   {
        x1=x.toInt();
        y1=y.toInt();
        ix=x1;
        iy=y1;
    }
    else if(i==count)
    {
        fx=x2;
        fy=y2;
        line(ix,iy,fx,fy);
        boundaryfill(a,b);
    }
    else
    {

        x2=a;
        y2=b;

        line(x1,y1,x2,y2);
        x1=x2;
        y1=y2;
    }
    i++;
    ui->label_4->setPixmap(QPixmap::fromImage(image));
}
