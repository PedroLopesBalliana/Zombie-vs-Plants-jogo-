#pragma once
#include "Personagem.h"
#include "Projetil.h"
class Inimigo : public Personagem
{
protected:
	bool goingUp;
	int tipo;
public:
	Inimigo();
	~Inimigo();
	virtual void flutua();
	virtual void executar(float deltaTempo);
	virtual void mover();
	void setTipo(int ti);
};
