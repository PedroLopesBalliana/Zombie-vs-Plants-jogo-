#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "Fase.h"

class ClasseJogo
{
private:
	sf::RenderWindow window;
	Jogador *jogador1;
	ListaEntidades* LEs;
	Fase* fase1;
public:
	ClasseJogo();
	~ClasseJogo();
	void Executar();
};

