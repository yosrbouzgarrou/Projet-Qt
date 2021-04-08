#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>


class Connexion
{
    QSqlDatabase db;
public:
    Connexion();
    bool createconnexion();
    void closeConnexion ();
};

#endif // CONNEXION_H
