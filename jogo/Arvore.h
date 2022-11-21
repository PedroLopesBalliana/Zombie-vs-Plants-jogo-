#pragma once
#include "Inimigo.h"

class Arvore : public Inimigo
{
private:
	float limEsq;
	float limDir;
public:
	Arvore();
	~Arvore();
	void executar(float deltaTempo);
	void mover();
	void setLimites(float esq, float dir);
};
