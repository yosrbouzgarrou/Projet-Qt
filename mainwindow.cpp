#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "publicite.h"
#include"notif.h"
#include "collaboration.h"
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
#include <QLineEdit>
#include <QDate>
#include <QDateEdit>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include"QSortFilterProxyModel"
#include <QPlainTextEdit>
#include <QPlainTextDocumentLayout>
#include<QChartView>
#include <QPieSeries>
#include<QDesktopServices>
#include<QUrl>
QT_CHARTS_USE_NAMESPACE
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(ar.connect_arduino())
       qDebug()<<"succes";
       else
  qDebug()<<"not very success";
  QObject::connect(ar.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
    ui->tableView->setModel(temppublicite.afficher_pub());
    ui->tableView_2->setModel(tempcollaboration.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_pub_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
        QString titre=ui->lineEdit_titre->text();
        QString domaine=ui->lineEdit_domaine->text();
        QString datep=ui->dateEdit->date().toString();
        QString redacteur=ui->lineEdit_redacteur->text();
        int recette=ui->lineEdit_recette->text().toInt();
            publicite p(id,titre,domaine,datep,redacteur,recette);
            bool test=p.ajouter_pub();
              N.notification_ajoutpublicite();
            if(test)
            {
                ui->tableView->setModel(temppublicite.afficher_pub());
                QMessageBox::information(nullptr, QObject::tr("Ajout"),
                            QObject::tr("Ajout avec succés.\n" "Click Cancel to exit."), QMessageBox::Cancel);

            }
             else
            {

                QMessageBox::critical(nullptr, QObject::tr("Ajout"),
                            QObject::tr("Ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
            }

}

void MainWindow::on_pushButton_9_clicked()
{
        int id=ui->lineEdit_id->text().toUInt();
            bool test=temppublicite.supprimer_pub(id);
              N.notification_supprimerpublicite();
            if(test)
            {
                ui->tableView->setModel(temppublicite.afficher_pub());
                QMessageBox::information(nullptr, QObject::tr("Supprimer"),
                QObject::tr("Suppression avec succée"), QMessageBox::Ok);
               // hide();
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Supprimer"),
                QObject::tr("Suppression echoués"), QMessageBox::Ok);
            }
}

void MainWindow::on_pushButton_8_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
        QString titre=ui->lineEdit_titre->text();
        QString domaine=ui->lineEdit_domaine->text();
        QString datep=ui->dateEdit->date().toString();
        QString redacteur=ui->lineEdit_redacteur->text();
        int recette=ui->lineEdit_recette->text().toInt();
            publicite p(id,titre,domaine,datep,redacteur,recette);
            bool test=p.modifier_pub(id);
           N.notification_modifierpublicite();
            if(test)
            {
                ui->tableView->setModel(temppublicite.afficher_pub());
                QMessageBox::information(nullptr, QObject::tr("Ajout"),
                            QObject::tr("Modification avec succés.\n" "Click Cancel to exit."), QMessageBox::Cancel);

            }
             else
            {

                QMessageBox::critical(nullptr, QObject::tr("Ajout"),
                            QObject::tr("Modification échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
            }
}

void MainWindow::on_pushButton_5_clicked()
{
    QString strStream;
                  QTextStream out(&strStream);

                  const int rowCount = ui->tableView->model()->rowCount();
                  const int columnCount = ui->tableView->model()->columnCount();
                  out <<"<html>\n"
                        "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                      << "<title>ERP - COMmANDE LIST<title>\n "
                      << "</head>\n"
                      "<body bgcolor=#ffffff link=#5000A0>\n"
                      "<h1 style=\"text-align: center;\"><strong> LISTE PUBS  ""</strong></h1>"
                      "<table style=\"text-align: center; font-size: 13px;\" border=1>\n "
                        "</br> </br>";
                  // headers
                  out << "<thead><tr bgcolor=#56089A>";
                  for (int column = 0; column < columnCount; column++)
                      if (!ui->tableView->isColumnHidden(column))
                          out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                  out << "</tr></thead>\n";

                  // data table
                  for (int row = 0; row < rowCount; row++) {
                      out << "<tr>";
                      for (int column = 0; column < columnCount; column++) {
                          if (!ui->tableView->isColumnHidden(column)) {
                              QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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

                  QPrinter printer;

                  QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                  if (dialog->exec() == QDialog::Accepted) {
                      document->print(&printer);
                  }

                  delete document;
}

/*void MainWindow::on_pushButton_4_clicked()
{
    QPdfWriter pdf("C:/Users/Lenovo/Documents/smartnewsagency_nourouni/pdfpub.pdf");

                  QPainter painter(&pdf);
                 int i = 4000;
                      painter.setPen(Qt::blue);
                      painter.setFont(QFont("Arial", 25));
                      painter.drawText(950,1100,"Liste Des publicités");
                      painter.setPen(Qt::black);
                      painter.setFont(QFont("Arial", 15));
                     // painter.drawText(1100,2000,afficheDC);
                      painter.drawRect(100,100,7300,2600);
                    //  painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("D:/Projet QT [Mon Travail]/Projet_MouadhElAmri_2A2/logo.png"));
                      painter.drawRect(0,3000,9600,500);
                      painter.setFont(QFont("Arial", 9));
                      painter.drawText(200,3300,"ID");
                      painter.drawText(1600,3300,"TITRE");
                      painter.drawText(2100,3300,"DOMAINE");
                      painter.drawText(3200,3300,"DATE");
                      painter.drawText(5300,3300,"REDACTEUR");
                      painter.drawText(7400,3300,"RECETTE");


                      QSqlQuery query;
                      query.prepare("select * from PUBLICITE");
                      query.exec();
                      while (query.next())
                      {
                          painter.drawText(200,i,query.value(0).toString());
                          painter.drawText(1300,i,query.value(1).toString());
                          painter.drawText(2100,i,query.value(2).toString());
                          painter.drawText(3200,i,query.value(3).toString());
                          painter.drawText(5300,i,query.value(4).toString());
                          painter.drawText(7400,i,query.value(5).toString());


                         i = i + 500;
                      }
                      QMessageBox::information(nullptr, QObject::tr("PDF Enregistré!"),
                                  QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}*/
void MainWindow::on_pushButton_4_clicked()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C://Users//user//Desktop//projet//loisir.pdf");
    QPainter painter;


    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");
    }

    QSqlQuery   query ;
    qDebug() << query.prepare("select sysdate from dual ");
    if ( query.exec() )
    {

        QString S= QDate::currentDate().toString();
        painter.drawText(850,50,S);
        QPen penred(Qt::black);

        painter.setFont(QFont("Arial", 30));
        penred.setWidth(1);
        painter.setPen(penred);

        QImage imagen(":/imagen/xii.png");
        painter.drawImage(-10,-10,imagen);
        painter.drawText(350,100," Loisir Planning ");
        painter.setFont(QFont("Arial",30));
        painter.setPen(Qt::black);

    }

    QString numloisir,type,lieu,date_loisir,duree,frais;
    QSqlQuery   qry ;
    int i =50;
    int k=0;
    qDebug() << qry.prepare("select * from LOIS ");

    if ( qry.exec() )
    {

        while(qry.next())
        {

            if ( k % 13 ==0)
            {   i=250;
                painter.setFont(QFont("Arial",10));
                QPen penblack(Qt::black);

                painter.setPen(penblack);
painter.drawText (0,200,"NumLoisir");
painter.drawText (90,200,"TypeLoisir");
painter.drawText (230,200,"Destination");
painter.drawText (420,200,"Date");
painter.drawText (530,200,"Duree");

            }

            painter.setFont(QFont("Arial",10));
            QPen penblack(Qt::black);

            painter.setPen(penblack);
            int j=0;
            numloisir= qry.value(0).toString();
            painter.drawText(j*20,i, numloisir);
            j++;
            type=qry.value(1).toString();
            painter.drawText(j*90,i, type);
            j++;
           lieu=qry.value(2).toString();
            painter.drawText(j*100,i, lieu);
            j++;
            date_loisir=qry.value(3).toString();
            painter.drawText(j*139,i, date_loisir);
            j++;
           duree=qry.value(4).toString();
            painter.drawText(j*140,i, duree);
            j++;
           frais=qry.value(5).toString();
             painter.drawText(j*140,i, frais);


            i+=80;
            k++;

        }
    }

    painter.end();
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_6_clicked() //recherche
{
   /* QString id =ui->lineEdit->text();
    ui->tableView->setModel(temppublicite.afficher_pub(id));*/
}




void MainWindow::on_pushButton_15_clicked()
{
    bool test;
            int id= ui->lineEdit_2->text().toInt();
            QString nom= ui->lineEdit_10->text();
            QString domaine=ui->lineEdit_12->text();
            int rib= ui->ribcollab->text().toInt();
            QString datec= ui->datecollab->text();
            QString contact=ui->lineEdit_13->text();
            if(nom==""|| domaine==""||id==0||rib==0)


                                {
                                              QMessageBox::critical(nullptr, QObject::tr("vide"),
                                              QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
                                              test=false;

                                }
                    else{
                    collaboration c(id,nom,domaine,rib,datec,contact);
                     test=c.ajouter();}
N.notification_ajoutcollaboration();
                     if(test)
                     {
                        ui->tableView_2->setModel(tempcollaboration.afficher());//refresh
                         QMessageBox::information(nullptr, QObject::tr("Ajouter une collaboration"),
                                           QObject::tr("collaboration ajouté.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);

                         }
                           else
                               QMessageBox::critical(nullptr, QObject::tr("Ajouter une collaboration"),
                                           QObject::tr("Erreur !.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_16_clicked()
{
    int id= ui->lineEdit_2->text().toInt();
    int rib= ui->ribcollab->text().toInt();




      bool test=tempcollaboration.modifier( id, rib );
N.notification_modifiercollaboration();
         if (test)
         {

             ui->tableView_2->setModel(tempcollaboration.afficher());//refresh
             QMessageBox::information(nullptr, QObject::tr("Modifier une collaboration"),
                         QObject::tr("collaboration modifiée.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier une collaboration"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_21_clicked()
{
    int id=ui->lineEdit_2->text().toInt();
        bool test=tempcollaboration.supprimer(id);
        N.notification_supprimercollaboration();
        if(test)
        {
            ui->tableView->setModel(tempcollaboration.afficher());
            QMessageBox::information(nullptr, QObject::tr("Supprimer"),
            QObject::tr("Suppression avec succés"), QMessageBox::Ok);
           // hide();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer"),
            QObject::tr("Suppression echouée"), QMessageBox::Ok);
        }
}
//void MainWindow::on_pushButton_recherche_publicite_clicked();


void MainWindow::on_radioButton_clicked()
{
    ui->tableView_2->setModel( tempcollaboration.afficher_tri());
}


void MainWindow::on_pushButton_10_clicked()
{
    int id;
        id=ui->lineEdit_6->text().toInt();


       bool test= true;
        if(test==(true))
        {
          ui->tableView_2->setModel(tempcollaboration.rechercher(id));
    }

}

void MainWindow::on_pushButton_recherche_publicite_clicked()
{int id;
    id=ui->lineEdit->text().toInt();


   bool test= true;
    if(test==(true))
    {
      ui->tableView->setModel(temppublicite.rechercher(id));
}

}

void MainWindow::on_radioButton_2_clicked()
{
    ui->tableView->setModel( temppublicite.afficher_tri());

}
void MainWindow::on_refresh_clicked()
{
   QByteArray data=ar.red_from_arduino();
   if(data.size()>10){
   QString temp =QString::fromStdString(data.toStdString());
   ui->textEdit->setText(temp);
}
}

void MainWindow::on_pushButton_17_clicked()
{

ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                        model->setQuery("select * from PUBLICITE where RECETTE  < 1750 ");
                        float recette=model->rowCount();
                        model->setQuery("select * from PUBLICITE  where RECETTE  between 1750 and 3000 ");
                        float recettee=model->rowCount();
                        model->setQuery("select * from PUBLICITEL where RECETTE>5000 ");
                        float recetteee=model->rowCount();
                        float total=recette+recettee+recetteee;
                        QString a=QString(" publicite moins de 1750 "+QString::number((recette*100)/total,'f',2)+"%" );
                        QString b=QString(" publicite entre 1750 et3000  "+QString::number((recette*100)/total,'f',2)+"%" );
                        QString c=QString("publicite +5000"+QString::number((recette*100)/total,'f',2)+"%" );
                        QPieSeries *series = new QPieSeries();
                        series->append(a,recette);
                        series->append(b,recettee);
                        series->append(c,recetteee);
                if (recette!=0)
                {QPieSlice *slice = series->slices().at(0);
                 slice->setLabelVisible();
                 slice->setPen(QPen());}
                if ( recette!=0)
                {
                         // Add label, explode and define brush for 2nd slice
                         QPieSlice *slice1 = series->slices().at(1);
                         //slice1->setExploded();
                         slice1->setLabelVisible();
                }
                if(recette!=0)
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
                        chart->setTitle("Pourcentage des publictes :recette  "+ QString::number(total));
                        chart->legend()->hide();
                        // Used to display the chart
                        QChartView *chartView = new QChartView(chart);
                        chartView->setRenderHint(QPainter::Antialiasing);
                        chartView->resize(1000,500);
                        chartView->show();
}





