#include "ttplayermainwindow.h"
#include <QFileDialog>
#include <QMenuBar>

ttPlayerMainWindow::ttPlayerMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QIcon sIcon("D:\\tt\\mysoft\\QTProj\\ttPlayer\\main.ico");// = new QIcon("main.ico");
    setWindowIcon(sIcon);

    createAction();
    createMenu();

    //mPlayerWidget = new ttPlayerWidget;
    //setWindowFlags(Qt::FramelessWindowHint);
    mMainWidget = new ttPlayerMainWidget;
    setCentralWidget(mMainWidget);
}

ttPlayerMainWindow::~ttPlayerMainWindow()
{

}

void ttPlayerMainWindow::createAction()
{
    openAction = new QAction(QIcon("D:\\tt\\svg\\open199.svg"), tr("打开"), this);
    openAction->setShortcut(tr("Ctrl+O"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(slotOpenFile()));
}

void ttPlayerMainWindow::createMenu()
{
    fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(openAction);
}

void ttPlayerMainWindow::slotOpenFile()
{
    QString name = QFileDialog::getOpenFileName(this, "打开", "D:\\", "video files(*.mp4)|*.*");
    mMainWidget->mPlayWidget->mPlayerThread->setFileName(name);
    mMainWidget->mPlayWidget->mPlayerThread->start();
}
