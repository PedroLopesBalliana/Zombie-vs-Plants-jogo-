#pragma once
#include "Inimigo.h"
class Bulbassauro : virtual public Inimigo
{
protected:
	float raiva;
	float limEsq;
	float limDir;
public:
	Bulbassauro();
	~Bulbassauro();
	virtual void executar(float deltaTempo);
	virtual void setLimites(float esq, float dir);
	virtual void mover();
 };
