#pragma once
#include <SFML/Graphics.hpp>


class Bullet: public sf::Drawable
{
  public:
    Bullet();
    Bullet(int horizontal,int vertical, int velocidad);
    //Bullet(int x ,int y, sf::Texture &texture, sf::IntRect intReact , int velociad);
    void Update();
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override;

  private:
    sf::Sprite _sprite;
    sf::Texture *_texture;
    int _velocidad;

};

