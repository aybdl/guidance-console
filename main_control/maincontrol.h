#ifndef MAINCONTROL_H
#define MAINCONTROL_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QFileDialog>

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

    void on_pushButton_6_clicked();

private:
    Ui::MainControl *ui;
    QUdpSocket* UdpClient = nullptr;
    QUdpSocket *UdpServer = nullptr;
};
#endif // MAINCONTROL_H
