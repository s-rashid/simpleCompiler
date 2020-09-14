#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->fileName = "";
    this->windowTitle = "Scapes IDE";
    ui->setupUi(this);
    this->setWindowTitle(windowTitle + ": untitled");
    this->ui->codeOutput->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_new_triggered()
{
    ui->codeInput->setText("");
}

void MainWindow::on_actionSave_program_triggered()
{

    uncompiledCode = ui->codeInput->toPlainText();
    if (fileName == "") {
        renameProgram();
    }
    QString directory = QDir::home().dirName(); //default for now
    directory = ".";
    ManageProgramControl control;
    control.saveFile(fileName, directory, uncompiledCode);
    this->setWindowTitle(windowTitle + ": " + fileName);
}

void MainWindow::on_actionRename_triggered()
{
    renameProgram();
}

void MainWindow::on_actionExit_2_triggered()
{
    ManageProgramControl control;
    control.exitProgram();
    QApplication::quit();
}

void MainWindow::on_actionCompile_2_triggered()
{
    ManageProgramControl control;
    if (fileName == "") {
        renameProgram();
    }
    uncompiledCode = ui->codeInput->toPlainText();
    ui->codeOutput->clear();
    control.compileProgram(this, uncompiledCode, fileName);
}

void MainWindow::on_actionLaunch_Run_triggered()
{
    ManageProgramControl control;
    if (fileName == "") {
        renameProgram();
    }
    control.runProgram();
}

void MainWindow::renameProgram() {
    fileName = QInputDialog::getText(this,
                                         tr("Save"),
                                         tr("Enter a New File Name:"),
                                         QLineEdit::Normal,
                                         "default",
                                         &ok);
    if (!fileName.endsWith(".scapes")) {
        fileName = fileName.split(".")[0] + ".scapes";
    }
    this->setWindowTitle(windowTitle + ": " + fileName);
}

void MainWindow::displayError(QString contents) {
    ui->codeOutput->setText("An error has occured during compiling:");
    ui->codeOutput->setTextColor(QColor(255, 0 ,0));
    ui->codeOutput->append(contents);
}
