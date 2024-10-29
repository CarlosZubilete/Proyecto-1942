#include "Scene.h"


Scene::Scene()
{
  _bg.loadFromFile("bg-maps-1942.png");
  _bgSprite.setTexture(_bg);
  //_playerFixed.setPosition({400,6358});
}

void Scene::update()
{
  _bgSprite.move(0,-1);
}

sf::Vector2f Scene::getCameraPosition()
{
  return _bgSprite.getPosition();
}

void Scene::draw(sf::RenderTarget &target, sf::RenderStates states)const
{
  target.draw(_bgSprite,states);
}




