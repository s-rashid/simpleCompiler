#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void createFile();
    void save();

private:
    Ui::MainWindow *ui;
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QPlainTextEdit *textEdit;
    QString curFile;
};

#endif // MAINWINDOW_H
