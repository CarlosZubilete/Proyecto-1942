#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class Enemy: public sf::Drawable, public Collisionable
{
    public:
        Enemy();
        void update();
        void draw(sf::RenderTarget &target , sf::RenderStates states)const override;
        sf::FloatRect getBounds() const override;
    private:
        sf::RectangleShape _body;
        float _velocity;

};

