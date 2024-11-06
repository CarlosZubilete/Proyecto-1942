#include "Scene.h"

Scene::Scene()
{
  _bg.loadFromFile("assets/sprites/bg-maps-1942.png");
  _bgSprite.setTexture(_bg);
  _bgSprite.setPosition(0, -4200);
  //Display de vidas y puntaje
  _font1.loadFromFile("assets/fonts/MONOCOQUE_FUENTE.ttf");
  _puntos.setFont(_font1);
  _puntos.setPosition(3, 0);
  _vidas.setFont(_font1);
  _vidas.setPosition(3, 30);
  _font2.loadFromFile("assets/fonts/monofonto_rg.otf");
  _frames_cartel.setFont(_font2);
  _frames_cartel.setPosition(500,0);
  _frames_cartel.setCharacterSize(14);
  _frames=0;


}

void Scene::cmd()
{
  _gamePlay.cmd();
}

void Scene::update()
{
  _bgSprite.move(0,3.f);
  _gamePlay.update();
  _puntos.setString("PUNTOS " + std::to_string(_gamePlay.getPuntos()));
  _vidas.setString("VIDA "    + std::to_string(_gamePlay.getVidas  ()));
  _frames_cartel.setString("Frames= " + std::to_string(_frames) + "\nTiempo= " + std::to_string(_frames/60));
  _frames = _gamePlay.getFrames();
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
  target.draw(_frames_cartel,states);
}




