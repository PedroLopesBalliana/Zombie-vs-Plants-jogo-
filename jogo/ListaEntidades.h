#pragma once
#include "Lista.h"
#include "Entidade.h"
class ListaEntidades
{
public:
	Lista<Entidades::Entidade> LEs;
	ListaEntidades();
	~ListaEntidades();
};
