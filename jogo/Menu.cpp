#include "Menu.h"
#include <iostream>


Menu::Menu(GerenciadorGrafico* ge):botaoFase1(), botaoFase2(), botaoRanking()
{
	if (!texture.loadFromFile("assets/Menu/MenuBg1.png"))
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
		posi_mouse = sf::Mouse::getPosition();
		mouse_coord = geren_graf->getWindow()->mapPixelToCoords(posi_mouse);
		mouse_coord -= corrigir_coord;
		
		if (botaoFase2.getRect().getGlobalBounds().contains(mouse_coord))
		{
			printf("cu inferno \n");
		}
		if (botaoFase1.getRect().getGlobalBounds().contains(mouse_coord))
		{
			printf("cu cu \n");
		}
		if (botaoRanking.getRect().getGlobalBounds().contains(mouse_coord))
		{
			printf("cu pinto \n");
		}
		imprimirSe();
		desenharBotoes();
		geren_graf->displayJanela();
	}
}