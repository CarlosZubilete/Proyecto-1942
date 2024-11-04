#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <cstdlib>
#include <ctime>
#include "Scene.h"
#include "Player.h"
#include "Bullet.h"
#include "Menu.h"
#include "GamePlay.h"

int main() {
   std::srand((unsigned)std::time(0));

    sf::RenderWindow window(sf::VideoMode(600, 800), "MENU 1942", sf::Style::Default);

    Menu mainMenu(window.getSize().x, window.getSize().y);

    window.setFramerateLimit(60);

    // Definir la vista
    sf::View view(sf::FloatRect(0.f, 0.f, 600.f, 800.f));
    window.setView(view);

    GamePlay gamePlay;
    Scene scene;
    Player player;

    sf::Font font;
    font.loadFromFile("assets/fonts/MONOCOQUE_FUENTE.ttf");

    sf::Text puntos;
    puntos.setFont(font);
    puntos.setPosition(3, 0);

    sf::Text vidas;
    vidas.setFont(font);
    vidas.setPosition(3, 30);

    // GAME LOOP
    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // CMD

            if (event.type == sf::Event::KeyReleased) {

                if (event.key.code == sf::Keyboard::Up) {
                    mainMenu.moveUp();

                } else if (event.key.code == sf::Keyboard::Down) {
                    mainMenu.moveDown();

                } else if (event.key.code == sf::Keyboard::Return) {

                    if (mainMenu.showInsertCoin) {
                        mainMenu.handleEnterPress();

                    } else {

                        int x = mainMenu.getPressedItem();

                        if (x == 0) {

                            sf::RenderWindow Play(sf::VideoMode(600, 800), "1942");
                            Play.setFramerateLimit(60);
                            window.close();


                            // GAME LOOP

                            while (Play.isOpen()) {

                                // EVENTS

                                sf::Event playEvent;

                                while (Play.pollEvent(playEvent)) {

                                    if (playEvent.type == sf::Event::Closed ||
                                        (playEvent.type == sf::Event::KeyPressed && playEvent.key.code == sf::Keyboard::Escape)) {
                                        Play.close();
                                    }
                                }

                                // CMD
                                 gamePlay.cmd();


                                // UPDATE
                                gamePlay.update();
                                scene.update();
                                if (gamePlay.isCollisionWithEnemy()) {
                                    player.changePuntos(1);
                                }

                                if (gamePlay.isCollisionWithPersonaje()) {
                                    player.changeVidas(10);
                                }

                                puntos.setString("PUNTOS " + std::to_string(player.getPuntos()));
                                vidas.setString("VIDA " + std::to_string(player.getVida()));


                                // DRAW
                                Play.clear();
                                Play.draw(scene);
                                Play.draw(gamePlay);
                                //Play.draw(puntos);
                                //Play.draw(vidas);

                                // FLIP
                                Play.display();

                                // LIBERACION DEL JUEGO


                            }

                        } else if (x == 1) {

                            sf::RenderWindow CREDITOS(sf::VideoMode(600, 820), "CREDITOS");

                            while (CREDITOS.isOpen()) {

                                sf::Event optionsEvent;

                                while (CREDITOS.pollEvent(optionsEvent)) {

                                    if (optionsEvent.type == sf::Event::Closed ||
                                        (optionsEvent.type == sf::Event::KeyPressed && optionsEvent.key.code == sf::Keyboard::Escape)) {
                                        CREDITOS.close();
                                    }
                                }

                                CREDITOS.clear();
                                CREDITOS.display();
                            }

                        } else if (x == 2) {
                            window.close();

                        }
                    }
                }
            }
        }

        mainMenu.update();
        window.clear();
        mainMenu.draw(window);
        window.display();




    }

    return 0;
}



