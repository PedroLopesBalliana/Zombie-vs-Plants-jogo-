#include "Menu.h"
#include <iostream>

Menu::Menu(GerenciadorGrafico* ge)
{
	if (!texture.loadFromFile("assets/Menu/MenuBg.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(1, 1.25));
	sprite.setPosition(sf::Vector2f(0.f, 0.f));
	setGerenciadorGrafico(ge);
	executar();
}
Menu::~Menu()
{

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
		imprimirSe();
		geren_graf->displayJanela();
	}
}