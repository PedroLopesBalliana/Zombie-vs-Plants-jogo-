#include "Obstaculo.h"

class Fogo : public Obstaculo
{
private:
	float labareda;
public:
	Fogo();
	~Fogo();
	void executar(float deltaTempo);


};