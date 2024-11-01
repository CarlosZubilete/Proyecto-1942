#include "Enemy.h"
#include "cstring"

Enemy::Enemy(){}

Enemy::Enemy(std::string namePng,sf::IntRect rect,float vel_x,float vel_y)
{
  _texture = new sf::Texture;
  _texture->loadFromFile(namePng.c_str());
  _sprite.setTexture(*_texture);
  //sf::Vector2f _texturaSize = _texture.getSize();
  _sprite.setTextureRect(rect);
  //_sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height);
  _velocity = {vel_x,vel_y};
  _sprite.setPosition(375,170);
  _sprite.setScale(3,3);
  _canShoot = true;
}


void Enemy::cmd()
{
  /**
  if(_newPosition.x > _sprite.getPosition().x)
  {
    _sprite.move(_velocity);
  }

  _newPosition = (std::rand() % 600 + _sprite.getGlobalBounds().width,
                      std::rand() % 600 + _sprite.getGlobalBounds().height);

  */
  if (_sprite.getPosition().x < 0  )
  {
    _velocity.x = -_velocity.x;
  }

  if (_sprite.getPosition().x + _sprite.getGlobalBounds().width > 600)
  {
    _velocity.x = -_velocity.x;
  }

  if (_sprite.getPosition().y  > 800)
  {
    respawn();
  }

  /*
  if(_sprite.getPosition().y < 0 )
  {
    _velocity.y = -_velocity.y;
  }

  if(_sprite.getPosition().y + _sprite.getGlobalBounds().height > 600)
  {
    _velocity.y = -_velocity.y;
  }
  */
}


void Enemy::update()
{
  _sprite.move(_velocity);
}

void Enemy::respawn()
{
  _sprite.setPosition(0,-300);
  //_newPosition = (std::rand() % 600 + _sprite.getGlobalBounds().width,
  //                    std::rand() % 600 + _sprite.getGlobalBounds().height);
}

bool Enemy::shot()
{
  if (_canShoot)
  {
    return true;
  }
  return false;
}

sf::Vector2f Enemy::getPosition()
{
  return _sprite.getPosition();
}

void Enemy::draw(sf::RenderTarget &target , sf::RenderStates states)const
{
  target.draw(_sprite,states);
}

sf::FloatRect Enemy::getBounds()const
{
  return _sprite.getGlobalBounds();
}
