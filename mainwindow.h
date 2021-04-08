#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"invite.h"
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

     void on_pb_ajouter_clicked();





     void on_pb_supprimer_clicked();

     void on_pb_modifier_clicked();

     void on_pb_recherche_clicked();

     void on_tri_id_clicked();

     void on_tri_nom_clicked();

     void on_pushButton_25_clicked();

     void on_ajouter_interv_clicked();

     void on_supprimer_interv_clicked();

     void on_modifier_interv_clicked();

     void on_pdf_clicked();

private:
    Ui::MainWindow *ui;
    invite i ;
};
#endif // MAINWINDOW_H
