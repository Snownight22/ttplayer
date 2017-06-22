#ifndef TTPLAYERMAINWINDOW_H
#define TTPLAYERMAINWINDOW_H

#include <QMainWindow>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include "ttplayermainwidget.h"

class ttPlayerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ttPlayerMainWindow(QWidget *parent = 0);
    ~ttPlayerMainWindow();

    void createAction();
    void createMenu();

private:
    QMenu *fileMenu;
    QMenu *editMenu;
    QAction *openAction;

    ttPlayerMainWidget *mMainWidget;
    //ttPlayerWidget *mPlayerWidget;

private slots:
    void slotOpenFile();
};

#endif // TTPLAYERMAINWINDOW_H
