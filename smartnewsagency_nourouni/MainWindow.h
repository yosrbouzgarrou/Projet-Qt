#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include <QDialog>
#include <QString>
#include <QSqlQueryModel>
#include "publicite.h"
#include "collaboration.h"
#include"notif.h"
#include <QFileDialog>
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QSound>
#include <QEventTransition>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>
#include "arduino.h"
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
    void on_ajouter_pub_clicked();

    void on_supprimer_pub_clicked();

    void on_modifier_pub_clicked();

    void on_imprimer_pub_clicked();

    void on_pdf_pub_clicked();

    void on_back_pub_clicked();

    void on_back_collab_clicked();

    void on_publicite_clicked();

    void on_collab_clicked();

    void on_pushButton_6_clicked();

    //void on_frame_2_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_21_clicked();


    void on_radioButton_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_recherche_publicite_clicked();

    void on_radioButton_2_clicked();
    void on_refresh_clicked();
void on_pushButton_17_clicked();



void on_pushButton_stat_clicked();


void on_pushButton_Mail_2_clicked();

void on_pushButton_18_clicked();

void on_pushButton_19_clicked();

void on_pushButton_11_clicked();

void on_recette_clicked();

void on_radioButton_3_clicked();

private:
    Ui::MainWindow *ui;
    publicite temppublicite;
    collaboration tempcollaboration;
    arduino ar;
    notif N;
};
#endif // MainWindow_H
