#include "Player.h"

Player::Player()
{
  _puntos = 0;
  _vida = 100;
}

void Player::setPuntos(int puntos)
{
  if (puntos > 0 )
  {
    _puntos = puntos;
  }
}

void Player::setVida(int vida)
{
  if (vida < 0 )
  {
    _vida = vida;
  }
}

void Player::changePuntos(int puntos)
{
  if(puntos > 0 )
  {
    _puntos++;
  }
  else
  {
    _puntos--;
  }
}

void Player::changeVidas(int vidas)
{
  _vida -= vidas;
}

int Player::getVida()const
{
  return _vida;
}

int Player::getPuntos()const
{
  return _puntos;
}



/// Clse control boleanos , abcde , cada vez que hacemos un cmd,
///
/**
  Mapeo de teclado -> archivo


*/


