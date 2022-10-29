#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
class ClasseJogo
{
private:
	sf::RenderWindow window;
	Jogador jogador1;
	Inimigo inimigo1;
public:
	ClasseJogo();
	~ClasseJogo();
	void Executar();


};

