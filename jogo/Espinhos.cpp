#include "Espinhos.h"
Espinhos::Espinhos()
{
	danoso = true;
	if (!texture.loadFromFile("assets/Bloco_Texturas/Floresta/espinhos.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(1,1));
	sprite.setPosition(sf::Vector2f(300.f, 100.f));
}
Espinhos::~Espinhos()
{

}