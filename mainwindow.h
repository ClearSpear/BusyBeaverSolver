/* Sicheng Zeng
 * 12/21/2016
 * mainwindow.h
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "sstream"
#include <QMessageBox>
#include "solvingwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    SolvingWindow *sw;

    bool setFromString(int& output, const std::string raw_string, const std::string stringName);

};

#endif // MAINWINDOW_H
