#pragma once
#include "Inimigo.h"
class Bulbassauro : public Inimigo
{
private:
public:
	Bulbassauro();
	~Bulbassauro();
	void executar(float deltaTempo);
	void mover();
 };
