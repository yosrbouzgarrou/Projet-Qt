#ifndef INVITE_H
#define INVITE_H
#include<QString>
#include<QSqlQueryModel>
#include<QTextEdit>
class invite
{
public:
    invite();
    invite(int ,QString , QString ,QString );
    int getID_INVITE() ;
    QString getNOM_PRENOM () ;
    QString getEMAIL();
    QString getTEL();
    void setID_INVITE(int);
    void setNOM_PRENOM(QString);
    void setEMAIL(QString) ;
    void setTEL(QString) ;
    bool ajouter();
      QSqlQueryModel *  afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* recherche(QString);
    QSqlQueryModel*Tri_id();
    QSqlQueryModel*Tri_nom();
    void imprimer(QTextEdit *, QString);

private:
    int ID_INVITE ;
    QString NOM_PRENOM ,EMAIL , TEL ;
};

#endif // INVITE_H
