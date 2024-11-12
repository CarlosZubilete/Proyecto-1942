#include "Scene.h"

Scene::Scene(): guardarPartida(false)
{

  _bg.loadFromFile("assets/sprites/bg-maps-1942.png");
  _bgSprite.setTexture(_bg);
  _bgSprite.setPosition(0, -5051+800);
  //Display de vidas y puntaje
  _font1.loadFromFile("assets/fonts/MONOCOQUE_FUENTE.ttf");
  _puntos.setFont(_font1);
  _puntos.setPosition(3, 0);

  _puntosMaximos.setFont(_font1);
  _puntosMaximos.setPosition(3,80);
  _puntosMaximos.setCharacterSize(14);

  _vidas.setFont(_font1);
  _vidas.setPosition(2, 40);
  _font2.loadFromFile("assets/fonts/monofonto_rg.otf");
  _frames_cartel.setFont(_font2);
  _frames_cartel.setPosition(500,0);
  _frames_cartel.setCharacterSize(14);
  _archivoGuardado = false;
  juegoTerminado = false;/// bandera para indicar que el juego termine.
}

void Scene::cmd()
{
  _gamePlay.cmd();
}

void Scene::update()
{
  _bgSprite.move(0,2.3f);

  _frames = _gamePlay.getFrames();

  if (_frames < 1800) {
    _bgSprite.move(0, 2.3f);
  }

  _gamePlay.update();

  _puntos.setString("PUNTOS " + std::to_string(_gamePlay.getPuntos()));
  _vidas.setString("VIDA "    + std::to_string(_gamePlay.getVidas  ()));
  _frames_cartel.setString("Frames= " + std::to_string(_frames) + "\nTiempo= " + std::to_string(_frames/60));
  _frames = _gamePlay.getFrames();

  int puntosMaximos = buscarPuntosMax();
  _puntosMaximos.setString("Ptos Maximos : " + std::to_string(puntosMaximos));


  if(_bgSprite.getPosition().y > 0 )
  {
    respawnBackground();
  }



}


int Scene::buscarPuntosMax()
{
    ArchivoPlayer archivo;
    int cantRegistros = archivo.CantidadRegistros();
    int maxPuntos = 0;
    Player player;

    for (int i = 0; i < cantRegistros; i++)
    {
        player = archivo.Leer(i);
        if (i == 0)
        {
            maxPuntos = player.getPuntos();
        }
        else if (player.getPuntos() > maxPuntos)
        {
            maxPuntos = player.getPuntos();
        }
    }

    return maxPuntos;
}

bool Scene::getJuegoTerminado()
{


    if (_gamePlay.getVidas() == 0)
    {
        if(guardarPartida==false){
        guardarArchivo();
        guardarPartida=true;
        }
        return true;
    }
    return false;

}

bool Scene::guardarArchivo(){
    int puntos = _gamePlay.getPuntos();
    int cantidadRegistros = _archivoPlayer.CantidadRegistros();


    Player player;
    player.changePuntos(puntos);

    bool guardado = _archivoPlayer.Guardar(player);

    if (guardado) {
        std::cout << "ARCHIVO GUARDADO CORRECTAMENTE :)" << std::endl;
    } else {
        std::cout << "ERROR: NO SE PUDO GUARDAR EL ARCHIVO :(" << std::endl;
    }

    return guardado;

}


sf::Vector2f Scene::getCameraPosition()
{
  return _bgSprite.getPosition();
}

void Scene::draw(sf::RenderTarget &target, sf::RenderStates states)const
{
  target.draw(_bgSprite,states);
  target.draw(_gamePlay, states);
  target.draw(_puntos,states);
  target.draw(_vidas,states);
  target.draw(_puntosMaximos,states);
  target.draw(_frames_cartel,states);
}

void Scene::respawnBackground()
{
  /// TODO: EN CASO DE VOLVER A JUGAR
  _bgSprite.setPosition({0,-5051+800});
}

void Scene::start(int nivel)
{
  switch(nivel)
  {
    case 1:
    {
      _bg.loadFromFile("assets/sprites/bg-maps-1942.png");
      _bgSprite.setTexture(_bg);
      _bgSprite.setPosition(0, -5051+800);
      //Display de vidas y puntaje
    }
      break;
    case 2:
    {
      _bg.loadFromFile("assets/sprites/bg-maps-1942.png");
      _bgSprite.setTexture(_bg);
      _bgSprite.setPosition(0, -5051+800);
      //Display de vidas y puntaje
    }
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      break;
    case 9:
      break;
    case 10:
      break;

  }
}

/**
  TRANSFORMACION , AL BOUDS ,
  EL X E Y SON RELATIVOS
*/







