#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class Explosion: public sf::Drawable
{
  public:
    Explosion();
    Explosion(int horizontal , int vertical);
    void smallExplosion();
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override;
    void Play();
  private:
    sf::Texture *_texture;
    sf::Sprite _sprite;
    float _frame;
    sf::SoundBuffer _buffer;
    sf::Sound _sound;
    bool _reproducirExplosion;

};

