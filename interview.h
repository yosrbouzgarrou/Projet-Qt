#ifndef INTERVIEW_H
#define INTERVIEW_H
#include<QString>
#include<QSqlQueryModel>
#include<QTextEdit>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtWidgets/QGridLayout>
QT_CHARTS_USE_NAMESPACE

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
  int  verif(int XXX);

   QChartView * stat();

  QSqlQueryModel * afficherid();


private:
    int ID_INVITE ;
    QString ID_INTERVIEW ,NOM_JOURNALISTE ,DOMAINE,DATEE ;
};

#endif // INTERVIEW_H
