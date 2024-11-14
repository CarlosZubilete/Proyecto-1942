#include "Menu.h"
#include <iostream>



Menu::Menu(float width, float height) {

  if (!font.loadFromFile("assets/fonts/fuente.ttf")) {

    std::cout << "No se pudo cargar la fuente" <<std::endl;
  }

  if (!logoTexture.loadFromFile("assets/sprites/logo.png")) {

    std::cout << "No se pudo cargar el Logo del Juego" <<std::endl;
  }

  if (!planeTexture.loadFromFile("assets/sprites/Personaje.png")) {

    std::cout << "No se pudo cargar la imagen del avion" << std::endl;
  }

  if (!capcomTexture.loadFromFile("assets/sprites/Capcom.jfif")) {

    std::cout << "No se pudo cargar la imagen del Logo Capcom" << std::endl;
  }



  //CONFIGURACION DEL AVION
  //-------------------------------------------------------------------------

  planeSprite.setTexture(planeTexture);
  planeSprite.setScale(0.70f,0.70f);  // CAMBIAR TAMA�O DEL AVION
  planeSprite.setPosition(40, 350);  // POSICION INICIAL DEL AVION


  //-------------------------------------------------------------------------


  //CONFIGURACION LOGO 1942
  //----------------------------------------------------

  logoSprite.setTexture(logoTexture);
  logoSprite.setPosition(95, 195); // POSICION DONDE VA EL LOGO

  // CAMBIAR TAMA�O DEL LOGO
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
  menu[0].setCharacterSize(27);  // TAMA�O DE LA LETRA
  menu[0].setPosition(235, 350);  // POSICION DEL TEXTO


  //----------------------------------------------------
  //CONFIG
  menu[1].setFont(font);
  menu[1].setFillColor(sf::Color::White);
  menu[1].setString("Configuracion");
  menu[1].setCharacterSize(27);
  menu[1].setPosition(130, 400);

  //----------------------------------------------------


  //----------------------------------------------------
  //RANKING
  menu[2].setFont(font);
  menu[2].setFillColor(sf::Color::White);
  menu[2].setString("Ranking");
  menu[2].setCharacterSize(27);
  menu[2].setPosition(200, 450);

  //----------------------------------------------------
  //CREDITOS
  menu[3].setFont(font);
  menu[3].setFillColor(sf::Color::White);
  menu[3].setString("Creditos");
  menu[3].setCharacterSize(27);
  menu[3].setPosition(190, 500);

  //----------------------------------------------------
  //SAlIR
  menu[4].setFont(font);
  menu[4].setFillColor(sf::Color::White);
  menu[4].setString("Salir");
  menu[4].setCharacterSize(27);
  menu[4].setPosition(230, 550);




  selectedItemIndex = 0;

  //Reinicia el reloj blinkClock al valor de 0. Este reloj se usa para contar el tiempo transcurrido, y su reinicio permite empezar a medir desde el inicio
  blinkClock.restart();

  //Inicializa la variable blinkState en true, indicando que el texto "Insert Coin" estar� visible al inicio.
  blinkState = true;

}

// METODO QUE DIBUJA TODOS LOS ELEMENTOS DEL VISUALES DEL MENU
//-------------------------------------------------------------

void Menu::draw(sf::RenderTarget &target , sf::RenderStates states)const{

  target.draw(logoSprite,states); //DIBUJA EL LOGO 1942

  target.draw(capcom,states); //DIBUJA EL TEXTO @1984 CAPCOM

  target.draw(capcomSprite,states); //DIBUJA EL LOGO DE CAPCOM

  //blinkState controla el parpadeo del texto "Insert Coin". Si est� en true, dibuja insertCoin en la ventana, haciendo que el texto "Insert Coin" parpadee.
  if (showInsertCoin) {
    if (blinkState) {
      target.draw(insertCoin,states);
    }
  }
  //Verifica si showMenuOptions est� en true
  if (showMenuOptions) {
    for (int i = 0; i < 5; i++) {
      target.draw(menu[i],states);      //Si es as�, recorre el arreglo menu y dibuja cada elemento de las opciones del men�
    }
    target.draw(planeSprite,states); // dibuja el sprite planeSprite, que representa la imagen del avi�n
  }
}


//METODO QUE ACTUALIZA
//-------------------------------------------------------------------
void Menu::update() {

  if (blinkClock.getElapsedTime().asSeconds() > 0.5f) {   //registra el tiempo transcurrido desde la �ltima vez que se reinici� con blinkClock.restart()

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

  //Primero, verifica si showMenuOptions es true, es decir, si las opciones del men� est�n visibles.
  if (showMenuOptions) {

    //RESTABLECE EL COLOR DE LA OPCION ACTUAL ANTES DE CAMBIAR LA SELECCION
    menu[selectedItemIndex].setFillColor(sf::Color::White);

    //VERIFICA SI ESTA EN EL PRIMER ELEMENTO, SI ES ASI, VA AL ULTIMO
    if (selectedItemIndex - 1 < 0) {
      selectedItemIndex = 4; // CAMBIA EL INDICE AL ULTIMO ELEMENTO
    } else {
      selectedItemIndex--; //MUEVE LA SELECCION HACIA ARRIBA

    }
    //CAMBIA EL COLOR DE LA NUEVA SELECCION
    menu[selectedItemIndex].setFillColor(sf::Color::Green);

    //MUEVE EL AVION A LA NUEVA OPCION SELECCIONADA
    planeSprite.setPosition(40, menu[selectedItemIndex].getPosition().y);
  }
}
//------------------------------------------------------------------------------------------------


//METODO PARA MOVER PARA ABAJO EN EL MENU Y ACTUALIZAR EL COLOR Y EL AVION QUE INDICAN LA SELECCION
//--------------------------------------------------------------------------------------------------
void Menu::moveDown() {

  //Primero, verifica si showMenuOptions es true, es decir, si las opciones del men� est�n visibles.
  if (showMenuOptions) {

    //RESTABLECE EL COLOR DE LA OPCION ACTUAL ANTES DE CAMBIAR LA SELECCION
    menu[selectedItemIndex].setFillColor(sf::Color::White);

    //VERIFICA SI ESTA EN EL ULTIMO ELEMENTO, SI ES ASI, VA AL PRIMERO
    if (selectedItemIndex + 1 >= 5) {
      selectedItemIndex = 0;  // CAMBIA EL INDICE AL PRIMER ELEMENTO
    } else {
      selectedItemIndex++; //MUEVE LA SELECCION HACIA ABAJO

    }
    //CAMBIA EL COLOR DE LA NUEVA SELECCION
    menu[selectedItemIndex].setFillColor(sf::Color::Green);

    //MUEVE EL AVION A LA NUEVA OPCION SELECCIONADA
    planeSprite.setPosition(40, menu[selectedItemIndex].getPosition().y);
  }
}
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
void Menu::handleEnterPress() {
  if (showInsertCoin) {
    showInsertCoin = false;
    showMenuOptions = true;
  } else if (showMenuOptions) {
    // Maneja la selecci�n del men�
    int x = getPressedItem();
    if (x == 0) {

    } else if (x == 1) {

    } else if (x == 2) {

    }
    else if(x == 3){

    }
    else if(x==4){


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