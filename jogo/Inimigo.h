#pragma once
#include "Entidade.h"
#include "Projetil.h"
class Inimigo : public Entidade
{
private:
	bool facingLeft;
	bool goingUp;
	Projetil* tiro;
public:
	Inimigo();
	~Inimigo();
	void gravidade(float DeltaTempo);
	void flutua();
	void executar(float deltaTempo);
	void mover();
};
