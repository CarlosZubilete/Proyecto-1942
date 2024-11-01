#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"
#include "Avion.h"
#include <string>

class Enemy: public sf::Drawable, public Collisionable, public Avion
{
    public:
        Enemy();
        Enemy(std::string namePng,sf::IntRect rect,float vel_x,float vel_y);
        /**
        void sf::Vector2f getPosition() const override;
        **/
        void respawn();
        void cmd() override; /// HEREDA DE AVION
        void update() override; /// HEREDA DE AVION
        sf::Vector2f getPosition();
        bool shot();
        void draw(sf::RenderTarget &target , sf::RenderStates states)const override;/// HEREDA DE COLLISIONABLE
        sf::FloatRect getBounds() const override; /// HEREDA DE DIBUJABLE
    private:
        sf::Vector2f _newPosition;
        bool _canShoot;

};

