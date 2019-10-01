#include "playercomputer.h"

#include <iostream>
#include "board.h"

using namespace std;

//if computer can win on next move, thats the move to make
void PlayerComputer::MakeMove(Board& board) const
{
	int move = 0;
	bool found = false;

	//loop to make the AI pick a spot
	while (!found && move < board.NUM_SQUARES)
	{
		if (board.IsLegalMove(move))
		{
			board.ReceiveMove(GetPiece(), move);
			found = board.IsWinner(GetPiece());		//this chunky monkey checks the legality and applies move if legal
			board.ReceiveMove(board.EMPTY, move);
		}

		if (!found)
		{
			++move;
		}
	}

	//otherwise, if opponent can win on the next move, that's the move to make
	if (!found)
	{
		move = 0;

		while (!found && move < board.NUM_SQUARES)
		{
			if (board.IsLegalMove(move))
			{
				board.ReceiveMove(GetOpponentPiece(), move);
				found = board.IsWinner(GetOpponentPiece());		//this chunky monkey checks the legality and applies move if legal
				board.ReceiveMove(board.EMPTY, move);
			}

			if (!found)
			{
				++move;
			}
		}
	}

	//this sexy beast has an array of the best (calculated) spots to place on the board, only if the above blocks aren't the best choice for the AI
	if (!found)
	{
		move = 0;
		int i = 0;

		const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };		//this is said array

		while (!found && i < board.NUM_SQUARES)
		{
			move = BEST_MOVES[i];
			if (board.IsLegalMove(move))		//this makes sure its a legal move
			{
				found = true;
			}

			++i;
		}
	}

	cout << "I, Player " << GetPiece();
	cout << ", shall take the square number ";
	cout << move << "." << endl;

	board.ReceiveMove(GetPiece(), move);
}