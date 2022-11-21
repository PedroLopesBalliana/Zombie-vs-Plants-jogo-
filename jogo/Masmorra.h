#pragma once
#include "Fase.h"
#include "Pedra.h"

class Masmorra : public Fase
{
private:
	Pedra* pe;
public:
	Masmorra(Jogador* j1, Jogador* j2, GerenciadorGrafico* GE);
	~Masmorra();
	void inicializaAtirador();
	void inicializaFogo();
	void inicializaPedra();
	void inicializaElementos();
	sf::RectangleShape bloco;
	sf::FloatRect sect;
	void executar();
};