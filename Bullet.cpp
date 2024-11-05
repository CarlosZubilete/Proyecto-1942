#include "Bullet.h"

Bullet::Bullet(){}


Bullet::Bullet(int horizontal,int vertical, int velocidad)
{
  _texture = new sf::Texture;
  _texture->loadFromFile("assets/sprites/1942-sprites-projectiles.png");
  _sprite.setTexture(*_texture);
  _sprite.setTextureRect({21,10,16,16}); // tamaño x 3 = 48*48
  _sprite.setScale(3,3);
  _sprite.setPosition(horizontal,vertical);
  _velocidad = velocidad;
}

void Bullet::update()
{
  _sprite.move(0,_velocidad);

}

void Bullet::draw(sf::RenderTarget &target, sf::RenderStates states)const
{
//  states.transform *= getTransform();
  target.draw(_sprite, states);
}

sf::FloatRect Bullet::getBounds()const
{
   return _sprite.getGlobalBounds();
}

Bullet::Bullet(sf::Vector2f position)
{
  _texture = new sf::Texture;
  _texture->loadFromFile("assets/sprites/1942-sprites-projectiles.png");
  _sprite.setTexture(*_texture);
  _sprite.setTextureRect({21,10,16,16}); // tamaño x 3 = 48*48
  _sprite.setScale(3,3);
  _sprite.setPosition(position);
  _velocidad = -7;
}


