#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class personnel
{
public:
    personnel();
    personnel(int,QString,QString,int,int,QString,int);
    int get_id();
    int get_num_telephone();
    QString get_nom();
    QString get_prenom();
    QString get_email();
    int get_cin();
     int get_salaire();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_email();
    bool testemail(QString);
    bool supprimer(int);
    bool modifier(int,int,int);
    QSqlQueryModel * rechercher(int );
    QSqlQueryModel * afficher_tri();
 QSqlQueryModel * loadData_personnel();
    QSqlQueryModel *displayClause(QString cls);



private:


int id,salaire;
QString nom;
QString prenom;
int num_telephone;
int cin;
QString email;

};

#endif // PERSONNEL_H
