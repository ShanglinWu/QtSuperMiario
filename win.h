#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include "widget.h"

namespace Ui {
class win;
}

class win : public QWidget
{
    Q_OBJECT

public:
    explicit win(QWidget *parent = nullptr);
    ~win();

public slots:
    void when_restart_clicked(void);

private:
    Ui::win *ui;
};

#endif // WIN_H
