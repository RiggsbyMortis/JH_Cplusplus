#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>

using namespace std;

class Node
{
	friend class Peg;

	friend class Game;

public:
	Node(const string& data);

private:
	string m_Data;
	Node* m_pNext;
	Node* m_pPrev;
};

#endif