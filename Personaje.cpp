#include "Personaje.h"


/// sf::Vector2u textureSize = texture.getSize();
// Obtemos el ancho y el alto de la textura: {textureSize.x , textureSize.y}

Personaje::Personaje()
{
  _velocity = {5,5};
  _shoot = false;
  _texture = new sf::Texture;
  _texture->loadFromFile("assets/sprites/1942-sprites-player.png");
  _sprite.setTexture(*_texture);
  _sprite.setTextureRect({1,62,25,18});
  _sprite.setPosition({375,770});
  _sprite.setScale(3,3);
  _sprite.setOrigin({_sprite.getGlobalBounds().width/2,
                    _sprite.getGlobalBounds().height/2});
}

void Personaje::cmd()
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    _sprite.move(_velocity.x,0);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    _sprite.move(-_velocity.x,0);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    _sprite.move(0,-_velocity.y);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    _sprite.move(0,_velocity.y);
  }
}

void Personaje::update()
{

  /// Restricciones de pantalla
  if (_sprite.getGlobalBounds().left < 0 )
  {
    _sprite.setPosition((_sprite.getOrigin().x + _sprite.getGlobalBounds().width) ,
                        _sprite.getPosition().y);
  }
  if (_sprite.getGlobalBounds().top < 0){
    _sprite.setPosition(_sprite.getPosition().x,
                        (_sprite.getOrigin().y + _sprite.getGlobalBounds().height));
  }
  if(_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 600){
    _sprite.setPosition(600 - ( _sprite.getOrigin().x - _sprite.getGlobalBounds().width),
                        _sprite.getPosition().y);
  }
  if(_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 800){
    _sprite.setPosition(_sprite.getPosition().x,
                        800 + ( _sprite.getGlobalBounds().height - _sprite.getOrigin().y));
  }
}

bool Personaje::Shoot()
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    if (!_shoot)
    {
      _shoot = true;
      return true;
    }
  }
  else
  {
    /// Cuando deje de soltar el espacio, el player va a poder disparar.
    if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
    {
      _shoot = false;
    }
  }

  return false;
}


sf::Vector2f Personaje::getPosicion()
{
  return _sprite.getPosition();
}

sf::FloatRect Personaje::getBounds()const
{
  return _sprite.getGlobalBounds();
}

void Personaje::draw(sf::RenderTarget &target, sf::RenderStates states)const
{
  target.draw(_sprite, states);
}


/// Clse control boleanos , abcde , cada vez que hacemos un cmd,
///
/**
  Mapeo de teclado -> archivo

*/


