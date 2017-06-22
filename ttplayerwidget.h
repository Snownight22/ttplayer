#ifndef TTPLAYERWIDGET_H
#define TTPLAYERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPaintEvent>
#include <QImage>
#include "ttplayerthread.h"

class ttPlayerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ttPlayerWidget(QWidget *parent = nullptr);
    ttPlayerThread *mPlayerThread;

protected:
    void paintEvent(QPaintEvent *);

private:
    QImage mImage;

signals:

public slots:
    void displayImage(QImage);
};

#endif // TTPLAYERWIDGET_H
