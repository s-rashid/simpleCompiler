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
#include "controller/displayerrorprompt.h"
#include "controller/manageprogcontrol.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public DisplayErrorPrompt
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displayError(QString);

private slots:

    /*void on_actionSave_triggered();
    void on_actionLoad_triggered();
    void on_actionCompile_triggered();
    void on_actionRun_triggered();
    void on_actionExit_triggered();
    void on_actionClear_triggered();
    void on_actionNew_triggered();
    void on_actionRename_File_triggered();
*/


    void on_actionOpen_new_triggered();

    void on_actionSave_program_triggered();

    void on_actionRename_triggered();

    void on_actionExit_2_triggered();

    void on_actionCompile_2_triggered();

    void on_actionLaunch_Run_triggered();



private:
    Ui::MainWindow *ui;
    QString currentFile, inputText, outputText, uncompiledCode, compiledCode, text, directory = "";
    QString fileName;
    QString windowTitle;
    QFile compiledFile, uncompiledFile;
    bool ok;
    void renameProgram();
};

#endif // MAINWINDOW_H
