#include "projet.h"
#include "ui_projet.h"
#include "personnel.h"
#include<QMessageBox>
projet::projet(QWidget *parent):

    QMainWindow(parent),
     ui(new Ui::projet),
 {  ui->setupUi(this);
    ui->tableview->setMdel(Etmp.afficher());

}
projet::~projet()
{
    delete ui;
}
void projet::on_pushButton_ajouter_personnel_clicked()
{
    int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    int cin=ui->cin->text().toInt();
     int num_telephone=ui->num->text().toInt();


    personnel p (id,nom,cin,prenom,num_telephone);
    bool test=p.ajouter();
            if (test)
            { QMessageBox::information(nullptr, QObject::tr("ok"),
                                       QObject::tr("ajout effectué.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
                   }
                   else
                           QMessageBox::critical(nullptr, QObject::tr("ok"),
                                       QObject::tr("erreur.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);


 }
void projet::on_pushButton_supprimer_personnel_clicked()
{
    int id=ui->ID->text().toInt();


    bool test=pmp.supprimer();
            if (test)
            { QMessageBox::information(nullptr, QObject::tr("ok"),
                                       QObject::tr("suppression effectué.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
                   }
                   else
                           QMessageBox::critical(nullptr, QObject::tr("ok"),
                                       QObject::tr("erreur.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);


 }




