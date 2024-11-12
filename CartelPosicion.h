#pragma once
#include <SFML/Graphics.hpp>

class CartelPosicion: public sf::Drawable
{
public:
    void update(); ///
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override;
    CartelPosicion();
    void showPositionOnScreen(std::string, sf::Vector2f, sf::Vector2f);
    sf::Text _cartel;
    sf::Font fuente;
};
