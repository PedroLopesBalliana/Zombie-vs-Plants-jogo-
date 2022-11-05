#pragma once
#include "Entidade.h"
#include <windows.h>

class Jogador :public Entidade
{
private:
	bool facingLeft;
	float jump;
	sf::Vector2f velocity;
public:
	bool pulou;
	Jogador();
	~Jogador();
	void move();
	float getY();
	void corrigir(float height);
	void gravidade();
	void flutua();
	void pula();
};
