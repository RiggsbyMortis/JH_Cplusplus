#include <iostream>
#include <string>
#include "game.h"
#include "peg.h"

using namespace std;

//contants for the pegs
const string Game::PEG1 = "Peg 1";
const string Game::PEG2 = "Peg 2";
const string Game::PEG3 = "Peg 3";
string Game::DISKS[NUM_DISKS] = { "EH", "BEER", "CANADA", "FRIGGINOH" };

//bring them to LIFE
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
	//if all items are on Peg 3, player wins
	if (Game::m_Peg3->Peg::Contains(DISKS[0]) && Game::m_Peg3->Peg::Contains(DISKS[1]) && Game::m_Peg3->Peg::Contains(DISKS[2]) && Game::m_Peg3->Peg::Contains(DISKS[3]))
	{
		cout << "Congratulations! You win!" << endl;
		return true;
	}
	//otherwise, player hasnt won
	return false;
}

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
	//clear the pegs of any data
	Game::m_Peg1->Peg::Clear();
	Game::m_Peg2->Peg::Clear();
	Game::m_Peg3->Peg::Clear();

	//add the initial 4 disks to PEG1
	for (int i = 0; i < NUM_DISKS; i++)
	{
		Game::m_Peg1->Peg::startAdd(DISKS[i]); 
	}
}

//displays instructions
void Game::DisplayInstructions() const
{
	//greet the player, explain the rules
	cout << "\t\t\t +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=" << endl;
	cout << "\t\t\t =RIGGSBY AND CO TOWERS OF HANOVER+" << endl;
	cout << "\t\t\t +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=" << endl;
	cout << "\t\t   Courtesy of Riggsby Creative!" << endl << endl;
	system("pause");
	system("CLS");
	//displays instructions
	cout << "\t Hey there guy! Welcome to Bob and Doug's Towers of Hanover, eh?" << endl << endl;
	cout << "Rules are pretty straightforward. " << endl << endl;
	cout << "Move all the items from Peg 1 to Peg 3." << endl << endl;
	cout << "You may only move one disk at a time!" << endl << endl;
	cout << "The game will ask 3 questions per move." << endl << endl;
	cout << "First, it asks what peg you are taking the disk away from. (Enter PEG1 or PEG2 or PEG3)" << endl << endl;
	cout << "Then, it will ask where you want the disk to go. (Enter PEG1, PEG2 or PEG3)" << endl << endl;
	cout << "Lastly, the game will ask the name of the disk you want to move.(Enter EH, BEER, CANADA or FRIGGINOH" << endl << endl;
	cout << "NOTE: PLEASE ENSURE YOUR CAPSLOCK IS ON, THE PROGRAM ONLY WORKS IF YOU YELL AT IT (she's a bit deaf don'tcha know>)" << endl << endl;
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
	//ask which disk is being moved
	string diskName;
	cout << "Which disk would you like to move?";
	cin >> diskName;
	cout << endl << endl;
	
	//while the disk name is equal to the head node data on the 'From Peg'
	while (diskName == fromPeg.m_pHead->m_Data)
	{
		if (toPeg.m_pHead == NULL)  // if the toPeg is empty
		{
			if (fromPeg.Contains(diskName) && fromPeg.Remove()) //check to see if the from peg has the disk and if it can be successfully removed
			{
				if (diskName == DISKS[0])
				{
					toPeg.Add(DISKS[0]); //if the disk is EH
				}
				else if (diskName == DISKS[1])
				{
					toPeg.Add(DISKS[1]); // if the disk is BEER
				}
				else if (diskName == DISKS[2])
				{
					toPeg.Add(DISKS[2]); //if the disk is CANADA
				}
				else if (diskName == DISKS[3])
				{
					toPeg.Add(DISKS[3]); //if the disk is FRIGGINOH
				}
				return;
			}
			else if (!fromPeg.Contains(diskName))
			{
				cout << "Not a valid choice." << endl; //if the disk isn't on the from peg
				return;
			}

			else
			{
				cout << "Not a valid choice." << endl; //just in case
				return;
			}
		}
		else
		{
			//pass the size's of the diskname and the topeg head element into variables
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
						if (fromPeg.Contains(fromPeg.m_pHead->m_Data) && handDiskSize < toPegTopSize) //does the fromPeg have the chosen disk?
						{
							fromPeg.Remove();
							if (diskName == DISKS[0])
							{
								toPeg.Add(DISKS[0]); //add EH
							}
							else if (diskName == DISKS[1])
							{
								toPeg.Add(DISKS[1]);	//add BEER
							}
							else if (diskName == DISKS[2])  // these block says to add the removed disk to the toPeg 
							{
								toPeg.Add(DISKS[2]);	//add CANADA
							}
							else if (diskName == DISKS[3])
							{
								toPeg.Add(DISKS[3]);	//add FRIGGINOH
							}
							return;
						}
						else
						{
							cout << "Not a valid choice." << endl; // if the diskName isn't legal
						}
					}
					return;
				}
			}
			else
			{
				cout << "Not a valid move." << endl; //else the handDisk size is greater then to toPeg head element size
				return;
			}
		}
		cout << endl;
	}
}

void Game::Play()
{
	//show them what I got
	DisplayPegs();

	//variables for peg choices
	string pegChoice1;
	string pegChoice2;

	do
	{
		//ask the burning question
		cout << "Which Peg would you like to take a disk from?";
		cin >> pegChoice1;
		cout << endl << endl;
		cout << "Which peg would you like to move the disk to?";
		cin >> pegChoice2;
		cout << endl << endl;
		
		if (pegChoice1 == "PEG1" && pegChoice2 == "PEG2" || pegChoice1 == "peg1" && pegChoice2 == "peg2")		//if the choices are PEG1 and PEG2
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
		else if (pegChoice1 == "PEG1" && pegChoice2 == "PEG3" || pegChoice1 == "peg1" && pegChoice2 == "peg3")	//PEG1 and PEG3
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
		else if (pegChoice1 == "PEG2" && pegChoice2 == "PEG1" || pegChoice1 == "peg2" && pegChoice2 == "peg1")		//PEG2 and PEG1
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
		else if (pegChoice1 == "PEG2" && pegChoice2 == "PEG3" || pegChoice1 == "peg2" && pegChoice2 == "peg3")	//PEG2 and PEG3
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
		else if (pegChoice1 == "PEG3" && pegChoice2 == "PEG1" || pegChoice1 == "peg3" && pegChoice2 == "peg1")		//PEG3 and PEG1
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
		else if (pegChoice1 == "PEG3" && pegChoice2 == "PEG2" || pegChoice1 == "peg3" && pegChoice2 == "peg2")		//PEG3 and PEG2
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
			cout << "Not a valid move." << endl;		 //choices are not legal
		}
	} while (isPlaying() && !isWon());
	return;
}
