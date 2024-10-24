#pragma once
#include <SFML/Graphics.hpp>


class Bullet: public sf::Drawable
{
  public:
    //Bullet();
    //Bullet(int x ,int y, sf::Texture &texture, sf::IntRect intReact , int velociad);
    Bullet(int horizontal,int vertical, int velocidad);
    void Update();
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override;
  private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    int _velocidad;

};

