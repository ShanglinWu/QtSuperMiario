#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "configure.h"
#include "widget.h"
#include <QSoundEffect>>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void when_configure_clicked(void);
    void when_start_clicked(void);
    //void when_music_clicked(void);

private:
    Ui::MainWindow *ui;
    QSoundEffect * startSound;
};
#endif // MAINWINDOW_H
