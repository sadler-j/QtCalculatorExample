#ifndef NUMBERPAD_H
#define NUMBERPAD_H

#include <string>
#include <QWidget>

namespace Controls
{
namespace Ui {
class NumberPad;
}

class NumberPad : public QWidget
{
    Q_OBJECT

signals:
    void ButtonPressed(const std::string& button);

public:
    explicit NumberPad(QWidget *parent = nullptr);
    ~NumberPad();

private slots:
    void on_buttonDecimal_clicked();
    void on_button0_clicked();
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();
    void on_button5_clicked();
    void on_button6_clicked();
    void on_button7_clicked();
    void on_button8_clicked();
    void on_button9_clicked();

private:
    Ui::NumberPad *ui;
};
}

#endif // NUMBERPAD_H
