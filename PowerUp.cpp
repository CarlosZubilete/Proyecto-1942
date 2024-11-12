#include "PowerUp.h"
#include <iostream>


PowerUp::PowerUp(){
//  _texture.loadFromFile("assets/sprites/1942-sprites-effects-projectiles.png");
//  _sprite.setTextureRect({38,55,35,34}); // X,Y,widh,heigh
//  _sprite.setPosition(sf::Vector2f(-50,-50));
//  _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height/2);
  _texture.loadFromFile("assets/sprites/1942-sprites-projectiles.png");
  _sprite.setTexture(_texture);
  _sprite.setTexture(_texture);
  int lista_powerUpRandom[] = {106,125,144,163,182,201,220,238};
  int powerUpRandom = std::rand()%8;
  _sprite.setTextureRect({lista_powerUpRandom[powerUpRandom],11,15,15}); // X,Y,widh,heigh
  _sprite.scale(3,3);
}

void PowerUp::update()
{
  _sprite.move(0,2.3f);
}

void PowerUp::respawn(){

  _sprite.setPosition(std::rand() % 550 + _sprite.getGlobalBounds().width,
                      std::rand() % 250 - _sprite.getGlobalBounds().height); // para que quede no quede debajo de la pantalla al inicio
}

void PowerUp::hidePowerUp()
{
  _sprite.setPosition({-1000,0});
}


sf::FloatRect PowerUp::getBounds()const{
  return _sprite.getGlobalBounds();
}

void PowerUp::draw(sf::RenderTarget &target, sf::RenderStates states)const{
  target.draw(_sprite, states);
}


