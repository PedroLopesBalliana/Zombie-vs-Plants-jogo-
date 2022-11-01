#pragma once
#include "Lista.h"
#include "Inimigo.h"
class ListaInimigos
{
public:
	Lista<Entidades::Personagens::Inimigo> LEs;
	ListaInimigos();
	~ListaInimigos();
};
