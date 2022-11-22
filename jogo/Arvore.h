#pragma once
#include "Inimigo.h"
#include "Projetil.h"

class Arvore : public Inimigo
{
private:
	Projetil* maca;
	float limEsq;
	float limDir;
public:
	Arvore();
	~Arvore();
	void executar(float deltaTempo);
	void setProjetil(Projetil* pr);
	void pular();
	void mover();
	void setLimites(float esq, float dir);
};
