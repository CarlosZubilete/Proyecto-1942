#pragma once
#include <SFML/Graphics.hpp>
#include "GamePlay.h"

class Scene: public sf::Drawable
{
  public:
    Scene();
    void update();
    sf::Vector2f getCameraPosition();
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override;
    void cmd();
    GamePlay _gamePlay;
    // Display de puntajes y vidas:
    sf::Text _puntos;
    sf::Font _font;
    sf::Text _vidas;


  private:
    sf::Texture _bg;
    sf::Sprite _bgSprite;
};


