#include "numberpad.h"
#include "ui_numberpad.h"

using namespace Controls;

NumberPad::NumberPad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NumberPad)
{
    ui->setupUi(this);
}

NumberPad::~NumberPad()
{
    delete ui;
}

void NumberPad::on_buttonDecimal_clicked()
{
    emit ButtonPressed(".");
}

void NumberPad::on_button0_clicked()
{
    emit ButtonPressed("0");
}

void NumberPad::on_button1_clicked()
{
    emit ButtonPressed("1");
}

void NumberPad::on_button2_clicked()
{
    emit ButtonPressed("2");
}

void NumberPad::on_button3_clicked()
{
    emit ButtonPressed("3");
}

void NumberPad::on_button4_clicked()
{
    emit ButtonPressed("4");
}

void NumberPad::on_button5_clicked()
{
    emit ButtonPressed("5");
}

void NumberPad::on_button6_clicked()
{
    emit ButtonPressed("6");
}

void NumberPad::on_button7_clicked()
{
    emit ButtonPressed("7");
}

void NumberPad::on_button8_clicked()
{
    emit ButtonPressed("8");
}

void NumberPad::on_button9_clicked()
{
    emit ButtonPressed("9");
}
