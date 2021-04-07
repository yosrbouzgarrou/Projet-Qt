#include "dialoghamzaoui.h"
#include "ui_dialoghamzaoui.h"
#include "personnel.h"
#include "journaliste.h"
#include <QMessageBox>
#include <QDate>
#include <QDateEdit>
#include <QLineEdit>
#include <QPrinter>
#include <QPrintDialog>
#include "smtp.h"
#include <QDebug>
#include<QComboBox>
#include <QPieSlice>
#include <QPieSeries>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include"QSortFilterProxyModel"
#include <QPlainTextEdit>
#include <QPlainTextDocumentLayout>


Dialoghamzaoui::Dialoghamzaoui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialoghamzaoui)
{
    ui->setupUi(this);
    ui->comboBox_mail_2->setModel(tmppersonnel.afficher_email());
    ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
    ui->comboBox_2->setModel(tmppersonnel.afficher());
    ui->comboBox_ID_personnel_modifier->setModel(tmppersonnel.afficher());
    ui->comboBox_ID_journaliste_modifier->setModel(tmpjournaliste.afficher());
    ui->tabjournaliste->setModel(tmpjournaliste.afficher());//refresh
}

Dialoghamzaoui::~Dialoghamzaoui()
{
    delete ui;
}
void Dialoghamzaoui::on_pushButton_ajouter_personnel_clicked()
{
    bool test;
        int id= ui->lineEdit_1->text().toInt();
        QString nom= ui->lineEdit_2->text();
        QString prenom=ui->lineEdit_3->text();
        int num_telephone= ui->lineEdit_4->text().toInt();
        int cin= ui->lineEdit_5->text().toInt();
        QString email=ui->lineEdit_6->text();


        if(nom==""|| prenom==""||id==0||cin>99999999||num_telephone==0||tmppersonnel.testemail(email)==false||num_telephone>99999999||cin==0)


                    {
                                  QMessageBox::critical(nullptr, QObject::tr("vide"),
                                  QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
                                  test=false;

                    }
        else{
        personnel p(id,nom,prenom,num_telephone,cin,email);
         test=p.ajouter();}
         if(test)
         {
             ui->comboBox_mail_2->setModel(tmppersonnel.afficher_email());
             ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
             QMessageBox::information(nullptr, QObject::tr("Ajouter un personnel"),
                               QObject::tr("Personnel ajouté.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

             }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Ajouter un personnel"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}





void Dialoghamzaoui::on_pushButton_modifier_personnel_clicked()
{
    int id= ui->comboBox_ID_personnel_modifier->currentText().toInt();
    int num_telephone= ui->lineEdit_21->text().toInt();

  bool test=tmppersonnel. modifier( id,num_telephone );
     if (test)
     {
         ui->comboBox_ID_personnel_modifier->setModel(tmppersonnel.afficher());
         ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Modifier un Personnel"),
                     QObject::tr("Personnel modifié.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Modifier un personnel"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialoghamzaoui::on_pushButton_supprimer_personnel_clicked()
{
    int res1=ui->comboBox_2->currentText().toInt();
            bool test=tmppersonnel.supprimer(res1);
            if(test)
            {   ui->comboBox_2->setModel(tmppersonnel.afficher());
                ui->tabpersonnel->setModel(tmppersonnel.afficher());
                QMessageBox::information(nullptr, QObject::tr("Supprimer une personnel"),
                            QObject::tr("personnel supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Supprimer un personnel"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialoghamzaoui::on_pushButton_rechercher_personnel_clicked()
{
    int id;
    id=ui->lineEdit_13->text().toInt();


   bool test= true;
    if(test==(true))
    {
      ui->tabpersonnel->setModel(tmppersonnel.rechercher(id));
}
}

void Dialoghamzaoui::on_radioButton_tri_personnel_clicked()
{
    ui->tabpersonnel->setModel( tmppersonnel.afficher_tri());
}



void Dialoghamzaoui::on_pushButton_ajouter_journaliste_clicked()
{
    bool test;
        int id= ui->lineEdit_27->text().toInt();
        QString nom= ui->lineEdit_7->text();
        QString prenom=ui->lineEdit_8->text();
        int cin= ui->lineEdit_35->text().toInt();
        int num_tel= ui->lineEdit_28->text().toInt();
        QString domaine= ui->comboBox->currentText();



        if(nom==""|| prenom==""||id==0||cin>99999999||nom.length()>20||num_tel==0||cin==0||num_tel>99999999)


                    {
                                  QMessageBox::critical(nullptr, QObject::tr("vide"),
                                  QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
                                  test=false;

                    }
        else{
        journaliste j(id,nom,prenom,cin,num_tel,domaine);
         test=j.ajouter();}
         if(test)
         {
             ui->comboBox_ID_journaliste_modifier->setModel(tmpjournaliste.afficher());
             ui->tabjournaliste->setModel(tmpjournaliste.afficher());//refresh
             QMessageBox::information(nullptr, QObject::tr("Ajouter un journaliste"),
                               QObject::tr("Journaliste ajouté.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

             }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Ajouter un journaliste"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialoghamzaoui::on_pushButton_modifier_journaliste_clicked()
{
    int id= ui->comboBox_ID_journaliste_modifier->currentText().toInt();
    int num_tel= ui->lineEdit_30->text().toInt();

  bool test=tmpjournaliste.modifier( id,num_tel );
     if (test)
     {
         ui->comboBox_ID_journaliste_modifier->setModel(tmpjournaliste.afficher());
         ui->tabjournaliste->setModel(tmpjournaliste.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Modifier un Journaliste"),
                     QObject::tr("Journaliste modifié.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Modifier un Journaliste"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}


void Dialoghamzaoui::on_pushButton_supprimer_journaliste_clicked()
{
    int res1=ui->comboBox_ID_journaliste->currentText().toInt();
            bool test=tmpjournaliste.supprimer(res1);
            if(test)
            {   ui->comboBox_ID_journaliste->setModel(tmpjournaliste.afficher());
                ui->tabjournaliste->setModel(tmpjournaliste.afficher());
                QMessageBox::information(nullptr, QObject::tr("Supprimer une journaliste"),
                            QObject::tr("Journaliste supprimé.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Supprimer un journaliste"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialoghamzaoui::on_radioButton_id_journaliste_clicked()
{
    ui->tabjournaliste->setModel( tmpjournaliste.afficher_tri());
}

void Dialoghamzaoui::on_pushButton_rechercher_journaliste_clicked()
{
    int id;
    id=ui->lineEdit_14->text().toInt();


   bool test= true;
    if(test==(true))
    {
      ui->tabjournaliste->setModel(tmpjournaliste.rechercher(id));
}
}

void Dialoghamzaoui::on_pushButton_Mail_2_clicked()
{
    Smtp* smtp = new Smtp("amen.benkhalifaaaaaa@gmail.com","amenamen1234","smtp.gmail.com",465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

       smtp->sendMail("amen.benkhalifaaaaaa@gmail.com",ui->comboBox_mail_2->currentText(),ui->subject_2->text(),ui->msg_2->toPlainText());
}

void Dialoghamzaoui::on_pushButton_imprimer_employe_clicked()
{
    //QDateTime datecreation = date.currentDateTime();
        //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
               QPdfWriter pdf("C:/Users/Midou/Desktop/hamzaoui/Pdf.pdf");
               QPainter painter(&pdf);
              int i = 4000;
                   painter.setPen(Qt::blue);
                   painter.setFont(QFont("Arial", 30));
                   painter.drawText(1100,1200,"Liste Des Personnels ");
                   painter.setPen(Qt::black);
                   painter.setFont(QFont("Arial", 50));
                  // painter.drawText(1100,2000,afficheDC);
                   painter.drawRect(100,100,7300,2600);
                   //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                   painter.drawRect(0,3000,9600,500);
                   painter.setFont(QFont("Arial", 9));
                   painter.drawText(200,3300,"ID");
                   painter.drawText(1700,3300,"NOM");
                   painter.drawText(3200,3300,"PRENOM");
                   painter.drawText(4900,3300,"NUMTEL");
                   painter.drawText(6600,3300,"CIN");
                   painter.drawText(8100,3300,"EMAIL");
                   QSqlQuery query;
                   query.prepare("select * from PERSONNEL");
                   query.exec();
                   while (query.next())
                   {
                       painter.drawText(200,i,query.value(0).toString());
                       painter.drawText(1700,i,query.value(1).toString());
                       painter.drawText(3200,i,query.value(2).toString());
                       painter.drawText(4900,i,query.value(3).toString());
                       painter.drawText(6600,i,query.value(4).toString());
                       painter.drawText(8100,i,query.value(5).toString());
                      i = i + 500;
                   }
                   int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                       if (reponse == QMessageBox::Yes)
                       {
                           QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Midou/Desktop/hamzaoui/Pdf.pdf"));
                           painter.end();
                       }
                       if (reponse == QMessageBox::No)
                       {
                            painter.end();
                       }

}
