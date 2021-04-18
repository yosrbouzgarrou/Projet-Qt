#ifndef GESTION_INVITE_INTERVIEW_H
#define GESTION_INVITE_INTERVIEW_H
#include"invite.h"
#include"interview.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Gestion_Invite_Interview; }
QT_END_NAMESPACE

class Gestion_Invite_Interview : public QMainWindow
{
    Q_OBJECT

public:
    Gestion_Invite_Interview(QWidget *parent = nullptr);
    ~Gestion_Invite_Interview();
    void refresh();

    private slots:
    void on_ajouter_invite_clicked();

    void on_supprimeinvite_clicked();

    void on_modifierinvite_clicked();

    void on_trieinvite_clicked();

    void on_pageeee_currentIndexChanged(int index);

    void on_lineEdit_9_textChanged(const QString &arg1);

    void on_ajouter_6_clicked();

    void on_modifier_4_clicked();

    void on_supprimerintervoew_clicked();

    void on_pushButton_14_clicked();

    void sendMail();

    void mailSent(QString) ;
    void on_pushButton_15_clicked();

private:
    Ui::Gestion_Invite_Interview *ui;
    invite i;
    interview e ;
};
#endif // GESTION_INVITE_INTERVIEW_H
