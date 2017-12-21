#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete complex;
}

void MainWindow::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    if (complex) showComplex();
}

void MainWindow::showComplex()
{
    ui->tableWidget->setRowCount(complex->getComplexSize());
    ui->tableWidget->setColumnCount(3);

    QStringList horizontalHeaders;
    horizontalHeaders << "Coordinates"
                      << "Size"
                      << "Type";
    ui->tableWidget->setHorizontalHeaderLabels(horizontalHeaders);

    QTableWidgetItem* item;
    int row = 0;
    Figure* curr = complex->getFirst();

    while(curr)
    {
        item = new QTableWidgetItem(curr->info->transformCoordinates());
        ui->tableWidget->setItem(row, 0, item);

        item = new QTableWidgetItem(curr->info->getVolume());
        ui->tableWidget->setItem(row, 1, item);

        //Вывод в поле "Text" в зависимости от типа записи
        switch (curr->info->getType())
        {
            case CUBE:
            {
//               Cube* art = static_cast<Cube*>(curr->info);
               item = new QTableWidgetItem("Cube");
            break;
            }
            case SPHERE:
            {
//                Sphere* comp = static_cast<Sphere*>(curr->info);
                item = new QTableWidgetItem("Sphere");
            break;
            }
        }
        ui->tableWidget->setItem(row, 2, item);
        row++;
        curr = curr->next;
    }
    ui->tableWidget->resizeColumnsToContents();
}

void MainWindow::on_addCubeBtn_clicked()
{
    Figure *newFigure = new Figure;

    newFigure->info->setCoordinates(ui->xSpinBox->value(), ui->ySpinBox->value(), ui->zSpinBox->value());
    newFigure->info->setVolume(newFigure->info->getVolume());
    newFigure->info->setType(CUBE);

    complex->addFigure(newFigure->info->getCoordinates(), newFigure->info->getVolume(), CUBE);
    showComplex();
}

void MainWindow::on_addSphereBtn_clicked()
{
    Figure *newFigure = new Figure;

    newFigure->info->setCoordinates(ui->xSpinBox->value(), ui->ySpinBox->value(), ui->zSpinBox->value());
    newFigure->info->setVolume(newFigure->info->getVolume());
    newFigure->info->setType(SPHERE);

    complex->addFigure(newFigure->info->getCoordinates(), newFigure->info->getVolume(), SPHERE);
    showComplex();
}
