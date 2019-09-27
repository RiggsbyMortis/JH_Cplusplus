#include "peg.h"
#include "node.h"

#include <iostream>
#include <string>

using namespace std;


//constructor
Peg::Peg() :
	m_pHead(NULL),
	m_pTail(NULL)
{}

//destructor
Peg::~Peg()
{
	Clear();
}


//tests for element existence
bool Peg::Contains(const string& data) const
{
	bool found = false;
	Node* pNode = m_pHead;

	while (!found && pNode != NULL)
	{
		if (pNode->m_Data == data)
		{
			found = true;
			return found;
		}
		pNode = pNode->m_pNext;
	}
}


//checks for empty status
bool Peg::isEmpty() const
{
	Node* pNode = m_pHead;
	int total = 0;
	//while pNode is NOT empty
	while (pNode != NULL)
	{
		//count what's in the peg stack
		++total;
		pNode = pNode->m_pNext;
	}

	//if the total is bigger than 0, it's not empty
	if (total > 0)
	{
		return false;
	}

	//otherwise, it is empty
	return true;

}

//show the goods
void Peg::Display() const
{
	Node* pNode = m_pHead;

	if (m_pHead == NULL)
	{
		cout << NULL << endl;
	}

	while (pNode != NULL)
	{
		if (pNode && !pNode->m_Data.empty())
		{
			cout << pNode->m_Data << endl;
			pNode = pNode->m_pNext;
		}
	}
}

//count the elements
int Peg::Count() const
{
	Node* pNode = m_pHead;
	int c_Total = 0;

	//go through list and print all legal elements
	while (pNode != NULL)
	{
		++c_Total;
		pNode = pNode->m_pNext;
	}

	return c_Total;
}

//read the top data of a peg
string Peg::Top() const
{
	bool found = false;
	string empty;
	Node* pNode = m_pHead;

	while (!found)	//while found is false, compare mData to the strings below and return true if found
	{
		if (pNode->m_Data == empty)
		{
			cout << "There's nothing there.";
		}

		else if (pNode->m_Data == "EH")
		{
			return pNode->m_Data;
		}
		else if (pNode->m_Data == "BEER")
		{
			return pNode->m_Data;
		}
		else if (pNode->m_Data == "CANADA")
		{
			return pNode->m_Data;
		}
		else if (pNode->m_Data == "FRIGGINOH")
		{
			return pNode->m_Data;
		}
	}
}

//add a new node to the peg
void Peg::Add(const string& data)
{
	//create new node
	Node* pNode = new Node(data);

	//if at least 1 node in the list, add new node to top
	if (m_pTail != NULL)
	{
		pNode->m_pNext = m_pHead;
		m_pHead = pNode;
	}

	//sets the head to pNode
	else if (m_pHead == NULL && m_pTail != NULL)
	{
		m_pHead = pNode;
		m_pHead->m_pNext = pNode->m_pNext;
	}

	//otherwise, new node becomes only node in list
	else
	{
		m_pHead = pNode;
		m_pTail = pNode;
	}
}

//inital add sequence
void Peg::startAdd(const string& data)
{
	Node* pNode = new Node(data);

	//if at least one node in list, add new node to the end
	if (m_pTail != NULL)
	{
		m_pTail->m_pNext = pNode;
		m_pTail = m_pTail->m_pNext;
	}

	//otherwise, new node is only node in list
	else
	{
		m_pHead = pNode;
		m_pTail = pNode;
	}
}

//returns true if it successfully removes a disk/node
bool Peg::Remove()
{
	//pointer to be removed
	Node* pNode = m_pHead;
	//pointer to node before node to be removed
	//Node* pPrevious = NULL;

	//node with data not found, unable to remove
	if (pNode == NULL)
	{
		return false;
	}

	//node the topmost node
	else if (pNode == m_pHead)
	{
		m_pHead = m_pHead->m_pNext;
		//Game::disk1 = pNode;
	}
	return true;
}

//clear peg of all elements
void Peg::Clear()
{
	while (m_pHead != NULL)
	{
		Node* pTemp = m_pHead;
		m_pHead = m_pHead->m_pNext;
		delete pTemp;
	}

	m_pHead = NULL;
	m_pTail = NULL;
}
