#include "maincontrol.h"
#include "ui_maincontrol.h"
#include "calculate_effectiveness.h"
#include<iostream>


QByteArray Int2Byte(int int_data, int bits);
int Byte2Int(QByteArray bytes);
QByteArray Float2Byte(float data);
QByteArray Double2Byte(double data);
QByteArray Short2Byte(short data);
QByteArray Long2Byte(qint64 data);
float Byte2Float(QByteArray byte);



QString newfilepath="C:/E/project/matlab/导控台/保存文件/test.txt";
QString filename;
QTimer *timer;//新建一个名为timer的QTimer类型变量
QFile *file;
QFile *aFile = new QFile(newfilepath);//创建 QFile对象用于实时写入UDP收到的文本数据，这个变量会在savelog函数中被调用
//打开文本，并以设置为以未追加的方式添加文本
QTextStream txtOutput;
QStringList lineList; //发送时保存



MainControl::MainControl(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainControl)
{
    ui->setupUi(this);
    UdpClient = new QUdpSocket(this);
    UdpServer = new QUdpSocket(this);
    UdpServer->bind(QHostAddress::Any, 8001);
    connect(UdpServer, SIGNAL(readyRead()), this, SLOT(readyData()));
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MainControl::timerupdate);//信号与槽的连接，当定时器超时时执行timerupdate函数
    //aFile->open(QIODevice::WriteOnly|QIODevice::Truncate);
    //aFile->close();
    aFile->open(QIODevice::Truncate | QIODevice::Append);//打开保存
}

MainControl::~MainControl()
{
    delete ui;
    aFile->close();
}

