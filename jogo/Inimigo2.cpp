#include "Inimigo2.h"
Inimigo2::Inimigo2():Entidade(), facingLeft(false)
{
	if (!texture.loadFromFile("assets/Inimigos/bublbassauroSprite.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(2, 2));
	sprite.setPosition(sf::Vector2f(700.f, 685.f));
}
Inimigo2::~Inimigo2()
{

}
void Inimigo2::gravidade(float DeltaTempo)
{
	sprite.move(sf::Vector2f(0.f, 0.15f));
	flutua();
}
void Inimigo2::flutua()
{
	sprite.move(sf::Vector2f(0.f, -0.15f));
}
void Inimigo2::executar(float deltaTempo)
{
	gravidade(deltaTempo);
	imprimirSe();
	mover();
}
void Inimigo2::mover()
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

