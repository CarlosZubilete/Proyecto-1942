#include "Scene.h"

Scene::Scene()
{
  _bg.loadFromFile("assets/sprites/bg-maps-1942.png");
  _bgSprite.setTexture(_bg);
  _bgSprite.setPosition(0, -4200);

}

void Scene::update()
{
  _bgSprite.move(0,0.8);
}

sf::Vector2f Scene::getCameraPosition()
{
  return _bgSprite.getPosition();
}

void Scene::draw(sf::RenderTarget &target, sf::RenderStates states)const
{
  target.draw(_bgSprite,states);
}




