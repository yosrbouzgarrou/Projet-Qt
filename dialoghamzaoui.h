#ifndef DIALOGHAMZAOUI_H
#define DIALOGHAMZAOUI_H
#include "personnel.h"
#include "journaliste.h"

#include <QDialog>

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

private:
    Ui::Dialoghamzaoui *ui;
    personnel tmppersonnel;
    journaliste tmpjournaliste;
};

#endif // DIALOGHAMZAOUI_H
