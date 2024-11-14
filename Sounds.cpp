#include "Sounds.h"

Sounds::Sounds()
{
  _buffer.loadFromFile("assets/sounds/sfx/impact_explosion_03.mp3");
  _sound.setBuffer(_buffer);
  _sound.setVolume(10.f);

  _bufferPew.loadFromFile("assets/sounds/sfx/pew-pew-disparo.mp3");
  _soundPew.setBuffer(_bufferPew);
  _soundPew.setVolume(15.f);

}

void Sounds::playExplosionSmall()
{
  if (_soundfx) _sound.play();
}


void Sounds::playDisparoPew()
{
  if (_soundfx) _soundPew.play();
}

void Sounds::setConfiguracion(Configuracion* reg)
{
  _configuracion = reg;
  _soundfx = _configuracion->getSoundEffects();
}