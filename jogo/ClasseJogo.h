#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "ListaInimigos.h"
#include "Obstaculo.h"
#include "ListaObstaculos.h"
#include "Fase.h"

class ClasseJogo
{
private:
	sf::RenderWindow window;
	Jogador *jogador1;
	ListaEntidades* LEs;
	ListaObstaculos* LOs;
	ListaInimigos* LIs;
	Fase* fase1;
public:
	ClasseJogo();
	~ClasseJogo();
	void Executar();
	void fase1Prin();
};

