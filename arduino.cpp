#include "arduino.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
arduino::arduino()
{
    serial= new QSerialPort;
}
bool  arduino::connect_arduino(){


    foreach(const QSerialPortInfo &serial_port_info,QSerialPortInfo::availablePorts()){
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
            if(serial_port_info.vendorIdentifier()==arduino_uno_vendor_id && serial_port_info.productIdentifier()==arduino_uno_producy_id){
                arduino_is_available=true;
            arduino_port_name=serial_port_info.portName();
            }
        }

    }
qDebug()<<"arduino_port_name is:"<< arduino_port_name;

   if(arduino_is_available){



    serial->setPortName(arduino_port_name);


    if(serial->open(QSerialPort::ReadWrite)){
        serial->setBaudRate(9600);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        return true;
   }

    else return false;


}

}
int arduino::close_arduino(){

    if(serial->isOpen()){
 serial->close();
            return 0;
}
return 1;
}
QByteArray arduino::red_from_arduino(){
QByteArray data;
    if(serial->isReadable()){
        data=serial->readAll();
        return data;
    }
    else
        return data;

}
bool arduino::write_arduino(QByteArray d){

    if(serial->isWritable()){
        serial->write(d);
    return true;

    }
    else{
        qDebug()<<"no no no";
        return false;
    }
    }
arduino::~arduino(){
    close_arduino();
    delete  serial;

}
QSerialPort* arduino::getserial(){
    return serial;


}



