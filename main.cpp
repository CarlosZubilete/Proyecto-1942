#include <SFML/Graphics.hpp>
#include "GamePlay.h"
#include "Scene.h"
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 800), "1942",sf::Style::Close);
    window.setFramerateLimit(60);

    sf::View view(sf::FloatRect(0.f, 0.f, 600.f, 800.f));
    window.setView(view);


    Scene scene;
    GamePlay gamePlay;
    /// Gameplay deberia tener a window las ecenas;
    Player player;

    sf::Font font;
    font.loadFromFile("assets/fonts/MONOCOQUE_FUENTE.ttf");

    sf::Text puntos;
    puntos.setFont(font);
    puntos.setPosition(3,0);

    sf::Text vidas;
    vidas.setFont(font);
    vidas.setPosition(3,30);

    while (window.isOpen()){
        /// PULL EVENT
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();


            // Cierra la ventana con ESCAPE
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }
        //end events

        /// IMPUT
        gamePlay.update();
        scene.update();

        if (gamePlay.isCollisionWithEnemy())
        {
            player.changePuntos(1);
        }

        if (gamePlay.isCollisionWithPersonaje())
        {
            player.changeVidas(10);
        }

        puntos.setString("PUNTOS " + std::to_string(player.getPuntos()));
        vidas.setString("VIDA " + std::to_string(player.getVida()));

        window.clear();
        window.draw(scene);
        window.draw(gamePlay);
        window.draw(puntos);
        window.draw(vidas);
        window.display();
    }

    return 0;
}
