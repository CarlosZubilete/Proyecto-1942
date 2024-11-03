#pragma once
#include <SFML/Graphics.hpp>


class Explosion: public sf::Drawable
{
  public:
    Explosion();
    Explosion(int horizontal , int vertical);
    void smallExplosion();
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override;

  private:
    sf::Texture *_texture;
    sf::Sprite _sprite;
    float _frame;
    float _accumulatedTime;
    float _frameDuration;
};

