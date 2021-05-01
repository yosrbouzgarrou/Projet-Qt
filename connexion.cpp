#include "connexion.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
connexion::connexion()
{

}
bool connexion::createConnexion()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("source_projet");
    db.setUserName("ines");//inserer nom de l'utilisateur
    db.setPassword("ines123");//inserer mot de passe de cet utilisateur

        if (db.open())
    test=true;

        return  test;
}
void connexion::closeConnexion(){db.close(); }
