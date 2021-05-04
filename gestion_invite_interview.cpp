#include "gestion_invite_interview.h"
#include "ui_gestion_invite_interview.h"
#include "invite.h"
#include "stmp.h"
#include"interview.h"
#include <QMessageBox>
#include<QIntValidator>
#include<QPdfWriter>
#include<QPrinter>
#include<QSqlQuery>
#include<QPainter>
#include <QtDebug>
Gestion_Invite_Interview::Gestion_Invite_Interview(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gestion_Invite_Interview)
{
    ui->setupUi(this);
    refresh() ;

}

Gestion_Invite_Interview::~Gestion_Invite_Interview()
{
    delete ui;
}
void Gestion_Invite_Interview::refresh(){
ui->tab_invite->setModel(i.afficher()) ;
 ui->idinvite1->setModel (i.afficherid()) ;
 ui->idinvite2->setModel (i.afficherid()) ;
 ui->idinvite4->setModel (i.afficherid()) ;
 ui->idinvite5->setModel (i.afficherid()) ;
 ui->table_interview->setModel(e.afficher());
 ui->idinterview6->setModel (e.afficherid()) ;

 ui->idinterview22->setModel (e.afficherid()) ;
 ui->comboBoxmail->setModel (i.affichermail()) ;
ui->verticalLayout->addWidget(e.stat());
 //ui->verticalLayout->addWidget(e.stat());
}

