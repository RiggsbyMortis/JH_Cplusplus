#include "node.h"
#include <iostream>

using namespace std;

Node::Node(const string& data) :
	m_Data(data),
	m_pNext(NULL),
	m_pPrev(NULL)
{}