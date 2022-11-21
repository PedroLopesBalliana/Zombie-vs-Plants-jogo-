#pragma once
#include "Inimigo.h"
#include "Projetil.h"

class Arvore : public Inimigo
{
private:
	Projetil* maca;
public:
	Arvore();
	~Arvore();
	void executar(float deltaTempo);
	void setProjetil(Projetil* pr);

};