//发送场景初始化
void MainControl::on_pushButton_clicked()
{
    QByteArray senddata;
    //QByteArray byte_data;
    float w=0;//西经度
    float e=2;//东经度
    float s=0;//南经度
    float n=2;//北经度
    int dizhi=0;//地质
    float maxdepth=3000;//最大海水深度
    float maxhigh=5000;//最大海水高度
    int sandbox=0;//沙盘序号
    float grid=1;//网格步长
    float ra=1;//模型显示比例

    w=ui->lineEdit_7->text().toFloat();
    e=ui->lineEdit_14->text().toFloat();
    s=ui->lineEdit_17->text().toFloat();
    n=ui->lineEdit_11->text().toFloat();
    dizhi=ui->comboBox_3->currentIndex();
    maxdepth=ui->lineEdit_36->text().toFloat();
    maxhigh=ui->lineEdit_35->text().toFloat();
    sandbox=ui->comboBox->currentIndex();
    grid=ui->lineEdit_37->text().toFloat();
    ra=ui->lineEdit_38->text().toFloat();
    //byte_data=Float2Byte(testint);
    //senddata.resize(5);

    senddata.append(Float2Byte(w));
    senddata.append(Float2Byte(e));
    senddata.append(Float2Byte(s));
    senddata.append(Float2Byte(n));
    senddata.append(Int2Byte(dizhi,4));
    senddata.append(Float2Byte(maxdepth));
    senddata.append(Float2Byte(maxhigh));
    senddata.append(Int2Byte(sandbox,4));
    senddata.append(Float2Byte(grid));
    senddata.append(Float2Byte(ra));
    UdpClient->writeDatagram(senddata,QHostAddress(ui->lineEdit_6->text()),ui->lineEdit->text().toInt());
    //UdpClient->writeDatagram(ui->lineEdit->text().toUtf8(),QHostAddress("127.0.0.1"),8000);
    txtOutput.setDevice(aFile);//创建输出流，也可以用下面这一句代码代替这两句
    //QTextStream txtOutput(file);
    txtOutput<<senddata<<Qt::endl;
}
//发送初始实体模型
void MainControl::on_pushButton_7_clicked()
{
    QByteArray senddata;
    //QByteArray byte_data;
    int s1=0;//唯一标识
    int s2=0;//三维模型编号
    int s3=0;//属方编号
    int s4=0;//类型编号
    int s5=0;//是否鹰眼地图显示
    int s6=0;//是否添加至三维实体模型列表
    int s7=0;//是否删除该实体
    int s8=0;//实体之间连线是否限定在海面
    QByteArray s9;//实体名称
    //char c='0';


    s1=ui->lineEdit_39->text().toInt();
    s2=ui->comboBox_4->currentIndex();
    s3=ui->lineEdit_41->text().toInt();
    s4=ui->lineEdit_42->text().toInt();
    s5=ui->lineEdit_43->text().toInt();
    s6=ui->lineEdit_44->text().toInt();
    s7=ui->lineEdit_45->text().toInt();
    s8=ui->lineEdit_47->text().toInt();
    s9.append(ui->lineEdit_46->text().toUtf8());
    s9.resize(50,0x20);
    //byte_data=Float2Byte(testint);
    //senddata.resize(5);


    senddata.append(Int2Byte(s1,4));
    senddata.append(Int2Byte(s2,4));
    senddata.append(Int2Byte(s3,4));
    senddata.append(Int2Byte(s4,4));
    senddata.append(Int2Byte(s5,4));
    senddata.append(Int2Byte(s6,4));
    senddata.append(Int2Byte(s7,4));
    senddata.append(Int2Byte(s8,4));
    senddata.append(s9);
    UdpClient->writeDatagram(senddata,QHostAddress(ui->lineEdit_6->text()),ui->lineEdit->text().toInt());
    //UdpClient->writeDatagram(ui->lineEdit->text().toUtf8(),QHostAddress("127.0.0.1"),8000);
    txtOutput.setDevice(aFile);//创建输出流，也可以用下面这一句代码代替这两句
    //QTextStream txtOutput(file);
    txtOutput<<senddata<<Qt::endl;
}
//发送探测能力范围数据
void MainControl::on_pushButton_15_clicked()
{
    QByteArray senddata;
    //QByteArray byte_data;
    int s1=0;//传感器类型
    int s2=0;//传感器ID
    int s3=0;//所属平台ID
    float s4=0;//水平开角
    float s5=0;//垂直开角
    float s6=0;//探测距离
    float s7=0;//方向角度
    float s8=0;//纵向角度
    float s9=0;//横向角度
    float s10=0;//平台X轴向偏移量
    float s11=0;//平台Y轴向偏移量
    float s12=0;//平台Z轴向偏移量
    int s13=0;//是否有动画
    int s14=0;//是否限制到水面以下
    int s15=0;//颜色值R
    int s16=0;//颜色值G
    int s17=0;//颜色值B
    int s18=0;//颜色值透明度

    s1=ui->lineEdit_48->text().toInt();
    s2=ui->lineEdit_49->text().toInt();
    s3=ui->lineEdit_50->text().toInt();
    s4=ui->lineEdit_51->text().toFloat();
    s5=ui->lineEdit_52->text().toFloat();
    s6=ui->lineEdit_53->text().toFloat();
    s7=ui->lineEdit_54->text().toFloat();
    s8=ui->lineEdit_55->text().toFloat();
    s9=ui->lineEdit_56->text().toFloat();
    s10=ui->lineEdit_57->text().toFloat();
    s11=ui->lineEdit_58->text().toFloat();
    s12=ui->lineEdit_59->text().toFloat();
    s13=ui->lineEdit_60->text().toInt();
    s14=ui->lineEdit_61->text().toInt();
    s15=ui->lineEdit_62->text().toInt();
    s16=ui->lineEdit_63->text().toInt();
    s17=ui->lineEdit_64->text().toInt();
    s18=ui->lineEdit_65->text().toInt();
    //byte_data=Float2Byte(testint);
    //senddata.resize(5);


    senddata.append(Int2Byte(s1,4));
    senddata.append(Int2Byte(s2,4));
    senddata.append(Int2Byte(s3,4));
    senddata.append(Float2Byte(s4));
    senddata.append(Float2Byte(s5));
    senddata.append(Float2Byte(s6));
    senddata.append(Float2Byte(s7));
    senddata.append(Float2Byte(s8));
    senddata.append(Float2Byte(s9));
    senddata.append(Float2Byte(s10));
    senddata.append(Float2Byte(s11));
    senddata.append(Float2Byte(s12));
    senddata.append(Int2Byte(s13,4));
    senddata.append(Int2Byte(s14,4));
    senddata.append(Int2Byte(s15,4));
    senddata.append(Int2Byte(s16,4));
    senddata.append(Int2Byte(s17,4));
    senddata.append(Int2Byte(s18,4));
    UdpClient->writeDatagram(senddata,QHostAddress(ui->lineEdit_6->text()),ui->lineEdit->text().toInt());
    //UdpClient->writeDatagram(ui->lineEdit->text().toUtf8(),QHostAddress("127.0.0.1"),8000);
    txtOutput.setDevice(aFile);//创建输出流，也可以用下面这一句代码代替这两句
    //QTextStream txtOutput(file);
    txtOutput<<senddata<<Qt::endl;
}
//发送通信链接数据
void MainControl::on_pushButton_16_clicked()
{
    QByteArray senddata;
    //QByteArray byte_data;
    int s1=0;//收到信息平台ID
    int s2=0;//发送平台ID
    float s3=0;//收到信息平台高度偏移量
    float s4=0;//发送信息平台高度偏移量
    int s5=0;//通信显示样式
    int s6=0;//显示持续时间

    s1=ui->lineEdit_90->text().toInt();
    s2=ui->lineEdit_91->text().toInt();
    s3=ui->lineEdit_92->text().toInt();
    s4=ui->lineEdit_93->text().toFloat();
    s5=ui->lineEdit_94->text().toFloat();
    s6=ui->lineEdit_95->text().toFloat();

    //byte_data=Float2Byte(testint);
    //senddata.resize(5);


    senddata.append(Int2Byte(s1,4));
    senddata.append(Int2Byte(s2,4));
    senddata.append(Float2Byte(s3));
    senddata.append(Float2Byte(s4));
    senddata.append(Int2Byte(s5,4));
    senddata.append(Int2Byte(s6,4));
    UdpClient->writeDatagram(senddata,QHostAddress(ui->lineEdit_6->text()),ui->lineEdit->text().toInt());
    //UdpClient->writeDatagram(ui->lineEdit->text().toUtf8(),QHostAddress("127.0.0.1"),8000);
    txtOutput.setDevice(aFile);//创建输出流，也可以用下面这一句代码代替这两句
    //QTextStream txtOutput(file);
    txtOutput<<senddata<<Qt::endl;
}
void MainControl::readyData()
{
    QByteArray arr,command,data,linedata;
    //float testread;
    int datalen;
    //QStringList datalist;

    arr.resize(UdpServer->bytesAvailable());
    UdpServer->readDatagram(arr.data(),arr.size());
    command = arr.sliced(8,2);
    datalen=arr.sliced(10,2).toInt();
    data=arr.sliced(12,datalen);
    QList<QByteArray> lines = data.split(',');
    for(int i=0;i<lines.size();i++){
        linedata= lines[i];
        if (linedata[0]=='T'){
            QList<QByteArray> state = linedata.split('|');
            for(int j=0;j<state.size();j++){

            }
            }
    }
    //testread=Byte2Float(tem);
    //ui->textBrowser->append(QString::number(testread,'f',3));
    //ui->textBrowser->append(arr);
    //ui->textEdit->append(arr);
    //ui->lineEdit_2->setText(arr);
    //ui->plainTextEdit_2->appendPlainText(QString::number(testread,'f',3));
    //ui->plainTextEdit_2->appendPlainText(arr);
    //saveTextByIODevice(newfilepath);//在D:/Desktop/文件夹创建一个文本文档text.txt用于保存UDP通信数据
}

