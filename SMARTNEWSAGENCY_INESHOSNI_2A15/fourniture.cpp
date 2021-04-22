#include "fourniture.h"
#include <QSqlQuery>
#include <QString>
#include <QTableView>

fourniture::fourniture()
{
    ref=0;
    nom="";
    type="";
    loc="";

}
fourniture::fourniture(int ref,QString nom,QString type,  QString loc )
{
    this->ref=ref;
    this->nom=nom;
    this->type=type;
    this->loc=loc;

}

int fourniture:: get_ref(){return ref; }


bool fourniture:: ajouter()
{
    QSqlQuery query;

    QString res= QString::number(ref);

    query.prepare("INSERT INTO FOURNITURE (REF,NOM,TYPE,LOC) "
                        "VALUES ( :ref,:nom,:type,:loc)");
    query.bindValue(":ref", res);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
    query.bindValue(":loc",loc);


    return    query.exec();
    }

QSqlQueryModel *fourniture::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FOURNITURE  order by REF desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("LOC"));



    return model;
}
bool fourniture::supprimer(int ref)
{
    QSqlQuery query;
    query.prepare("Delete from FOURNITURE where REF = :ref ");
    query.bindValue(":ref", ref);

    return    query.exec();
}

bool fourniture:: modifier(int ref,QString loc)
{
    QSqlQuery query;
        QString res= QString::number(ref);


             query.prepare("UPDATE FOURNITURE set REF=:ref, LOC=:loc where REF= :ref ");
             query.bindValue(":ref", res);
             query.bindValue(":loc", loc);

            return    query.exec();

}



QSqlQueryModel * fourniture::rechercher(int ref)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from FOURNITURE where REF =:ref");
    query.bindValue(":ref",ref);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));

        return model;
   }


QSqlQueryModel * fourniture::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FOURNITURE order by REF desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));

    return model;
}




QSqlQueryModel *fourniture::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM FOURNITURE " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("LOC"));



    return model;
}



