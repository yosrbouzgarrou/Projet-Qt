#include "fenetre.h"
#include "ui_fenetre.h"
#include "client.h"
#include "smtp.h"
#include "reclamation.h"
#include <QDate>
#include <QDateEdit>
#include <QLineEdit>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QSystemTrayIcon>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QIntValidator>
#include <QValidator>

fenetre::fenetre(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::fenetre)
{
    ui->setupUi(this);
    ui->comboBox_mail_2->setModel(tempreclam.afficher_email());
    ui->tableViewc->setModel(tempcli.afficher_client());
    ui->tableViewr->setModel(tempreclam.afficher_reclamation());
    ui->lineEdit_id->setValidator(new QIntValidator(1,9999,this));
    ui->lineEdit_tel->setValidator(new QIntValidator(1,99999999, this)); // juste numero
    ui->lineEdit_idr->setValidator(new QIntValidator(1,9999,this));
}


fenetre::~fenetre()
{
    delete ui;
}


void fenetre::on_pushButton_clicked() //client
{
    ui->stackedWidget->setCurrentIndex(1);
}

void fenetre::on_pushButton_2_clicked()  //reclamation
{
    ui->stackedWidget->setCurrentIndex(2);
}

void fenetre::on_pushButton_7_clicked() //Tri coiss client
{
    ui->tableViewc->setModel(tempcli.triercroi());
}

void fenetre::on_pushButton_18_clicked() // tri dec client
{
    ui->tableViewc->setModel(tempcli.trierdec());
}

void fenetre::on_pushButton_6_clicked() //recherche client
{
    int id =ui->lineEdit_id->text().toInt();
    ui->tableViewc->setModel(tempcli.recherche(id));
}

