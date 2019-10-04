#ifndef TRIGONOMETRY_H
#define TRIGONOMETRY_H

#include <string>
#include <QWidget>

namespace Controls
{
namespace Ui {
class Trigonometry;
}

class Trigonometry : public QWidget
{
    Q_OBJECT

signals:
    void ButtonPressed(const std::string& button);

public:
    explicit Trigonometry(QWidget *parent = nullptr);
    ~Trigonometry();

private slots:
    void on_buttonAcos_clicked();
    void on_buttonAsin_clicked();
    void on_buttonAtan_clicked();
    void on_buttonCos_clicked();
    void on_buttonSin_clicked();
    void on_buttonTan_clicked();

private:
    Ui::Trigonometry *ui;
};
}

#endif // TRIGONOMETRY_H
