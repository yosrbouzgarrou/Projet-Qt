#ifndef JOURNALISTE_H
#define JOURNALISTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class journaliste
{
public:
    journaliste();
    journaliste(int,QString,QString,int,int,QString,int);
    int get_id();
    QString get_nom();
    QString get_prenom();
    int get_cin();
    int get_num_tel();
    QString get_domaine();
int get_salaire();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int);
    QSqlQueryModel * rechercher(int );
    QSqlQueryModel * afficher_tri();
        QSqlQueryModel*Tri_nom();
 QSqlQueryModel *  trierr(const QString &critere, const QString &mode );
    QSqlQueryModel *displayClause(QString cls);
 QSqlQueryModel * loadData_journaliste();
private:
int id;
int salaire;
QString nom;
QString prenom;
int cin;
int num_tel;
QString domaine;

};

#endif // JOURNALISTE_H
