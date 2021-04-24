#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>


Client::Client()
{
    id=0;
    nom="";
    prenom="";
    adresse="";
    tel=0;
    date="";
}

Client::Client(int i, QString n, QString p, QString a, int t, QString d)
{
   this->id=i;
    this-> nom=n;
    this-> prenom=p;
   this->  adresse=a;
    this-> tel=t;
   this->  date=d;
}

QSqlQueryModel* Client::afficher_client()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* from Client");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TEL"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("DATEE"));

    return model;
}

bool Client::ajouter_client()
{

    QSqlQuery query;
    QString res= QString::number(id);
        QString res1= QString::number(tel);
    query.prepare("INSERT INTO CLIENT(ID, NOM, PRENOM, ADRESSE, TEL, DATEE)"
                  "VALUES(:id, :nom, :prenom, :adresse, :tel, :datee)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":tel", res1);
    query.bindValue(":datee", date);
        return query.exec();
}


bool Client::supprimer_client(int id)
{
    QSqlQuery query;

    query.prepare("delete from Client where ID =:id");
    query.bindValue (":id",id);
    return query.exec();
}

bool Client::modifier_client(int id, QString nom, QString prenom, QString adresse, int tel, QString date)
{
QSqlQuery query;
    QString res= QString::number(id);



         query.prepare("UPDATE CLIENT set ID=:id, NOM=:nom,PRENOM=:prenom,ADRESSE=:adresse ,TEL=:tel where ID= :id ");

              query.bindValue(":id", res);
              query.bindValue(":nom", nom);
              query.bindValue(":prenom", prenom);
              query.bindValue(":adresse",adresse);
              query.bindValue(":tel",tel);
              query.bindValue(":date",date);



        return    query.exec();
}
    QSqlQueryModel * Client::recherche(int id)
    {

        QSqlQueryModel *model=new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("Select * from CLIENT where ID =:id");
        query.bindValue(":id",id);
        query.exec();
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

            return model;
       }

//metiers
    QSqlQueryModel *Client::triercroi() // tri 0-9 de l'id
    {
        QSqlQuery *q = new QSqlQuery();
            QSqlQueryModel *model = new QSqlQueryModel();
            q->prepare ("SELECT * FROM Client order by ID ASC");
            q->exec();
            model->setQuery(*q);
            return model;
    }

    QSqlQueryModel *Client::trierdec() // tri 9-0 de l'id
    {
    QSqlQuery * q = new QSqlQuery();
    QSqlQueryModel* model = new QSqlQueryModel();
    q->prepare("SELECT * FROM Client order by ID DESC");
    q->exec();
    model->setQuery(*q);
    return model;

    }

    void Client::CREATION_PDF()
    {
        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM CERTIFDECES ");
        q.exec();
        QString pdf="<br> <h1  style='color:blue'>LISTE DES CLIENTS  <br></h1>\n <br> <table>  <tr>  <th>ID </th> <th>NOM </th> <th> PRENOM </th> <th> ADRESSE </th> <th> TEL </th> <th> DATE DE NAISSANCE </th> </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" <td>" +q.value(3).toString() +" <td>" +q.value(4).toString() +" <td>" +q.value(5).toString() +" "" " "</td> </td>" ;

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
    }
