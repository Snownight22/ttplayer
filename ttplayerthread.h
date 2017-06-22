#ifndef TTPLAYERTHREAD_H
#define TTPLAYERTHREAD_H

#include <QThread>
#include <QImage>
extern "C"
{
    #include "libavcodec/avcodec.h"
    #include "libavformat/avformat.h"
    #include "libswscale/swscale.h"
    #include "libavutil/imgutils.h"
}

typedef struct ttPlayer_Conf
{
    QString fileName;
}stTtPlayerConf;

class ttPlayerThread : public QThread
{
    Q_OBJECT
public:
    explicit ttPlayerThread(QObject *parent = 0);

    QWidget *paintWidget;

    void threadInit();
    void setFileName(QString);

    void threadDestory();
    void run();

    void setPaintWidget(QWidget *widget) {this->paintWidget = widget;}

signals:
    void changePic(QImage);

private:
    stTtPlayerConf *mPlayerConf;
};

#endif // TTPLAYERTHREAD_H
