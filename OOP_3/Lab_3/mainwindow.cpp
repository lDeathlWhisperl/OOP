#include "mainwindow.h"
#include "Polynom.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    polynom = new Polynom();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete polynom;
}


void MainWindow::on_Btn_A_clicked()
{
    number a(ui->LE_A_1->text().toDouble(), ui->LE_A_2->text().toDouble());
    number b = polynom->getB();
    number c = polynom->getC();

    polynom->setA(a);
    polynom->setB(b);
    polynom->setC(c);

    QString str;
    str << *polynom;
    ui->L_Equation->setText(str);
}


void MainWindow::on_Btn_B_clicked()
{
    number a = polynom->getA();
    number b(ui->LE_B_1->text().toDouble(), ui->LE_B_2->text().toDouble());
    number c = polynom->getC();

    polynom->setA(a);
    polynom->setB(b);
    polynom->setC(c);

    QString str;
    str << *polynom;
    ui->L_Equation->setText(str);
}


void MainWindow::on_Btn_C_clicked()
{
    number a = polynom->getA();
    number b = polynom->getB();
    number c(ui->LE_C_1->text().toDouble(), ui->LE_C_2->text().toDouble());

    polynom->setA(a);
    polynom->setB(b);
    polynom->setC(c);

    QString str;
    str << *polynom;
    ui->L_Equation->setText(str);
}


void MainWindow::on_Btn_Solve_clicked()
{
    ui->L_Solvation->setText(polynom->solve());
}


void MainWindow::on_Btn_X_clicked()
{
    QString str;
    str << polynom->solve(ui->LE_X->text().toDouble());
    ui->L_X->setText(str);
}

