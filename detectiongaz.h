#ifndef DETECTIONGAZ_H
#define DETECTIONGAZ_H
//#include "arduinodetec.h"
#include "arduino.h"
#include <QDialog>

namespace Ui {
class detectiongaz;
}

class detectiongaz : public QDialog
{
    Q_OBJECT

public:
    explicit detectiongaz(QWidget *parent = nullptr);
    ~detectiongaz();

private:
    Ui::detectiongaz *ui;
    arduino a;
//    QByteArray dataa;
    QString dataa;
 private slots:
    void update_label();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
};

#endif // DETECTIONGAZ_H
