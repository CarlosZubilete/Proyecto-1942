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
        void cmd() override;
        void respawn();
        void update() override;

        sf::Vector2f getPosition();
        bool shot();

        void draw(sf::RenderTarget &target , sf::RenderStates states)const override;
        sf::FloatRect getBounds() const override;
    private:
        sf::Vector2f _newPosition;
        bool _canShoot;

};

