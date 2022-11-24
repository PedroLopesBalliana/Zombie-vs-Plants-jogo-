#pragma once
#include "Personagem.h"
#include "Projetil.h"
#include "Jogador.h"
class Inimigo : public Personagem
{
private:
protected:
	static int quant;
	bool goingUp;
	int tipo;
public:
	Inimigo();
	~Inimigo();
	virtual void flutua();
	virtual void executar(float deltaTempo);
	virtual void mover(int tipo);
	void setTipo(int ti);
	static int getQuant();
	void operator--();
};
