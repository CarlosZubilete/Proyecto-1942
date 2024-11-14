#include "MenuRanking.h"
#include <iostream>

MenuRanking::MenuRanking()
{

  RankingArchivo ra("ranking.dat");

  _cantidadRegistros = ra.CantidadRegistros();
  Ranking *reg = ra.obtenerRegistrosRanking(_cantidadRegistros);
  Ranking::ordenarRanking(reg, _cantidadRegistros);
  _rankingleido = "";
  _rankingleido += "POS\tSCORE\tDATE\t\tNAME\n";
  for (int i = 0; i < 10; i++) {
    std::string nom_str = reg[i].getNombre().getString();
    _rankingleido +=
            std::to_string(i + 1) + "\t" + std::to_string(reg[i].getPuntos()) + "\t" + reg[i].getFecha().toString() +
            "\t" + nom_str + "\n";
  }
  _rankingMasBajo = reg[9].getPuntos();
  _rankingMasAlto = reg[0].getPuntos();


  if (!font.loadFromFile("assets/fonts/fuente.ttf")) {

    std::cout << "No se pudo cargar la fuente" << std::endl;
  }
  texto.setFillColor(sf::Color::Magenta);
  lectura_ranking = _rankingleido;
  texto.setString(lectura_ranking);
  texto.setFont(font);
  texto.setCharacterSize(15);
  texto.setLineSpacing(5);
  texto.setOrigin(texto.getLocalBounds().width / 2, texto.getLocalBounds().height / 2);
  texto.setPosition(600.f / 2, 1000.f);
  if (!fondo_texture.loadFromFile("assets/sprites/1942_clock_3x4.png")) {
    std::cout << "No se pudo cargar la fuente" << std::endl;
  }
  fondo.setTexture(fondo_texture);
  fondo.setPosition(0, 0);
  texto_front = texto;
  texto_front.setFillColor(sf::Color::White);
  texto_front.move(1,1);




}

void MenuRanking::update()
{
  texto.move(0,-0.4);
  texto_front.move(0,-0.4);
}

void MenuRanking::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(fondo, states);
  target.draw(texto, states);
  target.draw(texto_front, states);

}

void MenuRanking::setRankingLeido(std::string &rankingleido)
{
  lectura_ranking = rankingleido;
}

std::string MenuRanking::getRankingLeido() const
{
  return lectura_ranking;
}

int MenuRanking::obtenerRankingMasBajo() const
{
  return _rankingMasBajo;
}

int MenuRanking::obtenerRankingMasAlto() const
{
  return _rankingMasAlto;
}

