#pragma once
#include "Entidade.h"
#include <windows.h>

class Jogador :public Entidade
{
private:
	bool facingLeft;
	bool pulou;
public:
	Jogador();
	~Jogador();
	void move();
	float getY();
	void corrigir(float height);
	void gravidade();
	void flutua();
};
