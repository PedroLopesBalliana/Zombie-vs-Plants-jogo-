#pragma once
#include "Personagem.h"
#include "Projetil.h"
#include "Jogador.h"
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
	virtual void mover(int tipo);
	void setTipo(int ti);
};
