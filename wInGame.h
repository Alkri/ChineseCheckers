#ifndef WINGAME_H
#define WINGAME_H

#include <QWidget>
#include <QLCDNumber>

#include "GameBoard.h"

namespace Ui
{
    class wInGame;
}

class wInGame : public QWidget
{
    Q_OBJECT

public:
    wInGame(QWidget *parent = nullptr, int *nP = 0);
    ~wInGame();

private:
    Ui::wInGame *ui;
    GameBoard *gBoard; //棋盘

    int numPlayer;
    QString teamColor[7] = {
        "",
        "<img src=':/images/Resources/images/red.png' height='18' width='18'></img>",
        "<img src=':/images/Resources/images/orange.png' height='18' width='18'></img>",
        "<img src=':/images/Resources/images/yellow.png' height='18' width='18'></img>",
        "<img src=':/images/Resources/images/blue.png' height='18' width='18'></img>",
        "<img src=':/images/Resources/images/green.png' height='18' width='18'></img>",
        "<img src=':/images/Resources/images/purple.png' height='18' width='18'></img>"
    };

    QLCDNumber *stepTimerLCD;
    int LCDCountTimerID;    
    void playerChange(int playerID, int nxtPlayerID, int finished);

protected:
    void closeEvent(QCloseEvent *);
    void timerEvent(QTimerEvent *event);

signals:
    void closed();
};

#endif // WINGAME_H
