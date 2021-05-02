#include "collaboration.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QString>
#include <QTableView>

collaboration::collaboration()
{ id=0;
    nom="";
    domaine="";
    rib=0;
    datec="";
    contact="";
    email="";

}
collaboration::collaboration(int id,QString nom,QString domaine,int rib,QString datec,QString contact,QString email)
{
    this->id=id;
    this->nom=nom;
    this->domaine=domaine;
    this->rib=rib;
    this->datec=datec;
    this->contact=contact;
    this->email=email;



}
int collaboration:: get_id(){return id; }
bool collaboration::ajouter()
{
    QSqlQuery query;

        QString res= QString::number(id);
        QString res1= QString::number(rib);
        query.prepare("INSERT INTO COLLABORATION (ID,NOM,DOMAINE,DATEC,CONTACT,RIB,EMAIL) "
                            "VALUES ( :id,:nom,:domaine, :datec, :contact, :rib , :email)");
        query.bindValue(":id", res);
        query.bindValue(":nom",nom);
        query.bindValue(":domaine",domaine);
        query.bindValue(":rib", res1);
        query.bindValue(":contact", contact);
        query.bindValue(":datec",datec);
        query.bindValue(":email",email);


        return    query.exec();
}
QSqlQueryModel * collaboration::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from COLLABORATION");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("DOMAINE"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DATEC"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("CONTACT"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("RIB"));
    model->setHeaderData(6,Qt::Horizontal, QObject::tr("EMAIL"));

    return model;
}

 bool collaboration::supprimer(int id)
 {
     QSqlQuery query;
         query.prepare("Delete from COLLABORATION where ID = :id ");
         query.bindValue(":id", id);
         return    query.exec();
 }
 bool collaboration::modifier(int id, int rib)
  {
      QSqlQuery query;
      QString res=QString::number(id);
      QString res1=QString::number(rib);

      query.prepare("Update collaboration set ID = :id , RIB=:rib  where ID = :id ");
      query.bindValue(":id", res);
      query.bindValue(":rib", res1);



      return query.exec();
  }
 QSqlQueryModel * collaboration::afficher_tri()
 {QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select * from COLLABORATION order by ID asc ");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

     return model;
 }
 QSqlQueryModel * collaboration::afficher_tri_nom()
 {QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select * from COLLABORATION order by NOM asc ");
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));

     return model;
 }
 QSqlQueryModel * collaboration::rechercher(int id)
 {

     QSqlQueryModel *model=new QSqlQueryModel();
     QSqlQuery query;
     query.prepare("Select * from COLLABORATION where ID =:id");
     query.bindValue(":id",id);
     query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

         return model;
    }

 QSqlQueryModel * collaboration::afficher_email()
 {QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select EMAIL from COLLABORATION   ");
     return model;
 }

 QSqlQueryModel *collaboration::displayClause(QString cls)
 {
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("SELECT * FROM COLLABORATION " +cls);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("DOMAINE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("RIB"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("CONTACT"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));



     return model;
 }





