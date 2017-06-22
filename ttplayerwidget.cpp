#include "ttplayerwidget.h"
#include <QPainter>
#include "ttplayerthread.h"

ttPlayerWidget::ttPlayerWidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(600, 400);
    setPalette(QPalette(Qt::black));
    setAutoFillBackground(true);
    //setWindowFlags(Qt::FramelessWindowHint);

    mPlayerThread = new ttPlayerThread;
    connect(mPlayerThread, SIGNAL(changePic(QImage)), this, SLOT(displayImage(QImage)));
    //mPlayerThread->start();
}

void ttPlayerWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //QImage mImage("D:\\hm.jpg");
    QImage img = mImage.scaled(this->size(),Qt::KeepAspectRatio);
    int x = (this->width() - img.width()) / 2;
    int y = (this->height() - img.height()) / 2;

    painter.drawImage(QPoint(x, y), img);
}

void ttPlayerWidget::displayImage(QImage img)
{
    mImage = img;
    update();
}
