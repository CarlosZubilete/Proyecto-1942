#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu(float width, float height) {

    if (!font.loadFromFile("assets/fonts/fuente.ttf")) {

        cout << "No se pudo cargar la fuente" <<endl;
    }

    if (!logoTexture.loadFromFile("assets/sprites/logo.png")) {

        cout << "No se pudo cargar el Logo del Juego" <<endl;
    }

    if (!planeTexture.loadFromFile("assets/sprites/Personaje.png")) {

        cout << "No se pudo cargar la imagen del avion" << endl;
    }

    if (!capcomTexture.loadFromFile("assets/sprites/Capcom.jfif")) {

        cout << "No se pudo cargar la imagen del Logo Capcom" << endl;
    }



    //CONFIGURACION DEL AVION
    //-------------------------------------------------------------------------

    planeSprite.setTexture(planeTexture);
    planeSprite.setScale(0.70f,0.70f);  // CAMBIAR TAMAÑO DEL AVION
    planeSprite.setPosition(100, 350);  // POSICION INICIAL DEL AVION


    //-------------------------------------------------------------------------


    //CONFIGURACION LOGO 1942
    //----------------------------------------------------

    logoSprite.setTexture(logoTexture);
    logoSprite.setPosition(95, 195); // POSICION DONDE VA EL LOGO

    // CAMBIAR TAMAÑO DEL LOGO
    logoSprite.setScale(2.0f, 2.0f);

    //---------------------------------------------------


    //COONFIGURACION LOGO DE CAPCOM
    //---------------------------------------------------
    capcomSprite.setTexture(capcomTexture);
    capcomSprite.setPosition(230,650);

    capcomSprite.setScale(0.40f,0.40f);
    //------------------------------------------------------

    // CONFIGURACION DEL @1984 CAPCOM
    //---------------------------------------------------
    capcom.setFont(font);
    capcom.setFillColor(sf::Color::White);
    capcom.setString("@1984 CAPCOM");
    capcom.setCharacterSize(12);
    capcom.setPosition(223, 725);
    //---------------------------------------------------


    // CONFIGURACION DEL INSET COIN
    //---------------------------------------------------
    insertCoin.setFont(font);
    insertCoin.setFillColor(sf::Color::Yellow);
    insertCoin.setString("Insert Coin");
    insertCoin.setCharacterSize(32);
    insertCoin.setPosition(145, 400);
    //---------------------------------------------------


    showInsertCoin = true;
    showMenuOptions = false;


    // CONFIGURACION DE LA OPCIONES DEL MENU
    //----------------------------------------------------
    //JUGAR
    menu[0].setFont(font);  // TIPO DE FUENTE
    menu[0].setFillColor(sf::Color::Green);  // COLOR DE LA LETRA
    menu[0].setString("Jugar");  // TEXTO
    menu[0].setCharacterSize(32);  // TAMAÑO DE LA LETRA
    menu[0].setPosition(225, 350);  // POSICION DEL TEXTO


    //----------------------------------------------------
    //CREDITOS
    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Creditos");
    menu[1].setCharacterSize(32);
    menu[1].setPosition(190, 450);

    //----------------------------------------------------


    //----------------------------------------------------
    //SAlIR
    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Salir");
    menu[2].setCharacterSize(32);
    menu[2].setPosition(225, 550);




    selectedItemIndex = 0;

    //Reinicia el reloj blinkClock al valor de 0. Este reloj se usa para contar el tiempo transcurrido, y su reinicio permite empezar a medir desde el inicio
    blinkClock.restart();

    //Inicializa la variable blinkState en true, indicando que el texto "Insert Coin" estará visible al inicio.
    blinkState = true;






}

// METODO QUE DIBUJA TODOS LOS ELEMENTOS DEL VISUALES DEL MENU
//-------------------------------------------------------------

void Menu::draw(sf::RenderTarget &target , sf::RenderStates states)const{

    target.draw(logoSprite,states); //DIBUJA EL LOGO 1942

    target.draw(capcom,states); //DIBUJA EL TEXTO @1984 CAPCOM

    target.draw(capcomSprite,states); //DIBUJA EL LOGO DE CAPCOM

    //blinkState controla el parpadeo del texto "Insert Coin". Si está en true, dibuja insertCoin en la ventana, haciendo que el texto "Insert Coin" parpadee.
    if (showInsertCoin) {
        if (blinkState) {
            target.draw(insertCoin,states);
        }
    }
    //Verifica si showMenuOptions está en true
    if (showMenuOptions) {
        for (int i = 0; i < 3; i++) {
            target.draw(menu[i],states);      //Si es así, recorre el arreglo menu y dibuja cada elemento de las opciones del menú
        }
        target.draw(planeSprite,states); // dibuja el sprite planeSprite, que representa la imagen del avión
    }
}


