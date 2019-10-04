#ifndef OPERATORS_H
#define OPERATORS_H

#include <QWidget>

namespace Controls
{
namespace Ui {
class Operators;
}

class Operators : public QWidget
{
    Q_OBJECT

signals:
    void ButtonPressed(const std::string& character);

public:
    explicit Operators(QWidget *parent = nullptr);
    ~Operators();

private slots:
    void on_buttonPlus_clicked();
    void on_buttonMinus_clicked();
    void on_buttonTimes_clicked();
    void on_buttonDivide_clicked();
    void on_buttonEquals_clicked();

private:
    Ui::Operators *ui;
};
}

#endif // OPERATORS_H
