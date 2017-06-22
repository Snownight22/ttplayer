#include "ttplayermainwidget.h"

ttPlayerMainWidget::ttPlayerMainWidget(QWidget *parent) : QWidget(parent)
{
    mPlayWidget = new ttPlayerWidget;
    mPlaySlider = new ttPlayerSlider;
    mMsgBox = new ttPlayerMsgBox;

    mainLayout = new QGridLayout;
    mainLayout->addWidget(mPlayWidget, 0, 0);
    mainLayout->addWidget(mMsgBox, 0, 1, 2, 1);
    mainLayout->addWidget(mPlaySlider, 1, 0);

    //mMsgBox->hide();
    //mMsgBox->setStyleSheet("border:1px solid black");

    //setStyleSheet("QWidget#mMsgBox{border:2px solid #454648;}");
    setLayout(mainLayout);
}
