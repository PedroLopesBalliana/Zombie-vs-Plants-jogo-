#pragma once
#include "SFML/Graphics.hpp"
#include "GerenciadorGrafico.h"
class Ente
{
protected:
	static int id;
	sf::Texture texture;
	sf::Sprite sprite;
	GerenciadorGrafico* geren_graf;
public:
	Ente();
	~Ente();
	virtual void executar();
	void imprimirSe();
	void setGerenciadorGrafico(GerenciadorGrafico* gR);

};
