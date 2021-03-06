
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "materiel.h"
#include "fourniture.h"
#include "notification.h"
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=a.connect_arduino();
    switch(ret)
    {
    case(0):qDebug()<<"arduino is available and connecyed to :"<<a.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is availble but not connected to :"<<a.getarduino_port_name();
        break;
     case(-1):qDebug()<<"arduino is not availble";
    }
    QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
    ui->tableView_2->setModel(tempmateriel.afficher_materiel());
    ui->tableView->setModel(tmpfourniture.afficher());//refresh


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_14_clicked()//AJOUTER MATERIEL
{

    notification n;
    bool test;
int code= ui->lineEdit_code->text().toInt();
        QString nom= ui->lineEdit_nom_2->text();
         QString ref=ui->lineEdit_ref->text();
        QString type=ui->lineEdit_type->text();
        QString quantite=ui->lineEdit_quantite->text();


        if(nom==""|| quantite==""||type==""||code==0||nom.length()>10)


                    {
                                  QMessageBox::critical(nullptr, QObject::tr("vide"),
                                  QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
                                  test=false;

                    }
        else{
        materiel m(code,nom,ref,type,quantite);

         test=m.ajouter_materiel();}
         if(test)
         {
             n.setPopupText("Materiel  a été ajouté");
                         n.show();
                         mysystem->showMessage(tr("Notification"),tr("Il y a un ajout d'un Materiel "));
             ui->tableView->setModel(tempmateriel.afficher_materiel());//refresh
             QMessageBox::information(nullptr, QObject::tr("Ajouter un materiel"),
                               QObject::tr("materiel ajouté.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

             }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Ajouter un materiel"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_16_clicked()     //SUPPRIMER MATERIEL
{
    notification n;
    int code= ui->lineEdit_code->text().toInt();

        bool test=tempmateriel.supprimer_materiel(code);

        if(test)
        {
            n.setPopupText("Materiel  a été supprimé");
                        n.show();
                        mysystem->showMessage(tr("Notification"),tr("Il y a une supression d'un Materiel "));

            ui->tableView->setModel(tempmateriel.afficher_materiel());//refresh

            QMessageBox::information(nullptr, QObject::tr("Supprimer materiel"),
                        QObject::tr("materiel supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer materiel"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_15_clicked() //MODIFIER MATERIEL
{

    notification n;
    int code=ui->lineEdit_code->text().toInt();




     bool test=tempmateriel.modifier_materiel( code );
        if (test)

        {
            n.setPopupText("Materiel  a été modifié");
                        n.show();
                        mysystem->showMessage(tr("Notification"),tr("Il y a une modification d'un Materiel "));


            ui->tableView->setModel(tempmateriel.afficher_materiel());//refresh
            QMessageBox::information(nullptr, QObject::tr("Modifier un materiel"),
                        QObject::tr("materiel modifié.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier un materiel"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}











void MainWindow::on_pushButton_8_clicked()//MODIFIER FOURNITURE
{
    notification n;

    int ref= ui->lineEdit_ref_2->text().toInt();
    QString loc=ui->lineEdit_loc->text();

  bool test=tmpfourniture. modifier( ref,loc );
     if (test)
     {
         n.setPopupText("Fourniture  a été modifié");
                      n.show();
                      mysystem->showMessage(tr("Notification"),tr("Il y a une modification d'un Fourniture "));


         ui->tableView->setModel(tmpfourniture.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Modifier un fourniture"),
                     QObject::tr("Fourniture modifié.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Modifier un fourniture"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_9_clicked()
{
    notification n;
    int ref= ui->lineEdit_ref_2->text().toInt();

        bool test=tmpfourniture.supprimer(ref);

        if(test)
        {
            n.setPopupText("Fourniture  a été supprimé");
                         n.show();
                         mysystem->showMessage(tr("Notification"),tr("Il y a une supression d'un Fourniture "));

            ui->tableView->setModel(tmpfourniture.afficher());//refresh

            QMessageBox::information(nullptr, QObject::tr("Supprimer fourniture"),
                        QObject::tr("fourniture supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer fourniture"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_radioButton_clicked()
{
    ui->tableView->setModel( tmpfourniture.afficher_tri());
}

void MainWindow::on_pushButton_6_clicked()
{
    int ref;
    ref=ui->lineEdit->text().toInt();


   bool test= true;
    if(test==(true))
    {
      ui->tableView->setModel(tmpfourniture.rechercher(ref));
}
}

void MainWindow::on_pushButton_10_clicked()
{
    int ref;
    ref=ui->lineEdit->text().toInt();


   bool test= true;
    if(test==(true))
    {
      ui->tableView->setModel(tempmateriel.rechercher(ref));
}
}


void MainWindow::on_radioButton_2_clicked()
{
     ui->tableView->setModel( tempmateriel.afficher_tri());
}

void MainWindow::on_pushButton_11_clicked()
{

        ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_3_clicked()
{

        ui->stackedWidget->setCurrentIndex(0);


}

void MainWindow::on_pushButton_17_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_4_clicked()//PDF FOURNITURE
{
    QPdfWriter pdf("C:/Users/user/Music/SMARTNEWSAGENCY_INESHOSNI_2A15/fourniture.pdf");
                  QPainter painter(&pdf);
                 int i = 4000;
                      painter.setPen(Qt::blue);
                      painter.setFont(QFont("Arial", 25));
                      painter.drawText(950,1100,"Liste Des fournitures");
                      painter.setPen(Qt::black);
                      painter.setFont(QFont("Arial", 15));
                     // painter.drawText(1100,2000,afficheDC);
                      painter.drawRect(100,100,7300,2600);
                      painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/user/Music/SMARTNEWSAGENCY_INESHOSNI_2A15/logo.png"));
                      painter.drawRect(0,3000,9600,500);
                      painter.setFont(QFont("Arial", 9));
                      painter.drawText(200,3300,"LOC");
                      painter.drawText(1600,3300,"REF");
                      painter.drawText(2100,3300,"NOM");
                      painter.drawText(3200,3300,"TYPE");




                      QSqlQuery query;
                      query.prepare("select * from FOURNITURE");
                      query.exec();
                      while (query.next())
                      {
                          painter.drawText(200,i,query.value(0).toString());
                          painter.drawText(1300,i,query.value(1).toString());
                          painter.drawText(2100,i,query.value(2).toString());
                          painter.drawText(3200,i,query.value(3).toString());




                         i = i + 500;
                      }
                      QMessageBox::information(nullptr, QObject::tr("PDF Enregistré!"),
                                  QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    QString code=ui->tableView_2->model()->data(index).toString();
      QSqlQuery query;
      query.prepare("select * from gestion"
"materiel where code LIKE '"+code+"%' or nom LIKE '"+code+"%' or type LIKE '"+code+"%'");
      if(query.exec())
      {
        while(query.next())
        {
            ui->lineEdit_code->setText(query.value(0).toString());
            ui->lineEdit_ref->setText(query.value(1).toString());
            ui->lineEdit_nom_2->setText(query.value(2).toString());
            ui->lineEdit_type->setText(query.value(3).toString());
            ui->lineEdit_quantite->setText(query.value(4).toString());
        }
      }


}

void MainWindow::on_pushButton_ajouter_clicked()//AJOUTER FOURNITRE
{
    notification n;
    bool test;

        QString nom= ui->lineEdit_nom->text();
        QString loc=ui->lineEdit_loc->text();
        int ref= ui->lineEdit_ref_2->text().toInt();
        QString type=ui->lineEdit_type_2->text();


        if(nom==""|| loc==""||type==""||ref==0||nom.length()>10)


                    {
                                  QMessageBox::critical(nullptr, QObject::tr("vide"),
                                  QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
                                  test=false;

                    }
        else{
        fourniture f(ref,nom,loc,type);

         test=f.ajouter();}
         if(test)
         { n.setPopupText("Fourniture  a été ajouté");
             n.show();
             mysystem->showMessage(tr("Notification"),tr("Il y a un ajout d'un Fourniture "));

             ui->tableView->setModel(tmpfourniture.afficher());//refresh
             QMessageBox::information(nullptr, QObject::tr("Ajouter un fourniture"),
                               QObject::tr("Fourniture ajouté.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

             }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Ajouter un fourniture"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::update_label()
{
    dataa =a.read_from_arduino();
    qDebug() <<"dat = " << dataa ;
    if(dataa=="B")
    {
       ui->label_etat->setText("gaz non detecte");
    }
    else if(dataa=="A")
       ui->label_etat->setText("gaz détecté");
}

void MainWindow::on_pushButton_7_clicked()
{
    a.write_to_arduino("B");
}

void MainWindow::on_pushButton_18_clicked()
{
    a.write_to_arduino("C");
}