void Gestion_Invite_Interview::on_ajouter_invite_clicked()
{
    int ID_INVITE=ui->idinvite->text().toInt();
    QString NOM_PRENOM=ui->nominvite->text();
    QString EMAIL=ui->emailinvite->text();
    QString TEL=ui->telinvite->text();
    invite i (ID_INVITE , NOM_PRENOM ,EMAIL,TEL);
    int At = -1, Dot = -1;
     bool test = NULL ;
      // Traverse over the email id
      // string to find position of
      // Dot and At
      for (int i = 0;
           i < EMAIL.length(); i++) {

          // If the character is '@'
          if (EMAIL[i] == '@') {

              At = i;
          }

          // If character is '.'
          else if (EMAIL[i] == '.') {

              Dot = i;
          }
      }

      if (At == -1 || Dot == -1)
      {
          QMessageBox::critical(nullptr, QObject::tr("Verifier vos champs"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

  }
      else{
          test=i.ajouter();
}

    QMessageBox msgbox ;
     if (test)
     {    refresh() ;
     QMessageBox::information(nullptr, QObject::tr("Ajouter un invite"),
                       QObject::tr("invite ajouté.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
     }

}


void Gestion_Invite_Interview::on_supprimeinvite_clicked()
{
    int ref =ui->idinvite1->currentText().toInt();
    int reponse = QMessageBox::question(this, "Interrogatoire", "Voulez-vous supprimer cet invite :\n  " , QMessageBox ::Yes | QMessageBox::No);
if (reponse == QMessageBox::Yes)
{
    bool test=i.supprimer(ref);
    if(test)
    {refresh();//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un invite"),
                    QObject::tr(" paiement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un  invite"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
else if (reponse == QMessageBox::No)
{

}
}

void Gestion_Invite_Interview::on_modifierinvite_clicked()
{
    int ID_INVITE=ui->idinvite2->currentText().toInt();
        QString NOM_PRENOM=ui->nominvite2->text();
        QString EMAIL=ui->emailinvit2->text();
        QString TEL=ui->telinvite2->text();
        invite i (ID_INVITE , NOM_PRENOM ,EMAIL,TEL);

         bool test=i.modifier(ID_INVITE);
         if(test)
         {refresh();//refresh
             QMessageBox::information(nullptr, QObject::tr("Modifier un invite"),
                         QObject::tr(" invite modifier.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier un  invite"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

}

void Gestion_Invite_Interview::on_trieinvite_clicked()
{
    QString mode="DESC";
        if (ui->checkBox_5->checkState()==false)
            mode="ASC";
    ui->tab_invite->setModel(i.trierr(ui->champ_5->currentText(),mode));
}

void Gestion_Invite_Interview::on_pageeee_currentIndexChanged(int index)
{
     ui->stackedWidget_3->setCurrentIndex(index);
}

void Gestion_Invite_Interview::on_lineEdit_9_textChanged(const QString &arg1)
{
    ui->tab_invite->setModel(i.rechercher22(arg1));

}

void Gestion_Invite_Interview::on_ajouter_6_clicked()
{
    QString ID_INTERVIEW=ui->idinterview1->text();
      QString NOM_JOURNALISTE=ui->nominterview->text();
      QString DOMAINE=ui->domaineinterview->text();
      QString DATEE=ui->dateinterview->text();
      int ID_INVITE=ui->idinvite4->currentText().toInt();
      interview e (ID_INTERVIEW , NOM_JOURNALISTE ,DOMAINE,DATEE,ID_INVITE);
      bool test=e.ajouter();
           if(test)
           {refresh();//refresh
               QMessageBox::information(nullptr, QObject::tr("Ajouter un interview"),
                          QObject::tr(" interview ajoute.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

           }
           else
               QMessageBox::critical(nullptr, QObject::tr("Ajouter un interview"),
                           QObject::tr("Erreur !.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

           QSqlQuery query;
           int X=e.verif(ID_INVITE) ;
           if (X>1){
               query.prepare("Update invite set TYPE='VIP'  where ID_INVITE=:id ");
               query.bindValue(":id", ID_INVITE);
               query.exec();
               refresh();
           }





}

void Gestion_Invite_Interview::on_modifier_4_clicked()
{
    QString ID_INTERVIEW=ui->idinterview22->currentText() ;
    QString NOM_JOURNALISTE=ui->nominterview2->text();
    QString DOMAINE=ui->domaineinterview2->text();
    QString DATEE=ui->dateEdit_3->text();
    int ID_INVITE=ui->idinvite5->currentText().toInt();
    interview e (ID_INTERVIEW ,NOM_JOURNALISTE ,DOMAINE,DATEE,ID_INVITE);

     bool test=e.modifier(ID_INTERVIEW);
     if(test)
     {refresh();//refresh
         QMessageBox::information(nullptr, QObject::tr("Ajouter un interview"),
                     QObject::tr(" interview ajoute.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter un interview"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void Gestion_Invite_Interview::on_supprimerintervoew_clicked()
{

    bool test=e.supprimer( ui->idinterview6->currentText() );


    if(test)
    {refresh();//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un interview"),
                    QObject::tr(" interview ajoute.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un interview"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}

void Gestion_Invite_Interview::on_pushButton_14_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->table_interview->model()->rowCount();
        const int columnCount = ui->table_interview->model()->columnCount();

        out <<  "<html>\n"
            "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("voiture")
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            "<table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->table_interview->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->table_interview->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->table_interview->isColumnHidden(column)) {
                    QString data = ui->table_interview->model()->data(ui->table_interview->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

        QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

        QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("INTERVIEW.pdf");
            document->print(&printer);
                             QMessageBox::information(nullptr, QObject::tr("PDF Enregistré!"),
                                         QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}
/**************Mailling******************/

void Gestion_Invite_Interview::sendMail()
{
    Smtp* smtp = new Smtp("aminos.ayari@gmail.com", "taher54160298","smtp.gmail.com",465,3000);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("INVITE", ui->comboBoxmail->currentText(), ui->lineEdit_16->text(),ui->textEdit_2->toPlainText());
}

void Gestion_Invite_Interview::mailSent(QString status)
{
  //  if(status == "Message sent")
    //    QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


void Gestion_Invite_Interview::on_pushButton_15_clicked()
{
        connect(ui->pushButton_15, SIGNAL(clicked()),this, SLOT(sendMail()));
}
