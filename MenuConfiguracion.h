#pragma once
#include <SFML/Graphics.hpp>
#include "ConfiguracionArchivo.h"
#include "Configuracion.h"

class MenuConfiguracion: public sf::Drawable
{
public:
    //CONSTRUCTOR DE LA CLASE MENU
    MenuConfiguracion();

    //DIBUJA EN LA VENTANA DE LA APLICACION LOS ELEMENTOS DEL MENU
    void draw(sf::RenderTarget &target , sf::RenderStates states) const override;

    //CAMBIA LA SELECCION DEL MENU HACIA ARRIBA
    void moveUp();

    //CAMBIA LA SELECCION ACTUAL EN EL MENU HACIA ABAJO
    void moveDown();

    //PROCESA LA ACCION DE PRESIONAR enter EN El MENU
    void handleEnterPress();

    //RETORNA EL INDICE DE LA OPCION SELECCIONADA ACTUALMENTE EN EL MENU
    int getPressedItem();

    //ACTUALIZA EL ESTADO DE CIERTOS ELEMENTOS
    void update();


    bool getShowInsertCoin();
    bool getShowMenuOptions();




private:

    int selectedItemIndex;

    //FUENTE
    sf::Font font;

    //CANTIDAD DE OPCIONES DEL MENU
    sf::Text menu[3];

    //TEXTO INSERT COIN
    sf::Text insertCoin;

    //LOGO 1942
    sf::Texture logoTexture;
    sf::Sprite logoSprite;

    //@1984 CAPCOM
    sf::Text capcom;

    //LOGO CAPCOM
    sf::Texture capcomTexture;
    sf::Sprite capcomSprite;

    //AVION DEL MENU
    sf::Texture planeTexture;
    sf::Sprite planeSprite;

    //RELOJ QUE CONTROLA EL TIEMPO DE PARPADEO DEL TEXTO INSERT COIN
    sf::Clock blinkClock;

    //DETERMINA SI EL TEXTO INSERT COIN ESTA VISIBLE O INVISIBLE
    bool blinkState;

    bool showInsertCoin;
    bool showMenuOptions;


};