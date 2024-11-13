#pragma once
#include <string>
#include "Player.h"

class ArchivoPlayer
{
  public:
    ArchivoPlayer(); /// El nombre del archivo esta en el constructor
    bool Guardar(Player player);
    bool Guardar(Player player, int posicion);
    //int Buscar(int IDplayer);
    int Buscar(int puntos);
    Player Leer(int posicion);
    int CantidadRegistros();
    void Leer(int cantidadRegistros, Player *vector);

  private:
    std::string _nombreArchivo;

};

