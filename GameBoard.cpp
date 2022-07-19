#include <QDebug>

#include "GameBoard.h"

GameBoard::GameBoard(QWidget *parent, int *nP)
{
    this->setParent(parent);
    this->move(10,10);
    this->resize(880, 880);
    this->setMouseTracking(true);
    //this->setPalette(QPalette(teamColor[0]));
    //this->setAutoFillBackground(true);

    numPlayer = *nP;
    if (numPlayer == 2) playerList[1] = 1, playerList[2] = 4;
    if (numPlayer == 3) playerList[1] = 1, playerList[2] = 3, playerList[3] = 5;
    if (numPlayer == 4) playerList[1] = 1, playerList[2] = 2, playerList[3] = 4, playerList[4] = 5;
    if (numPlayer == 6) playerList[1] = 1, playerList[2] = 2, playerList[3] = 3, playerList[4] = 4, playerList[5] = 5, playerList[6] = 6;

    for (int i = 1; i <= 121; ++i) chessSquare[i].id = i;
    // area 6
    for (int i = 1; i <= 10; ++i) chessSquare[i].areaID = 6;
    // area 5
    for (int i = 11; i <= 14; ++i) chessSquare[i].areaID = 5;
    for (int i = 24; i <= 26; ++i) chessSquare[i].areaID = 5;
    for (int i = 36; i <= 37; ++i) chessSquare[i].areaID = 5;
    chessSquare[47].areaID = 5;
    // area 4
    chessSquare[66].areaID = 4;
    for (int i = 76; i <= 77; ++i) chessSquare[i].areaID = 4;
    for (int i = 87; i <= 89; ++i) chessSquare[i].areaID = 4;
    for (int i = 99; i <= 102; ++i) chessSquare[i].areaID = 4;
    // area 3
    for (int i = 112; i <= 121; ++i) chessSquare[i].areaID = 3;
    // area 2
    chessSquare[75].areaID = 2;
    for (int i = 85; i <= 86; ++i) chessSquare[i].areaID = 2;
    for (int i = 96; i <= 98; ++i) chessSquare[i].areaID = 2;
    for (int i = 108; i <= 111; ++i) chessSquare[i].areaID = 2;
    // area 1
    for (int i = 20; i <= 23; ++i) chessSquare[i].areaID = 1;
    for (int i = 33; i <= 35; ++i) chessSquare[i].areaID = 1;
    for (int i = 45; i <= 46; ++i) chessSquare[i].areaID = 1;
    chessSquare[56].areaID = 1;

    // team 1
    chess[1][1].chessSquare = &chessSquare[chess[1][1].id = 112];
    chess[1][2].chessSquare = &chessSquare[chess[1][2].id = 113];
    chess[1][3].chessSquare = &chessSquare[chess[1][3].id = 114];
    chess[1][4].chessSquare = &chessSquare[chess[1][4].id = 115];
    chess[1][5].chessSquare = &chessSquare[chess[1][5].id = 116];
    chess[1][6].chessSquare = &chessSquare[chess[1][6].id = 117];
    chess[1][7].chessSquare = &chessSquare[chess[1][7].id = 118];
    chess[1][8].chessSquare = &chessSquare[chess[1][8].id = 119];
    chess[1][9].chessSquare = &chessSquare[chess[1][9].id = 120];
    chess[1][10].chessSquare = &chessSquare[chess[1][10].id = 121];
    // team 2
    chess[2][1].chessSquare = &chessSquare[chess[2][1].id = 75];
    chess[2][2].chessSquare = &chessSquare[chess[2][2].id = 85];
    chess[2][3].chessSquare = &chessSquare[chess[2][3].id = 86];
    chess[2][4].chessSquare = &chessSquare[chess[2][4].id = 96];
    chess[2][5].chessSquare = &chessSquare[chess[2][5].id = 97];
    chess[2][6].chessSquare = &chessSquare[chess[2][6].id = 98];
    chess[2][7].chessSquare = &chessSquare[chess[2][7].id = 108];
    chess[2][8].chessSquare = &chessSquare[chess[2][8].id = 109];
    chess[2][9].chessSquare = &chessSquare[chess[2][9].id = 110];
    chess[2][10].chessSquare = &chessSquare[chess[2][10].id = 111];
    // team 3
    chess[3][1].chessSquare = &chessSquare[chess[3][1].id = 20];
    chess[3][2].chessSquare = &chessSquare[chess[3][2].id = 21];
    chess[3][3].chessSquare = &chessSquare[chess[3][3].id = 22];
    chess[3][4].chessSquare = &chessSquare[chess[3][4].id = 23];
    chess[3][5].chessSquare = &chessSquare[chess[3][5].id = 33];
    chess[3][6].chessSquare = &chessSquare[chess[3][6].id = 34];
    chess[3][7].chessSquare = &chessSquare[chess[3][7].id = 35];
    chess[3][8].chessSquare = &chessSquare[chess[3][8].id = 45];
    chess[3][9].chessSquare = &chessSquare[chess[3][9].id = 46];
    chess[3][10].chessSquare = &chessSquare[chess[3][10].id = 56];
    // team 4
    chess[4][1].chessSquare = &chessSquare[chess[4][1].id = 1];
    chess[4][2].chessSquare = &chessSquare[chess[4][2].id = 2];
    chess[4][3].chessSquare = &chessSquare[chess[4][3].id = 3];
    chess[4][4].chessSquare = &chessSquare[chess[4][4].id = 4];
    chess[4][5].chessSquare = &chessSquare[chess[4][5].id = 5];
    chess[4][6].chessSquare = &chessSquare[chess[4][6].id = 6];
    chess[4][7].chessSquare = &chessSquare[chess[4][7].id = 7];
    chess[4][8].chessSquare = &chessSquare[chess[4][8].id = 8];
    chess[4][9].chessSquare = &chessSquare[chess[4][9].id = 9];
    chess[4][10].chessSquare = &chessSquare[chess[4][10].id = 10];
    // team 5
    chess[5][1].chessSquare = &chessSquare[chess[5][1].id = 11];
    chess[5][2].chessSquare = &chessSquare[chess[5][2].id = 12];
    chess[5][3].chessSquare = &chessSquare[chess[5][3].id = 13];
    chess[5][4].chessSquare = &chessSquare[chess[5][4].id = 14];
    chess[5][5].chessSquare = &chessSquare[chess[5][5].id = 24];
    chess[5][6].chessSquare = &chessSquare[chess[5][6].id = 25];
    chess[5][7].chessSquare = &chessSquare[chess[5][7].id = 26];
    chess[5][8].chessSquare = &chessSquare[chess[5][8].id = 36];
    chess[5][9].chessSquare = &chessSquare[chess[5][9].id = 37];
    chess[5][10].chessSquare = &chessSquare[chess[5][10].id = 47];
    // team 6
    chess[6][1].chessSquare = &chessSquare[chess[6][1].id = 66];
    chess[6][2].chessSquare = &chessSquare[chess[6][2].id = 76];
    chess[6][3].chessSquare = &chessSquare[chess[6][3].id = 77];
    chess[6][4].chessSquare = &chessSquare[chess[6][4].id = 87];
    chess[6][5].chessSquare = &chessSquare[chess[6][5].id = 88];
    chess[6][6].chessSquare = &chessSquare[chess[6][6].id = 89];
    chess[6][7].chessSquare = &chessSquare[chess[6][7].id = 99];
    chess[6][8].chessSquare = &chessSquare[chess[6][8].id = 100];
    chess[6][9].chessSquare = &chessSquare[chess[6][9].id = 101];
    chess[6][10].chessSquare = &chessSquare[chess[6][10].id = 102];

    // init map
    int tmp = 1;
    memset(map, 0, sizeof(map));
    for (int i = 5; i <= 4 + dBoard[1]; ++i) map[1][i] = tmp++;
    for (int i = 5; i <= 4 + dBoard[2]; ++i) map[2][i] = tmp++;
    for (int i = 5; i <= 4 + dBoard[3]; ++i) map[3][i] = tmp++;
    for (int i = 5; i <= 4 + dBoard[4]; ++i) map[4][i] = tmp++;
    for (int i = 1; i <= dBoard[5]; ++i) map[5][i] = tmp++;
    for (int i = 2; i <= 1 + dBoard[6]; ++i) map[6][i] = tmp++;
    for (int i = 3; i <= 2 + dBoard[7]; ++i) map[7][i] = tmp++;
    for (int i = 4; i <= 3 + dBoard[8]; ++i) map[8][i] = tmp++;
    for (int i = 5; i <= 4 + dBoard[9]; ++i) map[9][i] = tmp++;
    for (int i = 5; i <= 4 + dBoard[10]; ++i) map[10][i] = tmp++;
    for (int i = 5; i <= 4 + dBoard[11]; ++i) map[11][i] = tmp++;
    for (int i = 5; i <= 4 + dBoard[12]; ++i) map[12][i] = tmp++;
    for (int i = 5; i <= 4 + dBoard[13]; ++i) map[13][i] = tmp++;
    for (int i = 10; i <= 9 + dBoard[14]; ++i) map[14][i] = tmp++;
    for (int i = 11; i <= 10 + dBoard[15]; ++i) map[15][i] = tmp++;
    for (int i = 12; i <= 11 + dBoard[16]; ++i) map[16][i] = tmp++;
    for (int i = 13; i <= 12 + dBoard[17]; ++i) map[17][i] = tmp++;
    for (int i = 1; i <= 17; ++i)
        for (int j = 1; j <= 17; ++j)
        {
            if (!map[i][j]) continue;
            chessSquare[map[i][j]].nxt[0] = !map[i-1][j-1] ? nullptr : &chessSquare[map[i-1][j-1]];
            chessSquare[map[i][j]].nxt[1] = !map[i-1][j] ? nullptr : &chessSquare[map[i-1][j]];
            chessSquare[map[i][j]].nxt[2] = !map[i][j+1] ? nullptr : &chessSquare[map[i][j+1]];
            chessSquare[map[i][j]].nxt[3] = !map[i+1][j+1] ? nullptr : &chessSquare[map[i+1][j+1]];
            chessSquare[map[i][j]].nxt[4] = !map[i+1][j] ? nullptr : &chessSquare[map[i+1][j]];
            chessSquare[map[i][j]].nxt[5] = !map[i][j-1] ? nullptr : &chessSquare[map[i][j-1]];
        }

    QPointF nowPoint = QPointF(200, 30);
    int len = 59;
    for (int i = 1; i <= 17; ++i)
    {
        for (int j = 1; j <= 17; ++j)
        {
            if (map[i][j]) pos[map[i][j]] = nowPoint;
            nowPoint += len * ix;
        }
        nowPoint += len * iy; nowPoint -= 17 * len * ix;
    }
}

