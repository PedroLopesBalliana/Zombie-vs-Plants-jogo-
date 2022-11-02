#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico():
	window(sf::VideoMode(1000, 800), "Jogo")
{
}
void GerenciadorGrafico::setListaEntidades(ListaEntidades Le)
{
	LE = Le;
}
GerenciadorGrafico::~GerenciadorGrafico()
{

}

void GerenciadorGrafico::desenharEntidades()
{
	window.clear();
	for (int i = 0; i < LE.LEs.getLen(); i++)
	{
		
		Entidades::Entidade* temp = LE.LEs.getItem(i);
		window.draw(temp->getSprite());
	}
	window.display();
}
sf::RenderWindow  *GerenciadorGrafico::getWindow()
{
	return &window;
}
