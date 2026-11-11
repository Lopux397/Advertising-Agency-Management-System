#include "../headers/mainwindow.h"
#include "../forms/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(std::make_unique<Ui::MainWindow>())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() = default;