void fenetre::on_tableViewc_activated(const QModelIndex &index) //Afficher client
{
    Client c;
    QString id=ui->tableViewc->model()->data(index).toString();
      QSqlQuery query;
      query.prepare("select * from CLIENT where id LIKE '"+id+"%' or nom LIKE '"+id+"%' or prenom LIKE '"+id+"%'");
      if(query.exec())
      {
        while(query.next())
        {
            ui->lineEdit_id->setText(query.value(0).toString());
            ui->lineEdit_nom->setText(query.value(1).toString());
            ui->lineEdit_prenom->setText(query.value(2).toString());
            ui->lineEdit_adresse->setText(query.value(3).toString());
            ui->lineEdit_tel->setText(query.value(4).toString());
          //ui->dateEdit->setText(query.value(5).toString());
      }
      }
        else
        {

            //QMessageBox::critical(this,tr("error::"),query.lastError().text());
          QMessageBox::critical(nullptr, QObject::tr("error"),
                      QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
      }
}

void fenetre::on_pushButton_4_clicked() //pdf liste clients
{
    QPdfWriter pdf("C:/Users/Dell/Documents/Yasmine/pdfclients.pdf");
                  QPainter painter(&pdf);
                 int i = 4000;
                      painter.setPen(Qt::blue);
                      painter.setFont(QFont("Arial", 25));
                      painter.drawText(950,1100,"Liste Des clients");
                      painter.setPen(Qt::black);
                      painter.setFont(QFont("Arial", 15));
                     // painter.drawText(1100,2000,afficheDC);
                      painter.drawRect(100,100,7300,2600);
                      painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/Dell/Documents/Yasmine/logo.png"));
                      painter.drawRect(0,3000,9600,500);
                      painter.setFont(QFont("Arial", 9));
                      painter.drawText(200,3300,"ID");
                      painter.drawText(1000,3300,"NOM");
                      painter.drawText(2000,3300,"PRENOM");
                      painter.drawText(3500,3300,"ADRESSE");
                      painter.drawText(5000,3300,"TEL");
                      painter.drawText(6500,3300,"DATE");


                      QSqlQuery query;
                      query.prepare("select * from CLIENT");
                      query.exec();
                      while (query.next())
                      {
                          painter.drawText(200,i,query.value(0).toString());
                          painter.drawText(1000,i,query.value(1).toString());
                          painter.drawText(2000,i,query.value(2).toString());
                          painter.drawText(3500,i,query.value(3).toString());
                          painter.drawText(5000,i,query.value(4).toString());
                          painter.drawText(6500,i,query.value(5).toString());


                         i = i + 500;
                      }
                      QMessageBox::information(nullptr, QObject::tr("PDF Enregistré!"),
                                  QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}

void fenetre::on_pushButton_21_clicked() //upload image
{

    QString filename = QFileDialog::getOpenFileName(this,tr("choose"),"",tr("Images(*.jpeg *jpg *.png *.bmp *.gif *.mp4)"));

        if (QString::compare(filename, QString()) !=0)
        {
            QImage image;
            bool valid = image.load(filename);
            if (valid)
            {
            image = image.scaledToWidth(ui->label_3->width(), Qt::SmoothTransformation);
            ui->label_3->setPixmap(QPixmap::fromImage(image));
            }
            else
            {
                ///error handling
            }
            }
}

void fenetre::on_pb_back_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void fenetre::on_pb_ajouterc_clicked() //Ajouter client
{

    int id=ui->lineEdit_id->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString adresse=ui->lineEdit_adresse->text();
    int tel=ui->lineEdit_tel->text().toInt();
    QString date=ui->dateEdit->date().toString();


        Client c(id,nom,prenom,adresse,tel,date);
        bool test=c.ajouter_client();
        if(test)
        {   ui->tableViewc->setModel(tempcli.afficher_client());
            QMessageBox::information(nullptr,QObject::tr("Ajouter un client"),
                                      QObject::tr("Ajout avec succés. \n Click Cancel to exit."),QMessageBox::Cancel);

        }
         else
        {

            QMessageBox::critical(nullptr, QObject::tr("Ajout un client"),
                        QObject::tr("Ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void fenetre::on_pb_modifierc_clicked() //modifier client
{
int id= ui->lineEdit_id->text().toInt();

QString nom =ui->lineEdit_nom->text();
QString prenom =ui->lineEdit_prenom->text();
QString adresse  =ui->lineEdit_adresse->text();
int tel =ui->lineEdit_tel->text().toInt();
QString date =ui->lineEdit_email->text();
bool test=tempcli.modifier_client( id ,nom ,prenom,adresse,tel,date);

 if (test)
 {

     ui->tableViewr->setModel(tempreclam.afficher_reclamation());//refresh
     QMessageBox::information(nullptr, QObject::tr("Modifier une reclamation"),
                 QObject::tr("reclamation modifié.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

 }
 else
     QMessageBox::critical(nullptr, QObject::tr("Modifier une reclamation"),
                 QObject::tr("Erreur !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
}

void fenetre::on_pb_supprimerc_clicked() //supprimer client
{
    int id=ui->lineEdit_id->text().toUInt();
            bool test=tempcli.supprimer_client(id);
            if(test)
            {
                ui->tableViewc->setModel(tempcli.afficher_client());
                QMessageBox::information(nullptr, QObject::tr("Supprimer"),
                QObject::tr("Suppression avec succée"), QMessageBox::Ok);
               // hide();
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Supprimer"),
                QObject::tr("Suppression echouée"), QMessageBox::Ok);
            }
}

void fenetre::on_pb_ajouterr_clicked() //ajouter reclamation
{
    int idr=ui->lineEdit_idr->text().toInt();
    QString nomauteur=ui->lineEdit_nom_r->text();
    QString prenomauteur=ui->lineEdit_prenom_r->text();
    QString reclamationn=ui->lineEditr->text();
    QString datereclamationn=ui->lineEdit->text();
    QString email=ui->lineEdit_email->text();

        Reclamation r(idr,nomauteur,prenomauteur,reclamationn,datereclamationn,email);
        bool test=r.ajouter_reclamation();
        if(test)
        {
            ui->comboBox_mail_2->setModel(tempreclam.afficher_email());
            ui->tableViewr->setModel(tempreclam.afficher_reclamation());
            QMessageBox::information(nullptr,QObject::tr("Ajouter une reclamation"),
                                      QObject::tr("Ajout avec succés. \n Click Cancel to exit."),QMessageBox::Cancel);

        }
         else
        {

            QMessageBox::critical(nullptr, QObject::tr("Ajout une reclaamtion"),
                        QObject::tr("Ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void fenetre::on_pb_supprimerr_clicked() //supprimer reclamation
{
    int id=ui->lineEdit_idr->text().toUInt();
            bool test=tempreclam.supprimer_reclamation(id);
            if(test)
            {
                ui->tableViewr->setModel(tempreclam.afficher_reclamation());
                QMessageBox::information(nullptr, QObject::tr("Supprimer"),
                QObject::tr("Suppression avec succée"), QMessageBox::Ok);
               // hide();
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Supprimer"),
                QObject::tr("Suppression echouée"), QMessageBox::Ok);
            }
}

void fenetre::on_pb_modifierr_clicked() //modifier reclamation
{
    int id= ui->lineEdit_idr->text().toInt();

QString nomauteur =ui->lineEdit_nom_r->text();
QString prenomauteur =ui->lineEdit_prenom_r->text();
QString reclamationn  =ui->lineEditr->text();
QString datereclamationn =ui->lineEdit->text();
QString email =ui->lineEdit_email->text();
  bool test=tempreclam.modifier_reclamation( id ,nomauteur ,prenomauteur,reclamationn,datereclamationn,email);

     if (test)
     {

         ui->tableViewr->setModel(tempreclam.afficher_reclamation());//refresh
         QMessageBox::information(nullptr, QObject::tr("Modifier une reclamation"),
                     QObject::tr("reclamation modifié.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Modifier une reclamation"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void fenetre::on_pushButton_8_clicked() //trier a-z reclamation
{

    ui->tableViewr->setModel(tempreclam.triercroi());
}

void fenetre::on_pushButton_19_clicked() //trier z-a reclamation
{
    ui->tableViewr->setModel(tempreclam.trierdec());
}



void fenetre::on_pb_back_2_clicked() //back lel menu
{
    ui->stackedWidget->setCurrentIndex(0);
}


void fenetre::on_pushButton_10_clicked() //Recherche reclamation
{
    int id =ui->lineEdit_idr->text().toInt();
    ui->tableViewr->setModel(tempreclam.recherche(id));
}

void fenetre::on_pb_ajouterr_2_clicked()
{
    Smtp* smtp = new Smtp("amen.benkhalifaaaaaa@gmail.com","amenamen1234","smtp.gmail.com",465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

       smtp->sendMail("amen.benkhalifaaaaaa@gmail.com",ui->comboBox_mail_2->currentText(),ui->subject_2->text(),ui->msg_2->toPlainText());
}

void fenetre::on_pushButton_3_clicked()
{
        ui->stackedWidget->setCurrentIndex(3);
}
