#include "materiel.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>


materiel::materiel()
{
code=0;
nom="";
ref="";
type="";
quantite="";
}
materiel::materiel(int c,QString n,QString p,QString d,QString l)
{
    code=c;
    nom=n;
    ref=p;
    type=d;
    quantite=l;

}
bool materiel::ajouter_materiel()
{
    QSqlQuery query;
    QString codes=QString::number(code);
    query.prepare("INSERT INTO GESTIONMATERIEL(CODE, NOM, REF, TYPE, QUANTITE)"
                  "VALUES(:code, :nom, :ref, :type, :quantite)");

    query.bindValue(":code",codes);
    query.bindValue(":nom",nom);
    query.bindValue(":ref",ref);
    query.bindValue(":type",type);
    query.bindValue(":quantite",quantite);

    return query.exec();
}
QSqlQueryModel * materiel::afficher_materiel()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from GESTIONMATERIEL");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Code"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("QUANTITE"));
    return model;
}

QSqlQueryModel * materiel::getDataForPieChart_materiel()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select Nom , Ref from GESTIONMATERIEL");

    model->setHeaderData(0,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("REFERENCE"));

    return model;
}

 bool materiel::supprimer_materiel(int idc)
 {
     QSqlQuery query;
     QString res=QString::number(idc);
     query.prepare("delete from GESTIONMATERIEL where code= :id");
     query.bindValue(":id",res);
     return query.exec();
 }

 bool materiel::modifier_materiel(int idd) //modifier certif
 {
     QSqlQuery query;
     QString res=QString::number(idd);
     query.prepare("Update GESTIONMATERIEL set CODE = :id , NOM = :nom , REF = :ref , TYPE = :type , QUANTITE = :quantite  where CODE = :id ");
     query.bindValue(":id", res);
     query.bindValue(":code",code);
     query.bindValue(":nom",nom);
     query.bindValue(":ref",ref);
     query.bindValue(":type",type);
     query.bindValue(":quantite",quantite);
     return query.exec();
 }
 QSqlQueryModel * materiel::rechercher(int code)
 {

     QSqlQueryModel *model=new QSqlQueryModel();
     QSqlQuery query;
     query.prepare("Select * from MATERIEL where CODE =:code");
     query.bindValue(":code",code);
     query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE  "));

         return model;
    }


 QSqlQueryModel * materiel::afficher_tri()
 {QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select * from MATERIEL order by CODE desc ");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE"));

     return model;
 }


