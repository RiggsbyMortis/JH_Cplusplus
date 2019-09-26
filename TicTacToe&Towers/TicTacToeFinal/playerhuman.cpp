#include "playerhuman.h"
#include <iostream>

#include "board.h"

using namespace std;

void PlayerHuman::MakeMove(Board& board) const
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
