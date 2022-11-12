#include "ListaEntidades.h"
ListaEntidades::ListaEntidades()
{

}
ListaEntidades::~ListaEntidades()
{

}
void ListaEntidades::percorrerSe(float deltaTempo)
{
	for (int i = 0; i < getTam(); i++)
	{
		Entidade* temp = getEntidade(i);
		temp->executar(deltaTempo);
	}
}
int ListaEntidades::getTam()
{
	return this->LEs.getLen();
}
Entidade* ListaEntidades::getEntidade(int p)
{
	return static_cast<Entidade*>(this->LEs.getItem(p));
}


