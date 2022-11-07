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
	i1 = new Atirador();
	gr = new Grama();
	i2 = new Bulbassauro();
	pr = new Projetil();
	esp = new Espinhos();
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
		if (i > 3 && i < 6)
		{
			esp = new Espinhos();
			esp->setGerenciadorGrafico(geren_graf);
			esp->setPosi((float)i * (100), 740.f);
			listaEntidades->LEs.push(esp);
			gerenciadorColisoes.pushObstaculo(esp);
		}
		else
		{
			gr = new Grama();
			gr->setGerenciadorGrafico(geren_graf);
			gr->setPosi((float)i * (100), 750.f);
			listaEntidades->LEs.push(gr);
			gerenciadorColisoes.pushObstaculo(gr);
		}
	}




	gerenciadorColisoes.setJogador(j1);
	j1->setGerenciadorGrafico(geren_graf);

	i1->setGerenciadorGrafico(geren_graf);
	listaEntidades->LEs.push(j1);
	listaEntidades->LEs.push(i1);
	listaEntidades->LEs.push(i2);
	pr->setGerenciadorGrafico(geren_graf);
	listaEntidades->LEs.push(pr);
	i1->setProjetil(pr);
	gerenciadorColisoes.pushInimigo(i2);
	gerenciadorColisoes.pushProjetil(pr);
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