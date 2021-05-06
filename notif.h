#ifndef NOTIF_H
#define NOTIF_H

#include <QSystemTrayIcon>
#include<QString>
class notif
{

public:
    notif();
    void notification_ajoutcollaboration();

    void notification_ajoutpublicite();
    void notification_supprimercollaboration();

    void notification_supprimerpublicite();
    void notification_modifiercollaboration();

    void notification_modifierpublicite();
 //   void mail_personnel();

};
#endif // NOTIF_H

