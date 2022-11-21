#include "Pedra.h"

Pedra::Pedra(): calor(0)
{
	if (!texture.loadFromFile("assets/Bloco_Texturas/Dungeon/Pedra2.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(0.2f, 0.2f);
}
Pedra::~Pedra()
{

}
void Pedra::executar(float deltaTempo)
{
	gravidade(deltaTempo);
	imprimirSe();
	flutua(deltaTempo);
	if (deltaTempo == 1.0f)
	{
		calor++;
	}
}
int Pedra::getTipo()
{
	return calor;
}