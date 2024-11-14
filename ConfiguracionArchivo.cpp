// ConfiguracionArchivo.cpp

#include <iostream>
#include "ConfiguracionArchivo.h"

ConfiguracionArchivo::ConfiguracionArchivo()
{
  _pConfiguracion = nullptr;
  _url = "assets/config/configuracion.dat";
}

ConfiguracionArchivo::ConfiguracionArchivo(const char* url)
{
  _pConfiguracion = nullptr;
  _url = url;
}

void ConfiguracionArchivo::setPConfiguracion(FILE * pRanking)
{
  _pConfiguracion = pRanking;
}

bool ConfiguracionArchivo::grabarConfiguracion(Configuracion &reg)
{

  _pConfiguracion = fopen(_url,"wb+");
  if (_pConfiguracion == nullptr)
  {
    std::cerr << "Error al abrir el archivo para escribir." << std::endl;
    return false;
  }
  fwrite(&reg,sizeof(Configuracion),1,_pConfiguracion);
  fclose(_pConfiguracion);
  std::cout << "Datos guardados correctamente en configuracion.dat" << std::endl;
  return true;
}

ConfiguracionArchivo::~ConfiguracionArchivo()
{
  if(_pConfiguracion != nullptr)
    fclose(_pConfiguracion);
}

Configuracion* ConfiguracionArchivo::obtenerConfiguracion()
{
  auto *reg = new Configuracion[1];
  _pConfiguracion = fopen(_url, "rb");
  if (_pConfiguracion == nullptr) {
    std::cerr << "Error al abrir el archivo para escribir." << std::endl;
    exit(0);
  }
  for (int i = 0; i < 1; i++) {
    fread(&reg[i], sizeof(Configuracion), 1, _pConfiguracion);
  }
  fclose(_pConfiguracion);

  return reg;
}

