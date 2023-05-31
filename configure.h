#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QWidget>

#include <mainwindow.h>

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

private:
    Ui::configure *ui;
};

#endif // CONFIGURE_H
