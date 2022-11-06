#include "Fase1.h"

Fase1::Fase1(Jogador* j1, GerenciadorGrafico* GE) : 
	Fase(),
	bloco(sf::Vector2f(100.f, 100.f))
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
	i2 = new Inimigo2();
	inicializaElementos();
	executar();
}
Fase1::~Fase1()
{

}
void Fase1::inicializaElementos()
{
	i2->setGerenciadorGrafico(geren_graf);
	for (int i = 0; i <= 20; i++)
	{
		ob1 = new Obstaculo();
		ob1->setGerenciadorGrafico(geren_graf);
		ob1->setPosi((float)i * (100), 750.f);
		listaEntidades->LEs.push(ob1);
		gerenciadorColisoes.pushObstaculo(ob1);
	}
	gerenciadorColisoes.setJogador(j1);
	j1->setGerenciadorGrafico(geren_graf);
	i1->setGerenciadorGrafico(geren_graf);
	listaEntidades->LEs.push(j1);
	listaEntidades->LEs.push(i1);
	listaEntidades->LEs.push(i2);
	gerenciadorColisoes.pushInimigo(i2);
}
void Fase1::executar()
{
	float deltaTempo = 0.0f;
	sf::Clock clock;
	while (geren_graf->pegarJanela())
	{
		deltaTempo = clock.restart().asSeconds();
		geren_graf->limpaJanela();
		sf::Event event;
		while (geren_graf->getWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				geren_graf->getWindow()->close();
		}
		 //imprimirSe até o percorrer
		imprimirSe();
		for(int i = 0; i < listaEntidades->LEs.getLen(); i++)
		{
			gerenciadorColisoes.percorrer();
			Entidade* temp = listaEntidades->LEs.getItem(i);
			temp->executar(deltaTempo);
		}
		geren_graf->displayJanela();
	}
}