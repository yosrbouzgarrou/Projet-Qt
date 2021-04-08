#include "invite.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QTextEdit>
#include<QMessageBox>
invite::invite()
{
ID_INVITE=0 ; NOM_PRENOM="" ; EMAIL=""; TEL="";

}

invite::invite(int ID_INVITE,QString NOM_PRENOM, QString EMAIL ,QString TEL )
{this->ID_INVITE=ID_INVITE; this->NOM_PRENOM=NOM_PRENOM;this->EMAIL=EMAIL; this->TEL=TEL ; }
int invite::getID_INVITE() {return ID_INVITE ;}
QString invite::getNOM_PRENOM (){return NOM_PRENOM;}
QString invite::getEMAIL(){return EMAIL;}
QString invite::getTEL(){return TEL;}
void invite::setID_INVITE(int ID_INVITE){this->ID_INVITE=ID_INVITE;}
void invite::setNOM_PRENOM(QString NOM_PRENOM){this->NOM_PRENOM=NOM_PRENOM;}
void invite::setEMAIL(QString EMAIL) {this->EMAIL=EMAIL;}
void invite::setTEL(QString TEL) {this->TEL=TEL;}

bool invite::ajouter()
{
    QSqlQuery query;
    QString ide=QString::number(ID_INVITE);
    query.prepare("INSERT INTO INVITE (ID_INVITE,NOM_PRENOM,EMAIL,TEL) "
                  "VALUES (:ID_INVITE, :NOM_PRENOM, :EMAIL,:TEL)");
    query.bindValue(":ID_INVITE", ide);
    query.bindValue(":NOM_PRENOM", "NOM_PRENOM");
    query.bindValue(":EMAIL", "EMAIL");
    query.bindValue(":TEL", "TEL");
    return query.exec();
}
bool invite::supprimer(int ID_INVITE)
{
   QSqlQuery query;
    query.prepare("Delete from INVITE where ID_INVITE=:ID_INVITE");
    query.bindValue(0, ID_INVITE);

    return query.exec();
}
QSqlQueryModel*invite::afficher()
{
   QSqlQueryModel*model=new QSqlQueryModel();

     model->setQuery("SELECT* FROM invite");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_INVITE"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PRENOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMAIL"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL"));

   return model ;
}

bool invite::modifier(int idd)//modifier invité
{
    QSqlQuery query;
    QString res=QString::number(idd);
    query.prepare("Update invite set ID_INVITE=:id,NOM_PRENOM=:NOM_PRENOM ,EMAIL=:EMAIL,TEL=:TEL where ID_INVITE=:id ");
    query.bindValue(":id", res);
    query.bindValue(":NOM_PRENOM",NOM_PRENOM);
    query.bindValue(":EMAIL",EMAIL);
    query.bindValue(":TEL",TEL);
    return query.exec();

}
QSqlQueryModel *invite::recherche(QString NOM_PRENOM)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from invite where ID_INVITE LIKE '"+NOM_PRENOM+"%' or NOM_PRENOM LIKE '"+NOM_PRENOM+"%' or EMAIL LIKE '"+NOM_PRENOM+"%'" );


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_INVITE"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PRENOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMAIL"));

 return model;
}

QSqlQueryModel*  invite::Tri_id()
{
    QSqlQueryModel* model =new QSqlQueryModel();
     QSqlQuery  *i  = new QSqlQuery();
     i->prepare("SELECT * FROM INVITE order by ID_INVITE asc");
     i->exec();
     model->setQuery(*i);
     return model ;

}
QSqlQueryModel*  invite::Tri_nom()
{
    QSqlQueryModel* model =new QSqlQueryModel();
     QSqlQuery  *i  = new QSqlQuery();
     i->prepare("SELECT * FROM INVITE order by NOM_PRENOM desc");
     i->exec();
     model->setQuery(*i);
     return model ;

}

void invite::imprimer(QTextEdit* i, QString val)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM INVITE WHERE numbon='"+val+"'");
    if (query.exec())
    {
        int j=0;
        while(query.next() and j==0)
        {
            i->append(query.value(0).toString());
            i->append(query.value(1).toString());
            i->append(query.value(2).toString());
            i->append(query.value(3).toString());
            j=1;
        }

         }

        else {
        QMessageBox msgBox;
        msgBox.setText("Erreur au niveau d'impression");
        msgBox.exec();
        }
}


