#include "interview.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QTextEdit>
#include<QMessageBox>
#include<QFileDialog>
#include<QPrinter>
interview::interview()
{
ID_INTERVIEW=""; NOM_JOURNALISTE=""; DOMAINE=""; DATE=""; ID_INVITE=0;
}
interview::interview(QString ID_INTERVIEW ,QString NOM_JOURNALISTE ,QString DOMAINE ,QString DATE, int ID_INVITE)
{this->ID_INTERVIEW=ID_INTERVIEW;this->NOM_JOURNALISTE=NOM_JOURNALISTE;this->DOMAINE=DOMAINE
            ;this->DATE=DATE; this->ID_INVITE=ID_INVITE;}
QString interview::getID_INTERVIEW() {return  ID_INTERVIEW ;}
QString interview::getNOM_JOURNALISTE(){return  NOM_JOURNALISTE;}
QString interview::getDOMAINE(){return DOMAINE;}
QString interview::getDATE(){return DATE;}

void interview::setID_INTERVIEW(QString ID_INTERVIEW){this->ID_INTERVIEW=ID_INTERVIEW;}
void interview::setNOM_JOURNALISTE(QString NOM_JOURNALISTE) {this->NOM_JOURNALISTE=NOM_JOURNALISTE;}
void interview::setDOMAINE(QString DOMAINE) {this->DOMAINE=DOMAINE;}
void interview::setDATE(QString DATE) {this->DATE=DATE;}
void interview::setID_INVITE(int ID_INVITE){this->ID_INVITE=ID_INVITE;}


bool interview::ajouter()
{
    QSqlQuery query;
    QString ide=QString(ID_INTERVIEW);
    query.prepare("INSERT INTO INVITE (ID_INTERVIEW,NOM_JOURNALISTE,DOMAINE,DATE,ID_INVITE) "
                  "VALUES (:ID_INTERVIEW, :NOM_JOURNALISTE, :DOMAINE,:DATE,:ID_INVITE)");
    query.bindValue(":ID_INTERVIEW", ide);
    query.bindValue(":NOM_JOURNALISTE", "NOM_JOURNALISTE");
    query.bindValue(":DOMAINE", "DOMAINE");
    query.bindValue(":DATE", "DATE");
    query.bindValue(":ID_INVITE", "ID_INVITE");
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
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_INVITE"));
   return model ;
}
bool interview::modifier(QString idd)//modifier invité
{
    QSqlQuery query;
    QString res=QString(idd);
    query.prepare("Update INTERVIEW set ID_INTERVIEW=:id,NOM_JOURNALISTE=:NOM_JOURNALISTE ,DOMAINE=:DOMAINE,DATE=:DATE, ID_INVITE=:ID_INVITE where ID_INTERVIEW=:id ");
    query.bindValue(":id", res);
    query.bindValue(":NOM_JOURNALISTE",NOM_JOURNALISTE);
    query.bindValue(":DOMAINE",DOMAINE);
    query.bindValue(":DATE",DATE);
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
