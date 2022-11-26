#pragma once
#include "SFML/Graphics.hpp"
#include "GerenciadorGrafico.h"
#include "Memoria.h"
class Ente
{
protected:
	int id;
	sf::Texture texture;
	sf::Sprite sprite;
	static Gerenciadores::GerenciadorGrafico* geren_graf;
public:
	Ente();
	~Ente();
	virtual void executar();
	void imprimirSe();
	void static setGerenciadorGrafico(Gerenciadores::GerenciadorGrafico* gR);
	sf::Sprite getSprite() const;
};
