#include "AIGameBoard.h"

AIGameBoard::AIGameBoard(QWidget *parent) : GameBoard()
{
    this->setParent(parent);
    this->move(10,10);
    this->resize(880, 880);
    this->setMouseTracking(true);
    //this->setPalette(QPalette(QColor(255, 0, 0)));
    //this->setAutoFillBackground(true);

    // add playerID to playerList
    numPlayer = 2;
    playerList[1] = 1, playerList[2] = 4;

    // init chessSquare
    for (int i = 1; i <= 121; ++i) chessSquare[i].id = i;
    // area 1
    for (int i = 20; i <= 23; ++i) chessSquare[i].areaID = 1;
    for (int i = 33; i <= 35; ++i) chessSquare[i].areaID = 1;
    for (int i = 45; i <= 46; ++i) chessSquare[i].areaID = 1;
    chessSquare[56].areaID = 1;
    // area 2
    chessSquare[75].areaID = 2;
    for (int i = 85; i <= 86; ++i) chessSquare[i].areaID = 2;
    for (int i = 96; i <= 98; ++i) chessSquare[i].areaID = 2;
    for (int i = 108; i <= 111; ++i) chessSquare[i].areaID = 2;
    // area 3
    for (int i = 112; i <= 121; ++i) chessSquare[i].areaID = 3;
    // area 4
    chessSquare[66].areaID = 4;
    for (int i = 76; i <= 77; ++i) chessSquare[i].areaID = 4;
    for (int i = 87; i <= 89; ++i) chessSquare[i].areaID = 4;
    for (int i = 99; i <= 102; ++i) chessSquare[i].areaID = 4;
    // area 5
    for (int i = 11; i <= 14; ++i) chessSquare[i].areaID = 5;
    for (int i = 24; i <= 26; ++i) chessSquare[i].areaID = 5;
    for (int i = 36; i <= 37; ++i) chessSquare[i].areaID = 5;
    chessSquare[47].areaID = 5;
    // area 6
    for (int i = 1; i <= 10; ++i) chessSquare[i].areaID = 6;

    // init chess
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

    // init edges
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

    // init center coordinates
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

    // init Timer
    paintTimerID = startTimer(8);
    stepTimerID = startTimer(30000);

    // init sound effects
    hitSound.setSource(QUrl::fromLocalFile(":/sounds/Resources/sounds/hit.wav"));

}

void AIGameBoard::mousePressEvent(QMouseEvent *event)
{
    if (mouseStatus == 2) return;
    int clickID = 0;
    for (int i = 1; i <= 121; ++i)
        if (mouseOnID(event, i))
        {
            clickID = i;
            break;
        }
    if (!mouseStatus)
    {
        if (!clickID) return;
        int isMyChess = 0;
        for (int i = 1; i <= 10; ++i)
            isMyChess |= (clickID == chess[playerList[nowPlayerID]][i].id);
        if (!isMyChess) return;
        mouseStatus = 1;
        selectedID = clickID;
        findReachableSquares(selectedID);
        return;
    }
    if (!clickID || selectedID == clickID) resetStatus();
    else if (isAbleToReach(clickID))
    {
        int id = 0;
        lastStep = clickID;
        lastPlayerID = nowPlayerID;
        for (int i = 1; i <= 10; ++i)
            if (selectedID == chess[playerList[nowPlayerID]][i].id) {id = i; break;}
//        qDebug() << selectedID << " " << clickID << " " << id;
        chess[playerList[nowPlayerID]][id].id = clickID;
        chess[playerList[nowPlayerID]][id].chessSquare = &chessSquare[clickID];
//        printPath(clickID);
        int tmp = nowPlayerID++;
        if (nowPlayerID > numPlayer) nowPlayerID = 1;

        path[0] = 0;
        int now = lastStep;
        while (now)
        {
            path[++path[0]] = now;
            now = fromWhichSquare[now];
        }
        resetStatus();
        checkWinner();

        animeLock = 1;
        animeNextID = path[0] - 1;
        animeX = pos[path[path[0]]].x();
        animeY = pos[path[path[0]]].y();
        animedx = (pos[path[animeNextID]].x() - animeX) / animeSpeedRate;
        animedy = (pos[path[animeNextID]].y() - animeY) / animeSpeedRate;
        animeDis = fabs(pos[path[animeNextID]].x() - animeX);
        animeDisCenter = (pos[path[animeNextID]].x() + animeX) / 2;
        mouseStatus = 2;

        emit playerChange(tmp, nowPlayerID, 1);
        killTimer(stepTimerID);
        stepTimerID = startTimer(30000);
    }
    else resetStatus();
    return;
}

void AIGameBoard::AIMain()
{
    // 随便写个AI吧
    qsrand(QTime(0, 0, 0).msecsTo(QTime::currentTime()));
    int AIStep = 0;
    while (!AIStep)
    {
        chessPiece* randChess = &chess[4][1 + (qrand() % 10)];
        findReachableSquares(randChess->id);
        if (!reachableSquareCount) {resetStatus(); continue;}
        int randStep = reachableSquareID[1 + (qrand() % reachableSquareCount)];
        int id = randChess->id;
        if (id > randStep) {resetStatus(); continue;}
        if (reachableSquareCount)
        {
            lastStep = randStep;
            lastPlayerID = nowPlayerID;
            randChess->id = randStep;
            randChess->chessSquare = &chessSquare[randStep];
            nowPlayerID = 1;

            path[0] = 0;
            int now = lastStep;
            while (now)
            {
                path[++path[0]] = now;
                now = fromWhichSquare[now];
            }
            resetStatus();
            checkWinner();

            animeLock = 1;
            animeNextID = path[0] - 1;
            animeX = pos[path[path[0]]].x();
            animeY = pos[path[path[0]]].y();
            animedx = (pos[path[animeNextID]].x() - animeX) / animeSpeedRate;
            animedy = (pos[path[animeNextID]].y() - animeY) / animeSpeedRate;
            animeDis = fabs(pos[path[animeNextID]].x() - animeX);
            animeDisCenter = (pos[path[animeNextID]].x() + animeX) / 2;

            emit playerChange(2, 1, 1);
            killTimer(stepTimerID);
            stepTimerID = startTimer(30000);
            AIStep = 1;
        }
        resetStatus();
    }
}

