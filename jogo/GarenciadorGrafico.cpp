#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico():
	window(sf::VideoMode(1000, 800), "Jogo")
{
	limpaJanela();
}
GerenciadorGrafico::~GerenciadorGrafico()
{

}

void GerenciadorGrafico::desenharEntidades(sf::Sprite sp)
{
	if (sp.getTexture() == NULL)
	{
		printf("FODEU");
		return;
	}
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

