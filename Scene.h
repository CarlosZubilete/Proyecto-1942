#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "GamePlay.h"
#include "ArchivoPlayer.h"
#include "Player.h" /// Lo usuamos solo para guardar el archivoPlayer.
#include <iostream> /// La vieja y confiable

class Scene: public sf::Drawable
{
  public:
    Scene();
    void update();
    sf::Vector2f getCameraPosition();
    void draw(sf::RenderTarget &target, sf::RenderStates states)const override;
    void cmd();
    void respawnBackground();
    void start(int nivel);
    bool getJuegoTerminado();
    bool guardarArchivo();
  private:
    // Display de puntajes y vidas:
    GamePlay _gamePlay;
    int buscarPuntosMax();
    ArchivoPlayer _archivoPlayer;
    sf::Text _puntos;
    sf::Font _font1;
    sf::Font _font2;
    sf::Text _vidas;
    sf::Text _frames_cartel;
    int _frames;
    sf::Texture _bg;
    sf::Sprite _bgSprite;
    int nivel;
    bool nivelTerminado;
    bool _archivoGuardado;
    bool juegoTerminado;
    sf::Text _puntosMaximos;
    bool guardarPartida;
};





