#ifndef NUMBERWIDGET_H
#define NUMBERWIDGET_H

#include <string>
#include <QWidget>

namespace Ui {
class NumberWidget;
}

class NumberWidget : public QWidget
{
    Q_OBJECT

signals:
    void ButtonPressed(const std::string& button);
    void Clear();

public:
    explicit NumberWidget(QWidget *parent = nullptr);
    ~NumberWidget();

private slots:
    void ChildButtonPressed(const std::string& button);
    void ClearPressed(bool);

private:
    Ui::NumberWidget *ui;
};

#endif // NUMBERWIDGET_H
