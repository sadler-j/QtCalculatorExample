#ifndef PARENTHESIS_H
#define PARENTHESIS_H

#include <string>
#include <QWidget>

namespace Controls
{
namespace Ui {
class Parenthesis;
}

class Parenthesis : public QWidget
{
    Q_OBJECT

signals:
    void ButtonPressed(const std::string& character);

public:
    explicit Parenthesis(QWidget *parent = nullptr);
    ~Parenthesis();

private slots:
    void on_buttonStart_clicked();

    void on_buttonEnd_clicked();

private:
    Ui::Parenthesis *ui;
};
}

#endif // PARENTHESIS_H
