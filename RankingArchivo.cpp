#include "RankingArchivo.h"

RankingArchivo::RankingArchivo(const char *)
{

}

bool RankingArchivo::leerRegistrosRanking()
{
  return false;
}

bool RankingArchivo::grabarRegistroRanking(Ranking &)
{
  return false;
}

Ranking RankingArchivo::buscaPosicion(int)
{
  return Ranking();
}

RankingArchivo::~RankingArchivo()
{

}

void RankingArchivo::setPRanking(FILE *)
{

}
