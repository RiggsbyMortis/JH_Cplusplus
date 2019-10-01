#include "player.h"

#include <iostream>

#include "board.h"

using namespace std;

const char Player::PIECES[NUM_PIECES] = { 'X', 'O' };

int Player::current = 0;

//constructor
Player::Player()
{
	m_Piece = PIECES[current];
	current = (current + 1) % NUM_PIECES;
}

//destructor
Player::~Player()
{
}

//returns the players piece to use in the game
char Player::GetPiece() const
{
	return m_Piece;
}

//same thing as above, but for the opponent
char Player::GetOpponentPiece() const
{
	char piece;

	if (m_Piece == PIECES[FIRST])
	{
		piece = PIECES[FIRST];
	}

	else
	{
		piece = PIECES[SECOND];
	}
	return piece;
}

//asks the player where they want to place their piece
void Player::MakeMove(Board& board) const
{
	int move;

	do
	{
		cout << "Player " << GetPiece();
		cout << ", where would you like to move? (0-8): ";
		cin >> move;
	} while (!board.IsLegalMove(move));

	board.ReceiveMove(GetPiece(), move);
}
