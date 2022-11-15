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
	ati = new Atirador();
	gr = new Grama();
	bulb = new Bulbassauro();
	pr = new Projetil();
	esp = new Espinhos();
	fogo = new Fogo();
	inicializaElementos();
	executar();
}
Fase1::~Fase1()
{

}
void Fase1::inicializaElementos()
{
	srand(time(NULL));
	for (int i = 0; i <= 20; i++)
	{
			gr = new Grama();
			gr->setGerenciadorGrafico(geren_graf);
			gr->setPosi((float)i * (50), 750.f);
			listaEntidades->LEs.push(gr);
			gerenciadorColisoes.pushObstaculo(gr);
	}

	//Plataformas

	gr = new Grama();
	gr->scaleSprite(3.f, 0.5f);
	gr->setGerenciadorGrafico(geren_graf);
	gr->setPosi(100.f, 600.f);
	listaEntidades->LEs.push(gr);
	gerenciadorColisoes.pushObstaculo(gr);

	gr = new Grama();
	gr->scaleSprite(0.5f, 2.f);
	gr->setGerenciadorGrafico(geren_graf);
	gr->setPosi(500.f, 350.f);
	listaEntidades->LEs.push(gr);
	gerenciadorColisoes.pushObstaculo(gr);

	gr = new Grama();
	gr->scaleSprite(0.5f, 0.5f);
	gr->setGerenciadorGrafico(geren_graf);
	gr->setPosi(600.f, 600.f);
	listaEntidades->LEs.push(gr);
	gerenciadorColisoes.pushObstaculo(gr);

	gr = new Grama();
	gr->scaleSprite(2.0f, 0.3f);
	gr->setGerenciadorGrafico(geren_graf);
	gr->setPosi(750.f, 650.f);
	listaEntidades->LEs.push(gr);
	gerenciadorColisoes.pushObstaculo(gr);

	gr = new Grama();
	gr->scaleSprite(3.f, 0.3f);
	gr->setGerenciadorGrafico(geren_graf);
	gr->setPosi(700.f, 200.f);
	listaEntidades->LEs.push(gr);
	gerenciadorColisoes.pushObstaculo(gr);

	gr = new Grama();
	gr->scaleSprite(4.f, 0.3f);
	gr->setGerenciadorGrafico(geren_graf);
	gr->setPosi(50.f, 250.f);
	listaEntidades->LEs.push(gr);
	gerenciadorColisoes.pushObstaculo(gr);

	//Obstaculos

	// espinho

	esp->setGerenciadorGrafico(geren_graf);
	esp->setPosi(400.f, 740.f);
	listaEntidades->LEs.push(esp);
	gerenciadorColisoes.pushObstaculo(esp);

	if (rand() % 2)
	{
		esp = new Espinhos();
		esp->setGerenciadorGrafico(geren_graf);
		esp->scaleSprite(0.3f, 1.5f);
		esp->setPosi(490.f, 370.f);
		listaEntidades->LEs.push(esp);
		gerenciadorColisoes.pushObstaculo(esp);
	}
	else
	{
		esp = new Espinhos();
		esp->setGerenciadorGrafico(geren_graf);
		esp->scaleSprite(0.3f, 1.5f);
		esp->setPosi(520.f, 370.f);
		listaEntidades->LEs.push(esp);
		gerenciadorColisoes.pushObstaculo(esp);
	}

	esp = new Espinhos();
	esp->setGerenciadorGrafico(geren_graf);
	esp->scaleSprite(1.0f, 0.5f);
	esp->setPosi(270.f, 230.f);
	listaEntidades->LEs.push(esp);
	gerenciadorColisoes.pushObstaculo(esp);

	if (rand() % 2)
	{
		esp = new Espinhos();
		esp->setGerenciadorGrafico(geren_graf);
		esp->scaleSprite(0.70f, 1.5f);
		esp->setPosi(920.f, 650.f);
		listaEntidades->LEs.push(esp);
		gerenciadorColisoes.pushObstaculo(esp);
	}

	//fogo

	fogo->setGerenciadorGrafico(geren_graf);
	fogo->setPosi(700.f, 700.f);
	listaEntidades->LEs.push(fogo);
	gerenciadorColisoes.pushObstaculo(fogo);


	fogo = new Fogo();
	fogo->setGerenciadorGrafico(geren_graf);
	fogo->setPosi(10.f, 700.f);
	listaEntidades->LEs.push(fogo);
	gerenciadorColisoes.pushObstaculo(fogo);

	fogo = new Fogo();
	fogo->setGerenciadorGrafico(geren_graf);
	fogo->setPosi(30.f, 200.f);
	listaEntidades->LEs.push(fogo);
	gerenciadorColisoes.pushObstaculo(fogo);

	if (rand() % 2)
	{
		fogo = new Fogo();
		fogo->setGerenciadorGrafico(geren_graf);
		fogo->setPosi(800.f, 600.f);
		listaEntidades->LEs.push(fogo);
		gerenciadorColisoes.pushObstaculo(fogo);
	}



	//Jogador 

	gerenciadorColisoes.setJogador(j1);
	j1->setGerenciadorGrafico(geren_graf);
	listaEntidades->LEs.push(j1);

	//Inimigos

	//Atiradores

	ati->setGerenciadorGrafico(geren_graf);
	ati->setProjetil(pr);
	ati->setTipo(1);
	listaEntidades->LEs.push(ati);
	gerenciadorColisoes.pushInimigo(ati);
	pr->setGerenciadorGrafico(geren_graf);
	gerenciadorColisoes.pushProjetil(pr);

	if (rand() % 2)
	{
		ati = new Atirador();
		pr = new Projetil();
		ati->setGerenciadorGrafico(geren_graf);
		ati->setProjetil(pr);
		ati->setTipo(1);
		ati->setPosi(600.f, 150.f);
		listaEntidades->LEs.push(ati);
		gerenciadorColisoes.pushInimigo(ati);
		pr->setGerenciadorGrafico(geren_graf);
		gerenciadorColisoes.pushProjetil(pr);
	}

	ati = new Atirador();
	pr = new Projetil();
	ati->setGerenciadorGrafico(geren_graf);
	ati->setPosi(50.f, 200.f);
	ati->setProjetil(pr);
	ati->setTipo(2);
	listaEntidades->LEs.push(ati);
	gerenciadorColisoes.pushInimigo(ati);
	pr->setGerenciadorGrafico(geren_graf);
	gerenciadorColisoes.pushProjetil(pr);

	if (rand() % 2)
	{
		ati = new Atirador();
		pr = new Projetil();
		ati->setGerenciadorGrafico(geren_graf);
		ati->setPosi(50.f, 700.f);
		ati->setProjetil(pr);
		ati->setTipo(2);
		listaEntidades->LEs.push(ati);
		gerenciadorColisoes.pushInimigo(ati);
		pr->setGerenciadorGrafico(geren_graf);
		gerenciadorColisoes.pushProjetil(pr);
	}

	ati = new Atirador();
	pr = new Projetil();
	ati->setGerenciadorGrafico(geren_graf);
	ati->setPosi(950.f, 200.f);
	ati->setProjetil(pr);
	ati->setTipo(3);
	gerenciadorColisoes.pushInimigo(ati);
	listaEntidades->LEs.push(ati);
	pr->setGerenciadorGrafico(geren_graf);
	gerenciadorColisoes.pushProjetil(pr);

	if (rand() % 2)
	{
		ati = new Atirador();
		pr = new Projetil();
		ati->setGerenciadorGrafico(geren_graf);
		ati->setPosi(950.f, 700.f);
		ati->setProjetil(pr);
		ati->setTipo(3);
		gerenciadorColisoes.pushInimigo(ati);
		listaEntidades->LEs.push(ati);
		pr->setGerenciadorGrafico(geren_graf);
		gerenciadorColisoes.pushProjetil(pr);
	}

	//Bulbassauros
	

	bulb->setGerenciadorGrafico(geren_graf);
	bulb->setPosi(870.f, 715.f);
	bulb->setLimites(500.f, 900.f);
	listaEntidades->LEs.push(bulb);
	gerenciadorColisoes.pushInimigo(bulb);

	if (rand() % 2)
	{
		bulb = new Bulbassauro();
		bulb->setGerenciadorGrafico(geren_graf);
		bulb->setPosi(530.f, 715.f);
		bulb->setLimites(500.f, 900.f);
		listaEntidades->LEs.push(bulb);
		gerenciadorColisoes.pushInimigo(bulb);
	}

	bulb = new Bulbassauro();
	bulb->setGerenciadorGrafico(geren_graf);
	bulb->setPosi(900.f, 170.f);
	bulb->setLimites(720.f, 900.f);
	listaEntidades->LEs.push(bulb);
	gerenciadorColisoes.pushInimigo(bulb);

	if (rand() % 2)
	{
		bulb = new Bulbassauro();
		bulb->setGerenciadorGrafico(geren_graf);
		bulb->setPosi(720.f, 170.f);
		bulb->setLimites(720.f, 900.f);
		listaEntidades->LEs.push(bulb);
		gerenciadorColisoes.pushInimigo(bulb);
	}

	bulb = new Bulbassauro();
	bulb->setGerenciadorGrafico(geren_graf);
	bulb->setPosi(100.f, 570.f);
	bulb->setLimites(100.f, 300.f);
	listaEntidades->LEs.push(bulb);
	gerenciadorColisoes.pushInimigo(bulb);

	if (rand() % 2)
	{
		bulb = new Bulbassauro();
		bulb->setGerenciadorGrafico(geren_graf);
		bulb->setPosi(300.f, 570.f);
		bulb->setLimites(100.f, 300.f);
		listaEntidades->LEs.push(bulb);
		gerenciadorColisoes.pushInimigo(bulb);
	}


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
		gerenciadorColisoes.percorrer();
		listaEntidades->percorrerSe(deltaTempo);
		geren_graf->displayJanela();
	}
}