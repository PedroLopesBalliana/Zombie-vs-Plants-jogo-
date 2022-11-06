#pragma once
#include "Entidade.h"
class Inimigo2 : public Entidade
{
private:
	bool facingLeft;
public:
	Inimigo2();
	~Inimigo2();
	void gravidade(float DeltaTempo);
	void flutua();
	void executar(float deltaTempo);
	void mover();
 };
