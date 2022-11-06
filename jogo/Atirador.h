#pragma once
#include "Inimigo.h"
#include "Projetil.h"
class Atirador : public Inimigo
{
private:
	Projetil* tiro;
public:
	Atirador();
	~Atirador();
	void executar(float deltaTempo);
	void mover();
	void setProjetil(Projetil* pr);
};