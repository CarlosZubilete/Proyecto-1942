#pragma once
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class Sounds
{
  public:
    Sounds();
    void playExplosionSmall();
  private:
    sf::SoundBuffer _buffer;
    sf::Sound _sound;
};


