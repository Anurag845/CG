#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void dda(int,int,int,int,QImage &,QRgb &);

    void circle(int,int,int,QImage &,QRgb &);

    void DDA_circle(int,int,int,QImage &,QRgb &);

    void draw_circle(int,int,int,int,QImage &,QRgb &);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
