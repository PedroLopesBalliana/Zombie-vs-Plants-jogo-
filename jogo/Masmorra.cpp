#include "Masmorra.h"

Masmorra::Masmorra(Jogador* j1, Jogador* j2, GerenciadorGrafico* GE): Fase()
{
	if (!texture.loadFromFile("assets/Bloco_Texturas/Dungeon/Fornalha.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(1.5, 1.5));
	sprite.setPosition(sf::Vector2f(0.f, 0.f));
	geren_graf = GE;
	Ente::setGerenciadorGrafico(geren_graf);
	this->j1 = j1;
	this->j2 = j2;
	listaEntidades = new ListaEntidades();
	srand(time(NULL));
	inicializaElementos();
	executar();
}
Masmorra::~Masmorra()
{

}
void Masmorra::inicializaPedra()
{
	for (int i = 0; i <= 20; i++)
	{
		pe = new Pedra();
		pe->setPosi((float)i * (50), 750.f);
		listaEntidades->LEs.push(pe);
		gerenciadorColisoes.pushObstaculo(pe);
	}

	pe = new Pedra();
	pe->scaleSprite(1.f, 0.5f);
	pe->setPosi(0.f, 200.f);
	listaEntidades->LEs.push(pe);
	gerenciadorColisoes.pushObstaculo(pe);

	pe = new Pedra();
	pe->scaleSprite(1.f, 0.5f);
	pe->setPosi(900.f, 200.f);
	listaEntidades->LEs.push(pe);
	gerenciadorColisoes.pushObstaculo(pe);

	pe = new Pedra();
	pe->scaleSprite(1.5f, 0.5f);
	pe->setPosi(0.f, 350.f);
	listaEntidades->LEs.push(pe);
	gerenciadorColisoes.pushObstaculo(pe);

	pe = new Pedra();
	pe->scaleSprite(1.5f, 0.5f);
	pe->setPosi(850.f, 350.f);
	listaEntidades->LEs.push(pe);
	gerenciadorColisoes.pushObstaculo(pe);

	pe = new Pedra();
	pe->scaleSprite(2.0f, 0.5f);
	pe->setPosi(0.f, 500.f);
	listaEntidades->LEs.push(pe);
	gerenciadorColisoes.pushObstaculo(pe);

	pe = new Pedra();
	pe->scaleSprite(2.0f, 0.5f);
	pe->setPosi(800.f, 500.f);
	listaEntidades->LEs.push(pe);
	gerenciadorColisoes.pushObstaculo(pe);

	pe = new Pedra();
	pe->scaleSprite(2.5f, 0.5f);
	pe->setPosi(0.f, 650.f);
	listaEntidades->LEs.push(pe);
	gerenciadorColisoes.pushObstaculo(pe);

	pe = new Pedra();
	pe->scaleSprite(2.5f, 0.5f);
	pe->setPosi(750.f, 650.f);
	listaEntidades->LEs.push(pe);
	gerenciadorColisoes.pushObstaculo(pe);

	pe = new Pedra();
	pe->scaleSprite(3.f, 0.5f);
	pe->setPosi(0.f, 800.f);
	listaEntidades->LEs.push(pe);
	gerenciadorColisoes.pushObstaculo(pe);

	pe = new Pedra();
	pe->scaleSprite(3.f, 0.5f);
	pe->setPosi(700.f, 800.f);
	listaEntidades->LEs.push(pe);
	gerenciadorColisoes.pushObstaculo(pe);

	pe = new Pedra();
	pe->scaleSprite(5.f, 0.5f);
	pe->setPosi(250.f, 125.f);
	listaEntidades->LEs.push(pe);
	gerenciadorColisoes.pushObstaculo(pe);
}

void Masmorra::inicializaElementos()
{
	listaEntidades->LEs.push(j1);
	j2->setMovimento(false);
	listaEntidades->LEs.push(j2);

	inicializaPedra();
}
void Masmorra::executar()
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
		gerenciadorColisoes.setJogador(j1);
		gerenciadorColisoes.percorrer();
		gerenciadorColisoes.setJogador(j2);
		gerenciadorColisoes.percorrer();
		listaEntidades->percorrerSe(deltaTempo);
		geren_graf->displayJanela();
		if (Inimigo::getQuant() == 0)
		{
			printf("venceu! \n");
		}
		printf("pontuacao %d\n", j1->getPontuacao());
	}
}