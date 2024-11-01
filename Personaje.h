#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"
#include "Avion.h"

class Personaje: public sf::Drawable, public Collisionable, public Avion
{
  public:
    Personaje();
    void cmd()override; /// HEREDA DE AVION
    void update() override; /// HEREDA DE AVION
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override;/// HEREDA DE COLLISIONABLE
    sf::FloatRect getBounds() const override; /// HEREDA DE COLLISIONABLE
    bool Shoot(); /// SI APRETAMOS LA TECLA DISPARO
    sf::Vector2f getPosicion();/// OBTENMOS LA POSICION DEL PERSONAJE ACTUALIZADO
  private:

  /// TODO: Machine states
};
