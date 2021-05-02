#include "notif.h"


#include <QSystemTrayIcon>
#include<QString>
notif::notif()
{

}

void notif::notification_ajoutcollaboration()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des collaborations ","Nouveau collaboration ajouté ",QSystemTrayIcon::Information,150);
}

void notif::notification_ajoutpublicite()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des publicites ","Nouvelle publicite ajoutée ",QSystemTrayIcon::Information,15000);
}




void notif::notification_supprimercollaboration(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des collaboration","collaboration Supprimé",QSystemTrayIcon::Information,15000);
}

void notif::notification_supprimerpublicite(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des publicites ","Une publicite est supprimée",QSystemTrayIcon::Information,15000);

}




void notif::notification_modifiercollaboration(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des collaborations ","Un collaboration est modifié",QSystemTrayIcon::Information,15000);

}

void notif::notification_modifierpublicite(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des publicites ","Une publicite est modifiée",QSystemTrayIcon::Information,15000);

}


// void notif::mail_personnel(){
  //  QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
  //  notifyIcon->show();
  //  notifyIcon->showMessage("","Votre Mail est envoyé :)",QSystemTrayIcon::Information,15000);

//}



