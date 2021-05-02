#include "journaliste.h"
#include <QSqlQuery>
#include <QString>
#include <QTableView>

journaliste::journaliste()
{
    id=0;
    nom="";
    prenom="";
    cin=0;
    num_tel=0;
    domaine="";
 salaire=0;
}

journaliste::journaliste(int id,QString nom,QString prenom,int cin,int num_tel,QString domaine,int salaire)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->cin=cin;
    this->num_tel=num_tel;
    this->domaine=domaine;
 this->salaire=salaire;


}

int journaliste:: get_id(){return id; }


bool journaliste:: ajouter()
{
    QSqlQuery query;

    QString res= QString::number(id);
    QString res1= QString::number(cin);
    QString res2= QString::number(num_tel);
           QString res3= QString::number(salaire);
    query.prepare("INSERT INTO JOURNALISTE (ID,NOM,PRENOM,CIN,NUMTEL,DOMAINE,SALAIRE) "
                        "VALUES ( :id,:nom,:prenom, :cin, :num_tel, :domaine,:salaire)");
    query.bindValue(":id", res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":cin", res1);
    query.bindValue(":num_tel", res2);
    query.bindValue(":domaine",domaine);
    query.bindValue(":salaire",res3);


    return    query.exec();
    }

QSqlQueryModel *journaliste::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from JOURNALISTE  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMTEL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("DOMAINE"));
model->setHeaderData(6,Qt::Horizontal, QObject::tr("SALAIRE"));

    return model;
}






bool journaliste::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from JOURNALISTE where ID = :id ");
    query.bindValue(":id", id);
    return    query.exec();
}

bool journaliste:: modifier(int id ,int num_telephone )
{QSqlQuery query;
    QString res= QString::number(num_telephone);
    QString res2= QString::number(id);

         query.prepare("UPDATE JOURNALISTE set ID=:id,NUMTEL=:num_telephone where ID= :id ");
         query.bindValue(":id", res2);
         query.bindValue(":num_telephone", res);

        return    query.exec();

}


QSqlQueryModel * journaliste::rechercher(int id)
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
QSqlQueryModel * journaliste::trierr(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from JOURNALISTE order by "+critere+" "+mode+"");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMTEL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("DOMAINE"));
model->setHeaderData(6,Qt::Horizontal, QObject::tr("SALAIRE"));

    return model;
}
QSqlQueryModel * journaliste::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from JOURNALISTE order by ID asc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

    return model;
}
QSqlQueryModel*  journaliste::Tri_nom()
{
    QSqlQueryModel* model =new QSqlQueryModel();
     QSqlQuery  *tmpjournaliste = new QSqlQuery();
     tmpjournaliste->prepare("SELECT * FROM JOURNALISTE order by NOM asc");
     tmpjournaliste->exec();
     model->setQuery(*tmpjournaliste);
     return model ;

}



QSqlQueryModel * journaliste::loadData_journaliste()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select SALAIRE from JOURNALISTE");
    query.exec();
    model->setQuery(query);
    return model;
}

QSqlQueryModel *journaliste::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM JOUNALISTE " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMTEL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DOMAINE"));
    model->setHeaderData(6,Qt::Horizontal, QObject::tr("SALAIRE"));


    return model;
}


