#pragma once
#include "Inimigo.h"

class Arvore : public Inimigo
{
private:
public:
	Arvore();
	~Arvore();
	void executar(float deltaTempo);

};
