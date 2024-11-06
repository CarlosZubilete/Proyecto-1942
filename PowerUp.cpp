#include "PowerUp.h"


PowerUp::PowerUp(){
  _texture.loadFromFile("Esmeralda-IMG.png");
  _sprite.setTexture(_texture);
  _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height/2);
}

void PowerUp::respawn(){
  _sprite.setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width,
                      std::rand() % 500 + _sprite.getGlobalBounds().height);
}

void PowerUp::draw(sf::RenderTarget &target, sf::RenderStates states)const{
  target.draw(_sprite, states);
}

sf::FloatRect PowerUp::getBounds()const{
  return _sprite.getGlobalBounds();
}

