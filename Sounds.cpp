#include "Sounds.h"

Sounds::Sounds()
{
  _buffer.loadFromFile("assets/sounds/sfx/impact_explosion_03.mp3");
  _sound.setBuffer(_buffer);
  _sound.setVolume(7.f);
}

void Sounds::playExplosionSmall()
{
  _sound.play();
}


