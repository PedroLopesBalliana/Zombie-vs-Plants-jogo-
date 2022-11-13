#pragma once
#include "Ente.h"

class Menu : public Ente
{
private:

public:
	Menu(GerenciadorGrafico* ge);
	~Menu();
	void executar();
};
