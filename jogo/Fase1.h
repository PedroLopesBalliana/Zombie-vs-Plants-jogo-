#pragma once
#include "Fase.h"
class Fase1 : public Fase
{
private:
	sf::RenderWindow window;
public:
	Fase1(Jogador* j1);
	~Fase1();
	void inicializaElementos();
	void faseExecutar();
};
