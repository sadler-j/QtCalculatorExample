#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void ButtonPressed(const std::string& button);
    void ClearPressed();

    void on_DegreesRadio_clicked(bool checked);
    void on_RadiansRadio_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    bool isDegrees;

    void AddExpression(const std::string& value);
    void Evaluate();
};

#endif // MAINWINDOW_H
