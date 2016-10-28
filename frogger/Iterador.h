#pragma once

#include "Node.h"

class Iterador
{
public:
	Iterador();
	Iterador(Node* posicio);
	~Iterador();

	void seguent();
	Vehicle& getElement() const;
	bool esNul() const;

private:
	Node* m_posicio;

};