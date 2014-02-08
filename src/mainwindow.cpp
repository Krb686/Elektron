#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPainterPath>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->configure();
    this->gridDrawn = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::configure(){
    QObject::connect(ui->actionGrid, &QAction::triggered, this, &MainWindow::drawGrid);


}



void MainWindow::drawGrid(){
    int i = 0;
    int j = 0;

    QGraphicsScene *scene = new QGraphicsScene();
    QPainterPath *path = new QPainterPath(QPointF(0, 0));
    QPainter *painter = new QPainter(scene);

    if(this->gridDrawn == false){
        this->gridDrawn = true;



        QPen pen = QPen(Qt::DashLine);



        for(i=-20;i<20;i++){
            for (j=-20;j<20;j++){
                //path->addEllipse(i*10, j*10, 1, 1);
                painter->drawPoint(i, j);
            }

        }



        scene->addPath(*path);


        qDebug() << this->gridDrawn;
        qDebug() << painter->isActive();

        ui->graphicsView->setScene(scene);
        ui->graphicsView->show();
    } else {
        *path = QPainterPath();
        scene->addPath(*path);
    }






}

