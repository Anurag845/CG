#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "qcolor.h"
#include "qcolordialog.h"

int *arr1,*arr2,i=0,flag=0;
QImage image(450,450,QImage::Format_RGB888);
QRgb value;

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
    int r,g,b;
    r = ui->textEdit->toPlainText().toInt();
    g = ui->textEdit_2->toPlainText().toInt();
    b = ui->textEdit_3->toPlainText().toInt();
    value = qRgb(r,g,b);
    arr1 = new int[2*10+2];
    arr2 = new int[2*10+2];
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::mousePressEvent(QMouseEvent *m)
{
    if(m->buttons()==Qt::LeftButton)
    {
        QString x = QString::number(m->x());
        QString y = QString::number(m->y());
        int x1,y1;
        x1 = x.toUInt();
        y1 = y.toUInt();
        arr1[i] = x1;
        arr2[i] = y1;
    }
    else if(m->buttons()==Qt::RightButton)
    {
        line(arr1[0],arr2[0],arr1[i-1],arr2[i-1]);
        flag=1;
    }
    if(i>=1 && flag==0)
    {
        line(arr1[i-1],arr2[i-1],arr1[i],arr2[i]);
    }
    if(flag==1)
    {
        QString x = QString::number(m->x());
        QString y = QString::number(m->y());
        int x2,y2;
        x2 = x.toUInt();
        y2 = y.toUInt();
        seedfill(x2,y2);
    }
    i++;
    emit(clicked());
}

void MainWindow::line(int x1,int y1,int x2,int y2)
{
    float x,y,len,xinc,yinc;
    int dx,dy;
    dx = x2-x1;
    dy = y2-y1;
    if(abs(dx)>abs(dy))
        len = abs(dx);
    else
        len = abs(dy);
    x = x1;
    y = y1;
    xinc = float(dx/len);
    yinc = float(dy/len);
    image.setPixel(x,y,value);
    for(int i=0;i<len;i++)
    {
        x = x+xinc;
        y = y+yinc;
        image.setPixel(x,y,value);
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::seedfill(int x,int y)
{
    if(image.pixel(x,y)!=value)
    {
        image.setPixel(x,y,value);
        seedfill(x+1,y);
        seedfill(x-1,y);
        seedfill(x,y+1);
        seedfill(x,y-1);
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_2_clicked()
{
    QColor color = QColorDialog::getColor(Qt::blue,this);
    color = color.rgb();
}
