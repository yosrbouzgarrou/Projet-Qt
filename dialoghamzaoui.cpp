#include "dialoghamzaoui.h"
#include"notificationham.h"
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
#include<QMediaPlayer>

QT_CHARTS_USE_NAMESPACE
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
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sounds/click.mp3"));
}

Dialoghamzaoui::~Dialoghamzaoui()
{
    delete ui;
}
void Dialoghamzaoui::on_pushButton_ajouter_personnel_clicked()
{sound->play();
    bool test;
        int id= ui->lineEdit_1->text().toInt();
        QString nom= ui->lineEdit_2->text();
        QString prenom=ui->lineEdit_3->text();
        int num_telephone= ui->lineEdit_4->text().toInt();
        int cin= ui->lineEdit_5->text().toInt();
        QString email=ui->lineEdit_6->text();
        int salaire= ui->lineEdit_9->text().toInt();


        if(nom==""|| prenom==""||id==0||cin>99999999||num_telephone==0||tmppersonnel.testemail(email)==false||num_telephone>99999999||cin==0)


                    {
                                  QMessageBox::critical(nullptr, QObject::tr("vide"),
                                  QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
                                  test=false;

                    }
        else{
        personnel p(id,nom,prenom,num_telephone,cin,email,salaire);
         test=p.ajouter();}
        N.notification_ajoutpersonnel();
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
{sound->play();
    int id= ui->comboBox_ID_personnel_modifier->currentText().toInt();
    int num_telephone= ui->lineEdit_21->text().toInt();
    int salaire= ui->lineEdit_22->text().toInt();


  bool test=tmppersonnel. modifier( id,num_telephone,salaire );
   N.notification_modifierpersonnel();
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
{sound->play();
    int res=ui->comboBox_2->currentText().toInt();
            bool test=tmppersonnel.supprimer(res);
            N.notification_supprimerpersonnel();
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
{sound->play();
    int id;
    id=ui->lineEdit_13->text().toInt();


   bool test= true;
    if(test==(true))
    {
      ui->tabpersonnel->setModel(tmppersonnel.rechercher(id));
}
}

void Dialoghamzaoui::on_radioButton_tri_personnel_clicked()
{sound->play();
    ui->tabpersonnel->setModel( tmppersonnel.afficher_tri());
}



void Dialoghamzaoui::on_pushButton_ajouter_journaliste_clicked()
{sound->play();
    bool test;
        int id= ui->lineEdit_27->text().toInt();
        QString nom= ui->lineEdit_7->text();
        QString prenom=ui->lineEdit_8->text();
        int cin= ui->lineEdit_35->text().toInt();
        int num_tel= ui->lineEdit_28->text().toInt();
        QString domaine= ui->comboBox->currentText();

 int salaire= ui->lineEdit_10->text().toInt();

        if(nom==""|| prenom==""||id==0||cin>99999999||nom.length()>20||num_tel==0||cin==0||num_tel>99999999)


                    {
                                  QMessageBox::critical(nullptr, QObject::tr("vide"),
                                  QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
                                  test=false;

                    }
        else{
        journaliste j(id,nom,prenom,cin,num_tel,domaine,salaire);
         test=j.ajouter();}
        N.notification_ajoutjournaliste();
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
{sound->play();
    int id= ui->comboBox_ID_journaliste_modifier->currentText().toInt();
    int num_tel= ui->lineEdit_30->text().toInt();

  bool test=tmpjournaliste.modifier( id,num_tel );
  N.notification_modifierjournaliste();
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
{sound->play();
    int res=ui->comboBox_ID_journaliste->currentText().toInt();
            bool test=tmpjournaliste.supprimer(res);
            N.notification_supprimerjournaliste();
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
{sound->play();
    ui->tabjournaliste->setModel( tmpjournaliste.afficher_tri());
}

void Dialoghamzaoui::on_pushButton_rechercher_journaliste_clicked()
{sound->play();
    int id;
    id=ui->lineEdit_14->text().toInt();


   bool test= true;
    if(test==(true))
    {
      ui->tabjournaliste->setModel(tmpjournaliste.rechercher(id));
}
}

void Dialoghamzaoui::on_pushButton_Mail_2_clicked()
{sound->play();
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

void Dialoghamzaoui::on_pushButton_statistique_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                        model->setQuery("select * from PERSONNEL where SALAIRE < 750 ");
                        float salaire=model->rowCount();
                        model->setQuery("select * from PERSONNEL where SALAIRE  between 750 and 2500 ");
                        float salairee=model->rowCount();
                        model->setQuery("select * from PERSONNEL where SALAIRE>2600 ");
                        float salaireee=model->rowCount();
                        float total=salaire+salairee+salaireee;
                        QString a=QString(" personnel moins de 750dt "+QString::number((salaire*100)/total,'f',2)+"%" );
                        QString b=QString(" personnel entre 750 et2500 dt "+QString::number((salairee*100)/total,'f',2)+"%" );
                        QString c=QString("personnel +2600dt"+QString::number((salaireee*100)/total,'f',2)+"%" );
                        QPieSeries *series = new QPieSeries();
                        series->append(a,salaire);
                        series->append(b,salairee);
                        series->append(c,salaireee);
                if (salaire!=0)
                {QPieSlice *slice = series->slices().at(0);
                 slice->setLabelVisible();
                 slice->setPen(QPen());}
                if ( salairee!=0)
                {
                         // Add label, explode and define brush for 2nd slice
                         QPieSlice *slice1 = series->slices().at(1);
                         //slice1->setExploded();
                         slice1->setLabelVisible();
                }
                if(salaireee!=0)
                {
                         // Add labels to rest of slices
                         QPieSlice *slice2 = series->slices().at(2);
                         //slice1->setExploded();
                         slice2->setLabelVisible();
                }
                        // Create the chart widget
                        QChart *chart = new QChart();
                        // Add data to chart with title and hide legend
                        chart->addSeries(series);
                        chart->setTitle("Pourcentage Par Duree d'e promotion'commande des personnels :salaire  "+ QString::number(total));
                        chart->legend()->hide();
                        // Used to display the chart
                        QChartView *chartView = new QChartView(chart);
                        chartView->setRenderHint(QPainter::Antialiasing);
                        chartView->resize(1000,500);
                        chartView->show();
}





void Dialoghamzaoui::on_pushButton_trinom_clicked()
{
    QString mode="DESC";
        if (ui->checkBox_5->checkState()==false)
            mode="ASC";
    ui->tabjournaliste->setModel(tmpjournaliste.trierr(ui->comboBox_3->currentText(),mode));

}


void Dialoghamzaoui::on_pushButton_affichersalaires_clicked()
{
    sound->play();
    journaliste s;
    personnel p;
    QSqlQueryModel *model1=new QSqlQueryModel();
 model1=p.loadData_personnel();
  QSqlQueryModel *model2=new QSqlQueryModel();
 model2=s.loadData_journaliste();


    ui->tabsalaires->setModel(model1);
    ui->tabsalaires_2->setModel(model2);



}