void AIGameBoard::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    // 绘制背景线
    drawBackgroundLine(&painter);
    // 绘制边框
    painter.setPen(QPen(Qt::black, 4.5, Qt::SolidLine));
    painter.setBrush(QBrush(QColor(240, 240, 240)));
    for (int i = 1; i <= 121; ++i)
        painter.drawEllipse(pos[i], 22, 22);
    // 绘制上一步提示
    painter.setPen(QPen(Qt::red, 4, Qt::DashLine));
    if (lastStep)
    {
        for (int i = path[0]; i > 1; --i)
            painter.drawLine(makeQLine(path[i], path[i-1]));
        painter.setPen(QPen(Qt::red, 10, Qt::SolidLine));
        painter.setBrush(QBrush(Qt::red));
        for (int i = path[0] - 1; i > 1; --i)
            painter.drawEllipse(pos[path[i]], 1.5, 1.5);
        painter.drawEllipse(pos[path[path[0]]], 3, 3);
        painter.drawEllipse(pos[path[1]], 3, 3);
    }
    if (animeLock)
    {
        killTimer(stepTimerID);
        stepTimerID = startTimer(30000);
        for (int i = 1; i <= numPlayer; ++i)
            for (int j = 1; j <= 10; ++j)
                if (chess[playerList[i]][j].id != lastStep)
                    painter.drawImage(pos[chess[playerList[i]][j].id] - QPointF(20, 20), teamColor[i]);
        animeX += animedx;
        animeY += animedy;
        double scaleRate = 1.3 - 0.6 * fabs(animeX - animeDisCenter) / animeDis;
        painter.drawImage(QPointF(animeX, animeY) - QPointF(20, 20) * scaleRate, teamColor[lastPlayerID].scaled(QSize(40, 40) * scaleRate));
        if (fabs(animeX - pos[path[animeNextID]].x()) < 1 && fabs(animeY - pos[path[animeNextID]].y()) < 1)
        {
            animeX = pos[path[animeNextID]].x();
            animeY = pos[path[animeNextID]].y();
            animeNextID-=1;
            if (!animeNextID)
            {
                animeLock = 0;
                mouseStatus = 0;
            }
            animedx = (pos[path[animeNextID]].x() - animeX) / animeSpeedRate;
            animedy = (pos[path[animeNextID]].y() - animeY) / animeSpeedRate;
            animeDis = fabs(pos[path[animeNextID]].x() - animeX);
            animeDisCenter = (pos[path[animeNextID]].x() + animeX) / 2;
            hitSound.play();
        }
        return;
    }
    if (lastPlayerID == 1)
    {
        lastPlayerID = 2;
        AIMain();
    }
    // 绘制棋子
    for (int i = 1; i <= numPlayer; ++i)
        for (int j = 1; j <= 10; ++j)
            painter.drawImage(pos[chess[playerList[i]][j].id] - QPointF(20, 20), teamColor[i]);
    // 绘制悬浮、选中效果
    painter.setPen(QPen(QColor(150, 114, 73), 4.5, Qt::SolidLine));
    painter.setBrush(QBrush());
    if (mouseoverID) painter.drawEllipse(pos[mouseoverID], 22, 22);
    if (selectedID)
    {
        painter.setPen(QPen(QColor(150, 114, 73), 8, Qt::SolidLine));
        painter.setBrush(Qt::transparent);
        QRectF tmp = QRectF((pos[selectedID] - QPointF(30, 30)).x(),(pos[selectedID] - QPointF(30, 30)).y(), 60, 60);
        painter.drawArc(tmp, 60 * 16, 60 * 16);
        painter.drawArc(tmp, 180 * 16, 60 * 16);
        painter.drawArc(tmp, 300 * 16, 60 * 16);
    }
    if (reachableSquareCount)
    {
        painter.setPen(QPen(Qt::black, 4.5, Qt::SolidLine));
        painter.setBrush(QBrush(QColor(253, 183, 175)));
        for (int i = 1; i <= reachableSquareCount; ++i)
            painter.drawEllipse(pos[reachableSquareID[i]], 22, 22);
    }
}

void AIGameBoard::timerEvent(QTimerEvent *event)
{
    int timerID = event->timerId();
    if (timerID == paintTimerID)
    {
        repaint();
        return;
    }
    if (timerID == stepTimerID)
    {
        selectedID = 0;
        int tmp = nowPlayerID++;
        if (nowPlayerID > numPlayer) nowPlayerID = 1;
        if (nowPlayerID == 2) lastPlayerID = 1;
        mouseStatus = 0;
        reachableSquareCount = 0;
        memset(reachableSquareID, 0, sizeof(reachableSquareID));
        emit playerChange(tmp, nowPlayerID,0);
        return;
    }
    return;
}
