#pragma once
#include "SFML/Graphics.hpp"
#include "GerenciadorGrafico.h"
class Ente
{
protected:
	int id;
	sf::Texture texture;
	sf::Sprite sprite;
	static GerenciadorGrafico* geren_graf;
public:
	Ente();
	~Ente();
	virtual void executar();
	void imprimirSe();
	void static setGerenciadorGrafico(GerenciadorGrafico* gR);
	sf::Sprite getSprite() const;
};
