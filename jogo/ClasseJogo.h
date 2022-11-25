#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "Obstaculo.h"
#include "Floresta.h"
#include "GerenciadorGrafico.h"
#include "Menu.h"

class ClasseJogo
{
private:
	GerenciadorGrafico* pGrafico;
	Jogador *jogador1;
	Jogador* jogador2;
	Menu* menu;
public:
	ClasseJogo();
	~ClasseJogo();
	void Executar();
	void fase1Prin();
};

