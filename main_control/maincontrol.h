#ifndef MAINCONTROL_H
#define MAINCONTROL_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QFileDialog>
#include<QTimer>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainControl; }
QT_END_NAMESPACE

class MainControl : public QMainWindow
{
    Q_OBJECT

public:
    MainControl(QWidget *parent = nullptr);
    ~MainControl();
    QTimer *timSend;

private slots:
    void on_pushButton_clicked();
    void readyData();
    void timerupdate();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainControl *ui;
    QUdpSocket* UdpClient = nullptr;
    QUdpSocket *UdpServer = nullptr;
};
#endif // MAINCONTROL_H
