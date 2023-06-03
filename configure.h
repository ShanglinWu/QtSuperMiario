#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QWidget>

#include "mainwindow.h"
#include "widget.h"

namespace Ui {
class configure;
}

class configure : public QWidget
{
    Q_OBJECT

public:
    explicit configure(QWidget *parent = nullptr);
    ~configure();

public slots:
    void when_voice_clicked(void);
    void when_music_clicked(void);

private:
    Ui::configure *ui;
};

#endif // CONFIGURE_H
