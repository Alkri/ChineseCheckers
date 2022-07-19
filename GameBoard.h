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
    //numPlayer:玩家总数 nowPlayerID:当前玩家ID playerList:玩家ID列表
    int numPlayer, nowPlayerID = 1, playerList[7];

    QColor teamColor[7] = {
        QColor(240, 240, 240),
        QColor(255, 0, 0),
        QColor(255, 255, 0),
        QColor(0, 0, 255),
        QColor(0, 255, 0),
        QColor(0, 255, 255),
        QColor(254, 137, 210)
    };
    int map[20][20]; //变换后矩阵
    QPointF pos[122]; //对应ID格子中心点坐标
    chessSquare chessSquare[122];
    chessPiece chess[7][11];

    QLine makeQLine(int i, int j);
    void drawBackgroundLine(QPainter *painter);
    virtual void paintEvent(QPaintEvent *); //绘制棋盘
    QPointF ix = QPointF(1, 0), iy = QPointF(-0.5, sqrt(3)/2);
    int dBoard[18] = {0, 1, 2, 3, 4, 13, 12, 11, 10, 9, 10, 11, 12, 13, 4, 3, 2, 1}; //每行格数

    void checkWinner();
    int isAbleToReach(int id);
    int reachableSquareCount = 0, reachableSquareID[122] = {0};
    void findReachableSquares(int id);

    int mouseoverID = 121, selectedID = 0;
    int mouseStatus = 0; // 0: unselected   1: selected
    int mouseOnID(QMouseEvent *event, int id);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *);

signals:
    void closed();
};

#endif // GAMEBOARD_H
