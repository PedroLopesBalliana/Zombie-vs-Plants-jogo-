#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
class ClasseJogo
{
private:
	sf::RenderWindow window;
	Jogador jogador1;
public:
	ClasseJogo();
	~ClasseJogo();
	void Executar();


};

