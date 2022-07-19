#ifndef CHESSSQUARE_H
#define CHESSSQUARE_H

class chessSquare
{
public:
    chessSquare();
    chessSquare *nxt[6];
    int id = 0, areaID = 0;
};

#endif // CHESSSQUARE_H
