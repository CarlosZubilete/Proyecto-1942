#pragma once


class Player
{
  public:
    Player();
    int getPuntos()const;
    void setPuntos(int puntos);
    void changePuntos(int puntos);
    void changeVidas();
    int getVida()const;
    void setVida(int vida);

  private:
    int _puntos; /// *READ DOWN*
    int _vida; ///

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
