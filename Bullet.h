#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"
#include "CartelPosicion.h"


class Bullet: public sf::Drawable, public Collisionable
{
  public:
    Bullet();
    Bullet(int horizontal,int vertical, int velocidad);
    Bullet(sf::Vector2f position);
    //Bullet(int x ,int y, sf::Texture &texture, sf::IntRect intReact , int velociad);
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override;
    sf::FloatRect getBounds() const override;
    CartelPosicion bala_cartel;
  private:
    sf::Sprite _sprite;
    sf::Texture *_texture;
    int _velocidad;

};

