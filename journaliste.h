#ifndef JOURNALISTE_H
#define JOURNALISTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class journaliste
{
public:
    journaliste();
    journaliste(int,QString,QString,int,int,QString);
    int get_id();
    QString get_nom();
    QString get_prenom();
    int get_cin();
    int get_num_tel();
    QString get_domaine();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int);
    QSqlQueryModel * rechercher(int );
    QSqlQueryModel * afficher_tri();

    QSqlQueryModel *displayClause(QString cls);

private:
int id;
QString nom;
QString prenom;
int cin;
int num_tel;
QString domaine;

};

#endif // JOURNALISTE_H
