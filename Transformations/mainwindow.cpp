#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "math.h"
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage image(400,400,QImage::Format_RGB888);
QRgb val1 = qRgb(255,0,0);
QRgb val2 = qRgb(0,0,255);
QRgb val3 = qRgb(0,255,0);

void MainWindow::on_pushButton_clicked()
{
    int x1,y1,x2,y2;
    x1 = ui->textEdit->toPlainText().toInt()+200;
    y1 = 200-ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt()+200;
    y2 = 200-ui->textEdit_4->toPlainText().toInt();
    line(0,200,400,200,val1);
    line(200,0,200,400,val1);
    line(x1,y1,x2,y2,val2);
}

void MainWindow::on_pushButton_2_clicked()
{
    int x1,y1,x2,y2,sx,sy;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();
    sx = ui->textEdit_5->toPlainText().toInt();
    sy = ui->textEdit_6->toPlainText().toInt();
    scale(x1,y1,x2,y2,sx,sy);
}

void MainWindow::on_pushButton_3_clicked()
{
    int x1,y1,x2,y2,tx,ty;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();
    tx = ui->textEdit_7->toPlainText().toInt();
    ty = ui->textEdit_8->toPlainText().toInt();
    translate(x1,y1,x2,y2,tx,ty);
}

void MainWindow::line(int x1,int y1,int x2,int y2,QRgb value)
{
    int x,y,dx,dy,inc,g,xend,yend;

    if((x2-x1)*(y2-y1)>0)
        inc = 1;
    else
        inc = -1;

    dx = abs(x2-x1);
    dy = abs(y2-y1);

    if(dx>dy)
    {
        g = 2*dy-dx;
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
        image.setPixel(x,y,value);
        while(x<xend)
        {
            if(g<0)
            {
                g = g+2*dy;
            }
            else
            {
                g = g+2*dy-2*dx;
                y = y+inc;
            }
            x++;
            image.setPixel(x,y,value);
        }
    }
    else
    {
        g = 2*dx-dy;
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
        image.setPixel(x,y,value);
        while(y<yend)
        {
            if(g<0)
            {
                g = g+2*dx;
            }
            else
            {
                g = g+2*dx-2*dy;
                x = x+inc;
            }
            y++;
            image.setPixel(x,y,value);
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::scale(int x1,int y1,int x2,int y2,int sx,int sy)
{
    int I[2][2] = {x1,y1,x2,y2};
    int S[2][2] = {sx,0,0,sy};
    int F[2][2] = {0,0,0,0};
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            for(int k = 0; k < 2; ++k)
            {
                F[i][j] += I[i][k] * S[k][j];
            }
        }
    }
    line(F[0][0]+200,200-F[0][1],F[1][0]+200,200-F[1][1],val3);
}

void MainWindow::translate(int x1,int y1,int x2,int y2,int tx,int ty)
{
    int I[2][3] = {x1,y1,1,x2,y2,1};
    int T[3][3] = {1,0,0,0,1,0,tx,ty,1};
    int F[2][3] = {0,0,0,0,0,0};
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<3;++j)
        {
            for(int k=0;k<3;++k)
                F[i][j] += I[i][k] * T[k][j];
        }
    }
    line(F[0][0]+200,200-F[0][1],F[1][0]+200,200-F[1][1],val3);
}
