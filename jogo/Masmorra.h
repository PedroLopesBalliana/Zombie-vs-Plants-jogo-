#pragma once
#include "Fase.h"
#include "Pedra.h"
#include "Arvore.h"

class Masmorra : public Fase
{
private:
	Pedra* pe;
	Arvore* kefka;
public:
	Masmorra(Jogador* j1, Jogador* j2, GerenciadorGrafico* GE);
	~Masmorra();
	void inicializaAtirador();
	void inicializaFogo();
	void inicializaKefka();
	void inicializaPedra();
	void inicializaElementos();
	sf::RectangleShape bloco;
	sf::FloatRect sect;
	void executar();
};