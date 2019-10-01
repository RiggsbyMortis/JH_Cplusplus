#pragma once
#ifndef PLAYERHUMAN_H
#define PLAYERHUMAN_H

#include "player.h"

class Board;

class PlayerHuman : public Player
{
public:
	virtual void MakeMove(Board& board) const;	//accepts a board state as an arguement, makes the move 
};
#endif