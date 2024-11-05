#include "Enemy.h"
#include "cstring"
#include <iostream>

Enemy::Enemy()
{
  _texture = new sf::Texture;
  _texture->loadFromFile("assets/sprites/1942-sprites-enemy.png");
  _sprite.setTexture(*_texture);
  _sprite.setTextureRect({59,55,17,18});
  _sprite.setScale(3,3);
  _canShoot = true;
  _frame = 0;
  setPosition( std::rand()%600+1,0-48-48);
  _velocity.x = std::rand()%2 ? (float)(std::rand()%30)/10+0.1 :  - (float)(std::rand()%30)/10+0.1;
  _velocity.y = 0.5;
}

void Enemy::cmd() {

  if (getPosition().x + getBounds().width < 0  ) {
    _velocity.x = -_velocity.x;
  }
  if (getPosition().x - getBounds().width > 600) {
    _velocity.x = -_velocity.x;
  }
  if (getPosition().y - getBounds().height > 800){
    respawn();
  }

}

void Enemy::update()
{

  move(_velocity.x,_velocity.y);
}

void Enemy::respawn() {
  _velocity.x = std::rand()%2 ? (float)(std::rand()%30)/10+0.1 :  - (float)(std::rand()%30)/10+0.1;
  setPosition(std::rand()%600,0-48-48);
}

bool Enemy::shot() {
  if (_canShoot)
  {
    return true;
  }
  return false;
}

void Enemy::draw(sf::RenderTarget &target , sf::RenderStates states)const {
  states.transform *= getTransform();
  target.draw(_sprite, states);
}

sf::FloatRect Enemy::getBounds()const {
  return _sprite.getGlobalBounds();
}

sf::Vector2f Enemy::getBulletOrigin()
{
  return {getPosition().x + (18-48)/2 ,getPosition().y};
}