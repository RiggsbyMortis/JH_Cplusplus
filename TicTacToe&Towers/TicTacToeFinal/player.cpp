#include "player.h"

#include <iostream>

#include "board.h"

using namespace std;

const char Player::PIECES[NUM_PIECES] = { 'X', 'O' };

int Player::current = 0;

Player::Player()
{
	m_Piece = PIECES[current];
	current = (current + 1) % NUM_PIECES;
}

Player::~Player()
{
}

char Player::GetPiece() const
{
	return m_Piece;
}

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
