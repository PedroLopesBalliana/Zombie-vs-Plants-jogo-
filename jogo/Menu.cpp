#include "Menu.h"
#include <iostream>


Menu::Menu(Gerenciadores::GerenciadorGrafico* ge) :botaoFase1(),
botaoFase2(), botaoRanking(), corrigir_coord(), aux(0.f, 30.f), rankBool(false)
{
	if (!texture.loadFromFile("assets/Menu/MenuBg1.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	if (!rankText.loadFromFile("assets/Menu/MenuBg.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	if (!posicoesFont.loadFromFile("assets/Menu/calibri.ttf"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(1, 1.25));
	sprite.setPosition(sf::Vector2f(0.f, 0.f));

	botaoFase1.mudarPosi(200, 100);
	botaoFase2.mudarPosi(200, 210);
	botaoRanking.mudarPosi(260, 320);


	setGerenciadorGrafico(ge);
	executar();
}
Menu::~Menu()
{

}
void Menu::desenharBotoes()
{
	geren_graf->getWindow()->draw(botaoFase1.getRect());
	geren_graf->getWindow()->draw(botaoFase2.getRect());
	geren_graf->getWindow()->draw(botaoRanking.getRect());
}
void Menu::executar()
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
		geren_graf->limpaJanela();
		corrigir_coord = static_cast<sf::Vector2f>(geren_graf->getWindow()->getPosition());
		corrigir_coord += aux;
		posi_mouse = sf::Mouse::getPosition();
		mouse_coord = geren_graf->getWindow()->mapPixelToCoords(posi_mouse);
		mouse_coord -= corrigir_coord;
		
		if (botaoFase1.getRect().getGlobalBounds().contains(mouse_coord))
		{
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{ 
				jogador1 = new Jogador();
				jogador2 = new Jogador();
				fase1 = new Floresta(jogador1, jogador2, geren_graf);
			}
				
		}
		if (botaoFase2.getRect().getGlobalBounds().contains(mouse_coord))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				jogador1 = new Jogador();
				jogador2 = new Jogador();
				fase2 = new Masmorra(jogador1, jogador2, geren_graf);
			}
		}
		if (botaoRanking.getRect().getGlobalBounds().contains(mouse_coord))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !rankBool)
			{
				mostrarRank();
				rankBool = true;
			}
		}
		imprimirSe();
		desenharBotoes();
		geren_graf->displayJanela();
	}
}
void Menu::mostrarRank()
{
	bool voltar = true;
	ifstream leitor;
	sprite.setTexture(rankText);
	try 
	{
		leitor.open("Rank.txt");
		if (leitor)
		{
			imprimirSe();
			for (int i = 0; i < 10; i++)
			{
				info aux;
				leitor >> aux.nome >> aux.pont;
				cout << aux.nome << aux.pont << endl;
				posicoesRank.setFont(posicoesFont);
				posicoesRank.setCharacterSize(25);
				posicoesRank.setFillColor(sf::Color::White);
				posicoesRank.setString(aux.nome + "  " + to_string(aux.pont));
				posicoesRank.setPosition(sf::Vector2f(500, 100 + (30.0f * i)));
				geren_graf->getWindow()->draw(posicoesRank);
			}
			posicoesRank.setString("pressione P para voltar");
			posicoesRank.setPosition(sf::Vector2f(300, 500));
			geren_graf->getWindow()->draw(posicoesRank);
			geren_graf->getWindow()->display();
			while (voltar)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
				{
					voltar = false;
				}
			}
		}

		else
		{
			cout << "falhou abertura arquivo :(" << endl;
		}
		sprite.setTexture(texture);
	}
	catch (std::exception const& e)
	{
		cout << "erro na gravada" << e.what() << endl;
	}
}