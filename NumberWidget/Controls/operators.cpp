#include "operators.h"
#include "ui_operators.h"

#include "QShortcut"

using namespace Controls;

Operators::Operators(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Operators)
{
    ui->setupUi(this);

    QShortcut* returnSignal = new QShortcut(QKeySequence("Enter"), this);
    QShortcut* enterSignal = new QShortcut(QKeySequence("Return"), this);

    connect(returnSignal, SIGNAL(activated()),
            this, SLOT(on_buttonEquals_clicked()));
    connect(enterSignal, SIGNAL(activated()),
            this, SLOT(on_buttonEquals_clicked()));
}

Operators::~Operators()
{
    delete ui;
}

void Operators::on_buttonPlus_clicked()
{
    emit ButtonPressed("+");
}

void Operators::on_buttonMinus_clicked()
{
    emit ButtonPressed("-");
}

void Operators::on_buttonTimes_clicked()
{
    emit ButtonPressed("*");
}

void Operators::on_buttonDivide_clicked()
{
    emit ButtonPressed("/");
}

void Operators::on_buttonEquals_clicked()
{
    emit ButtonPressed("=");
}
