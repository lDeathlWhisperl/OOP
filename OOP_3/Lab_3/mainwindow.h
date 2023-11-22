#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Btn_A_clicked();

    void on_Btn_B_clicked();

    void on_Btn_C_clicked();

    void on_Btn_Solve_clicked();

    void on_Btn_X_clicked();

private:
    Ui::MainWindow *ui;
    class Polynom *polynom;
};

#endif // MAINWINDOW_H