GameBoard::~GameBoard()
{
}

QLine GameBoard::makeQLine(int i, int j)
{
    return QLine(pos[i].x(), pos[i].y(), pos[j].x(), pos[j].y());
}

void GameBoard::drawBackgroundLine(QPainter *painter)
{
    painter->setPen(QPen(Qt::black, 2, Qt::SolidLine));
    //draw horizontal lines
    painter->drawLine(makeQLine(2, 3));
    painter->drawLine(makeQLine(4, 6));
    painter->drawLine(makeQLine(7, 10));
    painter->drawLine(makeQLine(11, 23));
    painter->drawLine(makeQLine(24, 35));
    painter->drawLine(makeQLine(36, 46));
    painter->drawLine(makeQLine(47, 56));
    painter->drawLine(makeQLine(57, 65));
    painter->drawLine(makeQLine(66, 75));
    painter->drawLine(makeQLine(76, 86));
    painter->drawLine(makeQLine(87, 98));
    painter->drawLine(makeQLine(99, 111));
    painter->drawLine(makeQLine(112, 115));
    painter->drawLine(makeQLine(116, 118));
    painter->drawLine(makeQLine(119, 120));
    //draw right slash
    painter->drawLine(makeQLine(22, 35));
    painter->drawLine(makeQLine(21, 46));
    painter->drawLine(makeQLine(20, 56));
    painter->drawLine(makeQLine(1, 111));
    painter->drawLine(makeQLine(2, 110));
    painter->drawLine(makeQLine(4, 109));
    painter->drawLine(makeQLine(7, 108));
    painter->drawLine(makeQLine(15, 107));
    painter->drawLine(makeQLine(14, 115));
    painter->drawLine(makeQLine(13, 118));
    painter->drawLine(makeQLine(12, 120));
    painter->drawLine(makeQLine(11, 121));
    painter->drawLine(makeQLine(66, 102));
    painter->drawLine(makeQLine(76, 101));
    painter->drawLine(makeQLine(87, 100));
    //draw left slash
    painter->drawLine(makeQLine(12, 24));
    painter->drawLine(makeQLine(13, 36));
    painter->drawLine(makeQLine(14, 47));
    painter->drawLine(makeQLine(1, 99));
    painter->drawLine(makeQLine(3, 100));
    painter->drawLine(makeQLine(6, 101));
    painter->drawLine(makeQLine(10, 102));
    painter->drawLine(makeQLine(19, 103));
    painter->drawLine(makeQLine(20, 112));
    painter->drawLine(makeQLine(21, 116));
    painter->drawLine(makeQLine(22, 119));
    painter->drawLine(makeQLine(23, 121));
    painter->drawLine(makeQLine(75, 108));
    painter->drawLine(makeQLine(86, 109));
    painter->drawLine(makeQLine(98, 110));
}

