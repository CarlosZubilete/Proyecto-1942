#include "Personaje.h"
#include <iostream>


/// sf::Vector2u textureSize = texture.getSize();
// Obtemos el ancho y el alto de la textura: {textureSize.x , textureSize.y}

Personaje::Personaje()
{
  _velocity = {5,5};
  _shoot = false;
  _texture = new sf::Texture;
  _texture->loadFromFile("assets/sprites/1942-sprites-player.png");
  _sprite.setTexture(*_texture);
  _sprite.setTextureRect({107,17,32,18}); // tamaño x3 = 75x54
  _position = {(600-96)/2+2,700};
//  move((600-96)/2+2,700);
  _sprite.setPosition(_position);
  _sprite.setScale(3,3);
//  _sprite.setOrigin({_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height/2});
  //_state = PersonajeState::Idle;
  //_frame = 0;

}

void Personaje::cmd()
{

  _velocity = {0, 0};

  bool teclaMovimientoPresionada;

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    teclaMovimientoPresionada = true;
    _velocity.x = 5;
    _sprite.setTextureRect({177,17,32,18});
  }

  if (!teclaMovimientoPresionada && getTeclaAnterior()) {
    _sprite.setTextureRect({107,17,32,18}); // tamaño x3 = 75x54
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    teclaMovimientoPresionada = true;
    _velocity.x = -5;
    _sprite.setTextureRect({177,17,32,18});
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    _velocity.y = -5;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    _velocity.y = 5;
  }

  setTeclaAnterior(teclaMovimientoPresionada);


//  /**
//  if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
//  {
//    _state = PersonajeState::Move_Back;
//  }
//  */

}


sf::Vector2f Personaje::getBulletOrigin() const
{
  return {_sprite.getPosition().x + (96-48)/2 ,_sprite.getPosition().y};
}



void Personaje::update()
{

  /*
  switch (_state)
  {
    case PersonajeState::Idle:
      _sprite.setTextureRect({213,33,50,34});

      break;
    case PersonajeState::Move_Right:
      _frame += 0.2;

      if(_frame >= 4){ _frame = 0;}

      _sprite.setTextureRect({270 + int(_frame)*40,33,65,34});
      break;
    case PersonajeState::Move_Left:

      break;
    case PersonajeState::Move_Up:

      break;
    case PersonajeState::Move_Down:

      break;
    case PersonajeState::Move_Back:

      break;
  }
*/

  /// Restricciones de pantalla
  if (_sprite.getPosition().x < -74/2 ){
    _sprite.setPosition(-74/2, _sprite.getPosition().y);
  }
  if (_sprite.getPosition().y < 0) {
    _sprite.setPosition(_sprite.getPosition().x, 0);
  }
  if(_sprite.getPosition().x > 600+ 74/2 - getBounds().width) {
    _sprite.setPosition(600 + 74/2 - getBounds().width, _sprite.getPosition().y);
  }
  if(_sprite.getPosition().y > 800 - getBounds().height) {
    _sprite.setPosition(_sprite.getPosition().x, 800 - getBounds().height);
  }
  _sprite.move({_velocity.x, _velocity.y});
}


bool Personaje::Shoot()
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    if (!_shoot)
    {
      _disparoPew.playDisparoPew();
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

//}

sf::FloatRect Personaje::getBounds()const
{
  return _sprite.getGlobalBounds();
}

void Personaje::draw(sf::RenderTarget &target, sf::RenderStates states)const
{
  target.draw(_sprite, states);
}

void Personaje::setTeclaAnterior(bool teclaAnterior)
{
  _teclaAnterior = teclaAnterior;
}

bool Personaje::getTeclaAnterior() const
{
  return _teclaAnterior;
}



void Personaje::respawn()
{
  _sprite.setPosition((600-96)/2+2, 700);
}

sf::Vector2f Personaje::getPosition() const
{
  return _sprite.getPosition();
}




/// Clse control boleanos , abcde , cada vez que hacemos un cmd,
///
/**
  Mapeo de teclado -> archivo

*/


