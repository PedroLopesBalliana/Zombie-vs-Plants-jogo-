#include "Fase.h"

Fase::Fase(Jogador* j1, sf::RenderWindow* window)
{
	this->window = window;
	this->j1 = j1;
	listaEntidades = new ListaEntidades();
	i1 = new Inimigo();
	listaInimigos.push_back(*i1);
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
	list <Inimigo>::iterator itt3;

	listaEntidades->LEs.push(ob1);
	listaEntidades->LEs.push(j1);
	for(itt3 = listaInimigos.begin(); itt3!=listaInimigos.end();itt3++)
	{
		Inimigo tempIni ;
		tempIni =(*itt3);
		listaEntidades->LEs.push(&tempIni);
	}
}

ListaEntidades* Fase::getListaEntidades()
{
	return listaEntidades;
}