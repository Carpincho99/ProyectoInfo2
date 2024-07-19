#include "mainwindow.h"

#include <QApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>


QSerialPort serial;

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

    serial.setPortName(arduino_uno_port_name);
    if(!serial.setBaudRate(QSerialPort::Baud115200))
        qDebug() << serial.errorString();
    if(!serial.setDataBits(QSerialPort::Data8))
        qDebug() << serial.errorString();
    if(!serial.setParity(QSerialPort::NoParity))
        qDebug() << serial.errorString();
    if(!serial.setStopBits(QSerialPort::OneStop))
        qDebug() << serial.errorString();
    if(!serial.setFlowControl(QSerialPort::NoFlowControl))
        qDebug() << serial.errorString();
    if(!serial.open(QIODevice::ReadWrite))
        qDebug() << serial.errorString();

    if(!serial.waitForReadyRead(-1)) //block until new data arrives
        qDebug() << "error: " << serial.errorString();
    else{
        QByteArray data = serial.readAll();
        qDebug() << data;
    }


    return a.exec();
}

void MainWindow::on_xNegativeButton_clicked()
{
    if(serial.isWritable()){
        serial.write("x-100\n");
    }
}


void MainWindow::on_smallXNegativeButton_clicked()
{
    if(serial.isWritable()){
        serial.write("x-10\n");
    }
}
void MainWindow::on_yNegativeButton_clicked()
{
    if(serial.isWritable()){
        serial.write("y-100\n");
    }
}


void MainWindow::on_smallYNegativeButton_clicked()
{
    if(serial.isWritable()){
        serial.write("y-10\n");
    }
}

void MainWindow::on_zNegativeButton_clicked()
{
    if(serial.isWritable()){
        serial.write("z-100\n");
    }
}


void MainWindow::on_smallZNegativeButton_clicked()
{
    if(serial.isWritable()){
        serial.write("z-10\n");
    }
}

//-----------------------------------------------------------------------------


void MainWindow::on_xPositiveButton_clicked()
{
    if(serial.isWritable()){
        serial.write("x100\n");
    }
}


void MainWindow::on_smallXPositiveButton_clicked()
{
    if(serial.isWritable()){
        serial.write("x10\n");
    }
}


void MainWindow::on_yPositiveButton_clicked()
{
    if(serial.isWritable()){
        serial.write("y100\n");
    }
}


void MainWindow::on_smallYPositiveButton_clicked()
{
    if(serial.isWritable()){
        serial.write("y10\n");
    }
}

void MainWindow::on_zPositiveButton_clicked()
{
    if(serial.isWritable()){
        serial.write("z100\n");
    }
}


void MainWindow::on_smallZPositiveButton_clicked()
{
    if(serial.isWritable()){
        serial.write("z10\n");
    }
}


void MainWindow::on_openClose_clicked()
{
    if(serial.isWritable()){
        serial.write("s\n");
    }
}



