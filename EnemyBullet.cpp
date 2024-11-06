#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(float horizontal,float vertical, float velocidadX, float velocidadY)
{
  _texture = new sf::Texture;
  _texture->loadFromFile("assets/sprites/1942-sprites-projectiles.png");
  _sprite.setTexture(*_texture);
  _sprite.setTextureRect({73,14,4,4}); // tamaño x 3 = 12*12
  _sprite.setScale(3,3);
  _sprite.setPosition(horizontal,vertical);
  _velocidadX = velocidadX;
  _velocidadY = velocidadY;
}

void EnemyBullet::update()
{
  _sprite.move(_velocidadX,_velocidadY);
}

void EnemyBullet::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(_sprite, states);
}

sf::FloatRect EnemyBullet::getBounds() const
{
  return _sprite.getGlobalBounds();
}
