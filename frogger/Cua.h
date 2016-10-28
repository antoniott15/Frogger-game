#include "Iterador.h"
#include "Vehicle.h"
#include "Node.h"
#pragma once

#include "Iterador.h"
class Cua
{

public:
	Cua();
	~Cua();

	bool afegeix(Vehicle valor);
	Vehicle treu();
	Vehicle& getPrimer() const;
	Vehicle& getUltim() const;
	bool esBuida() const;
	Iterador getInici() const;

private:
	Node* m_primer;
	Node*m_ultim;
};