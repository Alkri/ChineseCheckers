#include <QDebug>

#include "wInGame.h"
#include "ui_wInGame.h"

wInGame::wInGame(QWidget *parent, int *nP)
    : QWidget(parent), ui(new Ui::wInGame)
{
    ui->setupUi(this);
    numPlayer = *nP;
    gBoard = new GameBoard(this, nP);
    gBoard->show();
    connect(gBoard, &GameBoard::closed, this, &wInGame::close);
}

wInGame::~wInGame()
{
    delete ui;
}

void wInGame::closeEvent(QCloseEvent *)
{
    emit closed();
}
