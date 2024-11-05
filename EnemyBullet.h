#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class EnemyBullet: public sf::Drawable, public Collisionable, public sf::Transformable
{
public:
    EnemyBullet(int horizontal,int vertical, int velocidad);
    //Bullet(int x ,int y, sf::Texture &texture, sf::IntRect intReact , int velociad);
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override;
    sf::FloatRect getBounds() const override;
private:
    sf::Sprite _sprite;
    sf::Texture *_texture;
    int _velocidad;

};
