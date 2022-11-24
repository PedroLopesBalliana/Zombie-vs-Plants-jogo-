#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico():
	window(sf::VideoMode(1000, 800), "Jogo")
{
	limpaJanela();
	window.setFramerateLimit(60);
}
GerenciadorGrafico::~GerenciadorGrafico()
{

}

GerenciadorGrafico* GerenciadorGrafico::getGgr()
{
	if (pGrafico == nullptr)
	{
		return new GerenciadorGrafico();
	}
	return pGrafico;
}
void GerenciadorGrafico::desenharEntidades(sf::Sprite sp)
{
	window.draw(sp);
}
sf::RenderWindow  *GerenciadorGrafico::getWindow()
{
	return &window;
}
void GerenciadorGrafico::limpaJanela()
{
	window.clear();
}
void GerenciadorGrafico::displayJanela()
{
	window.display();
}
bool GerenciadorGrafico::pegarJanela()
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
GerenciadorGrafico* GerenciadorGrafico::pGrafico = nullptr;


