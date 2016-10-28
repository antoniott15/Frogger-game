#include "Cua.h"
#include <iostream>

Cua::Cua()
{
	m_primer = NULL;
	m_primer = NULL;
}

bool Cua::esBuida() const
{
	return m_primer == NULL; //si el primer element apunta a nul, la cua esta buida
}

Vehicle& Cua::getPrimer() const
{
	return m_primer->getValor();
}

Vehicle& Cua::getUltim() const
{
	return m_ultim->getValor();
}

bool Cua::afegeix(Vehicle valor)
{
	Node* aux;
	bool correcte = false;


	if ((aux = new Node) != NULL) //Creacio dinamica del nou node de la cua
	{
		correcte = true;
		aux->setValor(valor);  
		aux->setNext(NULL);

	if (esBuida())
		m_primer = aux;		//Si la cua esta buida, el nou element passa a ser el primer i l'ultim a la vegada
	else
		m_ultim->setNext(aux);			//Si no esta buida, el nou element s'ha d'enllacar amb l'ultim i passa a ser el primer
	m_ultim = aux;
	}
	return correcte;
}

Vehicle Cua::treu()
{
	Node* aux;
	Vehicle valor;

	aux = m_primer;
	if (m_primer == m_ultim)
		m_ultim = NULL; // si nomes tenim un element a la cua s'ha de modificar tambe l'apuntador a ultim
	valor = aux->getValor(); //recuperem el primer element de la cua
	m_primer = aux->getNext(); //Modifiques el primer element de la cua

	delete aux;

	return valor;
}


Cua::~Cua()
{
	while(!esBuida())  //mentre la cua no estigui buida, va treient els integrants 
		treu();
}

Iterador Cua::getInici() const
{
	return Iterador(m_primer);  //inicia l'iterador a la posicio del primer element
}