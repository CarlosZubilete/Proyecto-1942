#pragma once
#include <SFML/Graphics.hpp>


class Player: public sf::Drawable
{
  public:
    Player();
    //Player(int x,int y, sf::Texture &texture);
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override;
    bool Shoot();
    sf::Vector2f getPosicion();

  private:
    sf::Sprite _sprite;
    sf::Texture *_texture;
    sf::Vector2f _velocity;
    bool _shoot;
};
