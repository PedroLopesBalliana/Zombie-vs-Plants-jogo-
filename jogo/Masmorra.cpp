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

	if (rand() % 2)
	{
		pe = new Pedra();
		pe->scaleSprite(2.f, 0.3f);
		pe->setPosi(200.f, 125.f);
		listaEntidades->LEs.push(pe);
		gerenciadorColisoes.pushObstaculo(pe);

		pe = new Pedra();
		pe->scaleSprite(2.f, 0.3f);
		pe->setPosi(550.f, 125.f);
		listaEntidades->LEs.push(pe);
		gerenciadorColisoes.pushObstaculo(pe);
	}
	else
	{
		pe = new Pedra();
		pe->scaleSprite(1.f, 0.3f);
		pe->setPosi(200.f, 125.f);
		listaEntidades->LEs.push(pe);
		gerenciadorColisoes.pushObstaculo(pe);

		pe = new Pedra();
		pe->scaleSprite(1.f, 0.3f);
		pe->setPosi(400.f, 125.f);
		listaEntidades->LEs.push(pe);
		gerenciadorColisoes.pushObstaculo(pe);

		pe = new Pedra();
		pe->scaleSprite(1.f, 0.3f);
		pe->setPosi(600.f, 125.f);
		listaEntidades->LEs.push(pe);
		gerenciadorColisoes.pushObstaculo(pe);
	}
}

void Masmorra::inicializaElementos()
{
	listaEntidades->LEs.push(j1);
	j2->setMovimento(false);
	listaEntidades->LEs.push(j2);
	inicializaPedra();
	inicializaArvore();
	inicializaAtirador();
	inicializaFogo();
}
void Masmorra::inicializaAtirador()
{
	for (int i = 1; i < 4; i++)
	{
		ati = new Atirador();
		pr = new Projetil();
		ati->setProjetil(pr);
		ati->setTipo(1);
		ati->setPosi(100.f + (300.f * i), 20.f);
		listaEntidades->LEs.push(ati);
		gerenciadorColisoes.pushInimigo(ati);
		gerenciadorColisoes.pushProjetil(pr);

		if (rand() % 2)
		{
			ati = new Atirador();
			pr = new Projetil();
			ati->setProjetil(pr);
			ati->setTipo(1);
			ati->setPosi((200.f * i), 20.f);
			listaEntidades->LEs.push(ati);
			gerenciadorColisoes.pushInimigo(ati);
			gerenciadorColisoes.pushProjetil(pr);
		}
	}
}
void Masmorra::inicializaFogo()
{
	fogo = new Fogo();
	fogo->setPosi(800.f - (rand() % 2) * 650.f, 600.f);
	listaEntidades->LEs.push(fogo);
	gerenciadorColisoes.pushObstaculo(fogo);

	fogo = new Fogo();
	fogo->setPosi(850.f - (rand() % 2) * 750.f, 450.f);
	listaEntidades->LEs.push(fogo);
	gerenciadorColisoes.pushObstaculo(fogo);

	fogo = new Fogo();
	fogo->setPosi(900.f - (rand() % 2) * 850.f, 300.f);
	listaEntidades->LEs.push(fogo);
	gerenciadorColisoes.pushObstaculo(fogo);

	fogo = new Fogo();
	fogo->setPosi(950.f - (rand() % 2) * 950.f, 150.f);
	listaEntidades->LEs.push(fogo);
	gerenciadorColisoes.pushObstaculo(fogo);
}
void Masmorra::inicializaArvore()
{
	for (int i = 0; i < (rand() % 2) + 3; i++)
	{
		arvore = new Arvore();
		maca = new Projetil();
		maca->setMaca();
		arvore->setPosi(300.f + (150.f * i), 325.f);
		arvore->setProjetil(maca);
		listaEntidades->LEs.push(maca);
		gerenciadorColisoes.pushProjetil(maca);
		arvore->setLimites(200.f, 800.f);
		listaEntidades->LEs.push(static_cast<Entidade*>(arvore));
		gerenciadorColisoes.pushInimigo(static_cast<Inimigo*>(arvore));
	}
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
			setPontos();
			geren_graf->getWindow()->close();
		}
		if (j1->getNumVidas() <= 0 && j2->getNumVidas() <= 0)
		{
			setPontos();
			geren_graf->getWindow()->close();
		}
	}
}