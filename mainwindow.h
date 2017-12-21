#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <complex.h>
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void showEvent(QShowEvent *event);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addCubeBtn_clicked();

    void on_addSphereBtn_clicked();

private:
    Ui::MainWindow *ui;
    Complex *complex;
    void showComplex();
};

#endif // MAINWINDOW_H
