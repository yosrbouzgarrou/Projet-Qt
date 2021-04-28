#include "connexion.h"
#include"dialoghamzaoui.h"
#include"personnel.h"
#include"journaliste.h"

#include <QApplication>
#include <QMessageBox>
#include <QtDebug>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialoghamzaoui w;
    Connexion c;
       bool test=c.ouvrirConnexion();
       if(test)
       {w.show();
           QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("connection successful.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else
           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("connection failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();
}
