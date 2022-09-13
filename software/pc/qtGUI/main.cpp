#include "mainwindow.h"

#include <QApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>


QSerialPort arduino;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString arduino_uno_port_name;


    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 1;

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            if((serialPortInfo.productIdentifier() == arduino_uno_product_id) && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                arduino_uno_port_name = serialPortInfo.portName();
            }
        }
    }

    arduino.setPortName(arduino_uno_port_name);
    if(!arduino.setBaudRate(QSerialPort::Baud115200))
        qDebug() << arduino.errorString();
    if(!arduino.setDataBits(QSerialPort::Data8))
        qDebug() << arduino.errorString();
    if(!arduino.setParity(QSerialPort::NoParity))
        qDebug() << arduino.errorString();
    if(!arduino.setStopBits(QSerialPort::OneStop))
        qDebug() << arduino.errorString();
    if(!arduino.setFlowControl(QSerialPort::NoFlowControl))
        qDebug() << arduino.errorString();
    if(!arduino.open(QIODevice::ReadWrite))
        qDebug() << arduino.errorString();

    if(!arduino.waitForReadyRead(-1)) //block until new data arrives
        qDebug() << "error: " << arduino.errorString();
    else{
        QByteArray data = arduino.readAll();
        qDebug() << data;
    }


    return a.exec();
}

void MainWindow::on_xPositiveButton_clicked()
{
    if(arduino.isWritable()){
        arduino.write("x-10\n");
    }

}
