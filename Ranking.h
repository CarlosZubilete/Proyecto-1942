#pragma once
#include "Fecha.h"


class Ranking
{
public:
    Ranking();
    Ranking buscaPosicion(int);
private:
    int _pRankingNombre;
    int _pRankingPuntaje;
    Fecha _pFecha;
};
