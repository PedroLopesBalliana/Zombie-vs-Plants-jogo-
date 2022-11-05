#pragma once
#include "Fase.h"
class Fase1 : public Fase
{
private:
public:
	Fase1(Jogador* j1, GerenciadorGrafico* GE);
	~Fase1();
	void inicializaElementos();
	void executar();


	sf::RectangleShape bloco;
	sf::FloatRect sect;
};
