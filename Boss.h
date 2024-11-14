#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"
#include "Avion.h"


class Boss: public sf::Drawable, public Collisionable, public Avion{

public:

    Boss();
    void cmd() override; /// HEREDA DE AVION
    void update() override; /// HEREDA DE AVION
    void draw(sf::RenderTarget &target , sf::RenderStates states) const override;/// HEREDA DE DIBUJABLE
    sf::FloatRect getBounds() const override; /// HEREDA DE COLLISIONABLE
    void respawn();
    //sf::Vector2f getBulletOrigin();
    sf::Vector2f getPosition() const override;
    ///void respawn();
    bool canShot();
    void damaged();

private:

    sf::Vector2f _velocity;
    sf::Vector2f _newPosition;
    bool _llegeAlaPosicion;
    bool _canShot;
    int _timeReload;
};


