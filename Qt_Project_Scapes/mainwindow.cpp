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
}

void MainWindow::createFile(){
    int response;
    InputManager im = new InputManager();
    response = im.createFile(QString fileName);
    delete im;
}

bool MainWindow::saveFile(const QString& fileName){
    int response;
    InputManager im = new InputManager();
    response = im.saveFile(QString fileName);
    delete im;
}

bool MainWindow::compile(){

}
