#include <iostream>
#include <string>
#include "game.h"
#include "peg.h"

using namespace std;

const string Game::PEG1 = "Peg 1";
const string Game::PEG2 = "Peg 2";
const string Game::PEG3 = "Peg 3";
string Game::DISKS[NUM_DISKS] = { "EH", "BEER", "CANADA", "FRIGGINOH" };

Peg* Game::m_Peg1 = new Peg;
Peg* Game::m_Peg2 = new Peg;
Peg* Game::m_Peg3 = new Peg;


//constructor
Game::Game()
{
	Setup();
}

//status of whether or not game is won
bool Game::isWon() const
{
	//if all items are on Peg 3, in order, player wins
	if (Game::m_Peg3->Peg::Contains(DISKS[0]) && Game::m_Peg3->Peg::Contains(DISKS[1]) && Game::m_Peg3->Peg::Contains(DISKS[2]) && Game::m_Peg3->Peg::Contains(DISKS[3]))
	{
		cout << "Congratulations! You win!" << endl;
		return true;
	}
	//otherwise, player hasnt won
	return false;
}



//status of loss
//bool Game::isLost(const Peg& withoutPlayer) const
//{
//
//}

bool Game::isPlaying() const
{
	bool won = false;
	//if player has disks on peg 3, they win
	if (Game::m_Peg3->Peg::Count() == NUM_DISKS)
	{
		won = isWon();
	}
	//if player hasnt won, game still on
	return (!won);
}

void Game::Setup()
{
	Game::m_Peg1->Peg::Clear();
	Game::m_Peg2->Peg::Clear();
	Game::m_Peg3->Peg::Clear();

	for (int i = 0; i < NUM_DISKS; i++)
	{
		Game::m_Peg1->Peg::startAdd(DISKS[i]); 
	}
}

//displays instructions
void Game::DisplayInstructions() const

{
	cout << "\t\t\t +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=" << endl;
	cout << "\t\t\t =BOG 'N' DOUG'S TOWERS OF HANOVER+" << endl;
	cout << "\t\t\t +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=" << endl;
	system("pause");
	system("CLS");
	//displays instructions
	cout << "\t Hey there guy! Welcome to Bob and Doug's Towers of Hanover, eh?" << endl << endl;
	cout << "Rules are pretty straightforward. " << endl << endl;
	cout << "Move all the items from Peg 1 to Peg 3." << endl << endl;
	cout << "You may only move one disk at a time!" << endl << endl;
	cout << "The game will ask 3 questions per move." << endl << endl;
	cout << "First, it asks what peg you are taking the disk away from." << endl << endl;
	cout << "Then, it will ask where you want the disk to go." << endl << endl;
	cout << "Lastly, the game will ask the name of the disk you want to move." << endl << endl;
	cout << "NOTE: PLEASE ENSURE YOUR CAPSLOCK IS ON, THE PROGRAM ONLY WORKS IF YOU YELL AT IT" << endl << endl;
	cout << "Good luck, Have fun!" << endl << endl;
	system("pause");
}

//displays disks on pegs
void Game::DisplayPegs() const
{
	cout << PEG1 << endl;
	Game::m_Peg1->Peg::Display();
	cout << endl;

	cout << PEG2 << endl;
	Game::m_Peg2->Peg::Display();
	cout << endl;

	cout << PEG3 << endl;
	Game::m_Peg3->Peg::Display();
	cout << endl;

}

//moves a disk from one peg to another
void Game::MoveDisk(Peg& fromPeg, Peg& toPeg)
{	
	string diskName;
	cout << "Which disk would you like to move?";
	cin >> diskName;
	cout << endl << endl;
	
	while (diskName == fromPeg.m_pHead->m_Data)
	{
		if (toPeg.m_pHead == NULL)  // if the toPeg is empty
		{
			if (fromPeg.Contains(diskName) && fromPeg.Remove())
			{
				if (diskName == DISKS[0])
				{
					toPeg.Add(DISKS[0]);
				}
				else if (diskName == DISKS[1])
				{
					toPeg.Add(DISKS[1]);
				}
				else if (diskName == DISKS[2])
				{
					toPeg.Add(DISKS[2]);
				}
				else if (diskName == DISKS[3])
				{
					toPeg.Add(DISKS[3]);
				}
				return;
			}

			else if (!fromPeg.Contains(diskName))
			{
				cout << "Not a valid choice." << endl;
				return;
			}

			else
			{
				cout << "Not a valid choice." << endl;
				return;
			}
		}
		else
		{
			int handDiskSize = diskName.size();
			int toPegTopSize = toPeg.m_pHead->m_Data.size();
			if (handDiskSize < toPegTopSize) // if the toPeg has top disk bigger than removed disk 
			{
				
				for (int i = 0; i < NUM_DISKS; i++) //if the toPeg has stuff on it >
				{
					if (handDiskSize > toPegTopSize)
					{
						cout << "Not a valid move." << endl;//> make sure the move is legal >
						return;
					}

					else if (handDiskSize < toPegTopSize)
					{
						//Remove() returns true if succesful transfer
						if (fromPeg.Contains(fromPeg.m_pHead->m_Data) && handDiskSize < toPegTopSize) //does the fromPeg have the chosen disk?
						{
							fromPeg.Remove();
							if (diskName == DISKS[0])
							{
								toPeg.Add(DISKS[0]);				//j you still have to work out logic to place small disk on top of big one around here somewhere. love ya, rezz
							}
							else if (diskName == DISKS[1])
							{
								toPeg.Add(DISKS[1]);
							}
							else if (diskName == DISKS[2])  // these block says to add the removed disk to the toPeg 
							{
								toPeg.Add(DISKS[2]);
							}
							else if (diskName == DISKS[3])
							{
								toPeg.Add(DISKS[3]);
							}
							return;
						}

						else
						{
							cout << "Not a valid choice." << endl;
						}
					}
					return;
				}
			}
			else
			{
				cout << "Not a valid move." << endl;
				return;
			}
		}
		cout << endl;
	}
}

