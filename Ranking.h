#pragma once
#include <SFML/Graphics.hpp>
#include "Fecha.h"
#include "Player.h"



class Ranking
{

public:
    Ranking();
<<<<<<< HEAD
    void cargar(sf::Text puntos, sf::Text dia, sf::Text mes, sf::Text anio, sf::Text nombre);
=======
    void cargar(int puntos, Fecha fecha, sf::Text nombre);
>>>>>>> main
    Ranking buscaPosicion(int);
    void mostrar();
    sf::Text getNombre();
    Fecha getFecha();
    void setNombre(sf::Text nombre);
<<<<<<< HEAD
    void setFecha(sf::Text dia, sf::Text mes, sf::Text anio);
    void setPuntos(sf::Text puntos);
=======
    void setFecha(Fecha fecha);
    void setPuntos(int puntos);
>>>>>>> main
    int getPuntos();

private:
    int _puntos;
    char _nombre[30];
    Fecha _pFecha;


};


