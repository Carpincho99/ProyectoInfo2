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
    void on_xPositiveButton_clicked();

    void on_xNegativeButton_clicked();

    void on_yPositiveButton_clicked();

    void on_yNegativeButton_clicked();

    void on_zPositiveButton_clicked();

    void on_zNegativeButton_clicked();

    void on_smallXPositiveButton_clicked();

    void on_smallXNegativeButton_clicked();

    void on_smallYPositiveButton_clicked();

    void on_smallYNegativeButton_clicked();

    void on_smallZPositiveButton_clicked();

    void on_smallZNegativeButton_clicked();

    void on_openClose_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
