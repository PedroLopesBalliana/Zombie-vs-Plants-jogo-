#pragma once
#include "Fase.h"
class Fase1 : public Fase
{
private:
	sf::RenderWindow *window_f;
public:
	Fase1(Jogador* j1, GerenciadorGrafico* GE);
	~Fase1();
	void inicializaElementos();
	void faseExecutar();
	void setWindow(sf::RenderWindow* window);
};
