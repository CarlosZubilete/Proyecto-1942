#pragma once
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Configuracion.h"

class Sounds
{
  public:
    Sounds();
    void playExplosionSmall();
    void playDisparoPew();
    void setConfiguracion(Configuracion* reg);

  private:
    sf::SoundBuffer _buffer;
    sf::Sound _sound;
    sf::SoundBuffer _bufferPew;
    sf::Sound _soundPew;
    Configuracion* _configuracion;
    bool _soundfx;
};


