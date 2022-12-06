#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <QPushButton>

#include "chessSquare.h"

class chessPiece
{
public:
    chessPiece();
    int id;
    chessSquare *chessSquare;
};

#endif // CHESSPIECE_H
