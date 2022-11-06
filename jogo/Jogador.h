#pragma once
#include "Personagem.h"
#include <windows.h>

class Jogador :public Personagem
{
private:
public:
	bool pulou;
	Jogador();
	~Jogador();
	void move(float deltaTime);
	void corrigir(float height, float side);
	void executar(float deltaTempo);
	void operator--();
};
