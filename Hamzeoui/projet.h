#ifndef PROJET_H
#define PROJET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class projet; }
QT_END_NAMESPACE

class projet : public QMainWindow
{
    Q_OBJECT

public:
    projet(QWidget *parent = nullptr);

    ~projet();
private slots:
    void on_pushButton_ajouter_personnel_clicked();

    void on_pushButton_supprimer_personnel_clicked();

    void on_pushButton_modifier_personnel_clicked();
private:
    Ui::projet *ui;
    personnel tmp;



};
#endif // PROJET_H
