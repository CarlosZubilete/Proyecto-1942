#pragma once
#include <SFML/Graphics.hpp>
#include "Fecha.h"
#include "Player.h"



class Ranking
{

public:
    Ranking();
    void cargar(int puntos, Fecha fecha, sf::Text nombre);
    Ranking buscaPosicion(int);
    void mostrar();
    sf::Text getNombre();
    Fecha getFecha();
    void setNombre(sf::Text nombre);
    void setFecha(Fecha fecha);
    void setPuntos(int puntos);
    int getPuntos();

private:
    int _puntos;
    char _nombre[30];
    Fecha _pFecha;


};


