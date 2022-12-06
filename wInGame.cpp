#include <QDebug>

#include "wInGame.h"
#include "ui_wInGame.h"

wInGame::wInGame(QWidget *parent, int *nP, int mode)
    : QWidget(parent), ui(new Ui::wInGame)
{
    ui->setupUi(this);
    numPlayer = *nP;
    if (mode == 1) {
        gBoard = new GameBoard(this, nP);
        gBoard->show();
    }
    else if (mode == 2) {
        gBoard = new AIGameBoard(this);
        gBoard->show();
    }
    stepTimerLCD = new QLCDNumber(2, this);
    stepTimerLCD->move(1100, 10);
    stepTimerLCD->resize(81, 71);
    stepTimerLCD->display(30);
    LCDCountTimerID = startTimer(1000);
    connect(gBoard, &GameBoard::playerChange, this, &wInGame::playerChange);
    connect(gBoard, &GameBoard::closed, this, &wInGame::close);
    ui->textBrowser->append("现在是" + teamColor[1] + "的回合。");
}

wInGame::~wInGame()
{
    delete ui;
}

void wInGame::playerChange(int playerID, int nxtPlayerID, int finished)
{
    stepTimerLCD->display(30);
    if (!finished)
    {
        ui->textBrowser->append(teamColor[playerID] + "<font color='red'>大e了，没有下！</font>");
    }
    ui->textBrowser->append("现在是" + teamColor[nxtPlayerID] + "的回合。");
}

void wInGame::closeEvent(QCloseEvent *)
{
    emit closed();
}

void wInGame::timerEvent(QTimerEvent *event)
{
    int timerID = event->timerId();
    if (timerID == LCDCountTimerID)
    {
        stepTimerLCD->display(stepTimerLCD->intValue() - 1);
        return;
    }
}
