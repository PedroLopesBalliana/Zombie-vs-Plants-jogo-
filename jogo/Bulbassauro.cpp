#include "Bulbassauro.h"
Bulbassauro::Bulbassauro(): Inimigo()
{
	if (!texture.loadFromFile("assets/Inimigos/bublbassauroSprite.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(2, 2));
	sprite.setPosition(sf::Vector2f(700.f, 685.f));
}
Bulbassauro::~Bulbassauro()
{

}
void Bulbassauro::executar(float deltaTempo)
{
	gravidade(deltaTempo);
	imprimirSe();
	mover();
}
void Bulbassauro::mover()
{
	if (sprite.getPosition().x < 100 && !facingLeft)
	{
		facingLeft = true;
		sprite.scale(-1, 1);
	}
	if (sprite.getPosition().x > 900 && facingLeft)
	{
		facingLeft = false;
		sprite.scale(-1, 1);
	}
	if (!facingLeft)
		sprite.move(sf::Vector2f(-0.3f, 0.f));
	else
		sprite.move(sf::Vector2f(0.3f, 0.f));
}

