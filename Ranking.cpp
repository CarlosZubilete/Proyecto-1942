#include <iostream>
#include <stdio.h>
#include <cstring>
#include "Ranking.h"

Ranking::Ranking()
{
  _puntos = 0;
  strcpy(_nombre,"");
  _pFecha={1,1,1900};
}

Ranking Ranking::buscaPosicion(int)
{
  return Ranking();
}


void Ranking::cargar(int puntos, Fecha fecha, sf::Text nombre)
{
  setPuntos(puntos);
  setFecha(fecha);
  setNombre(nombre);
}

void Ranking::mostrar()
{
  std::cout << std::to_string(getPuntos()) << "   ";
  std::cout << std::to_string(getFecha().getDia()) << "-" << std::to_string(getFecha().getMes()) << "-" << std::to_string(getFecha().getAnio()) << "   ";
  std::string nom_str = getNombre().getString();
  std::cout << nom_str << std::endl;

}

sf::Text Ranking::getNombre()
{
  sf::Text nombre;
  std::string nombre_str (_nombre);
  nombre.setString(_nombre);
  return nombre;
}

void Ranking::setNombre(sf::Text nombre)
{
  std::string nombre_str = nombre.getString();
  strcpy(_nombre, nombre_str.c_str() );
}

int Ranking::getPuntos()
{
  return _puntos;
}

void Ranking::setPuntos(int puntos)
{
  _puntos = puntos;
}

Fecha Ranking::getFecha()
{
  return {_pFecha.getDia(),_pFecha.getMes(),_pFecha.getAnio()};
}

void Ranking::setFecha(Fecha fecha)
{
  _pFecha = fecha;
}
