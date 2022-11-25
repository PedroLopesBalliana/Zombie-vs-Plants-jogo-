#pragma once
#include "Inimigo.h"
#include "Projetil.h"
class Atirador : virtual public Inimigo
{
protected:
	Projetil* tiro;
public:
	Atirador();
	~Atirador();
	virtual void executar(float deltaTempo);
	virtual void mover();
	void setProjetil(Projetil* pr);
};