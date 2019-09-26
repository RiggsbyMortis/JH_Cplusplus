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
	bool IsPlaying() const;
	bool IsTie() const;
	void ClearPlayers();
	void SetPlayers();
	void DisplayInstructions() const;
	void NextPlayer();
	void AnnounceWinner() const;
	void Play();

private:
	static const int NUM_PLAYERS = 2;
	static const int FIRST = 0;
	static const int SECOND = 1;

	Board m_Board;
	Player* m_pPlayers[NUM_PLAYERS];
	int m_Current;
};

#endif