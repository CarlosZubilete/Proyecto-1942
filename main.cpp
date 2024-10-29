#include <SFML/Graphics.hpp>
#include <vector>
#include "Scene.h"
#include "Player.h"
#include "Bullet.h"
#include <list>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 800), "1942");
    window.setFramerateLimit(60);

    Scene scene;
    //Player jugador = Player();

    //bool bulletActive = false;
    /// 1 SOLA BALA.
    //Bullet balaDefault(0,0,0);
    //Bullet *balaJugador = nullptr;
    /**
        Bullet *vectorBalas = nullptr;
        vectorBalas = new Bullet[10];
        if (vectorBalas == nullptr){return 0;}
        int i = 0;
    **/

    while (window.isOpen())
    {
        /// PULL EVENT
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        /// IMPUT
        ///
        //jugador.update();
        scene.update();
        /**
        if(jugador.Shoot() && !bulletActive)
        {
            //Bullet balaDefault(jugador.getPosicion().x-80,jugador.getPosicion().y - 110,-8);
            balaDefault = Bullet(jugador.getPosicion().x-80,jugador.getPosicion().y - 110,-8);
            bulletActive = true;
            /**
            balaJugador = new Bullet(jugador.getPosicion().x-80,jugador.getPosicion().y - 110,-8);
            if (balaJugador == nullptr) {window.close();}
            if (i < 10)
            {
                vectorBalas[i] = Bullet(jugador.getPosicion().x-80,jugador.getPosicion().y - 110,-8);
            }

        }
        **/


        /**
        if(bulletActive)
        {
            balaDefault.Update();
            //vectorBalas[i].Update();
            //balaJugador->Update();
        }
        **/
        scene.update();
    /// ANTES DE ELEMINAR LA DIRECCION , DEVUEVLO LA MEMORIA.
        window.clear();
        /**
        window.draw(jugador);

        if(bulletActive)
        {
            window.draw(balaDefault);
            //window.draw(vectorBalas[i]);
            /**
            window.draw(*balaJugador);
            bulletActive = false;
            delete balaJugador;
        }
        **/
        // libero la memoria
        /**
        if ( i == 10 )
        {
            for ( int j = 0 ; j < 10  ; j++ )
            {
            }
        }
        **/
        //delete []vectorBalas;
        //i++;
        window.draw(scene);
        window.display();
    }

    return 0;
}
