#include "fenetre.h"
#include "connexion.h"
#include <QMessageBox>
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    bool test=c.createconnect();
    fenetre w;
        if(test)
        {
            w.show();
            QMessageBox::information(nullptr,QObject::tr("database is open"),
                                     QObject::tr("connection successful. \n"
                                                 "Click Cancel to exist."), QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                  QObject::tr("connexion failed. \n"
                                               "Click Cancel to exit."),QMessageBox::Cancel);

    return a.exec();
}
