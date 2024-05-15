#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

template <class T>
class SmartPointer {
public:
    SmartPointer(T* ptr = nullptr) : ptr(ptr) {}
    ~SmartPointer() {
        delete ptr;
    }
    T* operator->() {
        return ptr;
    }
    T& operator*() {
        return *ptr;
    }
private:
    T* ptr;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    SmartPointer<Ui::MainWindow> ui;
private slots:
            void digits();
    void on_pushButton_dot_clicked();
    void operations();
    void on_pushButton_eq_clicked();
    void math_operations();
    void on_pushButton_ac_clicked();
};
#endif // MAINWINDOW_H
