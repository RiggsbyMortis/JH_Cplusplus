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
	char GetPiece() const; //gets piece
	char GetOpponentPiece() const; //gets opponents piece
	virtual void MakeMove(Board& board) const = 0; //gets a board, and makes the move the player has asked for

private:
	static const int NUM_PIECES = 2; //num of pieces for game (X's and O's)
	static const int FIRST = 0;
	static const int SECOND = 1;
	static const char PIECES[NUM_PIECES]; //array of pieces
	static int current; //current piece

	char m_Piece; //data member for the piece
};


#endif
