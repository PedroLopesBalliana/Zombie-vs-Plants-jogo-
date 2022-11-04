#pragma once
#include "Inimigo.h"
#include "Obstaculo.h"
#include <list>
#include <vector>

class GerenciadorColisoes
{
private:
	std::vector<Entidades::Personagens::Inimigo> LIs;
	std::list<Obstaculo> LOs;
public:
	GerenciadorColisoes();
	~GerenciadorColisoes();
	std::vector<Entidades::Personagens::Inimigo> getLIs();
	std::list<Obstaculo> getLOs();
};