void GameBoard::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    drawBackgroundLine(&painter); //绘制棋格线
    painter.setPen(QPen(Qt::black, 4, Qt::SolidLine));
    painter.setBrush(QBrush(teamColor[0]));
    for (int i = 1; i <= 121; ++i)
        painter.drawEllipse(pos[i], 20, 20); //绘制棋格
    for (int i = 1; i <= numPlayer; ++i) //绘制棋子
    {
        painter.setBrush(QBrush(teamColor[playerList[i]]));
        for (int j = 1; j <= 10; ++j)
            painter.drawEllipse(pos[chess[playerList[i]][j].id], 20, 20);
    }
    painter.setPen(QPen(QColor(160, 32, 240), 4, Qt::SolidLine));
    painter.setBrush(QBrush());
    painter.drawEllipse(pos[mouseoverID], 20, 20);
    if (selectedID) painter.drawRect(pos[selectedID].x() - 20, pos[selectedID].y() - 20, 40, 40);
    if (reachableSquareCount)
        for (int i = 1; i <= reachableSquareCount; ++i)
            painter.drawEllipse(pos[reachableSquareID[i]], 20, 20);
}

int GameBoard::mouseOnID(QMouseEvent *event, int id)
{
    return (pos[id].x() - event->x()) * (pos[id].x() - event->x()) + (pos[id].y() - event->y()) * (pos[id].y() - event->y()) <= 400;
}

