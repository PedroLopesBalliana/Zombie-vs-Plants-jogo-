#include "Fase1.h"

Fase1::Fase1(Jogador* j1, GerenciadorGrafico* GE) : 
	Fase()
{
	if (!texture.loadFromFile("assets/Bloco_Texturas/Floresta/Background.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(1, 1.5));
	sprite.setPosition(sf::Vector2f(0.f, 0.f));
	geren_graf = GE;
	this->j1 = j1;
	listaEntidades = new ListaEntidades();
	i1 = new Inimigo();
	ob1 = new Obstaculo();
	inicializaElementos();
	executar();
}
Fase1::~Fase1()
{

}
void Fase1::inicializaElementos()
{
	for (int i = 1; i <= 20; i++)
	{
		ob1 = new Obstaculo();
		ob1->setGerenciadorGrafico(geren_graf);
		ob1->setPosi((float)i * (100), 300.f);
		listaEntidades->LEs.push(ob1);
		gerenciadorColisoes.getLOs().push_back(*ob1);
	}
	j1->setGerenciadorGrafico(geren_graf);
	i1->setGerenciadorGrafico(geren_graf);
	gerenciadorColisoes.getLIs().push_back(*i1);
	listaEntidades->LEs.push(j1);
	listaEntidades->LEs.push(i1);
}
void Fase1::executar()
{

	while (geren_graf->pegarJanela())
	{
		geren_graf->limpaJanela();
		sf::Event event;
		while (geren_graf->getWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				geren_graf->getWindow()->close();
		}
		imprimirSe();
		j1->move();
		j1->gravidade();
		for(int i = 0; i < listaEntidades->LEs.getLen(); i++)
		{
			Entidade* temp = listaEntidades->LEs.getItem(i);
			temp->imprimirSe();
		}
		geren_graf->displayJanela();
	}
}