#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class PowerUp : public sf::Drawable, public Collisionable
{
  public:
    PowerUp();
    void update();
    void respawn();
    void draw(sf::RenderTarget &, sf::RenderStates)const override;
    sf::FloatRect getBounds() const override;
    void hidePowerUp();
  private:
    sf::Texture _texture;
    sf::Sprite _sprite;
};
