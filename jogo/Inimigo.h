#pragma once
#include "Entidade.h"
class Inimigo : public Entidade
{
private:
	bool facingLeft;
	bool goingUp;
public:
	Inimigo();
	~Inimigo();
	void gravidade(float DeltaTempo);
	void flutua();
	void executar(float deltaTempo);
	void mover();
};
