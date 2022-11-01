#include "Fase.h"

Fase::Fase(Jogador* j1, sf::RenderWindow* window)
{
	this->window = window;
	this->j1 = j1;
	listaEntidades = new ListaEntidades();
	listainimigos = new ListaInimigos();
	listaObstaculos = new ListaObstaculos();
	i1 = new Entidades::Personagens::Inimigo();
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
	for (int i = 0; i <= 20; i++)
	{
		ob1 = new Obstaculo();
		ob1->setWindow(window);
		ob1->setPosi((float)i * (100), 300.f);
		listaObstaculos->LOs.push(ob1);
		listaEntidades->LEs.push(ob1);
	}
	listaEntidades->LEs.push(j1);
	listainimigos->LEs.push(i1);
	for (int i = 0; i < listainimigos->LEs.getLen(); i++)
	{
		Entidades::Entidade* temp = listainimigos->LEs.getItem(i);
		listaEntidades->LEs.push(temp);
	}
}
ListaInimigos* Fase::getListaInimigos()
{
	return listainimigos;
}
ListaObstaculos* Fase::getListaObstaculos()
{
	return listaObstaculos;
}
ListaEntidades* Fase::getListaEntidades()
{
	return listaEntidades;
}