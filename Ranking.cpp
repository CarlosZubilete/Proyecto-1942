#include <iostream>
<<<<<<< HEAD
=======
#include <stdio.h>
#include <cstring>
>>>>>>> main
#include "Ranking.h"
#include <stdio.h>
#include <cstring>

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


<<<<<<< HEAD
void Ranking::cargar(sf::Text puntos, sf::Text dia, sf::Text mes, sf::Text anio, sf::Text nombre)
{
  setPuntos(puntos);
  setFecha(dia, mes, anio);
=======
void Ranking::cargar(int puntos, Fecha fecha, sf::Text nombre)
{
  setPuntos(puntos);
  setFecha(fecha);
>>>>>>> main
  setNombre(nombre);
}

void Ranking::mostrar()
{
<<<<<<< HEAD
  sf::Text dia,mes,anio,puntos,nombre;

  std::string dia_str = std::to_string(_pFecha.getDia());
  dia.setString(dia_str);

  std::string mes_str = std::to_string(_pFecha.getMes());
  mes.setString(mes_str);

  std::string anio_str = std::to_string(_pFecha.getAnio());
  anio.setString(anio_str);

  puntos.setString(std::to_string(_puntos));
  nombre.setString(_nombre);
=======
  std::cout << std::to_string(getPuntos()) << "   ";
  std::cout << std::to_string(getFecha().getDia()) << "-" << std::to_string(getFecha().getMes()) << "-" << std::to_string(getFecha().getAnio()) << "   ";
  std::string nom_str = getNombre().getString();
  std::cout << nom_str << std::endl;

>>>>>>> main
}

sf::Text Ranking::getNombre()
{
  sf::Text nombre;
  std::string nombre_str (_nombre);
  nombre.setString(_nombre);
  return nombre;
}

<<<<<<< HEAD
=======
void Ranking::setNombre(sf::Text nombre)
{
  std::string nombre_str = nombre.getString();
  strcpy(_nombre, nombre_str.c_str() );
}

>>>>>>> main
int Ranking::getPuntos()
{
  return _puntos;
}

<<<<<<< HEAD
=======
void Ranking::setPuntos(int puntos)
{
  _puntos = puntos;
}

>>>>>>> main
Fecha Ranking::getFecha()
{
  return {_pFecha.getDia(),_pFecha.getMes(),_pFecha.getAnio()};
}

<<<<<<< HEAD
void Ranking::setNombre(sf::Text nombre)
{
  std::string nombre_str = nombre.getString();
  strcpy(_nombre, nombre_str.c_str() );
}

void Ranking::setFecha(sf::Text dia, sf::Text mes, sf::Text anio)
{
  std::string dia_str = dia.getString();
  std::string mes_str = mes.getString();
  std::string anio_str = anio.getString();
  _pFecha = {stoi(dia_str), stoi(mes_str), stoi(anio_str)};
}

void Ranking::setPuntos(sf::Text puntos)
{
  std::string puntos_str = puntos.getString();
  _puntos = std::stoi(puntos_str);
=======
void Ranking::setFecha(Fecha fecha)
{
  _pFecha = fecha;
>>>>>>> main
}
