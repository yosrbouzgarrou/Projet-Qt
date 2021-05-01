#ifndef MATERIEL_H
#define MATERIEL_H
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

class materiel
{
public:
    materiel();
    materiel(int,QString,QString,QString,QString);
    bool ajouter_materiel();
    QSqlQueryModel * afficher_materiel();
    bool supprimer_materiel(int);
    bool modifier_materiel(int);
    QSqlQueryModel * rechercher(int);
    QSqlQueryModel * afficher_tri();
    QSqlQueryModel * getDataForPieChart_materiel();


   /* QSqlQueryModel* recherche(QString);
    QSqlQueryModel * triercroi();
    QSqlQueryModel * trierdec();
    void CREATION_PDF();*/

        int getcode();
        QString getnom(){return nom;};
        QString getref(){return ref;};
        QString gettype(){return type;};
        QString getquantite(){return quantite;};
       // QString getetatmatrim(){return etatmatrim;};
        void setcode(int);
        void setnom(QString);
        void setref(QString);
       // void setdatedeces(QString);
        void settype(QString);
        void setquantite(QString);

    private:
        int code;
        QString ref,nom,type,quantite;

};

#endif // MATERIEL_H
