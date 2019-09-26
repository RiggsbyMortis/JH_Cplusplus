#pragma once
#ifndef PLAYER_H 
#define PLAYER_H

class Board;

class Player
{
public:
	Player();
	//virtual destructor in base class
	virtual ~Player();
	char GetPiece() const;
	char GetOpponentPiece() const;
	virtual void MakeMove(Board& board) const = 0;

private:
	static const int NUM_PIECES = 2;
	static const int FIRST = 0;
	static const int SECOND = 1;
	static const char PIECES[NUM_PIECES];
	static int current;

	char m_Piece;
};


#endif
