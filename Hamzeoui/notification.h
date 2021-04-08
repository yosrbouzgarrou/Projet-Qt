#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QSystemTrayIcon>
#include<QString>
class Notification
{
public:
    Notification();
    void notification_ajoutjournaliste();

    void notification_ajoutpersonnel();
    void notification_supprimerjournaliste();

    void notification_supprimerpersonnel();
    void notification_modifierjournaliste();

    void notification_modifierpersonnel();
    void mail_personnel();






};

