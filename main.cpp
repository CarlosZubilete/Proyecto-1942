#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 800), "1942");
    window.setFramerateLimit(60);

    Player jugador;

    Bullet balaDefault(-50,-50,0);
    Bullet balaJugador(0,0,0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        jugador.Update();

        if(jugador.Shoot())
        {
            //balaDefault = Bullet(jugador.getPosicion().x-80,jugador.getPosicion().y - 100,-8);
            //balaDefault = balaJugador;
            balaJugador = Bullet(jugador.getPosicion().x-80,jugador.getPosicion().y - 100,-8);
        }

        balaJugador.Update();
        //balaDefault.Update();

        window.clear();

        window.draw(balaJugador);
        //window.draw(balaDefault);

        window.draw(jugador);

        window.display();
    }

    return 0;
}
