#ifndef AIGAMEBOARD_H
#define AIGAMEBOARD_H

#include <QtGlobal>
#include <QWidget>
#include <QTime>
#include <QDebug>

#include "GameBoard.h"

class AIGameBoard : public GameBoard
{
    Q_OBJECT
public:
    explicit AIGameBoard(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *event);
    void AIMain();
};

#endif // AIGAMEBOARD_H