void GameBoard::checkWinner()
{
    for (int i = 1; i <= numPlayer; ++i)
    {
        int flag = 1;
        for (int j = 1; j <= 10; ++j)
            flag &= (chessSquare[chess[playerList[i]][j].id].areaID + playerList[i] == 7);
        if (flag)
        {
            switch (playerList[i])
            {
                case 1: QMessageBox::information(this,"游戏结束","玩家 Red 获得胜利！"); break;
                case 2: QMessageBox::information(this,"游戏结束","玩家 Yellow 获得胜利！"); break;
                case 3: QMessageBox::information(this,"游戏结束","玩家 Blue 获得胜利！"); break;
                case 4: QMessageBox::information(this,"游戏结束","玩家 Green 获得胜利！"); break;
                case 5: QMessageBox::information(this,"游戏结束","玩家 Cyan 获得胜利！"); break;
                case 6: QMessageBox::information(this,"游戏结束","玩家 Pink 获得胜利！"); break;
            }
            this->close();
        }
    }
    return;
}

int GameBoard::isAbleToReach(int id)
{
    return 1;
    int flag = 0;
    for (int i = 1; i <= reachableSquareCount; ++i)
        flag |= (reachableSquareID[i] == id);
    return flag;
}

void GameBoard::findReachableSquares(int id)
{
    int flag[122] = {0}, check[122] = {0};
    std::queue<int> q;
    for (int i = 1; i <= numPlayer; ++i)
        for (int j = 1; j <= 10; ++j)
           flag[chess[playerList[i]][j].id] = 1;
    for (int i = 0; i < 6; ++i)
    {
        if (chessSquare[id].nxt[i] == nullptr) continue;
        if (!flag[chessSquare[id].nxt[i]->id]) reachableSquareID[++reachableSquareCount] = chessSquare[id].nxt[i]->id;
    }
    q.push(id); check[id] = 1;
    while (!q.empty())
    {
        int now = q.front(); q.pop();
        for (int i = 0; i < 6; ++i)
        {
            if (chessSquare[now].nxt[i] == nullptr) continue;
            int mid = chessSquare[now].nxt[i]->id, step = 1, b = 0;
            while (!flag[mid])
            {
                if (chessSquare[mid].nxt[i] != nullptr) mid = chessSquare[mid].nxt[i]->id;
                else {b = 1; break;}
                ++step;
            }
            if (b) continue;
            while (step)
            {
                if (chessSquare[mid].nxt[i] != nullptr) mid = chessSquare[mid].nxt[i]->id;
                else {b = 1; break;}
                --step;
                if (flag[mid]) break;
            }
            if (b) continue;
            if (!step && !flag[mid] && !check[mid])
            {
                reachableSquareID[++reachableSquareCount] = mid;
                q.push(mid);
                check[mid] = 1;
            }
        }
    }
}

