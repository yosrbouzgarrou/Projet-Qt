#ifndef INTERVIEW_H
#define INTERVIEW_H
#include<QString>
#include<QSqlQueryModel>
#include<QTextEdit>

class interview
{
public:
    interview();
    interview(QString ,QString , QString ,QString , int);
    QString getID_INTERVIEW() ;
    QString getNOM_JOURNALISTE () ;
    QString getDOMAINE();
    QString getDATEE();
    int  getID_INVITE();
    void setID_INTERVIEW( QString);
    void setNOM_JOURNALISTE( QString);
    void setDOMAINE( QString);
    void setDATEE( QString);
    void setID_INVITE(int);
    bool ajouter();
    QSqlQueryModel *  afficher();
  bool supprimer(QString);
  bool modifier(QString);
  void PDF();

private:
    int ID_INVITE ;
    QString ID_INTERVIEW ,NOM_JOURNALISTE ,DOMAINE,DATEE ;
};

#endif // INTERVIEW_H
