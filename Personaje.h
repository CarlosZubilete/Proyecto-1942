#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"
#include "Avion.h"
#include <string>
#include "CartelPosicion.h"

class Personaje: public sf::Drawable, public Collisionable, public Avion, public sf::Transformable
{
  public:
    Personaje();
    void cmd()override; /// HEREDA DE AVION
    void update() override; /// HEREDA DE AVION
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override;/// HEREDA DE COLLISIONABLE
    sf::FloatRect getBounds() const override; /// HEREDA DE COLLISIONABLE
    bool Shoot(); /// SI APRETAMOS LA TECLA DISPARO
    bool getTeclaAnterior()const;
    void setTeclaAnterior(bool);
    sf::Vector2f getBulletOrigin() const;

  private:
    bool _teclaAnterior = false;
  /// TODO: Machine states
};
