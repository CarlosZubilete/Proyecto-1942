#pragma once
#include <SFML/Graphics.hpp>


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
};


