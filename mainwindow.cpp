#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

double num_first;
const double PI = 3.14159265358979;
const double exp1 = 2.7182818284590;

double fact(double num) {
    double res = 1;
    for (double i {num}; i > 0; i--) {
        res *= i;
    }

    return res;
}

QString bin(double num) {
    if (num == 0) return "0";

    // Обработка целой части числа
    long long intPart = static_cast<long long>(num);
    QString binStr = "";
    while (intPart > 0) {
        binStr.prepend(QString::number(intPart % 2));
        intPart /= 2;
    }

    // Обработка дробной части числа
    double fracPart = num - static_cast<long long>(num);
    if (fracPart > 0) {
        binStr.append('.'); // Десятичный разделитель
        int precision = 20; // Ограничение на количество знаков после запятой
        while (fracPart > 0 && precision > 0) {
            fracPart *= 2;
            if (fracPart >= 1) {
                binStr.append('1');
                fracPart -= 1;
            } else {
                binStr.append('0');
            }
            --precision;
        }
    }

    return binStr.isEmpty() ? "0" : binStr;
}

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits()));

    connect(ui->pushButton_plusminus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_perc, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_ctg, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_pi, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_e, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_fact, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_bin, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_dif, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(math_operations()));

    connect(ui->pushButton_eq, SIGNAL(clicked()), this, SLOT(on_pushButton_eq_clicked()));
    connect(ui->pushButton_ac, SIGNAL(clicked()), this, SLOT(on_pushButton_ac_clicked()));

    ui->pushButton_mul->setCheckable(true);
    ui->pushButton_dif->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_div->setCheckable(true);
}

MainWindow::~MainWindow()
{

}

void MainWindow::digits() {
    QPushButton *button = (QPushButton *)sender();

    double numbers;
    QString new_label;

    if (ui->monitor->text().contains(".") && button->text() == "0") {
        new_label = ui->monitor->text() + button->text();
    } else {
        numbers = (ui->monitor->text() + button->text()).toDouble();
        new_label = QString::number(numbers, 'g', 15);
    }

    ui->monitor->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (!ui->monitor->text().contains('.')) {
        ui->monitor->setText(ui->monitor->text() + '.');
    }
}

void MainWindow::operations() {
    QPushButton *button = (QPushButton *)sender();

    double numbers;
    QString new_label;

    if (button->text() == "+/-") {
        numbers = (ui->monitor->text().toDouble());
        numbers *= -1;

        new_label = QString::number(numbers, 'g', 15);

        ui->monitor->setText(new_label);
    } else if (button->text() == "%") {
        numbers = (ui->monitor->text().toDouble());
        numbers *= 0.01;

        new_label = QString::number(numbers, 'g', 15);

        ui->monitor->setText(new_label);
    } else if (button->text() == "cos") {
        numbers = (ui->monitor->text().toDouble());
        numbers = cos(numbers);

        new_label = QString::number(numbers, 'g', 15);

        ui->monitor->setText(new_label);
    } else if (button->text() == "sin") {
        numbers = (ui->monitor->text().toDouble());
        numbers = sin(numbers);

        new_label = QString::number(numbers, 'g', 15);

        ui->monitor->setText(new_label);

    } else if (button->text() == "tan") {
        numbers = (ui->monitor->text().toDouble());
        numbers = tan(numbers);

        new_label = QString::number(numbers, 'g', 15);

        ui->monitor->setText(new_label);

    } else if (button->text() == "ctg") {
        numbers = (ui->monitor->text().toDouble());
        numbers = cos(numbers) / sin(numbers);

        new_label = QString::number(numbers, 'g', 15);

        ui->monitor->setText(new_label);

    } else if (button->text() == "log") {
        numbers = (ui->monitor->text().toDouble());
        numbers = log10(numbers);

        new_label = QString::number(numbers, 'g', 15);

        ui->monitor->setText(new_label);

    } else if (button->text() == "ln") {
        numbers = (ui->monitor->text().toDouble());
        numbers = log(numbers);

        new_label = QString::number(numbers, 'g', 15);

        ui->monitor->setText(new_label);

    } else if (button->text() == "π") {
        numbers = PI;

        new_label = QString::number(numbers, 'g', 15);

        ui->monitor->setText(new_label);

    } else if (button->text() == "e") {
        numbers = exp1;

        new_label = QString::number(numbers, 'g', 15);

        ui->monitor->setText(new_label);

    } else if (button->text() == "x!") {
        numbers = (ui->monitor->text().toDouble());
        numbers = fact(numbers);

        new_label = QString::number(numbers, 'g', 15);

        ui->monitor->setText(new_label);

    } else if (button->text() == "√") {
        numbers = (ui->monitor->text().toDouble());
        numbers = sqrt(numbers);

        new_label = QString::number(numbers, 'g', 15);

        ui->monitor->setText(new_label);

    } else if (button->text() == "bin") {
        numbers = (ui->monitor->text().toDouble());

        new_label = bin(numbers);

        ui->monitor->setText(new_label);
    }
}

void MainWindow::on_pushButton_eq_clicked()
{
    double LabelNumber, num_second;
    QString new_label;

    num_second = ui->monitor->text().toDouble();

    if (ui->pushButton_plus->isChecked()) {
        LabelNumber = num_first + num_second;
        new_label = QString::number(LabelNumber, 'g', 15);

        ui->monitor->setText(new_label);
        ui->pushButton_plus->setChecked(false);

    } else if (ui->pushButton_dif->isChecked()) {
        LabelNumber = num_first - num_second;
        new_label = QString::number(LabelNumber, 'g', 15);

        ui->monitor->setText(new_label);
        ui->pushButton_dif->setChecked(false);
    } else if (ui->pushButton_div->isChecked()) {
        if (num_second == 0) {
            ui->monitor->setText("-0");
        } else {
            LabelNumber = num_first / num_second;
            new_label = QString::number(LabelNumber, 'g', 15);

            ui->monitor->setText(new_label);
        }
        ui->pushButton_div->setChecked(false);
    } else if (ui->pushButton_mul->isChecked()) {
        LabelNumber = num_first * num_second;
        new_label = QString::number(LabelNumber, 'g', 15);

        ui->monitor->setText(new_label);
        ui->pushButton_mul->setChecked(false);
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();

    num_first = ui->monitor->text().toDouble();
    ui->monitor->setText("");

    button->setChecked(true);
}

void MainWindow::on_pushButton_ac_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_dif->setChecked(false);
    ui->pushButton_div->setChecked(false);
    ui->pushButton_mul->setChecked(false);

    ui->monitor->setText("0");
}
