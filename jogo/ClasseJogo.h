#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include <iostream>
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

