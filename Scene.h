#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Scene: public sf::Drawable
{
  public:
    Scene();
    void update();
    sf::Vector2f getCameraPosition();
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override;

  private:
    sf::Texture _bg;
    sf::Sprite _bgSprite;
    sf::Font _font;
    sf::Text _textPuntos;
    Player _player;
};


