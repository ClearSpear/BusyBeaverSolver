#ifndef SOLVINGWINDOW_H
#define SOLVINGWINDOW_H

#include <QDialog>
#include "busybeaver.h"

namespace Ui {
class SolvingWindow;
}

class SolvingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SolvingWindow(QWidget *parent = 0, int numStates = 1, int targetMin=0, int targetMax=0);
    ~SolvingWindow();
    void getSolution();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SolvingWindow *ui;
    int numStates, targetMin, targetMax;
};

#endif // SOLVINGWINDOW_H
