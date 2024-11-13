//
// Created by Mariano Belgrano on 13/11/2024.
//

#include "Configuracion.h"

bool Configuracion::getSoundEffects() const
{
  return _soundEffects;
}

void Configuracion::setSoundEffects(bool soundEffects)
{
  _soundEffects = soundEffects;
}

bool Configuracion::getMusic() const
{
  return _music;
}

void Configuracion::setMusic(bool music)
{
  _music = music;
}

void Configuracion::cargarConfiguracion(bool soundEffects, bool music)
{
  _soundEffects = soundEffects;
  _music = music;
}

