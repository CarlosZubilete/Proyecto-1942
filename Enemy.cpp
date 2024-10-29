#include "Enemy.h"

Enemy::Enemy()
{
  _body.setFillColor(sf::Color::Yellow);
  _body.setSize({50,50});
  _velocity = 5.0f;
}

void Enemy::update()
{

}

void Enemy::draw(sf::RenderTarget &target , sf::RenderStates states)const
{
    target.draw(_body,states);
}

sf::FloatRect Enemy::getBounds()const
{
    return _body.getGlobalBounds();
}
