#include "Obstaculo.h"

class Pedra : public Obstaculo
{
private:
	int calor;
public:
	Pedra();
	~Pedra();
	void executar(float deltaTempo);
	int getTipo();
};