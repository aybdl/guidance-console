#include "maincontrol.h"
#include "ui_maincontrol.h"


QByteArray Int2Byte(int int_data, int bits);
int Byte2Int(QByteArray bytes);
QByteArray Float2Byte(float data);
float Byte2Float(QByteArray byte);


MainControl::MainControl(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainControl)
{
    ui->setupUi(this);
    UdpClient = new QUdpSocket(this);
    UdpServer = new QUdpSocket(this);
    UdpServer->bind(QHostAddress::Any, 8002);
    connect(UdpServer, SIGNAL(readyRead()), this, SLOT(readyData()));
}

MainControl::~MainControl()
{
    delete ui;
}

//发送场景初始化
void MainControl::on_pushButton_clicked()
{
    QByteArray senddata;
    QByteArray byte_data;
    float testint=5129.03;
    byte_data=Float2Byte(testint);
    senddata.resize(5);
    senddata[0]='h';
    senddata[1]='e';
    senddata[2]='l';
    senddata[3]='l';
    senddata[4]='o';
    senddata.append(byte_data);
    UdpClient->writeDatagram(senddata,QHostAddress("127.0.0.1"),8002);
    //UdpClient->writeDatagram(ui->lineEdit->text().toUtf8(),QHostAddress("127.0.0.1"),8000);
}

void MainControl::readyData()
{
    QByteArray arr;
    float testread;

    arr.resize(UdpServer->bytesAvailable());
    UdpServer->readDatagram(arr.data(),arr.size());
    QByteArray y = arr.sliced(5, 4);
    testread=Byte2Float(y);
    ui->textBrowser->append(QString::number(testread,'f',3));
    //ui->textEdit->append(arr);
    //ui->lineEdit_2->setText(arr);
}







QByteArray Int2Byte(int int_data, int bits)
{
    static int andArray[4] = {0x000000FF, 0x0000FF00, 0x00FF0000, static_cast<int>(0xFF000000)};
    QByteArray byte_data;
    bits = (bits > 4 || bits <= 0)? 4: bits;//1/2/3/4

    for(int index = 0; index < bits; index++)
    {
        int offset = index * 8;
        byte_data.append((char) ((andArray[index] & int_data) >> offset));
    }
    return byte_data;
}
int Byte2Int(QByteArray bytes)
{
    int addr = bytes[0] & 0x000000FF;
    addr |= ((bytes[1] << 8) & 0x0000FF00);
    addr |= ((bytes[2] << 16) & 0x00FF0000);
    addr |= ((bytes[3] << 24) & 0xFF000000);
    return addr;
}
QByteArray Float2Byte(float data)
{
    QByteArray byte_data;

    char* data_char = (char*)&data;
    for(int index = 3; index >= 0; index--)
    {
        byte_data.append(data_char[index]);
    }
    return byte_data;
}

float Byte2Float(QByteArray byte)
{
    float result = 0;
    int size = byte.size();
    char* data_char = byte.data();
    char* p = (char*)&result;
    for(int index = 0; index < size; index++)
    {
        *(p + index) = *(data_char + size - 1 - index);
    }
    return result;
}

void MainControl::on_pushButton_6_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Select File", "D:\\",  "Text files (*.txt)");
    ui->lineEdit_2->setText(filename);

    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    while(!file.atEnd()) {
        QString line = file.readLine();
        line =line.trimmed();
        ui->plainTextEdit->appendPlainText(line);
    }

    file.close();

}

