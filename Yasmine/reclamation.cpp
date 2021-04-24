#include "reclamation.h"
#include "client.h"
#include <QtDebug>
#include <QObject>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QSqlQuery>
#include <QString>
#include <QTableView>

Reclamation::Reclamation()
{
    id=0;
    nomauteur="";
    prenomauteur="";
    reclamationn="";
    datereclamationn="";
       email="";
}
Reclamation::Reclamation(int id, QString nomauteur, QString prenomauteur, QString reclamationn, QString datereclamationn,QString email)
{
    this->id=id;
    this->nomauteur=nomauteur;
    this->prenomauteur=prenomauteur;
    this->reclamationn=reclamationn;
    this->datereclamationn=datereclamationn;
    this->email=email;
}

int Reclamation:: getid(){return id; }


bool Reclamation::ajouter_reclamation()
{

    QSqlQuery query;

    query.prepare("INSERT INTO RECLAMATION(ID, NOMAUTEUR, PRENOMAUTEUR, RECLAMATION, DATERECLAMATION,EMAIL)"
                  "VALUES(:id, :nomauteur, :prenomauteur, :reclamation, :datereclamationn,:email)");
    query.bindValue(":id",id);
    query.bindValue(":nomauteur",nomauteur);
    query.bindValue(":prenomauteur", prenomauteur);
    query.bindValue(":reclamation", reclamationn);
    query.bindValue(":datereclamationn", datereclamationn);
     query.bindValue(":email", email);
        return query.exec();
}

QSqlQueryModel* Reclamation::afficher_reclamation()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* from Reclamation");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOMAUTEUR"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("PRENOMAUTEUR"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("RECLAMATION"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATERECLAMATION"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("EMAIL"));

    return model;
}

bool Reclamation::supprimer_reclamation(int id)
{
    QSqlQuery query;

    query.prepare("delete from reclamation where ID =:id");
    query.bindValue (":id",id);
    return query.exec();
}



bool Reclamation::modifier_reclamation(int id,QString nomauteur,QString prenomauteur, QString reclamationn,QString datereclamationn,QString email )
{
    QSqlQuery query;
        QString res= QString::number(id);


             query.prepare("UPDATE RECLAMATION set ID=:id, NOMAUTEUR=:nomauteur,PRENOMAUTEUR=:prenomauteur,RECLAMATION=:reclamationn ,EMAIL=:email where ID= :id ");

                  query.bindValue(":id", res);
                  query.bindValue(":nomauteur", nomauteur);
                  query.bindValue(":prenomauteur", prenomauteur);
                  query.bindValue(":reclamationn",reclamationn);
                  query.bindValue(":datereclamationn",datereclamationn);
                  query.bindValue(":email",email);



            return    query.exec();

}

QSqlQueryModel * Reclamation::afficher_email()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select EMAIL from RECLAMATION   ");
    return model;
}

QSqlQueryModel *Reclamation::recherche(int id)
{
  QSqlQueryModel *model= new QSqlQueryModel();
  QSqlQuery query;
  query.prepare("Select * from RECLAMATION where ID =:id");
  query.bindValue(":id",id);
  query.exec();
  model->setQuery(query);
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

  return model;
}
//metiers
QSqlQueryModel *Reclamation::triercroi() // tri a-z du nom
{
    QSqlQuery *q = new QSqlQuery();
        QSqlQueryModel *model = new QSqlQueryModel();
        q->prepare ("SELECT * FROM Reclamation order by ID ASC");
        q->exec();
        model->setQuery(*q);
        return model;
}

QSqlQueryModel *Reclamation::trierdec() // tri z-a du nom
{
QSqlQuery * q = new QSqlQuery();
QSqlQueryModel* model = new QSqlQueryModel();
q->prepare("SELECT * FROM Reclamation order by ID DESC");
q->exec();
model->setQuery(*q);
return model;

}

