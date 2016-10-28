#include "Node.h"

Node::Node()
{
	m_next = NULL;
}

Node::Node(Vehicle vehicle, Node* next)
{
	m_vehicle = vehicle;
	m_next = next;
}

Node::~Node()
{
	m_next = NULL;
}

void Node::setNext(Node* next)
{
	m_next = next;
}

Vehicle& Node::getValor() 
{
	return m_vehicle;
}

Node* Node::getNext() 
{
	return m_next;
}

void Node::setValor(Vehicle vehicle)
{
	m_vehicle = vehicle;
}