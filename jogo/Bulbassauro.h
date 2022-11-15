#pragma once
#include "Inimigo.h"
class Bulbassauro : public Inimigo
{
private:
	float raiva;
	float limEsq;
	float limDir;
public:
	Bulbassauro();
	~Bulbassauro();
	void executar(float deltaTempo);
	void setLimites(float esq, float dir);
	void mover();
 };
