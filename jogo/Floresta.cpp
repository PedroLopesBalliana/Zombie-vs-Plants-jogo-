#include "Floresta.h"

Fases::Floresta::Floresta(Entidades::Personagens::Jogador* j1, Entidades::Personagens::Jogador* j2, Gerenciadores::GerenciadorGrafico* GE) :
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
	Ente::setGerenciadorGrafico(geren_graf);
	this->j1 = j1;
	this->j2 = j2;
	listaEntidades = new Listas::ListaEntidades();
	srand(time(NULL));
	inicializaElementos();
	executar();
}
Fases::Floresta::~Floresta()
{

}
void Fases::Floresta::inicializaGrama()
{
	for (int i = 0; i <= 20; i++)
	{
		gr = new Entidades::Obstaculos::Grama();
		gr->setPosi((float)i * (50), 750.f);
		listaEntidades->LEs.push(gr);
		gerenciadorColisoes.pushObstaculo(gr);
	}

	gr = new Entidades::Obstaculos::Grama();
	gr->scaleSprite(3.f, 0.5f);
	gr->setPosi(100.f, 600.f);
	listaEntidades->LEs.push(gr);
	gerenciadorColisoes.pushObstaculo(gr);

	gr = new Entidades::Obstaculos::Grama();
	gr->scaleSprite(0.5f, 2.f);
	gr->setPosi(500.f, 350.f);
	listaEntidades->LEs.push(gr);
	gerenciadorColisoes.pushObstaculo(gr);

	gr = new Entidades::Obstaculos::Grama();
	gr->scaleSprite(0.5f, 0.5f);
	gr->setPosi(600.f, 600.f);
	listaEntidades->LEs.push(gr);
	gerenciadorColisoes.pushObstaculo(gr);

	gr = new Entidades::Obstaculos::Grama();
	gr->scaleSprite(2.0f, 0.3f);
	gr->setPosi(750.f, 650.f);
	listaEntidades->LEs.push(gr);
	gerenciadorColisoes.pushObstaculo(gr);

	gr = new Entidades::Obstaculos::Grama();
	gr->scaleSprite(3.f, 0.3f);
	gr->setPosi(700.f, 200.f);
	listaEntidades->LEs.push(gr);
	gerenciadorColisoes.pushObstaculo(gr);

	gr = new Entidades::Obstaculos::Grama();
	gr->scaleSprite(4.f, 0.3f);
	gr->setPosi(50.f, 250.f);
	listaEntidades->LEs.push(gr);
	gerenciadorColisoes.pushObstaculo(gr);
}
void Fases::Floresta::inicializaEspinhos()
{
	esp = new Entidades::Obstaculos::Espinho();
	esp->setPosi(400.f, 740.f);
	listaEntidades->LEs.push(esp);
	gerenciadorColisoes.pushObstaculo(esp);

	if (rand() % 2)
	{
		esp->setGerenciadorGrafico(geren_graf);
		esp->scaleSprite(0.3f, 1.5f);
		esp->setPosi(490.f, 370.f);
		listaEntidades->LEs.push(esp);
		gerenciadorColisoes.pushObstaculo(esp);
	}
	else
	{
		esp = new Entidades::Obstaculos::Espinho();
		esp->scaleSprite(0.3f, 1.5f);
		esp->setPosi(520.f, 370.f);
		listaEntidades->LEs.push(esp);
		gerenciadorColisoes.pushObstaculo(esp);
	}

	esp = new Entidades::Obstaculos::Espinho();
	esp->scaleSprite(1.0f, 0.5f);
	esp->setPosi(270.f, 230.f);
	listaEntidades->LEs.push(esp);
	gerenciadorColisoes.pushObstaculo(esp);

	if (rand() % 2)
	{
		esp = new Entidades::Obstaculos::Espinho();
		esp->scaleSprite(0.70f, 1.5f);
		esp->setPosi(920.f, 650.f);
		listaEntidades->LEs.push(esp);
		gerenciadorColisoes.pushObstaculo(esp);
	}
}
void Fases::Floresta::inicializaFogo()
{
	fogo = new Entidades::Obstaculos::Fogo();
	fogo->setPosi(700.f, 700.f);
	listaEntidades->LEs.push(fogo);
	gerenciadorColisoes.pushObstaculo(fogo);


	fogo = new Entidades::Obstaculos::Fogo();
	fogo->setPosi(10.f, 700.f);
	listaEntidades->LEs.push(fogo);
	gerenciadorColisoes.pushObstaculo(fogo);

	fogo = new Entidades::Obstaculos::Fogo();
	fogo->setPosi(30.f, 200.f);
	listaEntidades->LEs.push(fogo);
	gerenciadorColisoes.pushObstaculo(fogo);

	if (rand() % 2)
	{
		fogo = new Entidades::Obstaculos::Fogo();
		fogo->setPosi(800.f, 600.f);
		listaEntidades->LEs.push(fogo);
		gerenciadorColisoes.pushObstaculo(fogo);

	}
}
void Fases::Floresta::inicializaBulbassauro()
{
	bulb = new Entidades::Personagens::Bulbassauro();
	bulb->setPosi(870.f, 715.f);
	bulb->setLimites(500.f, 900.f);
	listaEntidades->LEs.push(bulb);
	gerenciadorColisoes.pushInimigo(bulb);

	if (rand() % 2)
	{
		bulb = new Entidades::Personagens::Bulbassauro();
		bulb->setPosi(530.f, 715.f);
		bulb->setLimites(500.f, 900.f);
		listaEntidades->LEs.push(bulb);
		gerenciadorColisoes.pushInimigo(bulb);
	}

	bulb = new Entidades::Personagens::Bulbassauro();
	bulb->setPosi(900.f, 170.f);
	bulb->setLimites(720.f, 900.f);
	listaEntidades->LEs.push(bulb);
	gerenciadorColisoes.pushInimigo(bulb);

	if (rand() % 2)
	{
		bulb = new Entidades::Personagens::Bulbassauro();
		bulb->setPosi(720.f, 170.f);
		bulb->setLimites(720.f, 900.f);
		listaEntidades->LEs.push(bulb);
		gerenciadorColisoes.pushInimigo(bulb);
	}

	bulb = new Entidades::Personagens::Bulbassauro();
	bulb->setPosi(100.f, 570.f);
	bulb->setLimites(100.f, 300.f);
	listaEntidades->LEs.push(bulb);
	gerenciadorColisoes.pushInimigo(bulb);

	if (rand() % 2)
	{
		bulb = new Entidades::Personagens::Bulbassauro();
		bulb->setPosi(300.f, 570.f);
		bulb->setLimites(100.f, 300.f);
		listaEntidades->LEs.push(bulb);
		gerenciadorColisoes.pushInimigo(bulb);
	}
}
void Fases::Floresta::inicializaAtirador()
{
	ati = new Entidades::Personagens::Atirador();
	pr = new Entidades::Projetil();
	ati->setProjetil(pr);
	ati->setTipo(1);
	listaEntidades->LEs.push(ati);
	gerenciadorColisoes.pushInimigo(ati);
	gerenciadorColisoes.pushProjetil(pr);

	if (rand() % 2)
	{
		ati = new Entidades::Personagens::Atirador();
		pr = new Entidades::Projetil();
		ati->setProjetil(pr);
		ati->setTipo(1);
		ati->setPosi(600.f, 150.f);
		listaEntidades->LEs.push(ati);
		gerenciadorColisoes.pushInimigo(ati);
		gerenciadorColisoes.pushProjetil(pr);
	}

	ati = new Entidades::Personagens::Atirador();
	pr = new Entidades::Projetil();
	ati->setPosi(50.f, 200.f);
	ati->setProjetil(pr);
	ati->setTipo(2);
	listaEntidades->LEs.push(ati);
	gerenciadorColisoes.pushInimigo(ati);
	gerenciadorColisoes.pushProjetil(pr);

	if (rand() % 2)
	{
		ati = new Entidades::Personagens::Atirador();
		pr = new Entidades::Projetil();
		ati->setPosi(50.f, 700.f);
		ati->setProjetil(pr);
		ati->setTipo(2);
		listaEntidades->LEs.push(ati);
		gerenciadorColisoes.pushInimigo(ati);
		gerenciadorColisoes.pushProjetil(pr);
	}

	ati = new Entidades::Personagens::Atirador();
	pr = new Entidades::Projetil();
	ati->setPosi(950.f, 200.f);
	ati->setProjetil(pr);
	ati->setTipo(3);
	gerenciadorColisoes.pushInimigo(ati);
	listaEntidades->LEs.push(ati);
	gerenciadorColisoes.pushProjetil(pr);

	if (rand() % 2)
	{
		ati = new Entidades::Personagens::Atirador();
		pr = new Entidades::Projetil();
		ati->setPosi(950.f, 700.f);
		ati->setProjetil(pr);
		ati->setTipo(3);
		gerenciadorColisoes.pushInimigo(ati);
		listaEntidades->LEs.push(ati);
		gerenciadorColisoes.pushProjetil(pr);
	}
}
void Fases::Floresta::inicializaElementos()
{
	listaEntidades->LEs.push(j1);
	listaEntidades->LEs.push(j2);

	inicializaGrama();
	inicializaEspinhos();
	inicializaFogo();
	inicializaBulbassauro();
	inicializaAtirador();
}
void Fases::Floresta::executar()
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
		if (Entidades::Personagens::Inimigo::getQuant() == 0)
		{
			j1->setPosi(100.f, 700.f);
			j2->setPosi(100.f, 700.f);
			fase2 = new Masmorra(j1, j2, geren_graf);
		}
		if (j1->getNumVidas() <= 0 && j2->getNumVidas() <= 0)
		{
			setPontos();
			geren_graf->getWindow()->close();

		}
	}
}