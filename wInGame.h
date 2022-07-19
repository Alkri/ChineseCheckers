#ifndef WINGAME_H
#define WINGAME_H

#include <QWidget>

#include "GameBoard.h"

namespace Ui
{
    class wInGame;
}

class wInGame : public QWidget
{
    Q_OBJECT

public:
    explicit wInGame(QWidget *parent = nullptr, int *nP = 0);
    ~wInGame();

private:
    Ui::wInGame *ui;
    GameBoard *gBoard; //棋盘

    int numPlayer;

protected:
    void closeEvent(QCloseEvent *);

signals:
    void closed();
};

#endif // WINGAME_H
