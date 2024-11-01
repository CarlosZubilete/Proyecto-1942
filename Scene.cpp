#include "Scene.h"
#include <cstring>

Scene::Scene()
{
  _bg.loadFromFile("assets/sprites/bg-maps-1942.png");
  _bgSprite.setTexture(_bg);
  _bgSprite.setPosition(0, -4200);

  /*
  */
  _font.loadFromFile("assets/fonts/MONOCOQUE_FUENTE.ttf");
  _textPuntos.setFont(_font);
  _textPuntos.setCharacterSize(24); /// SETEMOS LOS PIXELES DEL TEXTO
  _textPuntos.setPosition(300,0);
  _textPuntos.setFillColor(sf::Color::Black);


}

void Scene::update()
{
  _textPuntos.setString("PUNTOS: " + std::to_string(_player.getPuntos()));
  _bgSprite.move(0,1);

}

sf::Vector2f Scene::getCameraPosition()
{
  return _bgSprite.getPosition();
}

void Scene::draw(sf::RenderTarget &target, sf::RenderStates states)const
{
  target.draw(_textPuntos,states);
  target.draw(_bgSprite,states);
}




