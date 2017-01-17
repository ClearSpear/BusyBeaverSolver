#include "solvingwindow.h"
#include "ui_solvingwindow.h"

SolvingWindow::SolvingWindow(QWidget *parent, int numStates, int targetMin, int targetMax):
    QDialog(parent),
    ui(new Ui::SolvingWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Solving Window");

    this->numStates = numStates;
    this->targetMin = targetMin;
    this->targetMax = targetMax;

    ui->label_numStates->setText("Number of States: " + QString::number(numStates));
    ui->label_targetMin->setText("Target minimum: " + QString::number(targetMin));
    ui->label_targetMax->setText("Target maximum: " +QString::number(targetMax));
}

SolvingWindow::~SolvingWindow()
{
    delete ui;
}

void SolvingWindow::getSolution()
{
    BusyBeaver bb(numStates, targetMin, targetMax);

    int counter = 0;
    do
    {
        bb.tm.reset();
        bb.setRandomInstructions();
        counter++;
        if( counter % 10000 == 0 )
        {
            std::cout << counter << std::endl;
            if( ui->dial->value() >= 99 )
            {
                ui->dial->setValue(0);
            }
            else
            {
                ui->dial->setValue(ui->dial->value()+1);
            }
        }
    }
    while( !bb.testSolution() );

    std::string solution =  bb.tm.toStringInstructions() + "\nOnes: " + std::to_string(bb.tm.getOnes()) + "\n" + bb.tm.toStringPaper();

    ui->textBrowser->setText(QString::fromStdString(solution));
}

void SolvingWindow::on_pushButton_clicked()
{
    getSolution();
}
