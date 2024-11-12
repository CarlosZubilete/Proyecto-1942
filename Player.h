#pragma once


class Player
{
  public:
    Player();
    //int getIDPlayer();
    int getPuntos()const;
    void setPuntos(int puntos);
    void changePuntos(int puntos);
    void changeVidas();
    void addVidas();
    int getVida()const;
    void setVida(int vida);

  private:
    int _puntos; /// *READ DOWN*
    int _vida;///
    //int _id;
};


/**
    TODO: completar
    _puntos :
        -> Cada vez que mata un enemigo suma puntos
        -> mostrar en pantalla cuantos puntos acumula


    _vidas:
        -> Por cada bala recibida, desminuiremos vidas.
        -> Si hagarramos los powerUp...
*/