//METODO QUE ACTUALIZA
//-------------------------------------------------------------------
void Menu::update() {

    if (blinkClock.getElapsedTime().asSeconds() > 0.5f) {   //registra el tiempo transcurrido desde la última vez que se reinició con blinkClock.restart()

        //Alterna el valor de blinkState entre true y false. Esto permite que el texto parpadee
        blinkState = !blinkState;

        //Reinicia el reloj blinkClock para que comience a contar nuevamente desde cero
        blinkClock.restart();
    }
}
//-------------------------------------------------------------------


//METODO PARA MOVER PARA ARRIBA EN EL MENU Y ACTUALIZAR EL COLOR Y EL AVION QUE INDICAN LA SELECCION
//--------------------------------------------------------------------------------------------------
void Menu::moveUp() {

    //Primero, verifica si showMenuOptions es true, es decir, si las opciones del menú están visibles.
    if (showMenuOptions) {

        //RESTABLECE EL COLOR DE LA OPCION ACTUAL ANTES DE CAMBIAR LA SELECCION
        menu[selectedItemIndex].setFillColor(sf::Color::White);

        //VERIFICA SI ESTA EN EL PRIMER ELEMENTO, SI ES ASI, VA AL ULTIMO
        if (selectedItemIndex - 1 < 0) {
            selectedItemIndex = 2; // CAMBIA EL INDICE AL ULTIMO ELEMENTO
        } else {
            selectedItemIndex--; //MUEVE LA SELECCION HACIA ARRIBA

        }
        //CAMBIA EL COLOR DE LA NUEVA SELECCION
        menu[selectedItemIndex].setFillColor(sf::Color::Green);

        //MUEVE EL AVION A LA NUEVA OPCION SELECCIONADA
        planeSprite.setPosition(100, menu[selectedItemIndex].getPosition().y);
    }
}
//------------------------------------------------------------------------------------------------


//METODO PARA MOVER PARA ABAJO EN EL MENU Y ACTUALIZAR EL COLOR Y EL AVION QUE INDICAN LA SELECCION
//--------------------------------------------------------------------------------------------------
void Menu::moveDown() {

    //Primero, verifica si showMenuOptions es true, es decir, si las opciones del menú están visibles.
    if (showMenuOptions) {

       //RESTABLECE EL COLOR DE LA OPCION ACTUAL ANTES DE CAMBIAR LA SELECCION
        menu[selectedItemIndex].setFillColor(sf::Color::White);

        //VERIFICA SI ESTA EN EL ULTIMO ELEMENTO, SI ES ASI, VA AL PRIMERO
        if (selectedItemIndex + 1 >= 3) {
            selectedItemIndex = 0;  // CAMBIA EL INDICE AL PRIMER ELEMENTO
        } else {
            selectedItemIndex++; //MUEVE LA SELECCION HACIA ABAJO

        }
        //CAMBIA EL COLOR DE LA NUEVA SELECCION
        menu[selectedItemIndex].setFillColor(sf::Color::Green);

        //MUEVE EL AVION A LA NUEVA OPCION SELECCIONADA
        planeSprite.setPosition(100, menu[selectedItemIndex].getPosition().y);
    }
}
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
void Menu::handleEnterPress() {
    if (showInsertCoin) {
        showInsertCoin = false;
        showMenuOptions = true;
    } else if (showMenuOptions) {
        // Maneja la selección del menú
        int x = getPressedItem();
        if (x == 0) {
            // Lógica para iniciar el juego
        } else if (x == 1) {
            // Lógica para mostrar créditos
        } else if (x == 2) {
            // Lógica para salir
        }
    }
}
//--------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------
int Menu::getPressedItem() {
    return selectedItemIndex;
}
//--------------------------------------------------------------------------------------------------


bool Menu::getShowInsertCoin(){

    return showInsertCoin;

}

bool Menu::getShowMenuOptions(){

return showMenuOptions;
}
