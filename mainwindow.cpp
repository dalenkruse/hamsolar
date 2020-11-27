#include "mainwindow.h"
#include "ui_mainwindow.h"
 #include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(reload()));
    timer->start(21600000);   //1000msec = 1 sec, 3600000 = 1 hour, 21600000 = 6 hours
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reload()
{
    ui->solar_WV->load(QUrl("http://www.hamqsl.com/solar101pic.php"));
    ui->solar_WV->show();
}
