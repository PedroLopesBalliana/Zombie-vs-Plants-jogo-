#pragma once
#include "Entidade.h"
#include <windows.h>

class Personagem :public Entidade
{
protected:
	bool facingLeft;
	float jump;
	int num_vidas;
public:
	Personagem();
	~Personagem();
	virtual void move(float deltaTime);
	virtual void executar(float deltaTempo);
};