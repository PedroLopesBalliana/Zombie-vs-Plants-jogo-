#pragma once
#include "Entidade.h"
class Inimigo : public Entidade
{
private:

public:
	Inimigo();
	~Inimigo();
	void gravidade();
	void flutua();
};
