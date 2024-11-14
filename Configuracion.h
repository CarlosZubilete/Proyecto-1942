// Configuracion.h

#pragma once

class Configuracion
{
public:
    bool getSoundEffects() const;
    void setSoundEffects(bool soundEffects);
    bool getMusic() const;
    void setMusic(bool music);
    void cargarConfiguracion(bool,bool);
private:
  bool _soundEffects;
  bool _music;
};
