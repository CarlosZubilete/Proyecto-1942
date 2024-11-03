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
        void cmd() override; /// HEREDA DE AVION
        void update() override; /// HEREDA DE AVION
        sf::Vector2f getPosition() override; /// HEREDA DE AVION
        void draw(sf::RenderTarget &target , sf::RenderStates states)const override;/// HEREDA DE DIBUJABLE
        sf::FloatRect getBounds() const override; /// HEREDA DE COLLISIONABLE
        bool shot();
        void respawn();
        void explosion();
    private:
        sf::Vector2f _newPosition;
        bool _canShoot;
        float _frame;

};