void GameBoard::mouseMoveEvent(QMouseEvent *event)
{
    for (int i = 1; i <= 121; ++i)
        if (mouseOnID(event, i))
        {
            mouseoverID = i;
            break;
        }
    update();
    //qDebug() << id;
}

void GameBoard::mousePressEvent(QMouseEvent *event)
{
    int clickID = 0;
    for (int i = 1; i <= 121; ++i)
        if (mouseOnID(event, i))
        {
            clickID = i;
            break;
        }
    if (!clickID) return;
    if (!mouseStatus)
    {
        int isMyChess = 0;
        for (int i = 1; i <= 10; ++i)
            isMyChess |= (clickID == chess[playerList[nowPlayerID]][i].id);
        if (!isMyChess) return;
        mouseStatus = 1;
        selectedID = clickID;
        findReachableSquares(selectedID);
    }
    else if (selectedID == clickID)
    {
        selectedID = 0;
        mouseStatus = 0;
        reachableSquareCount = 0;
        memset(reachableSquareID, 0, sizeof(reachableSquareID));
    }
    else if (isAbleToReach(clickID))
    {
        int id = 0;
        for (int i = 1; i <= 10; ++i)
            if (selectedID == chess[playerList[nowPlayerID]][i].id) {id = i; break;}
        //qDebug() << selectedID << " " << clickID << " " << id;
        chess[playerList[nowPlayerID]][id].id = clickID;
        chess[playerList[nowPlayerID]][id].chessSquare = &chessSquare[clickID];
        selectedID = 0;
        ++nowPlayerID;
        if (nowPlayerID > numPlayer) nowPlayerID = 1;
        mouseStatus = 0;
        reachableSquareCount = 0;
        memset(reachableSquareID, 0, sizeof(reachableSquareID));
        checkWinner();
    }
    update();
    return;
}

void GameBoard::closeEvent(QCloseEvent *)
{
    emit closed();
}
