#include "playerhuman.h"
#include <iostream>

#include "board.h"

using namespace std;

//Gets a players move
void PlayerHuman::MakeMove(Board& board) const
{
	int move;

	//loop to ask player the question
	do
	{
		cout << "Player " << GetPiece();
		cout << ", where would you like to move? (0-8): ";
		cin >> move;
	} while (!board.IsLegalMove(move));

	//board receives the move
	board.ReceiveMove(GetPiece(), move);
}
