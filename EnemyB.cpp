#include "EnemyB.h"

EnemyB::EnemyB()
{
  _texture = new sf::Texture;
  _texture->loadFromFile("assets/sprites/1942-sprites-enemy.png");
  _sprite.setTexture(*_texture);
  _sprite.setTextureRect({426,324,31,23});
  _velocity = {3,3};
  _sprite.setPosition(std::rand()%600,0-48-48); /// APARECE EN EL LADO NEGATIVO.
  _sprite.setScale(2,2);
  _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height/2);
  _timeRespawn = 60*2;
  _canShoot = false;
}

void EnemyB::cmd()
{
  _timeRespawn--;

  if(_timeRespawn > 0)
  {
    _canShoot = false;
  }

  if (_timeRespawn < 0 )
  {
    _timeRespawn = 60*2;
    _canShoot = true;
  }


  /// SI LA NUEVA POS EN X ESTA ADELANTE DE LA ACUTUAL POSICION
  if(_newPosition.x > _sprite.getPosition().x){
    _sprite.move(_velocity.x,0);

  }
  /// SI LA NUEVA POS EN X ESTA ATRAS DE LA ACTUAL POSICION
  if(_newPosition.x <  _sprite.getPosition().x){
    _sprite.move(-_velocity.x,0);

  }

  /// SI LA NUEVA POS EN Y  ES MAYOR  DE LA ACTUAL POSICION
  if(_newPosition.y > _sprite.getPosition().y){
    _sprite.move(0,_velocity.y);

  }
  /// SI LA NUEVA POS EN Y  ES MENOR DE LA ACTUAL POSICION
  if(_newPosition.y < _sprite.getPosition().y){
    _sprite.move(0,-_velocity.y);
  }

}

void EnemyB::update()
{

  ///CORREGIR: SI LA DIFERENCIA ABSOLUTA ES MENOR ENTRE LA POSICION ACTUAL Y LA NUEVA POSICION,
  /// NOS MOVEMOS EN
  if (std::abs(_newPosition.x - _sprite.getPosition().x) <= 15)
  {
    //_sprite.setPosition(_newPosition.x,_sprite.getPosition().y);
    _newPosition = {std::rand() % 400 + _sprite.getGlobalBounds().width, std::rand() % 400 + _sprite.getGlobalBounds().height};
  }
  if (std::abs(_newPosition.y - _sprite.getPosition().y) <= 15)
  {
    //_sprite.setPosition(_sprite.getPosition().x,_newPosition.y);
    _newPosition = {std::rand() % 400 + _sprite.getGlobalBounds().width, std::rand() % 400 + _sprite.getGlobalBounds().height};
  }

}
void EnemyB::respawn()
{
  _sprite.setPosition(std::rand()%600,0-48-48);
  _timeRespawn = 60*2;
}

bool EnemyB::shot()
{
  return _canShoot;
}

sf::Vector2f EnemyB::getPosition()const
{
  return _sprite.getPosition();
}

sf::FloatRect EnemyB::getBounds()const
{
  return _sprite.getGlobalBounds();
}

void EnemyB::draw(sf::RenderTarget &target , sf::RenderStates states)const
{
  target.draw(_sprite,states);
}



/*
1.CALCUALAR EL ANGULO DE LA DIRECCION :
    _angle = atan2(_velocity.y, _velocity.x);

2. _angle = _angle * (180 / M_PI);
    Ajustar el rango del �ngulo: Si angle es negativo, puedes convertirlo a un     �ngulo positivo sumando 360.

3.
Asignar el �ngulo a un horizonte: Divide los 360 grados en 16 partes (22.5 grados cada una) para mapear el �ngulo a los horizontes. Por ejemplo:

    if (_angle < 0) {
    _angle += 360;
    }

4.
Esto funciona al redondear el �ngulo a la parte m�s cercana de 22.5 grados y mapearlo a un valor entre 1 y 16.

int horizonte = static_cast<int>((angle + 11.25) / 22.5) % 16 + 1;
*/
/*
void EnemyB::update()
{

///////////////////////////////////////////////////////////////////////////////
/// velocidad x = H . cos&.
/// velocidad y = H . sen&.
    _angle = atan2(_newPosition.y, _newPosition.x);

    _angle = _angle * (180 / M_PI);

    _horizonte = static_cast<int>((_angle + 11.25) / 22.5) % 16 + 1;

///////////////////////////////////////////////////////////////////////////////
    switch (_horizonte)
    {
        case 1:
            std::cout << "HORIZONTE " << _horizonte << std::endl;
            std::cout << "Angulo" << _angle << std::endl;

            break;
        case 2:
            std::cout << "HORIZONTE " << _horizonte << std::endl;
            std::cout << "Angulo" << _angle << std::endl;
            break;
        case 3:
            std::cout << "HORIZONTE " << _horizonte << std::endl;
            std::cout << "Angulo" << _angle << std::endl;
            break;
        case 4:
            std::cout << "HORIZONTE " << _horizonte << std::endl;
            std::cout << "Angulo" << _angle << std::endl;
            break;
        case 5:
            std::cout << "HORIZONTE " << _horizonte << std::endl;
            std::cout << "Angulo" << _angle << std::endl;
            break;
        case 6:
            std::cout << "HORIZONTE " << _horizonte << std::endl;
            std::cout << "Angulo" << _angle << std::endl;
            break;
        case 7:
            std::cout << "HORIZONTE " << _horizonte << std::endl;
            std::cout << "Angulo" << _angle << std::endl;
            break;
        case 8:
            std::cout << "HORIZONTE " << _horizonte << std::endl;
            std::cout << "Angulo" << _angle << std::endl;
            break;
        case 9:
            std::cout << "HORIZONTE " << _horizonte << std::endl;
            std::cout << "Angulo" << _angle << std::endl;
            break;
        case 10:
            std::cout << "HORIZONTE " << _horizonte << std::endl;
            std::cout << "Angulo" << _angle << std::endl;
            break;
        case 11:
            std::cout << "HORIZONTE " << _horizonte << std::endl;
            std::cout << "Angulo" << _angle << std::endl;
            break;
        case 12:
            std::cout << "HORIZONTE " << _horizonte << std::endl;
            std::cout << "Angulo" << _angle << std::endl;
            break;
        case 13:
            std::cout << "HORIZONTE " << _horizonte << std::endl;
            std::cout << "Angulo" << _angle << std::endl;
            break;
        case 14:
            std::cout << "HORIZONTE " << _horizonte << std::endl;
            std::cout << "Angulo" << _angle << std::endl;
            break;
        case 15:
            std::cout << "HORIZONTE " << _horizonte << std::endl;
            std::cout << "Angulo" << _angle << std::endl;
            break;
    }
}
*/
