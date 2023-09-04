#ifndef MAINCONTROL_H
#define MAINCONTROL_H

#include <QMainWindow>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainControl; }
QT_END_NAMESPACE

class MainControl : public QMainWindow
{
    Q_OBJECT

public:
    MainControl(QWidget *parent = nullptr);
    ~MainControl();

private slots:
    void on_pushButton_clicked();
    void readyData();

private:
    Ui::MainControl *ui;
    QUdpSocket* UdpClient = nullptr;
    QUdpSocket *UdpServer = nullptr;
};
#endif // MAINCONTROL_H
