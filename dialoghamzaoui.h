#ifndef DIALOGHAMZAOUI_H
#define DIALOGHAMZAOUI_H
#include "personnel.h"
#include "journaliste.h"
#include"notificationham.h"

#include <QDialog>
#include <QMediaPlayer>
#include <QSound>

namespace Ui {
class Dialoghamzaoui;
}

class Dialoghamzaoui : public QDialog
{
    Q_OBJECT

public:
    explicit Dialoghamzaoui(QWidget *parent = nullptr);
    ~Dialoghamzaoui();

private slots:
    void on_pushButton_ajouter_personnel_clicked();

    void on_pushButton_modifier_personnel_clicked();

    void on_pushButton_supprimer_personnel_clicked();

    void on_pushButton_rechercher_personnel_clicked();

    void on_radioButton_tri_personnel_clicked();

    void on_pushButton_ajouter_journaliste_clicked();

    void on_pushButton_modifier_journaliste_clicked();

    void on_pushButton_supprimer_journaliste_clicked();

    void on_radioButton_id_journaliste_clicked();

    void on_pushButton_rechercher_journaliste_clicked();

    void on_pushButton_Mail_2_clicked();

    void on_pushButton_imprimer_employe_clicked();




    void on_pushButton_statistique_clicked();

    void on_radioButton_id_journaliste_3_clicked();

    void on_pushButton_supprimer_journaliste_2_clicked();

    void on_pushButton_affichersalaires_clicked();

private:
    Ui::Dialoghamzaoui *ui;
    personnel tmppersonnel;
    journaliste tmpjournaliste;

Notification N;
 QMediaPlayer * sound;
};

#endif // DIALOGHAMZAOUI_H
