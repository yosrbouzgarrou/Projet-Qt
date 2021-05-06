#ifndef ARDUINO_H
#define ARDUINO_H


#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
class arduino
{
public:
    arduino();
bool connect_arduino();
int close_arduino();
bool write_arduino(QByteArray d);
QByteArray red_from_arduino();
QSerialPort *getserial();
QString getarduino_port_name();
~arduino();
private:

QSerialPort *serial;

static const quint16 arduino_uno_vendor_id=9025;
static const quint16 arduino_uno_producy_id=67;
QString arduino_port_name;
bool arduino_is_available;
QByteArray data;


};

#endif // ARDUINO_H
