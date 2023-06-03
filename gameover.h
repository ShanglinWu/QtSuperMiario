#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>

namespace Ui {
class gameover;
}

class gameover : public QWidget
{
    Q_OBJECT

public:
    explicit gameover(QWidget *parent = nullptr);
    ~gameover();
public slots:
    void when_restart_clicked(void);

private:
    Ui::gameover *ui;
};

#endif // GAMEOVER_H
