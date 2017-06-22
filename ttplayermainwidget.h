#ifndef TTPLAYERMAINWIDGET_H
#define TTPLAYERMAINWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include "ttplayerwidget.h"
#include "ttplayerslider.h"
#include "ttplayermsgbox.h"

class ttPlayerMainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ttPlayerMainWidget(QWidget *parent = nullptr);

    ttPlayerWidget *mPlayWidget;
    ttPlayerSlider *mPlaySlider;
    ttPlayerMsgBox *mMsgBox;

signals:

public slots:

private:
    QGridLayout *mainLayout;
};

#endif // TTPLAYERMAINWIDGET_H
