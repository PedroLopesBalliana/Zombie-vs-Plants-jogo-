#pragma once
#include "Lista.h"
#include "Entidade.h"
class ListaEntidades
{
public:
	Entidade* getEntidade(int p);
	int getTam();
	void percorrerSe(float deltaTempo );
	Lista<Entidade> LEs;
	ListaEntidades();
	~ListaEntidades();
};
