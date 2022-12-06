#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <queue>
#include <QColor>
#include <QWidget>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <QMessageBox>
#include <QSoundEffect>

#include "chessPiece.h"
#include "chessSquare.h"

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    GameBoard(QWidget *parent);
    GameBoard(QWidget *parent, int *nP);
    ~GameBoard();

protected:
    //numPlayer:玩家总数   nowPlayerID:当前玩家在ID列表中的index   playerList:玩家ID列表
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

    void resetStatus();
    void checkWinner();
    void printPath(int now);
    int isAbleToReach(int id);
    int reachableSquareCount = 0, reachableSquareID[122] = {0};
    int lastStep = 0, fromWhichSquare[122] = {0}, path[122] = {0}; // path[0]记录数组长度
    void findReachableSquares(int id);

    int mouseoverID = 121, selectedID = 0;
    int mouseStatus = 0; // 0: unselected   1: selected   2: in animation
    int mouseOnID(QMouseEvent *event, int id);

    int lastPlayerID = 0;
    int animeLock = 0, animeNextID = 0, animeSpeedRate = 20, animeDis = 0, animeDisCenter = 0; // speedrate越大动画越慢
    double animeX = 0, animeY = 0, animedx = 0, animedy = 0;
    int paintTimerID, stepTimerID;

    QSoundEffect hitSound;

    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void timerEvent(QTimerEvent *event);
    void closeEvent(QCloseEvent *event);

signals:
    void playerChange(int playerID, int nxtPlayerID, int finished);
    void closed();
};

#endif // GAMEBOARD_H
