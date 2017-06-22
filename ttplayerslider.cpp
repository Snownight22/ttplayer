#include "ttplayerslider.h"

ttPlayerSlider::ttPlayerSlider(QWidget *parent) : QWidget(parent)
{
    setFixedHeight(40);
    processSlider = new QSlider(Qt::Horizontal);
    mHboxLayout = new QHBoxLayout;
    mHboxLayout->addWidget(processSlider);
    setLayout(mHboxLayout);
}
