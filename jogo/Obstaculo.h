#pragma once
#include "Entidade.h"
class Obstaculo : public Entidades::Entidade
{
private:
public:
	Obstaculo();
	~Obstaculo();
	void setPosi(float x, float y);
};
