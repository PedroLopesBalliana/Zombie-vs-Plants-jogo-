#pragma once
#include "Entidade.h"
#include "Projetil.h"
class Inimigo : public Entidade
{
protected:
	bool facingLeft;
	bool goingUp;
	Projetil* tiro;
public:
	Inimigo();
	~Inimigo();
	virtual void gravidade(float DeltaTempo);
	virtual void flutua();
	virtual void executar(float deltaTempo);
	virtual void mover();
};
