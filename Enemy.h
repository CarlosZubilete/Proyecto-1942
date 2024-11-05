#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"
#include "Avion.h"
#include <string>
#include "CartelPosicion.h"

class Enemy: public sf::Drawable, public Collisionable, public Avion
{
    public:
        Enemy();
        void cmd() override; /// HEREDA DE AVION
        void update() override; /// HEREDA DE AVION
        void draw(sf::RenderTarget &target , sf::RenderStates states)const override;/// HEREDA DE DIBUJABLE
        sf::FloatRect getBounds() const override; /// HEREDA DE COLLISIONABLE
        bool shot();
        void respawn();
        void explosion();
        sf::Vector2f getBulletOrigin();
        sf::Vector2f getPosition() const;

    private:
        sf::Vector2f _newPosition;
        bool _canShoot;
        float _frame;

};

