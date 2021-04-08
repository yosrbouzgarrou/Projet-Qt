#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "invite.h"
#include"interview.h"
#include <QMessageBox>
#include<QIntValidator>
#include<QPdfWriter>
#include<QPrinter>
#include<QSqlQuery>
#include<QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 ui->lineEdit_cin->setValidator( new QIntValidator(100, 9999999, this));
 ui->tab_invite->setModel(i.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pb_ajouter_clicked()
{

 int ID_INVITE=ui->lineEdit_cin->text().toInt();
 QString NOM_PRENOM=ui->lineEdit_nom->text();
 QString EMAIL=ui->lineEdit_email->text();
 QString TEL=ui->lineEdit_tel->text();
 invite i (ID_INVITE , NOM_PRENOM ,EMAIL,TEL);
 bool test=i.ajouter();
 QMessageBox msgbox ;
  if (test)
      msgbox.setText("Ajout avec succes.");
  else
      msgbox.setText("Echec d'ajout");
      msgbox.exec();
 ui->tab_invite->setModel(i.afficher());
}

void MainWindow::on_pb_supprimer_clicked()
{
      invite i1; i1.setID_INVITE(ui->lineEdit_cin->text().toInt());
      bool test=i1.supprimer(i1.getID_INVITE());

      QMessageBox msgbox ;
       if (test)
           msgbox.setText("Suppression avec succes.");
       ui->tab_invite->setModel(i.afficher());

}

void MainWindow::on_pb_modifier_clicked()
{

    int ID_INVITE=ui->lineEdit_cin->text().toInt();
    QString NOM_PRENOM=ui->lineEdit_nom->text();
    QString EMAIL=ui->lineEdit_email->text();
    QString TEL=ui->lineEdit_tel->text();
    invite i (ID_INVITE , NOM_PRENOM ,EMAIL,TEL);

     bool test=i.modifier(i.getID_INVITE());
     QMessageBox msgbox ;
      if (test)
          msgbox.setText("Modification avec succes.");
      else
          msgbox.setText("Echec de modification");
          msgbox.exec();
 ui->tab_invite->setModel(i.afficher());
}


void MainWindow::on_pb_recherche_clicked()
{
    QString NOM_PRENOM=ui->lineEdit_rech->text();
    invite i2;
       ui->tab_invite->setModel(i2.recherche(NOM_PRENOM));
}

void MainWindow::on_tri_id_clicked()
{
    invite i3;
    ui->tab_invite->setModel(i3.Tri_id());
}

void MainWindow::on_tri_nom_clicked()
{
    invite i4;
    ui->tab_invite->setModel(i4.Tri_nom());
}

void MainWindow::on_pushButton_25_clicked() // imprimer
{
    invite i5;

}

void MainWindow::on_ajouter_interv_clicked()
{
    QString ID_INTERVIEW=ui->lineEdit_2->text();
    QString NOM_JOURNALISTE=ui->lineEdit_10->text();
    QString DOMAINE=ui->lineEdit_11->text();
    QString DATE=ui->lineEdit_12->text();
    int ID_INVITE=ui->lineEdit_13->text().toInt();
    interview e (ID_INTERVIEW , NOM_JOURNALISTE ,DOMAINE,DATE,ID_INVITE);
    bool test=i.ajouter();
    QMessageBox msgbox ;
     if (test)
         msgbox.setText("Ajout avec succes.");
     else
         msgbox.setText("Echec d'ajout");
         msgbox.exec();
 ui->table_interview->setModel(e.afficher());
}


void MainWindow::on_supprimer_interv_clicked()
{
    interview e1; e1.setID_INTERVIEW(ui->lineEdit_2->text());
    bool test=e1.supprimer(e1.getID_INTERVIEW());

    QMessageBox msgbox ;
     if (test)
         msgbox.setText("Suppression avec succes.");
     ui->table_interview->setModel(e1.afficher());
}

void MainWindow::on_modifier_interv_clicked()
{

    QString ID_INTERVIEW=ui->lineEdit_2->text();
    QString NOM_JOURNALISTE=ui->lineEdit_10->text();
    QString DOMAINE=ui->lineEdit_11->text();
    QString DATE=ui->lineEdit_12->text();
    int ID_INVITE=ui->lineEdit_13->text().toInt();
    interview e (ID_INTERVIEW ,NOM_JOURNALISTE ,DOMAINE,DATE,ID_INVITE);

     bool test=e.modifier(e.getID_INTERVIEW());
     QMessageBox msgbox ;
      if (test)
          msgbox.setText("Modification avec succes.");
      else
          msgbox.setText("Echec de modification");
          msgbox.exec();
 ui->table_interview->setModel(e.afficher());
}

void MainWindow::on_pdf_clicked()
{
    QPdfWriter pdf("C:\Maquette/pdfinterview.pdf");
                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::red);
                          painter.setFont(QFont("Arial", 25));
                          painter.drawText(950,1100,"Liste Des interview");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial", 15));
                        // text
                         painter.drawRect(100,100,7300,2600);
                          painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:\Maquette/logo.png"));
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial", 9));
                          painter.drawText(200,3300,"ID_INTERVIEW");
                          painter.drawText(1600,3300,"NOM_JOURNALISTE");
                          painter.drawText(2100,3300,"DOMAINE");
                          painter.drawText(2100,3300,"DATE");
                          painter.drawText(2100,3300,"ID_INVITE");

                          QSqlQuery query;
                          query.prepare("select * from INTERVIEW");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(200,i,query.value(0).toString());
                              painter.drawText(1300,i,query.value(1).toString());
                              painter.drawText(2100,i,query.value(2).toString());
                               painter.drawText(2100,i,query.value(3).toString());
                              painter.drawText(2100,i,query.value(4).toString());

                             i = i + 500;
                          }
                          QMessageBox::information(nullptr, QObject::tr("PDF Enregistré!"),
                                      QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);


}
