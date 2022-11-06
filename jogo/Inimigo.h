#pragma once
#include "Personagem.h"
#include "Projetil.h"
class Inimigo : public Personagem
{
protected:
	bool goingUp;
public:
	Inimigo();
	~Inimigo();
	virtual void flutua();
	virtual void executar(float deltaTempo);
	virtual void mover();
};
