#include "personnel.h"
#include <QSqlQuery>
#include <QString>
#include <QTableView>


personnel::personnel()
{
    id=0;
    nom="";
    prenom="";
    num_telephone=0;
    cin=0;
    email="";
     salaire=0;
}
personnel::personnel(int id,QString nom,QString prenom, int num_telephone, int cin, QString email, int salaire)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->num_telephone=num_telephone;
    this->cin=cin;
    this->email=email;
     this->salaire=salaire;
}

int personnel:: get_id(){return id; }


bool personnel:: ajouter()
{
    QSqlQuery query;

    QString res= QString::number(id);
        QString res1= QString::number(num_telephone);
        QString res2= QString::number(cin);
        QString res3= QString::number(salaire);
    query.prepare("INSERT INTO Personnel (ID,NOM,PRENOM,NUMTEL,CIN,EMAIL,SALAIRE) "
                        "VALUES ( :id,:nom,:prenom,:num_telephone,:cin,:email,:salaire)");
    query.bindValue(":id", res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":num_telephone", res1);
    query.bindValue(":cin",res2);
    query.bindValue(":email",email);

    query.bindValue(":salaire",res3);


    return    query.exec();
    }

QSqlQueryModel *personnel::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONNEL  order by ID desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMTEL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(6,Qt::Horizontal, QObject::tr("SALAIRE"));


    return model;
}
bool personnel::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from PERSONNEL where ID = :id ");
    query.bindValue(":id", id);
    return    query.exec();
}

bool personnel:: modifier(int id ,int num_telephone ,int salaire)
{QSqlQuery query;
    QString res= QString::number(num_telephone);
    QString res2= QString::number(id);
   QString res1= QString::number(salaire);
         query.prepare("UPDATE PERSONNEL set ID=:id,NUMTEL=:num_telephone,SALAIRE=:salaire where ID= :id ");
         query.bindValue(":id", res2);
         query.bindValue(":num_telephone", res);
          query.bindValue(":salaire", res1);

        return    query.exec();

}



QSqlQueryModel * personnel::rechercher(int id)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from PERSONNEL where ID =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

        return model;
   }


QSqlQueryModel * personnel::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONNEL order by ID asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

    return model;
}
QSqlQueryModel * personnel::afficher_email()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select EMAIL from PERSONNEL   ");
    return model;
}
bool personnel::testemail(QString email){
    int test=0;
    for(int i = 0; i < email.size(); i++) {
if(email[i]=="@")
{test++;

}}
    for(int i = 0; i < email.size(); i++) {
if((test==1)&&(email[i]=="."))
{if(email.size()>i+1)
    return true;
}}
return false;}




QSqlQueryModel *personnel::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM PERSONNEL " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMTEL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("SALAIRE"));



    return model;
}


