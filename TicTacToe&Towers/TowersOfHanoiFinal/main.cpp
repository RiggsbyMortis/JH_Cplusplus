#include "game.h"
#include <iostream>

using namespace std;

int main()
{
	Game towersOfHanoi;

	towersOfHanoi.DisplayInstructions();
	system("CLS");

	char choice;

	do
	{
		cout << "Hey there, guy! Care for a rousing round of Bob and Doug's Unofficial Towers of Hanover? (Y/N)";
		cin >> choice;
		if (choice == 'N')
		{
			cout << "Okay, bud! Catch ya later, eh?" << endl;
		}
		else if (choice != 'N' && choice != 'Y')
		{
			cout << "Please enter a valid option (Y/N): ";
			cin >> choice;
		}
		while (choice == 'Y')
		{
			system("CLS");
			towersOfHanoi.Play();
			cout << endl;
		}
		
		return 0;
	} while (choice != 'Y');
	return 0;
}