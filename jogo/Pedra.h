#pragma once
#include "Obstaculo.h"

class Pedra : public Obstaculo
{
private:
	static bool envenenado;
	sf::Texture veneno;
public:
	Pedra();
	~Pedra();
	void executar(float deltaTempo);
	int getTipo();
	static void setVeneno(bool ven);
};