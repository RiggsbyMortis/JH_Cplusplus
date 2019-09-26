#include "playercomputer.h"

#include <iostream>
#include "board.h"

using namespace std;

void PlayerComputer::MakeMove(Board& board) const
{
	int move = 0;
	bool found = false;

	while (!found && move < board.NUM_SQUARES)
	{
		if (board.IsLegalMove(move))
		{
			board.ReceiveMove(GetPiece(), move);
			found = board.IsWinner(GetPiece());
			board.ReceiveMove(board.EMPTY, move);
		}

		if (!found)
		{
			++move;
		}
	}

	if (!found)
	{
		move = 0;

		while (!found && move < board.NUM_SQUARES)
		{
			if (board.IsLegalMove(move))
			{
				board.ReceiveMove(GetOpponentPiece(), move);
				found = board.IsWinner(GetOpponentPiece());
				board.ReceiveMove(board.EMPTY, move);
			}

			if (!found)
			{
				++move;
			}
		}
	}

	if (!found)
	{
		move = 0;
		int i = 0;

		const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };

		while (!found && i < board.NUM_SQUARES)
		{
			move = BEST_MOVES[i];
			if (board.IsLegalMove(move))
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