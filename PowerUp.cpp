#include "PowerUp.h"


PowerUp::PowerUp(){
  _texture.loadFromFile("assets/sprites/1942-sprites-effects.png");
  _sprite.setTexture(_texture);
  _sprite.setTextureRect({38,55,35,34}); // X,Y,widh,heigh
  _sprite.scale(1.5,1.5);
  _sprite.setPosition({-50,-50});
  _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height/2);
}

void PowerUp::respawn(){
  _sprite.setPosition(std::rand() % 500 + _sprite.getGlobalBounds().width,
                      std::rand() % 400 + _sprite.getGlobalBounds().height);
}

sf::FloatRect PowerUp::getBounds()const{
  return _sprite.getGlobalBounds();
}

void PowerUp::draw(sf::RenderTarget &target, sf::RenderStates states)const{
  target.draw(_sprite, states);
}


