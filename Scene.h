#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <iostream> /// La vieja y confiable
#include <ctime>
#include "GamePlay.h"
#include "ArchivoPlayer.h"
#include "Player.h" /// Lo usuamos solo para guardar el archivoPlayer.
#include "RankingArchivo.h"
#include "MenuRanking.h"
#include "Ranking.h"
#include "Fecha.h"


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
    void setJuegoTerminado(bool);
    bool guardarArchivo();
    void RestarLastPoint();
    void guardarUltimaJugada(int puntos);
    int buscarPuntosMaxRanking();
    void musicaEndPlay(sf::Sound) const;
    void musicaEndStop(sf::Sound) const;

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
    bool nivelTerminado;
    bool _archivoGuardado;
    bool juegoTerminado;
    sf::Text _puntosMaximos;
    bool guardarPartida;
    sf::Texture gameOverTexture;
    sf::Sprite gameOverSprite;
    int _nivel;
    sf::Text _nivel_txt;
    bool _stopGamePlay;
    bool _music;
    sf::SoundBuffer buffer_stagecompleted;
    sf::Sound stagecompleted;
};





