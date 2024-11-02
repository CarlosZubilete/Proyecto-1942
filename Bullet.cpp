#include "Bullet.h"

Bullet::Bullet(){}

Bullet::Bullet(int horizontal,int vertical, int velocidad)
{
  _texture = new sf::Texture;
  _texture->loadFromFile("assets/sprites/1942-sprites-effects.png");
  _sprite.setTexture(*_texture);
  _sprite.setTextureRect({2,10,8,8});
  _sprite.setScale(4,4);
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

/**
Bullet::Bullet()
{
  _texture.loadFromFile("1942-sprites-effects.png");
  _sprite.setTexture(_texture);
  _sprite.setTextureRect({4,9,4,10});
  _sprite.setScale(4,4);
  _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height/2);
  _sprite.setPosition(300,300);
  _velocidad = -5;
}
**/
/**
Bullet::Bullet(int x ,int y, sf::Texture &texture,sf::IntRect intReact, int velocidad)
{
  _sprite.setTexture(texture);
  _sprite.setTextureRect(intReact);
  _sprite.setPosition(x,y);
  _sprite.setScale(4,4);
  _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height/2);
  _sprite.setPosition(300,300);
  _velocidad = velocidad;
}
**/

