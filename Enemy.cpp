#include "Enemy.h"
#include "cstring"
#include <iostream>

Enemy::Enemy()
{
  _texture = new sf::Texture;
  _texture->loadFromFile("assets/sprites/1942-sprites-enemy.png");
  _sprite.setTexture(*_texture);
  _sprite.setTextureRect({59,57,15,14});
  _sprite.setScale(3,3);
  _sprite.setPosition( std::rand()%600+1,0-48-48);
  _velocity.x = std::rand()%2 ? (float)(std::rand()%30)/10+1.0 :  - (float)(std::rand()%30)/10+1.0;
//  _sprite.setPosition( 320,400);
//  _velocity.x = 0.5;
  _velocity.y = 3.2f;
}

void Enemy::cmd() {

  // rebote en los costados:
  if (_sprite.getPosition().x + getBounds().width < 0 + getBounds().width/2  ) {
    _velocity.x = -_velocity.x;
  }
  if (_sprite.getPosition().x + getBounds().width > 600 + getBounds().width/2) {
    _velocity.x = -_velocity.x;
  }
  if (_sprite.getPosition().y - getBounds().height > 800){
    respawn();
  }
}

void Enemy::update()
{

  _sprite.move(_velocity.x,_velocity.y);
}

void Enemy::respawn(){

  _sprite.setPosition(std::rand()%600,0-48-48);
//  _velocity.x = std::rand()%2 ? (float)(std::rand()%30)/10+1.0 :  - (float)(std::rand()%30)/10+1.0;
}

void Enemy::draw(sf::RenderTarget &target , sf::RenderStates states)const {
  target.draw(_sprite, states);
}

sf::FloatRect Enemy::getBounds()const {
  return _sprite.getGlobalBounds();
}

sf::Vector2f Enemy::getBulletOrigin()
{
  return {_sprite.getPosition().x + 20 ,_sprite.getPosition().y+54};
}

sf::Vector2f Enemy::getPosition() const
{
  return _sprite.getPosition();
}


