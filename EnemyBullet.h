#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class EnemyBullet: public sf::Drawable, public Collisionable
{
public:
    EnemyBullet(float horizontal,float vertical, float velocidadX, float velocidadY);
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override;
    sf::FloatRect getBounds() const override;
private:
    sf::Sprite _sprite;
    sf::Texture *_texture;
    float _velocidadX;
    float _velocidadY;

};
