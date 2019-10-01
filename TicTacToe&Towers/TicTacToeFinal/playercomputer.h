#pragma once
#ifndef PLAYERCOMPUTER_H
#define PLAYERCOMPUTER_H

#include "player.h"

class Board;

class PlayerComputer : public Player
{
public:
	virtual void MakeMove(Board& board) const; //accepts a board state as an arguement, makes the move 
};

#endif