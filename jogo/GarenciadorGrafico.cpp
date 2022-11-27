#include "GerenciadorGrafico.h"

Gerenciadores::GerenciadorGrafico::GerenciadorGrafico():
	window(sf::VideoMode(1000, 800), "Jogo")
{
	limpaJanela();
	window.setFramerateLimit(60);
}
Gerenciadores::GerenciadorGrafico::~GerenciadorGrafico()
{
	delete pGrafico;
	pGrafico = nullptr;
}

Gerenciadores::GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::getGgr()
{
	if (pGrafico == nullptr)
	{
		return new Gerenciadores::GerenciadorGrafico();
	}
	return pGrafico;
}
void Gerenciadores::GerenciadorGrafico::desenharEntidades(sf::Sprite sp)
{
	window.draw(sp);
}
sf::RenderWindow  *Gerenciadores::GerenciadorGrafico::getWindow()
{
	return &window;
}
void Gerenciadores::GerenciadorGrafico::limpaJanela()
{
	window.clear();
}
void Gerenciadores::GerenciadorGrafico::displayJanela()
{
	window.display();
}
const bool Gerenciadores::GerenciadorGrafico::pegarJanela()
{
	if (window.isOpen() == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
Gerenciadores::GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::pGrafico = nullptr;


