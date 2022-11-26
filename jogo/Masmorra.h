#pragma once
#include "Fase.h"
#include "Pedra.h"
#include "Arvore.h"

class Masmorra : public Fase
{
private:
	Pedra* pe;
	Arvore* arvore;
	Projetil* maca;
public:
	Masmorra(Jogador* j1, Jogador* j2, Gerenciadores::GerenciadorGrafico* GE);
	~Masmorra();
	void inicializaAtirador();
	void inicializaFogo();
	void inicializaArvore();
	void inicializaPedra();
	void inicializaElementos();
	void executar();
};