//读取文件
void MainControl::on_pushButton_6_clicked()
{
    filename = QFileDialog::getOpenFileName(this,"Select File", "D:\\",  "Text files (*.txt)");
    ui->lineEdit_2->setText(filename);

    file=new QFile(filename);
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text)) return;

    while(!file->atEnd()) {
        QString line = file->readLine();
        line =line.trimmed();
        ui->plainTextEdit->appendPlainText(line);
    }

    file->close();

}
//暂停/继续
void MainControl::on_pushButton_4_clicked()
{
    if( timer->isActive()){
        timer->stop();
    }
    else{
        timer->start(ui->lineEdit_40->text().toInt());//新建的定时器间隔为1s
    }
}

//发运动数据
void MainControl::on_pushButton_2_clicked()
{
    lineList.clear();
    timer->start(ui->lineEdit_40->text().toInt());//新建的定时器间隔为1s
    if(!file->isOpen())
        if(!file->open(QIODevice::ReadOnly | QIODevice::Text)) return;

}
void MainControl::timerupdate()
{
    while(!file->atEnd()) {
        QByteArray senddata;
        QString line = file->readLine();
        line =line.trimmed();
        int num_auv;

        lineList = line.split("  ");
        //ui->plainTextEdit_2->appendPlainText(line);
        //UdpClient->writeDatagram(line.toUtf8(),QHostAddress("127.0.0.1"),8001);
        num_auv=lineList.size()/11;


        for(int i = 0; i < num_auv; i++)
        {
            senddata.append('#');
            qint64 timexx=(qint64)1697884820309;

            senddata.append(Long2Byte(timexx));
            senddata.append(char(i+1));//平台ID
            senddata.append(char(0));//平台类型
            senddata.append(char(1));//报文类型
            senddata.append(Long2Byte(timexx));
            for (int j = 0; j < 11; j++){
                if(j==0){
                    senddata.append(Double2Byte(119.5));
                    //senddata.append(Double2Byte(lineList[i*11+j].toDouble()/200+119.5));
                }
                else if(j==1){
                    senddata.append(Double2Byte(20.5));
                    //senddata.append(Double2Byte(lineList[i*11+j].toDouble()/200+20.5));
                }
                else if(j<7){
                    senddata.append(Float2Byte(lineList[i*11+j].toFloat()));
                }
                else{
                    senddata.append(Short2Byte(lineList[i*11+j].toShort()));
                }
                //ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(lineList[i*7+j].toFloat(),'f',3)));
                //ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(num_auv)));
            //ui->plainTextEdit_3->appendPlainText(lineList[i]);
            }
            unsigned char sum=0x00;
            for (int k=0;k<senddata.size();k++){
                sum=sum+senddata[k];
            }
            senddata.append('1');
            senddata.append('$');
        }
        UdpClient->writeDatagram(senddata,QHostAddress(ui->lineEdit_6->text()),ui->lineEdit->text().toInt());
        break;

    }
    //ui->textEdit->setText(str);//显示当前时间
}

