
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "materiel.h"
#include "fourniture.h"

#include <QDialog>
#include <QString>
#include <QSqlQueryModel>
#include <QFileDialog>
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QSound>
#include <QEventTransition>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>
#include"arduino.h"

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

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();
    void on_pushButton_17_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_radioButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_tableView_2_activated(const QModelIndex &index);
    void on_pushButton_7_clicked();

    void on_pushButton_18_clicked();
    void update_label();


private:
    arduino a;
    QString dataa;
    Ui::MainWindow *ui;
    materiel tempmateriel;
    fourniture tmpfourniture;
     QSystemTrayIcon *mysystem;
};
#endif // MAINWINDOW_H
