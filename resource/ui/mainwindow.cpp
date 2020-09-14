#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->codeOutput->setReadOnly(true);

    this->fileName = "";
    this->windowTitle = "Scapes IDE";
    this->setWindowTitle(windowTitle + ": untitled");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_new_triggered()
{
    ui->codeInput->clear();
    ui->codeOutput->clear();
    fileName = "";
    this->setWindowTitle(windowTitle + ": untitled");
}

void MainWindow::on_actionSave_program_triggered()
{
    uncompiledCode = ui->codeInput->toPlainText();
    if (fileName == "") {
        bool ok = false;
        renameProgram(ok);
        if(!ok){
            QMessageBox::warning(this, "Error", "Unable to save unnamed file");
            return;
        }
    }
    QString directory = QDir::home().dirName(); //default for now
    directory = ".";
    ManageProgramControl control;
    control.saveFile(fileName, directory, uncompiledCode);
    this->setWindowTitle(windowTitle + ": " + fileName);
}

void MainWindow::on_actionRename_triggered()
{
    bool ok = false;
    renameProgram(ok);
}

void MainWindow::on_actionExit_2_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCompile_2_triggered()
{
    ManageProgramControl control;
    if (fileName == "") {
        bool ok = false;
        renameProgram(ok);
        if(!ok){
            QMessageBox::warning(this, "Error", "Unable to compile unnamed program");
            return;
        }
    }
    uncompiledCode = ui->codeInput->toPlainText();
    ui->codeOutput->setText("Compiling...");
    control.compileProgram(this, uncompiledCode, fileName);
}

void MainWindow::on_actionLaunch_Run_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Chose a compiled program to run", directory);
    if (filePath.isEmpty()){
        return;
    }
    ManageProgramControl control;
    ui->codeOutput->setText("Running...\n");
    control.runProgram(this, filePath);
}

void MainWindow::renameProgram(bool &ok) {
    fileName = QInputDialog::getText(this,
                                         tr("Rename"),
                                         tr("Enter a New File Name:"),
                                         QLineEdit::Normal,
                                         "default",
                                         &ok);

    if(ok){
        if (!fileName.endsWith(".scapes")) {
           fileName = fileName.split(".")[0] + ".scapes";
        }
        this->setWindowTitle(windowTitle + ": " + fileName);
    }
}

void MainWindow::displayError(QString contents) {
    ui->codeOutput->setTextColor(QColor(255, 0 ,0));
    ui->codeOutput->append(contents);
    ui->codeOutput->setTextColor(QColor(0, 0, 0));
}

void MainWindow::printToDisplay(QString contents) {
    //ui->codeOutput->append(contents);
    QString orgText = ui->codeOutput->toPlainText();
    ui->codeOutput->setText(orgText + contents);

}

void MainWindow::displaySuccessfullCompileMsg(QString filePath) {
    ui->codeOutput->setTextColor(QColor(50, 205, 50));
    ui->codeOutput->append("Successfully compiled program!");
    ui->codeOutput->setTextColor(QColor(0, 0, 0));
    ui->codeOutput->append("Compilaton output stored at: " + filePath + "\n");
}

void MainWindow::displayCompileError(QString contents) {
    ui->codeOutput->append("An error has occured during compiling:");
    displayError(contents);
}

void MainWindow::displayRuntimeError(QString contents) {
    ui->codeOutput->append("An error has occured while running the program:");
    displayError(contents);
}

int MainWindow::displayInputPrompt(int& integerValue) {
    bool ok;
    integerValue = QInputDialog::getInt(this,
                                     tr("Input"),
                                     tr("Enter an integer:"),
                                     0,
                                     -2147483647,
                                      2147483647,
                                     1,
                                     &ok);

    if(ok)
        return 0; //successful integer input
    return 1; //user canceled action
}


void MainWindow::on_actionLoad_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open a file", directory);
    if (filePath.isEmpty()){
        return;
    }

    ManageProgramControl control;
    control.loadProgram(text, filePath);
    ui->codeInput->setPlainText(text);

    fileName = filePath.section("/", -1);
    this->setWindowTitle(windowTitle + ": " + fileName);
    ui->codeOutput->clear();
}
