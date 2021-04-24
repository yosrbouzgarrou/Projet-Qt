#ifndef FENETRE_H
#define FENETRE_H
#include <QDialog>
#include <QString>
#include <QSqlQueryModel>
#include "client.h"
#include "reclamation.h"
#include <QFileDialog>
#include <QTimer>
#include <QTime>
#include <QPainter>
//#include <QSound>
#include <QEventTransition>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class fenetre; }
QT_END_NAMESPACE

class fenetre : public QMainWindow
{
    Q_OBJECT

public:
    fenetre(QWidget *parent = nullptr);
    ~fenetre();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pb_back0_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_6_clicked();

    void on_tableViewc_activated(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_21_clicked();

    void on_pb_back_1_clicked();

    void on_pb_ajouterc_clicked();

    void on_pb_modifierc_clicked();

    void on_pb_supprimerc_clicked();

     void on_pb_ajouterr_clicked();

    void on_pb_supprimerr_clicked();

    void on_pb_modifierr_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_19_clicked();

    void on_tableViewr_activated(const QModelIndex &index);

    void on_pushButton_12_clicked();

    void on_pb_back_2_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_10_clicked();

    void on_pb_ajouterr_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::fenetre *ui;
    Client tempcli;
    Reclamation tempreclam;

};
#endif // FENETRE_H
