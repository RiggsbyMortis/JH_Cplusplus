#pragma once
#ifndef PLAYERCOMPUTER_H
#define PLAYERCOMPUTER_H

#include "player.h"

class Board;

class PlayerComputer : public Player
{
public:
	virtual void MakeMove(Board& board) const;
};

#endif