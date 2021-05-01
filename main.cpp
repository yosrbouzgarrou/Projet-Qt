#include "ineswindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include <QSqlDatabase>



#include <QtCore>
#include <QPdfWriter>
#include <QPainter>
#include <QSplashScreen>
#include <QTimer>




int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(chart);

    QApplication a(argc, argv);

   // QPixmap pixmap(":/Charts/logo.png");
   // QSplashScreen splash(pixmap, Qt::WindowStaysOnTopHint);
   // splash.show();
   // QTimer::singleShot(1000, &splash, &QWidget::close);

    connexion c;


    bool test=c.createConnexion();





     MainWindow w;


    if(test)
    {
     // ui->tableView->setModel(ptmp.afficher());
      //  ui->tableView_2->setModel(rtmp.afficher());
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
