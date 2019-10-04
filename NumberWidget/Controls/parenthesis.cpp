#include "parenthesis.h"
#include "ui_parenthesis.h"

using namespace Controls;

Parenthesis::Parenthesis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Parenthesis)
{
    ui->setupUi(this);
}

Parenthesis::~Parenthesis()
{
    delete ui;
}

void Parenthesis::on_buttonStart_clicked()
{
    emit ButtonPressed("(");
}

void Parenthesis::on_buttonEnd_clicked()
{
    emit ButtonPressed(")");
}
