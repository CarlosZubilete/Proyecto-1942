// ConfiguracionArchivo.h

#pragma once
#include "Configuracion.h"

class ConfiguracionArchivo
{
public:
    ConfiguracionArchivo(const char* url);
    void setPConfiguracion(FILE * pRanking);
    bool grabarConfiguracion(Configuracion &reg);
    Configuracion* obtenerConfiguracion();
    ~ConfiguracionArchivo();
private:
    FILE * _pConfiguracion;
    const char* _url;
};





