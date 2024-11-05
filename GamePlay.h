#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Avion.h"
#include "Player.h"
#include "Personaje.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Explosion.h"
#include "CartelPosicion.h"

class GamePlay: public sf::Drawable
{
    public:
        GamePlay();
        void cmd();
        void update();
        bool isCollisionWithPersonaje();
        bool isCollisionWithEnemy();
        void draw(sf::RenderTarget &target, sf::RenderStates states)const override;
        CartelPosicion cartel_player;
        CartelPosicion cartel_bullets;
        CartelPosicion cartel_colision;
        int getPuntos() const;
        int getVidas() const;



    private:
        Personaje _player;
        std::vector<Bullet*> _bullets;
        std::vector<Bullet*> _bulletEnemy;
        Enemy _enemy;
        bool _bulletActive;
        int _timerReload;
        Player _juego;
        Explosion _explosion;
        float _frameExplosion;
        bool _isExplosionActive;

};

