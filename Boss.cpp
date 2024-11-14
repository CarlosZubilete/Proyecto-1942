#include "Boss.h"
#include "cstring"
#include <iostream>

Boss::Boss(){
  _texture = new sf::Texture;
  _texture->loadFromFile("assets/sprites/1942-sprites-enemy.png");
  _sprite.setTexture(*_texture);
  _sprite.setTextureRect({68,468,65,53});
  //_sprite.setTextureRect({1,468,65,57});
  _sprite.setScale(4,4);
  _sprite.setPosition(150,800+50);
  //_sprite.setOrigin({_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height});
  _velocity.x = 0;
  _velocity.y = -2.2f;
  _llegeAlaPosicion = false;
  _canShot = true;
  _timeReload = 60*3;
}


void Boss::cmd() {

  _timeReload--;

  if(_timeReload > 0 )
  {
    _canShot = false;
  }

  if(_timeReload < 0 )
  {
    _canShot = true;
    _timeReload = 60*1;
  }

}


void Boss::respawn(){
  _sprite.setPosition(150,800+50);
}


void Boss::damaged(float &frame)
{
  frame+=0.2;
  //_sprite.setTextureRect({68*(int)(frame/1.25),468,65,57});
  _sprite.setTextureRect({68+67*(int)(frame/1.43),468,65,53});

  if( frame > 9)
  {
    _sprite.setTextureRect({68,468,65,53});
  }
}

void Boss::update()
{

  /*TODO: Casi lo logro
  if (_sprite.getGlobalBounds().height + _sprite.getPosition().y > 50){
     _sprite.move(_velocity.x,_velocity.y);
  }
  */
  //if ( 800 -  _sprite.getPosition().y )
  if (   _sprite.getPosition().y - getBounds().height > -50){
     _sprite.move(_velocity.x,_velocity.y);
  }
}

void Boss::draw(sf::RenderTarget &target , sf::RenderStates states)const {
  target.draw(_sprite, states);
}

sf::FloatRect Boss::getBounds()const {
  return _sprite.getGlobalBounds();
}

bool Boss::canShot()
{
  return _canShot;
}

/*
sf::Vector2f Boss::getBulletOrigin()
{
  return {_sprite.getPosition().x + 20 ,_sprite.getPosition().y+54};
}
*/

sf::Vector2f Boss::getPosition() const
{
  return _sprite.getPosition();
}
