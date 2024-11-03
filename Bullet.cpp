#include "Bullet.h"

Bullet::Bullet(){}


Bullet::Bullet(int horizontal,int vertical, int velocidad)
{
  _texture = new sf::Texture;
  _texture->loadFromFile("assets/sprites/1942-sprites-effects.png");
  _sprite.setTexture(*_texture);
  _sprite.setTextureRect({0,15,17,15});
  _sprite.setScale(2,2);
  _sprite.setPosition(horizontal,vertical);
  _velocidad = velocidad;
}

void Bullet::Update()
{
  _sprite.move(0,_velocidad);
}

void Bullet::draw(sf::RenderTarget &target, sf::RenderStates states)const
{
  target.draw(_sprite, states);
}

sf::FloatRect Bullet::getBounds()const
{
   return _sprite.getGlobalBounds();
}




