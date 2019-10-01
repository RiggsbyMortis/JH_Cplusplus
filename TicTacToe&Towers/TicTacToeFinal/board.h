#pragma once
#ifndef BOARD_H
#define BOARD_H

class Board
{
public:
	Board();
	bool IsFull() const;		//is the board full?
	bool IsLegalMove(int move) const;	//checks legality of player's moves
	bool IsWinner(char piece) const;	//takes a piece as an arguement, checks to see if that piece has won
	void Display() const;			//displays the board
	void Reset();					//resets the game
	void ReceiveMove(char piece, int move);	//receieves a piece and a move as arguements, uses them to receive a players move

	static const int NUM_SQUARES = 9;	//max num of suqares on a tictactoe grid
	static const char EMPTY = ' ';		//value to be shown if square is empty

private:
	static const int NUM_COMBOS = 8;
	static const int NUM_IN_COMBO = 3;
	static const int WINNING_COMBOS[NUM_COMBOS][NUM_IN_COMBO];

	char m_Squares[NUM_SQUARES];
};

#endif