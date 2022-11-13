#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "Obstaculo.h"
#include "Fase1.h"
#include "GerenciadorGrafico.h"
#include "Menu.h"

class ClasseJogo
{
private:
	GerenciadorGrafico gerenciadorGrafico;
	Jogador *jogador1;
	Fase1* fase1;
	Menu* menu;
public:
	ClasseJogo();
	~ClasseJogo();
	void Executar();
	void fase1Prin();
};

