#pragma once
#include <SFML/Graphics.hpp>

class Avion
{
  public:
  /**
    Avion();
    Avion(sf::Sprite sprite,sf::Texture *textura,sf::IntRect rect);
    void setTexture(sf::Texture *textura);
    void setSprite(sf::Sprite sprite);
    void setVelocity(sf::Vector2f velocity);
    virtual void sf::Vector2f getPosition() const = 0;
  **/
    virtual void cmd()  = 0;
    virtual void update() = 0;

  protected:
    sf::Texture *_texture;
    sf::Sprite _sprite;
    sf::Vector2f _velocity;
    //sf::IntRect _rectangulo;
};

