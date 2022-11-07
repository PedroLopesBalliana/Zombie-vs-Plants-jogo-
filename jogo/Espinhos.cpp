#include "Espinhos.h"
Espinhos::Espinhos()
{
	danoso = true;
	if (!texture.loadFromFile("assets/Bloco_Texturas/Floresta/espinhos.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(500.f, 300.f));
}
Espinhos::~Espinhos()
{

}