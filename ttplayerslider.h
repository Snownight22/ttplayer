#ifndef TTPLAYERSLIDER_H
#define TTPLAYERSLIDER_H

#include <QWidget>
#include <QSlider>
#include <QHBoxLayout>

class ttPlayerSlider : public QWidget
{
    Q_OBJECT
public:
    explicit ttPlayerSlider(QWidget *parent = nullptr);

signals:

public slots:

private:
    QSlider *processSlider;
    QHBoxLayout *mHboxLayout;
};

#endif // TTPLAYERSLIDER_H
