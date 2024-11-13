#include "Boss.h"
#include "cstring"
#include <iostream>


Boss::Boss(){
  _texture = new sf::Texture;
  _texture->loadFromFile("assets/sprites/1942-sprites-enemy.png");
  _sprite.setTexture(*_texture);
  _sprite.setTextureRect({6,601,169,93});
  _sprite.setScale(2.3,2.3);
  _sprite.setPosition(150,800+50);
  _velocity.x = 0;

  _velocity.y = -2.2f;
}


void Boss::cmd() {


}


void Boss::respawn(){

  _sprite.setPosition(150,800+50);

}

void Boss::update()
{

  if (_sprite.getPosition().y - getBounds().height >-50){

     _sprite.move(_velocity.x,_velocity.y);
  }
}




void Boss::draw(sf::RenderTarget &target , sf::RenderStates states)const {
  target.draw(_sprite, states);
}

sf::FloatRect Boss::getBounds()const {
  return _sprite.getGlobalBounds();
}

sf::Vector2f Boss::getBulletOrigin()
{
  return {_sprite.getPosition().x + 20 ,_sprite.getPosition().y+54};
}

sf::Vector2f Boss::getPosition() const
{
  return _sprite.getPosition();
}
