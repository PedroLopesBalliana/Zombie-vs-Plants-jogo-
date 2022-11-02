#include "Fase1.h"

Fase1::Fase1(Jogador* j1, GerenciadorGrafico* GE) : 
	Fase()
{
	gerenciadorGrafico = GE;
	this->j1 = j1;
	setWindow(gerenciadorGrafico->getWindow());
	listaEntidades = new ListaEntidades();
	listainimigos = new ListaInimigos();
	listaObstaculos = new ListaObstaculos();
	i1 = new Entidades::Personagens::Inimigo();
	ob1 = new Obstaculo();
	i1->setWindow(gerenciadorGrafico->getWindow());
	ob1->setWindow(gerenciadorGrafico->getWindow());
	this->j1->setWindow(gerenciadorGrafico->getWindow());
	inicializaElementos();
	faseExecutar();
}
Fase1::~Fase1()
{

}
void Fase1::setWindow(sf::RenderWindow* window)
{
	this->window_f = window;
}
void Fase1::inicializaElementos()
{
	for (int i = 1; i <= 20; i++)
	{
		ob1 = new Obstaculo();
		ob1->setPosi((float)i * (100), 300.f);
		ob1->setWindow(gerenciadorGrafico->getWindow());
		listaEntidades->LEs.push(ob1);
	}
	listaEntidades->LEs.push(j1);
	listaEntidades->LEs.push(i1);
}
void Fase1::faseExecutar()
{
	while (window_f->isOpen())
	{
		sf::Event event;
		while (window_f->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window_f->close();
		}
		window_f->clear();
		j1->move();
		j1->gravidade();

		for (int i = 0; i < listaEntidades->LEs.getLen(); i++)
		{
			Entidades::Entidade* temp = listaEntidades->LEs.getItem(i);
			temp->draw();
		}
		window_f->display();

	}
}