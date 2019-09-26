#pragma once
#ifndef PLAYERHUMAN_H
#define PLAYERHUMAN_H

#include "player.h"

class Board;

class PlayerHuman : public Player
{
public:
	virtual void MakeMove(Board& board) const;
};
#endif