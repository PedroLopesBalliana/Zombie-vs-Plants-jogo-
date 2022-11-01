#include "Fase.h"

Fase::Fase(Jogador* j1, sf::RenderWindow* window)
{
	this->window = window;
	this->j1 = j1;
	listaEntidades = new ListaEntidades();
	listainimigos = new ListaInimigos();
	i1 = new Inimigo();
	ob1 = new Obstaculo();
	ob1->setWindow(window);
	i1->setWindow(window);
	inicializaElementos();
}
Fase::~Fase()
{

}
void Fase::inicializaElementos()
{
	for (int i = 1; i <= 20; i++)
	{
		ob1 = new Obstaculo();
		ob1->setWindow(window);
		ob1->setPosi((float)i*(100), 300.f);
		listaEntidades->LEs.push(ob1);
	}
	listaEntidades->LEs.push(j1);
	listainimigos->LEs.push(i1);
	for (int i = 0; i < listainimigos->LEs.getLen(); i++)
	{
		Entidade* temp = listainimigos->LEs.getItem(i);
		listaEntidades->LEs.push(temp);
	}
}

ListaEntidades* Fase::getListaEntidades()
{
	return listaEntidades;
}