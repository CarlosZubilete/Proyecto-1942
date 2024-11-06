#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
//#define M_PI 3.14159265358979323846
//#include <iostream>
#include "Collisionable.h"
#include "Avion.h"

class EnemyB: public sf::Drawable, public Collisionable, public Avion
{
    public:
        EnemyB();
        void cmd() override; /// HEREDA DE AVION
        void update() override; /// HEREDA DE AVION
        sf::Vector2f getPosition()const override; /// HEREDA DE AVION
        void draw(sf::RenderTarget &target , sf::RenderStates states)const override;/// HEREDA DE DIBUJABLE
        sf::FloatRect getBounds() const override; /// HEREDA DE COLLISIONABLE
        bool shot();
        void respawn();
        void explosion();
    private:
        sf::Vector2f _newPosition;
        bool _canShoot;
        float _frame;
        int _timeRespawn;
        int _timeReload;
        //sf::Vector2f _moveHacia;
        //float _angle;
        //int _horizonte;

};

