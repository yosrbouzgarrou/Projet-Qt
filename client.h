#ifndef CLIENT_H
#define CLIENT_H
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
class Client
{

public:
    //Constructeurs
    Client();
    Client(int,QString,QString,QString,int,QString);

    //Getters
     int getid();
    QString getNom();
    QString getPrenom();
    QString getAdresse();
    int getTel();
    QString getDate();

    //Setters
    void setID(int);
    void setNom(QString);
    void setPrenom(QString);
    void setAdresse(QString);
    void setTel(int);
    void setDate(QString);

    bool ajouter_client();
    QSqlQueryModel* afficher_client();
    bool supprimer_client(int);
    bool modifier_client(int,QString , QString , QString, int, QString);
    QSqlQueryModel* recherche (int);
    QSqlQueryModel *triercroi();
    QSqlQueryModel *trierdec();
    void CREATION_PDF();
    //Fonctionnalités de base relatives à l'entité connecion

private:
    int id,tel;
    QString nom, prenom, adresse,date;

};

#endif // CLIENT_H