//结束这次发数据，关闭文件
void MainControl::on_pushButton_5_clicked()
{
    timer->stop();
    file->close();
}






//四个处理转换函数
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
    for(int index = 0; index <= 3; index++)
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
QByteArray Double2Byte(double data)
{
    QByteArray byte_data;

    char* data_char = (char*)&data;
    for(int index = 0; index <= 7; index++)
    {
        byte_data.append(data_char[index]);
    }
    return byte_data;
}
QByteArray Short2Byte(short data)
{
    QByteArray byte_data;

    char* data_char = (char*)&data;
    for(int index = 0; index <= 1; index++)
    {
        byte_data.append(data_char[index]);
    }
    return byte_data;
}
QByteArray Long2Byte(qint64 data)
{
    QByteArray byte_data;
    unsigned char byteArray[8];

    memcpy(byteArray, &data, 8);
    for(int i=0;i<8;i++){
        byte_data.append(byteArray[i]);
    }
    return byte_data;
}




void MainControl::on_tabWidget_currentChanged(int index)
{

}


void MainControl::on_pushButton_9_clicked()
{
    float effectiveness = get_effectiveness();
    std::cout<<effectiveness<<std::endl;
    QString out = QString::number(effectiveness);
    //QString out = "hello";
    ui->lineEdit_3->setText(out);

}

