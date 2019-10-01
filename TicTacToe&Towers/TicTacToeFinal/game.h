#pragma once
#ifndef GAME_H
#define GAME_H

#include "board.h"

class Player;

class Game
{
public:
	Game();
	~Game();
	bool IsPlaying() const;		//is the game still going?
	bool IsTie() const;		//did the players hit a stalemate?
	void ClearPlayers();		//cleans players out from the program
	void SetPlayers();		//sets the players for the game
	void DisplayInstructions() const;		//teaches n00bz how to play X's and O's
	void NextPlayer();		//switches between players playing the game
	void AnnounceWinner() const;		//makes the losing player feel bad for losing
	void Play();		//runs a bunch of stuff to play the game

private:
	static const int NUM_PLAYERS = 2;
	static const int FIRST = 0;
	static const int SECOND = 1;

	Board m_Board;
	Player* m_pPlayers[NUM_PLAYERS];
	int m_Current;
};

#endif