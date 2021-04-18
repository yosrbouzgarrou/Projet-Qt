#include "interview.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QTextEdit>
#include<QMessageBox>
#include<QFileDialog>
#include<QPrinter>


#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtWidgets/QGridLayout>
QT_CHARTS_USE_NAMESPACE
interview::interview()
{
ID_INTERVIEW=""; NOM_JOURNALISTE=""; DOMAINE=""; DATEE=""; ID_INVITE=0;
}
interview::interview(QString ID_INTERVIEW ,QString NOM_JOURNALISTE ,QString DOMAINE ,QString DATEE, int ID_INVITE)
{this->ID_INTERVIEW=ID_INTERVIEW;this->NOM_JOURNALISTE=NOM_JOURNALISTE;this->DOMAINE=DOMAINE
            ;this->DATEE=DATEE; this->ID_INVITE=ID_INVITE;}
QString interview::getID_INTERVIEW() {return  ID_INTERVIEW ;}
QString interview::getNOM_JOURNALISTE(){return  NOM_JOURNALISTE;}
QString interview::getDOMAINE(){return DOMAINE;}
QString interview::getDATEE(){return DATEE;}

void interview::setID_INTERVIEW(QString ID_INTERVIEW){this->ID_INTERVIEW=ID_INTERVIEW;}
void interview::setNOM_JOURNALISTE(QString NOM_JOURNALISTE) {this->NOM_JOURNALISTE=NOM_JOURNALISTE;}
void interview::setDOMAINE(QString DOMAINE) {this->DOMAINE=DOMAINE;}
void interview::setDATEE(QString DATEE) {this->DATEE=DATEE;}
void interview::setID_INVITE(int ID_INVITE){this->ID_INVITE=ID_INVITE;}

QSqlQueryModel * interview::afficherid(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ID_INTERVIEW  from INTERVIEW");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("etat"));
    return model;
}
int  interview::verif(int XXX){

    int C=  NULL ;
    QSqlQuery XX ;
    QString res= QString::number(XXX);
    XX.prepare("SELECT COUNT(ID_INVITE) FROM INTERVIEW WHERE ID_INVITE = "+ res +" ");
    XX.exec();
    while (XX.next()) {
        C=XX.value(0).toInt() ;
    }
    return C ;
}
bool interview::ajouter()
{

    /*
    QSqlQuery query;
    QString ide=QString::number(ID_INVITE);
    query.prepare("INSERT INTO INVITE (ID_INVITE,NOM_PRENOM,EMAIL,TEL) "
                  "VALUES (:ID_INVITE, :NOM_PRENOM, :EMAIL,:TEL)");
    query.bindValue(":ID_INVITE", ide);
    query.bindValue(":NOM_PRENOM", NOM_PRENOM);
    query.bindValue(":EMAIL", EMAIL);
    query.bindValue(":TEL", TEL);
    return query.exec();

*/

    QSqlQuery query;
    QString ide=QString(ID_INTERVIEW);
    query.prepare("INSERT INTO INTERVIEW (ID_INTERVIEW,NOM_JOURNALISTE,DOMAINE,DATEE,ID_INVITE) "
                  "VALUES (:ID_INTERVIEW, :NOM_JOURNALISTE, :DOMAINE,:DATEE,:ID_INVITE)");
    query.bindValue(":ID_INTERVIEW", ide);
    query.bindValue(":NOM_JOURNALISTE", NOM_JOURNALISTE);
    query.bindValue(":DOMAINE", DOMAINE);
    query.bindValue(":DATEE", DATEE);
    query.bindValue(":ID_INVITE", ID_INVITE);
    return query.exec();




}
bool interview::supprimer(QString ID_INTERVIEW)
{
   QSqlQuery query;
    query.prepare("Delete from INTERVIEW where ID_INTERVIEW=:ID_INTERVIEW");
    query.bindValue(0, ID_INTERVIEW);

    return query.exec();
}
QSqlQueryModel*interview::afficher()
{
   QSqlQueryModel*model=new QSqlQueryModel();

     model->setQuery("SELECT* FROM INTERVIEW");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_INTERVIEW"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_JOURNALISTE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("DOMAINE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEE"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_INVITE"));
   return model ;
}
bool interview::modifier(QString idd)//modifier invité
{
    QSqlQuery query;
    QString res=QString(idd);
    query.prepare("Update INTERVIEW set NOM_JOURNALISTE=:NOM_JOURNALISTE ,DOMAINE=:DOMAINE,DATEE=:DATEE, ID_INVITE=:ID_INVITE where ID_INTERVIEW=:id ");
    query.bindValue(":id", res);
    query.bindValue(":NOM_JOURNALISTE",NOM_JOURNALISTE);
    query.bindValue(":DOMAINE",DOMAINE);
    query.bindValue(":DATEE",DATEE);
     query.bindValue(":ID_INVITE",ID_INVITE);
    return query.exec();

}
void interview::PDF()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM INTERVIEW ");
    q.exec();
    QString pdf="<br> <h1  style='color:blue'>LISTE DES INTERVIEW <br></h1>\n <br> <table>  <tr>  <th>CIN </th> <th>LIEU </th> <th> CODE POSTALE </th> </tr>" ;


    while ( q.next()) {

    pdf= pdf+ " <br> <tr>  <td>"+ q.value(0).toString()+"    &nbsp;&nbsp;&nbsp;     " + q.value(1).toString() +"</td>  &nbsp;&nbsp;&nbsp; <td>" +q.value(2).toString() +" &nbsp; </td> </td>" ;
    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}

QChartView * interview::stat()
{


        // Assign names to the set of bars used
        QBarSet *set0 = new QBarSet("duree");

        QVector <QString> duree;

        // Assign values for each bar

        QSqlQuery query,query2;
        query.prepare("select count(*) from interview group by datee");
        query.exec();

        query2.prepare("select datee from interview group by datee");
        query2.exec();


        QStringList categories;
        while(query.next())
          {
            *set0 << query.value(0).toInt();

          }
        while(query2.next())
          {
            categories << query2.value(0).toString();
          }


       // *set0 << 283 << 341 << 313 << 338 << 346 << 335;




        // Add all sets of data to the chart as a whole
        // 1. Bar Chart
        QBarSeries *series = new QBarSeries();

        // 2. Stacked bar chart
        // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
        series->append(set0);


        // Used to define the bar chart to display, title
        // legend,
        QChart *chart = new QChart();

        // Add the chart
        chart->addSeries(series);

        // Set title
        chart->setTitle("Seance avg by duree");

        // Define starting animation
        // NoAnimation, GridAxisAnimations, SeriesAnimations
        chart->setAnimationOptions(QChart::AllAnimations);

        // Holds the category titles


        // Adds categories to the axes
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();

        // 1. Bar chart
        chart->setAxisX(axis, series);

        // 2. Stacked Bar chart
        // chart->setAxisY(axis, series);

        // Define where the legend is displayed
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        // Used to display the chart
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);




        chartView->setRenderHint(QPainter::Antialiasing);


       return chartView;


}
