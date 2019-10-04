#include "trigonometry.h"
#include "ui_trigonometry.h"

using namespace Controls;

Trigonometry::Trigonometry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Trigonometry)
{
    ui->setupUi(this);
}

Trigonometry::~Trigonometry()
{
    delete ui;
}

void Trigonometry::on_buttonAcos_clicked()
{
    emit ButtonPressed("acos");
}

void Trigonometry::on_buttonAsin_clicked()
{
    emit ButtonPressed("asin");
}

void Trigonometry::on_buttonAtan_clicked()
{
    emit ButtonPressed("atan");
}

void Trigonometry::on_buttonCos_clicked()
{
    emit ButtonPressed("cos");
}

void Trigonometry::on_buttonSin_clicked()
{
    emit ButtonPressed("sin");
}

void Trigonometry::on_buttonTan_clicked()
{
    emit ButtonPressed("tan");
}
