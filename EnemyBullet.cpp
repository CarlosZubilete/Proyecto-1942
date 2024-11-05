#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(int horizontal,int vertical, int velocidad)
{
  _texture = new sf::Texture;
  _texture->loadFromFile("assets/sprites/1942-sprites-projectiles.png");
  _sprite.setTexture(*_texture);
  _sprite.setTextureRect({73,14,4,4}); // tamaño x 3 = 12*12
  _sprite.setScale(3,3);
  _sprite.setPosition(horizontal,vertical);
  _velocidad = velocidad;
}

void EnemyBullet::update()
{
  move(0,_velocidad);
}

void EnemyBullet::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  target.draw(_sprite, states);
}

sf::FloatRect EnemyBullet::getBounds() const
{
  return getBounds();
}
