#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qmessagebox.h"
#include "qradiobutton.h"

#include "Compute/expression.h"
#include "Compute/Exceptions/computeexception.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    isDegrees = ui->DegreesRadio->isChecked();

    connect(ui->ButtonPad, SIGNAL(ButtonPressed(std::string)),
            this, SLOT(ButtonPressed(std::string)));
    connect(ui->ButtonPad, SIGNAL(Clear()),
            this, SLOT(ClearPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ButtonPressed(const std::string &button)
{
    if (button == "=")
        Evaluate();
    else
        AddExpression(button);
}

void MainWindow::ClearPressed()
{
    ui->lineEdit->setText("0");
}

void MainWindow::on_DegreesRadio_clicked(bool checked)
{
    isDegrees = checked;
}

void MainWindow::on_RadiansRadio_clicked(bool checked)
{
    isDegrees = !checked;
}

void MainWindow::AddExpression(const std::string &value)
{
    QString display {ui->lineEdit->text()};

    if (display == '0')
        display = QString();

    display += QString::fromStdString(value);

    if (value.size() > 1)
        display += '(';

    ui->lineEdit->setText(display);
}

void MainWindow::Evaluate()
{
    try
    {
        const std::string phrase {ui->lineEdit->text().toStdString()};
        const Compute::Expression expression {Compute::Expression::Build(phrase)};

        Compute::EvaluationSettings settings;
        settings.IsRadians(!isDegrees);

        ui->lineEdit->setText(QString::number(expression.Evaluate(settings)));
    }
    catch (Compute::Exceptions::ComputeException exception)
    {
        QMessageBox messageBox;
        messageBox.setText("Error");
        messageBox.setInformativeText(exception.what());
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.setDefaultButton(QMessageBox::Ok);
        messageBox.exec();
    }
}
