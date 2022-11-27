#pragma once
#include "Lista.h"
#include "Entidade.h"
namespace Listas
{
	class ListaEntidades
	{
	public:
		Entidades::Entidade* getEntidade(int p);
		int getTam();
		void percorrerSe(float deltaTempo);
		Listas::Lista<Entidades::Entidade> LEs;
		ListaEntidades();
		~ListaEntidades();
	};
}
