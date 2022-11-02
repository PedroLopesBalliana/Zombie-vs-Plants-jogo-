#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico():
	window(sf::VideoMode(1000, 800), "Jogo")
{
}
void GerenciadorGrafico::setListaEntidades(ListaEntidades Le)
{
	LE = Le;
	for (int i = 0; i < LE.LEs.getLen(); i++)
	{
		Entidades::Entidade* temp = LE.LEs.getItem(i);
		temp->setWindow(&window);
	}
}
GerenciadorGrafico::~GerenciadorGrafico()
{

}

void GerenciadorGrafico::desenharEntidades()
{
	for (int i = 0; i < LE.LEs.getLen(); i++)
	{
		Entidades::Entidade* temp = LE.LEs.getItem(i);
		temp->draw();
	}
}
sf::RenderWindow  *GerenciadorGrafico::getWindow()
{
	return &window;
}
