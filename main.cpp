#include "gestion_invite_interview.h"
#include "connexion.h"
#include"interview.h"
#include <QApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;
    bool t= c.ouvrirConnexion();
    Gestion_Invite_Interview w;
    w.show();
  /*  interview AA ;
    int b=AA.verif(169);
    try {
        qDebug()<<"date"<<b ;

    } catch (QString s) {
        qDebug()<<"qdfqfdqsdf";

    }*/


    return a.exec();
}
