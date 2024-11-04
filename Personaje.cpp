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
//  _sprite.setPosition({375,770});
  _sprite.setScale(3,3);
//  _sprite.setOrigin({_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height/2});
  //_state = PersonajeState::Idle;
  //_frame = 0;

}

void Personaje::cmd()
{

 // _state = PersonajeState::Idle;


  bool teclaMovimientoPresionada;

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    teclaMovimientoPresionada = true;
    move(_velocity.x,0);
    _sprite.setTextureRect({177,17,32,18});
    //_state = PersonajeState::Move_Right;
  }

  if (!teclaMovimientoPresionada && getTeclaAnterior())
  {
    _sprite.setTextureRect({107,17,32,18}); // tamaño x3 = 75x54
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    move(-_velocity.x,0);
    teclaMovimientoPresionada = true;
    _sprite.setTextureRect({2,17,32,18});
    //_state = PersonajeState::Move_Left;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    move(0,-_velocity.y);
    //_state = PersonajeState::Move_Up;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    move(0,_velocity.y);
    //_state = PersonajeState::Move_Down;
  }

  setTeclaAnterior(teclaMovimientoPresionada);
  /**
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
  {
    _state = PersonajeState::Move_Back;
  }
  */

}

//sf::Vector2f Personaje::getPosition()
//{
//  return _sprite.getPosition();
//  return getPosition();

sf::Vector2f Personaje::getBulletOrigin() const
{
  return {getPosition().x + (96-48)/2 ,getPosition().y};
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

  cartel_personaje.showPositionOnScreen("Player:", {getPosition().x+100,getPosition().y-50},{getPosition().x,getPosition().y});

  /// Restricciones de pantalla
  if (getPosition().x < -74/2 ){
    setPosition(-74/2,getPosition().y);
  }
  if (getPosition().y < 0) {
    setPosition(getPosition().x, 0);
  }
  if(getPosition().x > 600+ 74/2 - getBounds().width) {
    setPosition(600 + 74/2 - getBounds().width, getPosition().y);
  }
  if(getPosition().y > 800 - getBounds().height) {
    setPosition(getPosition().x, 800 - getBounds().height);
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

//}

sf::FloatRect Personaje::getBounds()const
{
  return _sprite.getGlobalBounds();
}

void Personaje::draw(sf::RenderTarget &target, sf::RenderStates states)const
{
  states.transform *= getTransform();
  target.draw(_sprite, states);
  target.draw(cartel_personaje);
}

void Personaje::setTeclaAnterior(bool teclaAnterior)
{
  _teclaAnterior = teclaAnterior;
}

bool Personaje::getTeclaAnterior() const
{
  return _teclaAnterior;
}


/// Clse control boleanos , abcde , cada vez que hacemos un cmd,
///
/**
  Mapeo de teclado -> archivo

*/


