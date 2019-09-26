#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "peg.h"

using namespace std;

class Peg;

class Game
{
	friend class Peg;
public:
	Game();

	//status of whether or not game is won
	bool isWon() const;
	//status of whether or not game is on
	bool isPlaying() const;
	//set up pegs
	void Setup();
	//displays instructions
	void DisplayInstructions() const;
	//displays items on pegs
	void DisplayPegs() const;
	//moves item from one peg to another
	void MoveDisk(Peg& fromPeg, Peg& toPeg);
	//plays game
	void Play();

private:
	static const string PEG1; //constant for peg 1
	static const string PEG2; //constant for peg 2
	static const string PEG3; //constant for peg 3

	static const int NUM_DISKS = 4; //constant for max number of disks at any time
	static string DISKS[NUM_DISKS]; //disks

	static Peg* m_Peg1;
	static Peg* m_Peg2;
	static Peg* m_Peg3;
};

#endif