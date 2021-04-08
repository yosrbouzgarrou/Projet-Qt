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
    QString getDATE();
    int getID_INVITE();
    void setID_INTERVIEW( QString);
    void setNOM_JOURNALISTE( QString);
    void setDOMAINE( QString);
    void setDATE( QString);
    void setID_INVITE(int);
    bool ajouter();
    QSqlQueryModel *  afficher();
  bool supprimer(QString);
  bool modifier(QString);
  void PDF();

private:
    int ID_INVITE ;
    QString ID_INTERVIEW ,NOM_JOURNALISTE ,DOMAINE,DATE ;
};

#endif // INTERVIEW_H
