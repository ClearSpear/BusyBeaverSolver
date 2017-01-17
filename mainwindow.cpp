/* Sicheng Zeng
 * 12/21/2016
 * mainwindow.cpp
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Busy Beaver Stochastic Solver");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int numStates, targetMin, targetMax;

    std::string raw_numStates = ui->lineEdit_stateNum->text().toStdString();
    if( !setFromString(numStates, raw_numStates, "Number of States") ) return;

    std::string raw_targetMin = ui->lineEdit_targetMin->text().toStdString();
    if( !setFromString(targetMin, raw_targetMin, "Target Minimum") ) return;

    std::string raw_targetMax = ui->lineEdit_targetMax->text().toStdString();
    if( !setFromString(targetMax, raw_targetMax, "Target Maximum") ) return;

    sw = new SolvingWindow(this, numStates, targetMin, targetMax);
    sw->show();
}

/* Throws error when string doesn't convert properly
 * Doesn't affect |output| if raw_string is in an incorrect format
 */
bool MainWindow::setFromString(int& output, const std::string raw_string, const std::string stringName)
{
    int temp;
    std::stringstream ss;
    ss << raw_string;

    // raw_string doesn't start with an integer
    if( !(ss >> temp) )
    {
        std::string errorMessage = "Please enter a number into '" + stringName + "'.";
        QMessageBox::critical(this, tr("ERROR"), QString::fromStdString(errorMessage));
        return false;
    }

    // raw_string contains more text
    std::string trash;
    if( ss >> trash )
    {
        std::string errorMessage = "Please enter a number into '" + stringName + "'.";
        QMessageBox::critical(this, tr("ERROR"), QString::fromStdString(errorMessage));
        return false;
    }

    output = temp;
    return true;
}
