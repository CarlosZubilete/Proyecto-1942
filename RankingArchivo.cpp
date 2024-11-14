#include <iostream>
#include "RankingArchivo.h"
#include "CompatibilidadMacos.h"

RankingArchivo::RankingArchivo(const char* url)
{
  _pRanking = nullptr;
  _url = url;
}

void RankingArchivo::setPRanking(FILE * pRanking)
{
  _pRanking = pRanking;
}

bool RankingArchivo::leerRegistrosRanking()
{
  Ranking reg;
  setPRanking(fopen(_url,"rb"));
  if(_pRanking==nullptr)
  {
    std::cerr << "Error al abrir el archivo para leer" << std::endl;
    return false;
  } else
  {
    std::cout << "--- DATOS LEIDOS CORRECTAMENTE... ---" << std::endl;
  }

  //limpiar();

  while(fread(&reg,sizeof(Ranking),1,_pRanking)==1)
  {
    reg.mostrar();
    std::cout << "----------------o---------------" << std::endl;
  }
  //pausar();
  fclose(_pRanking);
  return true;
}

bool RankingArchivo::grabarRegistroRanking(Ranking &reg)
{
    _pRanking = fopen(_url,"ab");
    if (_pRanking == nullptr)
    {
      std::cerr << "Error al abrir el archivo para escribir." << std::endl;
      return false;
    }
    fwrite(&reg,sizeof(Ranking),1,_pRanking);
    fclose(_pRanking);
      std::cout << "Datos guardados correctamente en ranking.dat" << std::endl;
    return true;
}

RankingArchivo::~RankingArchivo()
{
  if(_pRanking != nullptr)
    fclose(_pRanking);
}

Ranking* RankingArchivo::obtenerRegistrosRanking(int cantidad_registros)
{
  auto *reg = new Ranking[cantidad_registros];
  _pRanking = fopen(_url, "rb");
  if (_pRanking == nullptr) {
    std::cerr << "Error al abrir el archivo para escribir." << std::endl;
    exit(0);
  }
  for (int i = 0; i < cantidad_registros; i++) {
    fread(&reg[i], sizeof(Ranking), 1, _pRanking);
  }
  fclose(_pRanking);

  return reg;
}

int RankingArchivo::CantidadRegistros(){
  FILE *pArchivo = fopen(_url, "rb");
  if(pArchivo == NULL){
    return 0;
  }
  fseek(pArchivo, 0, SEEK_END);
  int cantidadRegistros = ftell(pArchivo) / sizeof(Ranking);
  fclose(pArchivo);
  return cantidadRegistros;
}
