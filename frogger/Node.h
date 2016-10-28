#pragma once

#include "Vehicle.h"

class Node
{
public: 
	Node();
	Node(Vehicle vehicle, Node* next);
	~Node();
	Vehicle& getValor();
	Node* getNext();
	void setValor(Vehicle vehicle);
	void setNext(Node* next);
private:
	Vehicle m_vehicle;
	Node* m_next;
};