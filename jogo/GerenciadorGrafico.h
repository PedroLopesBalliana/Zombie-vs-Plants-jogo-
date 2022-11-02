#pragma once
#include <SFML/Graphics.hpp>
#include "ListaEntidades.h"
#include "Entidade.h"

class GerenciadorGrafico
{
private:
	sf::RenderWindow window;
	ListaEntidades LE;
public:
	GerenciadorGrafico();
	~GerenciadorGrafico();
	void setListaEntidades(ListaEntidades Le);
	void desenharEntidades();
};

