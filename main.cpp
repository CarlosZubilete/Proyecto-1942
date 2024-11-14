#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <iostream>

#include "Scene.h"
#include "Menu.h"
#include "Creditos.h"
#include "RankingArchivo.h"
#include "Ranking.h"
#include "Fecha.h"
#include "MenuRanking.h"
#include "MenuConfiguracion.h"
#include "Configuracion.h"
#include "ConfiguracionArchivo.h"


int main() {

  ConfiguracionArchivo ca("configuracion.dat");
  Configuracion * reg = ca.obtenerConfiguracion();
  std::cout << reg->getSoundEffects() << std::endl;
  std::cout << reg->getMusic() << std::endl;


  std::srand((unsigned) std::time(0));

  sf::RenderWindow window(sf::VideoMode(600, 800), "1942 @UTN", sf::Style::Default);

  Menu mainMenu(window.getSize().x, window.getSize().y);

  window.setFramerateLimit(60);

//   Definir la vista
  sf::View view(sf::FloatRect(0.f, 0.f, 600.f, 800.f));
  window.setView(view);

  Scene scene;

  // Main theme 2
  sf::SoundBuffer buffer_main_theme_v2;
  buffer_main_theme_v2.loadFromFile("assets/sounds/themes/02_main_theme_v2_stereo.mp3");
  sf::Sound main_theme_v2;
  main_theme_v2.setBuffer(buffer_main_theme_v2);
  main_theme_v2.setVolume(7.f);
  if( reg->getMusic()) main_theme_v2.play();

  // Main theme 1
  sf::SoundBuffer buffer_main_theme_v1;
  buffer_main_theme_v1.loadFromFile("assets/sounds/themes/01_main_theme_v1_stereo.mp3");
  sf::Sound main_theme_v1;
  main_theme_v1.setBuffer(buffer_main_theme_v1);
  main_theme_v1.setVolume(7.f);

  // Nostalgia theme
  sf::SoundBuffer buffer_nostalgia;
  buffer_nostalgia.loadFromFile("assets/sounds/themes/04_high_score_entry_stereo.mp3");
  sf::Sound nostalgia;
  nostalgia.setBuffer(buffer_nostalgia);
  nostalgia.setVolume(7.f);

  // CARTEL CONTINUAR EN EL JUEGO
  sf::Font font;
  font.loadFromFile("assets/fonts/MONOCOQUE_FUENTE.ttf");
  sf::Text continuar_text;
  sf::RectangleShape continuar_text_fondo;

  bool mostrarContinuar = false;

  // GAME LOOP
  while (window.isOpen()) {

    sf::Event event;

    while (window.pollEvent(event)) {
//
      if ((event.type == sf::Event::Closed) ||
          (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
        window.close();
      }
//
//
      if (event.type == sf::Event::KeyReleased) {
//
        if (event.key.code == sf::Keyboard::Up) {
          mainMenu.moveUp();
//
        } else if (event.key.code == sf::Keyboard::Down) {
          mainMenu.moveDown();
//
        } else if (event.key.code == sf::Keyboard::Return) {
//
          if (mainMenu.getShowInsertCoin()) {
            mainMenu.handleEnterPress();
//
          } else {
//
            int x = mainMenu.getPressedItem();
//
            if (x == 0) {
//
              sf::RenderWindow Play(sf::VideoMode(600, 800), "1942");
              Play.setFramerateLimit(60);
              main_theme_v2.stop();
              if( reg->getMusic()) main_theme_v1.play();

              // GAME LOOP
              while (Play.isOpen()) {

                // EVENTS /////////////////////////////////////////////////////////
                sf::Event playEvent;

                while (Play.pollEvent(playEvent))
                {

                  if (playEvent.type == sf::Event::Closed) {
                    Play.close();
                    main_theme_v1.stop();

                  }

                  if (playEvent.type == sf::Event::KeyPressed) {
                    if (playEvent.key.code == sf::Keyboard::Escape) {
                      mostrarContinuar = true;
                      continuar_text_fondo.setSize({300, 150});
                      continuar_text_fondo.setOrigin(continuar_text_fondo.getLocalBounds().width / 2,
                                                     continuar_text_fondo.getLocalBounds().height /
                                                     2);
                      continuar_text_fondo.setPosition(600 / 2, 800 / 2);
                      continuar_text_fondo.setFillColor(sf::Color(0, 0, 0, 128));

                      continuar_text.setFillColor(sf::Color::White);
                      continuar_text.setString("SALIR  Y   N");
                      continuar_text.setCharacterSize(24);
                      continuar_text.setPosition(600 / 2, 800 / 2);
                      continuar_text.setFont(font);
                      continuar_text.setOrigin(continuar_text.getGlobalBounds().width / 2,
                                               continuar_text.getGlobalBounds().height / 2);
                    }

                    if (mostrarContinuar) {
                      if (playEvent.key.code == sf::Keyboard::Y) {
                        main_theme_v1.stop();
                        main_theme_v2.play();
                        Play.close();

                      } else if (playEvent.key.code == sf::Keyboard::N) {
<<<<<<< HEAD
                        main_theme_v1.stop();
                        main_theme_v2.play();
                        Play.close();
=======
                        mostrarContinuar = false;
>>>>>>> a1a7f0622252c9cccfc529b4170d7d04c79a3d12
                      }
                    }
                  }
                }/// FIN DEL WHILE INTERNO . . .

                // CMD ////////////////////////////////////////////////////////////
                if (scene.getJuegoTerminado()) {
                  ///  STOP MUSICA DEL JUEGO
                  scene.setJuegoTerminado(true);
                }
                // UPDATE /////////////////////////////////////////////////////////
                if (!scene.getJuegoTerminado()) {
                  scene.cmd();
                  scene.update();
                }

                // DRAW ///////////////////////////////////////////////////////////
                Play.clear();

                Play.draw(scene);

                if (mostrarContinuar) {
                  Play.draw(continuar_text_fondo);
                  Play.draw(continuar_text);
                } // DIBUJO CARTEL CONTINUAR
                // FLIP ///////////////////////////////////////////////////////////
                Play.display();
                // LIBERACION DEL JUEGO

              } /// FIN DEL GAME LOOP
//
            } else if (x == 3) {
//
              sf::RenderWindow CREDITOS(sf::VideoMode(600, 820), "CREDITOS");
              Creditos creditosObj;

              while (CREDITOS.isOpen()) {

                sf::Event optionsEvent;

                while (CREDITOS.pollEvent(optionsEvent)) {

                  if (optionsEvent.type == sf::Event::Closed ||
                      (optionsEvent.type == sf::Event::KeyPressed && optionsEvent.key.code == sf::Keyboard::Escape)) {
                    CREDITOS.close();
                  }
                }

                creditosObj.update();

                CREDITOS.clear();
                CREDITOS.draw(creditosObj);
                CREDITOS.display();
              }

            } else if (x == 4) {
              window.close();

            } else if (x == 1) // CONFIGURACION
            {

              sf::RenderWindow windowConfiguracion(sf::VideoMode(600,800), "Configuracion");
              MenuConfiguracion menuConfiguracion;
              windowConfiguracion.setFramerateLimit(60);
              while(windowConfiguracion.isOpen())
              {
                sf::Event configuracionEvent;

                while(windowConfiguracion.pollEvent(configuracionEvent))
                {
                  if (configuracionEvent.type == sf::Event::Closed ||
                      (configuracionEvent.type == sf::Event::KeyPressed && configuracionEvent.key.code == sf::Keyboard::Escape))
                  {
                    if( reg->getMusic()) main_theme_v2.play();
                    windowConfiguracion.close();
                  }

                  if (configuracionEvent.type == sf::Event::KeyReleased) {
                    if (configuracionEvent.key.code == sf::Keyboard::Up) {
                      menuConfiguracion.moveUp();
                    } else if (configuracionEvent.key.code == sf::Keyboard::Down) {
                      menuConfiguracion.moveDown();
                    } else if (configuracionEvent.key.code == sf::Keyboard::Return) {
                      if (menuConfiguracion.getShowInsertCoin()) {
                        menuConfiguracion.handleEnterPress();
                      } else {
                        int x = menuConfiguracion.getPressedItem();
                        if (x == 0)
                        {
                            reg->setSoundEffects(!reg->getSoundEffects()); // pongo el contrario de la configuracion
                            reg->cargarConfiguracion(reg->getSoundEffects(),reg->getMusic()); // preparo el reg
                            ca.grabarConfiguracion(*reg); // grabo el reg

                        } else if (x == 1)
                        {
                          reg->setMusic(!reg->getMusic()); // pongo el contrario de la configuracion
                          reg->cargarConfiguracion(reg->getSoundEffects(),reg->getMusic()); // preparo el reg
                          ca.grabarConfiguracion(*reg); // grabo el reg
                          if (reg->getMusic()) {
                            main_theme_v2.play();
                          } else {
                            main_theme_v2.stop();
                          }

                        }
                        else if (x == 2)
                        {
                          // TODO: salir
                          windowConfiguracion.close();
                        }



                      }

                    }
                  }





                }
                // CMD
                // UPDATE
                menuConfiguracion.update();
                // DRAW
                windowConfiguracion.clear();
                windowConfiguracion.draw(menuConfiguracion);
                windowConfiguracion.display();
                // FLIP
              }

            } else if (x == 2) // RANKING
            {
              main_theme_v2.stop();
              if( reg->getMusic()) nostalgia.play();
              sf::RenderWindow windowRanking(sf::VideoMode(600, 800), "Ranking");
              MenuRanking menuRanking;
              windowRanking.setFramerateLimit(60);

              while (windowRanking.isOpen()) {

                sf::Event menuRankingEvent;

                while(windowRanking.pollEvent(menuRankingEvent)) {

                  if (menuRankingEvent.type == sf::Event::Closed ||
                      (menuRankingEvent.type == sf::Event::KeyPressed && menuRankingEvent.key.code == sf::Keyboard::Escape)) {
                    nostalgia.stop();
                    if( reg->getMusic()) main_theme_v2.play();
                    windowRanking.close();
                  }
                }

                // Actualizar el estado de MenuRanking
                menuRanking.update();

                // Limpiar, dibujar y mostrar el contenido en pantalla
                windowRanking.clear();
                windowRanking.draw(menuRanking);
                windowRanking.display();
              }
            }
          }
        }
      }
    }
//
    mainMenu.update();
    window.clear();
    window.draw(mainMenu);
    window.display();
//
  }

  delete []reg;

  return 0;
}
