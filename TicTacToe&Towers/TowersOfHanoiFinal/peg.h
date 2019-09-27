#pragma once
#ifndef PEG_H
#define PEG_H

#include <iostream>
#include "node.h"
#include "game.h"

using namespace std;

class Node;

class Game;

class Peg
{
	friend class Game;
public:
	//constructor
	Peg();

	//destructor
	~Peg();

	//returns the empty status
	bool isEmpty() const;

	//checks to see if the elements are gucci when called upon
	bool Contains(const string& data) const;

	//displays all values on peg
	void Display() const;

	//returns number of data elements on peg
	int Count() const;

	//returns copy of data element atop peg, num of elements stays the same
	string Top() const;

	//stores a new data on top of peg, num of elements increases by 1
	void Add(const string& data);

	//initial setup for first peg
	void startAdd(const string& data);

	//removes topmost data on peg, num of elements decreases by 1
	bool Remove();

	//removes all data elements on stack
	void Clear();

private:
	//value returned when call Top() of empty stack
	static const string ERROR;
	static const string EMPTY;

	//points to top data element on stack
	Node* m_pHead;
	Node* m_pTail;

};

#endif