#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <queue>
#include <QColor>
#include <QWidget>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <QMessageBox>

#include "chessPiece.h"
#include "chessSquare.h"

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    GameBoard(QWidget *parent, int *nP);
    ~GameBoard();

private:
    //numPlayer:玩家总数   playerList:玩家ID列表
    int numPlayer, nowPlayerID = 1, playerList[7];

    QImage teamColor[7] = {
        QImage(),
        QImage(":/images/Resources/images/red.png"),
        QImage(":/images/Resources/images/orange.png"),
        QImage(":/images/Resources/images/yellow.png"),
        QImage(":/images/Resources/images/blue.png"),
        QImage(":/images/Resources/images/green.png"),
        QImage(":/images/Resources/images/purple.png")
    };
    QString playerName[7] = {
        QString(),
        QString("Red"),
        QString("Orange"),
        QString("Yellow"),
        QString("Blue"),
        QString("Green"),
        QString("Purple")
    };
    int map[20][20]; //变换后矩阵
    QPointF pos[122]; //对应ID格子中心点坐标
    chessSquare chessSquare[122];
    chessPiece chess[7][11];

    QLine makeQLine(int i, int j);
    void drawBackgroundLine(QPainter *painter);
    QPointF ix = QPointF(1, 0), iy = QPointF(-0.5, sqrt(3)/2);
    int dBoard[18] = {0, 1, 2, 3, 4, 13, 12, 11, 10, 9, 10, 11, 12, 13, 4, 3, 2, 1};

    void checkWinner();
    int isAbleToReach(int id);
    int reachableSquareCount = 0, reachableSquareID[122] = {0};
    void findReachableSquares(int id);

    int mouseoverID = 121, selectedID = 0;
    int mouseStatus = 0; // 0: unselected   1: selected
    int mouseOnID(QMouseEvent *event, int id);

    int paintTimerID, stepTimerID;

protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void timerEvent(QTimerEvent *event);

signals:
    void playerChange(int playerID, int nxtPlayerID, int finished);
};

#endif // GAMEBOARD_H