void Game::Play()
{
	
	DisplayPegs();

	string pegChoice1;
	string pegChoice2;

	

	do
	{
		
		cout << "Which Peg would you like to take a disk from?";
		cin >> pegChoice1;
		cout << endl << endl;
		cout << "Which peg would you like to move the disk to?";
		cin >> pegChoice2;
		cout << endl << endl;
		

		if (pegChoice1 == "PEG1" && pegChoice2 == "PEG2")
		{
			if (m_Peg1->isEmpty())
			{
				cout << "Peg is empty, pick a different peg!" << endl;
				Play();
			}
			else
			{
				MoveDisk(*m_Peg1, *m_Peg2);
				cout << PEG1 << endl;
				Game::m_Peg1->Peg::Display();
				cout << endl;
				cout << PEG2 << endl;
				Game::m_Peg2->Peg::Display();
				cout << endl;
				cout << PEG3 << endl;
				Game::m_Peg3->Peg::Display();
				cout << endl;
			}
		}

		else if (pegChoice1 == "PEG1" && pegChoice2 == "PEG3")
		{
			if (m_Peg1->isEmpty())
			{
				cout << "Peg is empty, pick a different peg!" << endl;
				Play();
			}
			else
			{
				MoveDisk(*m_Peg1, *m_Peg3);
				cout << PEG1 << endl;
				Game::m_Peg1->Peg::Display();
				cout << endl;
				cout << PEG2 << endl;
				Game::m_Peg2->Peg::Display();
				cout << endl;
				cout << PEG3 << endl;
				Game::m_Peg3->Peg::Display();
				cout << endl;
			}
		}

		else if (pegChoice1 == "PEG2" && pegChoice2 == "PEG1")
		{
			if (m_Peg2->isEmpty())
			{
				cout << "Peg is empty, pick a different peg!" << endl;
				Play();
			}
			else
			{
				MoveDisk(*m_Peg2, *m_Peg1);
				cout << PEG1 << endl;
				Game::m_Peg1->Peg::Display();
				cout << endl;
				cout << PEG2 << endl;
				Game::m_Peg2->Peg::Display();
				cout << endl;
				cout << PEG3 << endl;
				Game::m_Peg3->Peg::Display();
				cout << endl;
			}
		}

		else if (pegChoice1 == "PEG2" && pegChoice2 == "PEG3")
		{
			if (m_Peg2->isEmpty())
			{
				cout << "Peg is empty, pick a different peg!" << endl;
				Play();
			}
			else
			{
				MoveDisk(*m_Peg2, *m_Peg3);
				cout << PEG1 << endl;
				Game::m_Peg1->Peg::Display();
				cout << endl;
				cout << PEG2 << endl;
				Game::m_Peg2->Peg::Display();
				cout << endl;
				cout << PEG3 << endl;
				Game::m_Peg3->Peg::Display();
				cout << endl;
			}
		}

		else if (pegChoice1 == "PEG3" && pegChoice2 == "PEG1")
		{
			if (m_Peg3->isEmpty())
			{
				cout << "Peg is empty, pick a different peg!" << endl;
				Play();
			}
			else
			{
				MoveDisk(*m_Peg3, *m_Peg1);
				cout << PEG1 << endl;
				Game::m_Peg1->Peg::Display();
				cout << endl;
				cout << PEG2 << endl;
				Game::m_Peg2->Peg::Display();
				cout << endl;
				cout << PEG3 << endl;
				Game::m_Peg3->Peg::Display();
				cout << endl;
			}
		}

		else if (pegChoice1 == "PEG3" && pegChoice2 == "PEG2")
		{
			if (m_Peg3->isEmpty())
			{
				cout << "Peg is empty, pick a different peg!" << endl;
				Play();
			}
			else
			{
				MoveDisk(*m_Peg3, *m_Peg2);
				cout << PEG1 << endl;
				Game::m_Peg1->Peg::Display();
				cout << endl;
				cout << PEG2 << endl;
				Game::m_Peg2->Peg::Display();
				cout << endl;
				cout << PEG3 << endl;
				Game::m_Peg3->Peg::Display();
				cout << endl;
			}		
		}

		else
		{
			system("CLS");
			cout << "Not a valid move." << endl;
		}
	} while (isPlaying() && !isWon());

	return;
}
