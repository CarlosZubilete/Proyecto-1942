
#include "CartelPosicion.h"


void CartelPosicion::showPositionOnScreen(std::string cartel, sf::Vector2f  posicionCartel, sf::Vector2f  posicionElemento)
{
  fuente.loadFromFile("assets/fonts/monofonto_rg.otf");
  _cartel.setFont(fuente);
  _cartel.setPosition(posicionCartel);
  _cartel.setString(cartel + "\nPosicion: \nx = " +  std::to_string((int)posicionElemento.x) +  "\ny = " + std::to_string((int)posicionElemento.y));
  _cartel.setCharacterSize(10);
}

void CartelPosicion::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(_cartel, states);
}

CartelPosicion::CartelPosicion()
{

}


