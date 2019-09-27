#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>

using namespace std;

class Node
{
	//hey look i haz friendz
	friend class Peg;

	friend class Game;

public:
	Node(const string& data); //contructor

private:
	//OI don't look at my privates, they hold my important info!
	string m_Data;
	Node* m_pNext;
	Node* m_pPrev;
};

#endif