#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <clicklabel.h>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //void mousePressEvent(QMouseEvent *ev);
    QRgb val1;
    void ddaline(float,float,float,float,QRgb);
    void seedfill(int,int,QRgb);

private slots:
    void on_pushButton_clicked();
    void clickedev();
    void clickedev2();

private:
    Ui::MainWindow *ui;
    clicklabel *l;
};

#endif // MAINWINDOW_H
