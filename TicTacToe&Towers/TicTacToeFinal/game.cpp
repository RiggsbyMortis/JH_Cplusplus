#include "game.h"
#include "playerhuman.h"
#include "playercomputer.h"

#include <iostream>

using namespace std;
class Player;

Game::Game():
	m_Current(FIRST)
{
	for (int i = 0; i < NUM_PLAYERS; ++i)
	{
		m_pPlayers[i] = NULL;
	}
}

Game::~Game()
{
	ClearPlayers();
}

bool Game::IsPlaying() const
{
	return ( !m_Board.IsFull() && !m_Board.IsWinner(m_pPlayers[FIRST]->GetPiece()) && !m_Board.IsWinner(m_pPlayers[SECOND]->GetPiece()) );
}

bool Game::IsTie() const
{
	return ( m_Board.IsFull() && !m_Board.IsWinner(m_pPlayers[FIRST]->GetPiece()) && !m_Board.IsWinner(m_pPlayers[SECOND]->GetPiece()) );
}

void Game::ClearPlayers()
{
	for (int i = 0; i < NUM_PLAYERS; ++i)
	{
		delete m_pPlayers[i];
		m_pPlayers[i] = NULL;
	}
}

void Game::SetPlayers()
{
	ClearPlayers();

	cout << "Who shall wage this epic fight? ";
	cout << "Declare opponents..." << endl;

	for (int i = 0; i < NUM_PLAYERS; ++i)
	{
		cout << "Player " << i + 1;
		cout << " - human or computer? (h/c): ";
		char playerType;
		cin >> playerType;

		if (playerType == 'h')
		{
			m_pPlayers[i] = new PlayerHuman();
		}
		else if (playerType == 'c')
		{
			m_pPlayers[i] = new PlayerComputer();
		}
		else
		{
			cout << "Please enter 'h' or 'c' to identify player types!" << endl;
			SetPlayers();
			return;
		}
	}
}

void Game::DisplayInstructions() const
{
	cout << "\tWelcome to Tic Tac Toe.";
	cout << endl << endl;
	cout << "Make your move by entering a number, ( 0 - 8 ). The number " << endl;
	cout << "corresponds with board position, as shown below: " << endl << endl;

	cout << endl << "\t" << "0 | 1 | 2";
	cout << endl << "\t" << "----------";
	cout << endl << "\t" << "3 | 4 | 5";
	cout << endl << "\t" << "----------";
	cout << endl << "\t" << "0 | 1 | 2";

	cout << endl << endl << "Prepare yourself. The game is starting...";
	cout << endl << endl;
}

void Game::NextPlayer()
{
	m_Current = (m_Current + 1) % NUM_PLAYERS;
}

void Game::AnnounceWinner() const
{
	cout << "The game has finished!" << endl;

	if (IsTie())
	{
		cout << "STALEMATE!" << endl;
	}

	else
	{
		cout << "And the winning Player is~~~";
		if (m_Board.IsWinner(m_pPlayers[FIRST]->GetPiece()))
		{
			cout << m_pPlayers[FIRST]->GetPiece() << endl;
		}

		else
		{
			cout << m_pPlayers[SECOND]->GetPiece() << endl;
		}
	}
}

void Game::Play()
{
	m_Current = FIRST;
	m_Board.Reset();

	while (IsPlaying())
	{
		system("CLS");
		m_Board.Display();
		m_pPlayers[m_Current]->MakeMove(m_Board);
		NextPlayer();
	}

	m_Board.Display();
	AnnounceWinner();
}
