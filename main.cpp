#include <SFML/Graphics.hpp>
#include <vector>
#include "GamePlay.h"
#include "Scene.h"
#include "Player.h"
#include "Bullet.h"
#include <list>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 800), "1942",sf::Style::Close);
    window.setFramerateLimit(60);


    // let's define a view
    //sf::View view(sf::FloatRect(0.f, 4194.f, 600.f, 800.f));
    sf::View view(sf::FloatRect(0.f, 0.f, 600.f, 800.f));

    //
    // activate it
    window.setView(view);

    //sf::Vector2u getTamnio = view.getSize();

    GamePlay gamePlay;
    /// Gameplay deberia tener a window las ecenas;
    Scene scene;

    while (window.isOpen()) {
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

        //view.getCenter(scene.getCameraPosition());
        scene.update();

        window.clear();


        window.draw(scene);
        window.draw(gamePlay);
        window.display();
    }

    return 0;
}
