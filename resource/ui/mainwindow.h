#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <QObject>
#include <QInputDialog>
#include "controller/userdisplayprompt.h"
#include "controller/manageprogcontrol.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public UserDisplayPrompt
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void printToDisplay(QString);
    void displaySuccessfullCompileMsg(QString);
    void displayCompileError(QString);
    void displayRuntimeError(QString);
    int displayInputPrompt(int&);

private slots:

    void on_actionOpen_new_triggered();
    void on_actionSave_program_triggered();
    void on_actionRename_triggered();
    void on_actionExit_2_triggered();
    void on_actionCompile_2_triggered();
    void on_actionLaunch_Run_triggered();
    void on_actionLoad_triggered();


private:
    Ui::MainWindow *ui;
    QString currentFile, inputText, outputText, uncompiledCode, compiledCode, text, directory = "";
    QString fileName;
    QString windowTitle;
    QFile compiledFile, uncompiledFile;
    void renameProgram(bool&);
    void displayError(QString);
};

#endif // MAINWINDOW_H
