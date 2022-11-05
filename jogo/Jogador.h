#pragma once
#include "Entidade.h"
class Jogador :public Entidade
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
