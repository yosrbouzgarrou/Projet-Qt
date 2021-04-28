#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QSystemTrayIcon>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QIntValidator>
#include <QValidator>
class Reclamation
{

public:
    //Constructeurs
    Reclamation();
    Reclamation(int,QString,QString,QString,QString,QString);

    //Getters
     int getid();
    QString getNomauteur();
    QString getPrenomauteur();
    QString getReclamationn();
    QString getDatereclamation();
     QString getemail();

    //Setters
    void setid(int);
    void setNomauteur(QString);
    void setPrenomauteur(QString);
    void setReclamationn(QString);
    void setDatereclamationn(QString);
     void setEmail(QString);

    bool ajouter_reclamation();
    QSqlQueryModel* afficher_reclamation();
    QSqlQueryModel * afficher_email();
    bool supprimer_reclamation(int);
    bool modifier_reclamation(int,QString,QString,QString,QString,QString);
    QSqlQueryModel* recherche (int);
    QSqlQueryModel *triercroi();
    QSqlQueryModel *trierdec();


    //Fonctionnalités de base relatives à l'entité connecion

private:
    int id;
    QString nomauteur, prenomauteur, reclamationn,datereclamationn,email;

};

#endif // RECLAMATION_H
