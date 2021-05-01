#ifndef FOURNITURE_H
#define FOURNITURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fourniture
{
public:
    fourniture();
    fourniture(int,QString,QString,QString);
    int get_ref();
    QString get_nom();
    QString get_type();
    QString get_loc();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);

    bool modifier(int,QString);
    QSqlQueryModel * rechercher(int);
    QSqlQueryModel * afficher_tri();

    void CREATION_PDF();

    QSqlQueryModel *displayClause(QString cls);

private:


int ref;
QString nom;
QString type;
QString loc;




};


#endif // FOURNITURE_H
