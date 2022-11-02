#pragma once
#include "Entidade.h"
class Jogador :public Entidades::Entidade
{
private:
	bool facingLeft;
public:
	Jogador();
	~Jogador();
	void move();
	void gravidade();
	float getY();

};
