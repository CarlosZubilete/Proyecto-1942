#pragma once
#include <SFML/Graphics.hpp>

class Avion /// CLASE ABSTRACTA, ["Avionabel" o "IAvion"]
{
  public:
  /**
    Avion();
    Avion(sf::Sprite sprite,sf::Texture *textura,sf::IntRect rect);
    void setTexture(sf::Texture *textura);
    void setSprite(sf::Sprite sprite);
    void setVelocity(sf::Vector2f velocity);
  **/
    virtual void update() = 0; /// VIRTUAL PURO
    virtual void cmd() = 0; /// VIRTUAL PURO
    virtual sf::Vector2f getPosition() = 0; /// VIRTUAL PURO

  protected:
    sf::Texture *_texture;
    sf::Sprite _sprite;
    sf::Vector2f _velocity;
    bool _shoot;

};

