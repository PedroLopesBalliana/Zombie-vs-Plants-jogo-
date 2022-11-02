#include "Fase1.h"

Fase1::Fase1(Jogador* j1) : 
	Fase(),
	window(sf::VideoMode(1000, 800), "Jogo")
{
	this->j1 = j1;
	listaEntidades = new ListaEntidades();
	listainimigos = new ListaInimigos();
	listaObstaculos = new ListaObstaculos();
	i1 = new Inimigo();
	ob1 = new Obstaculo();
	i1->setWindow(&window);
	ob1->setWindow(&window);
	j1->setWindow(&window);
	inicializaElementos();
	faseExecutar();
}
Fase1::~Fase1()
{

}
void Fase1::inicializaElementos()
{
	for (int i = 1; i <= 20; i++)
	{
		ob1 = new Obstaculo();
		ob1->setPosi((float)i * (100), 300.f);
		ob1->setWindow(&window);
		listaEntidades->LEs.push(ob1);
	}
	listaEntidades->LEs.push(j1);
	listaEntidades->LEs.push(i1);
}
void Fase1::faseExecutar()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		j1->move();
		j1->gravidade();
		for (int i = 0; i < listaEntidades->LEs.getLen(); i++)
		{
			Entidade* temp = listaEntidades->LEs.getItem(i);
			temp->draw();
		}
		window.display();

	}
}