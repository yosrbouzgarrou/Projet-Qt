#include "connexion.h"
#include "QSqlDatabase"
Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_projet2A");
db.setUserName("amin");//inserer nom de l'utilisateur
db.setPassword("azerty");//inserer mot de passe de cet utilisateur
if (db.open())
    test=true;
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
