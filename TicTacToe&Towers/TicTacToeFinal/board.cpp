#include "board.h"
#include <iostream>

using namespace std;

//all possible winning combos
const int Board::WINNING_COMBOS[NUM_COMBOS][NUM_IN_COMBO] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6} };

Board::Board()
{
	Reset();
}

//is the board filled?
bool Board::IsFull() const
{
	bool full = true;
	int i = 0;

	while (full && i < NUM_SQUARES)
	{
		if (m_Squares[i] == EMPTY)
		{
			full = false;
		}

		++i;
	}
	return full;
}

//checks legality of player's moves
bool Board::IsLegalMove(int move) const
{
	return (move >= 0 && move < NUM_SQUARES && m_Squares[move] == EMPTY);
}

//chcecks to see if a player has won yet
bool Board::IsWinner(char piece) const
{
	bool winner = false;
	int i = 0;

	while (!winner && i < NUM_COMBOS)
	{
		int piecesInCombo = 0;

		for (int j = 0; j < NUM_IN_COMBO; j++)
		{
			if (m_Squares[WINNING_COMBOS[i][j]] == piece)
			{
				++piecesInCombo;
			}
		}

		if (piecesInCombo == NUM_IN_COMBO)
		{
			winner = true;
		}
		++i;
	}
	return winner;
}

//displays board
void Board::Display() const
{
	cout << endl << "\t" << m_Squares[0] << " | " << m_Squares[1] << " | " << m_Squares[2] << endl << "\t" << "----------" << endl;
	cout << endl << "\t" << m_Squares[3] << " | " << m_Squares[4] << " | " << m_Squares[5] << endl << "\t" << "----------" << endl;
	cout << endl << "\t" << m_Squares[6] << " | " << m_Squares[7] << " | " << m_Squares[8] << endl << "\t" << "----------" << endl;
	cout << endl << endl;
}

//resets the board
void Board::Reset()
{
	for (int i = 0; i < NUM_SQUARES; i++)
	{
		m_Squares[i] = EMPTY;
	}
}

//receives a move from a player, then sets the piece in that square
void Board::ReceiveMove(char piece, int move)
{
	m_Squares[move] = piece;
}
