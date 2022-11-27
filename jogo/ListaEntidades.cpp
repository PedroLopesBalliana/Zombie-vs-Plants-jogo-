#include "ListaEntidades.h"
Listas::ListaEntidades::ListaEntidades()
{

}
Listas::ListaEntidades::~ListaEntidades()
{
	LEs.limpaLista();
}
void Listas::ListaEntidades::percorrerSe(float deltaTempo)
{
	for (int i = 0; i < getTam(); i++)
	{
		Entidades::Entidade* temp = getEntidade(i);
		temp->executar(deltaTempo);
	}
}
int Listas::ListaEntidades::getTam()
{
	return this->LEs.getLen();
}
Entidades::Entidade* Listas::ListaEntidades::getEntidade(int p)
{
	return static_cast<Entidades::Entidade*>(this->LEs.getItem(p));
}


