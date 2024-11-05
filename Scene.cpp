#include "Scene.h"

Scene::Scene()
{
  _bg.loadFromFile("assets/sprites/bg-maps-1942.png");
  _bgSprite.setTexture(_bg);
  _bgSprite.setPosition(0, -4200);
  //Display de vidas y puntaje
  _font.loadFromFile("assets/fonts/MONOCOQUE_FUENTE.ttf");
  _puntos.setFont(_font);
  _puntos.setPosition(3, 0);
  _vidas.setFont(_font);
  _vidas.setPosition(3, 30);

}

void Scene::cmd()
{
  _gamePlay.cmd();
}

void Scene::update()
{
  _bgSprite.move(0,0.8);
  _gamePlay.update();
  _puntos.setString("PUNTOS " + std::to_string(_gamePlay.getPuntos()));
  _vidas.setString("VIDA "    + std::to_string(_gamePlay.getVidas  ()));
}

sf::Vector2f Scene::getCameraPosition()
{
  return _bgSprite.getPosition();
}

void Scene::draw(sf::RenderTarget &target, sf::RenderStates states)const
{
  target.draw(_bgSprite,states);
  target.draw(_gamePlay, states);
  target.draw(_puntos,states);
  target.draw(_vidas,states);
}




