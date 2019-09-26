#include <iostream>

#include "game.h"

using namespace std;

int main()
{
	Game ticTacToe;

	
	

	bool wantsToPlay = false;

	char choice;
	char again;

	cout << "\t\t\t =+=+=+=+=+=" << endl;
	cout << "\t\t\t TIC-TAC-TOE" << endl;
	cout << "\t\t\t =+=+=+=+=+=" << endl << endl;
	cout << "A classic game of TicTacToe with an A.I twist!" << endl;
	cout << "Your goal is to dominate your opponent using the power of placement!" << endl;
	cout << "Would you like to play a game?";
	cin >> choice;

	if (choice == 'y')
	{
		wantsToPlay = true;
	}
	else if (choice == 'n')
	{
		cout << "Well okay! Sorry to see you go before trying against our fabulous A.I!";
		return 0;
	}
	else
	{
		cout << "Please enter a valid choice (y/n): ";
		cin >> choice;
	}


	while (wantsToPlay == true)
	{
		do
		{
			ticTacToe.DisplayInstructions();
			system("pause");
			ticTacToe.SetPlayers();
			ticTacToe.Play();
			cout << endl << "Play again? (y/n): ";
			cin >> again;
		} while (again != 'n');
		wantsToPlay = false;
	}
	return 0;
}