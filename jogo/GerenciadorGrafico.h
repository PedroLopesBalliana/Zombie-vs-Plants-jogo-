#pragma once
#include <SFML/Graphics.hpp>

class GerenciadorGrafico
{
private:
	sf::RenderWindow window;
public:
	GerenciadorGrafico();
	~GerenciadorGrafico();
	void desenharEntidades(sf::Sprite sp);
	sf::RenderWindow* getWindow();
	void limpaJanela();
	void displayJanela();
	bool pegarJanela();
};

