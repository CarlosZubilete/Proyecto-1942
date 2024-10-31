#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class Player: public sf::Drawable, public Collisionable
{
  public:
    Player();
    //Player(int x,int y, sf::Texture &texture);
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override;
    sf::FloatRect getBounds() const override; /// Hereda de collisionable.
    bool Shoot();
    sf::Vector2f getPosicion();

  private:
    sf::Sprite _sprite;
    sf::Texture *_texture;
    sf::Font _font;
    sf::Vector2f _velocity;
    bool _shoot;
};
