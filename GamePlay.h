#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Avion.h"
#include "Player.h"
#include "Personaje.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Explosion.h"
#include "CartelPosicion.h"
#include "EnemyB.h"

class GamePlay: public sf::Drawable
{
    public:
        GamePlay();
        void cmd();
        void update();
        bool isCollisionWithPersonaje();
        bool isCollisionWithEnemy();
        void draw(sf::RenderTarget &target, sf::RenderStates states)const override;
        int getPuntos() const;
        int getVidas() const;
        bool checkCollision(const Enemy& enemigo1) const;
        int getFrames() const;
        bool isCollision_vBullestEnemyB_whitPersonaje();
        bool isCollision_bullets_whitEnemyB();

private:
        void inicioEnemyB();

        CartelPosicion enemigo1_cartel;
        CartelPosicion player_cartel;
        std::vector<CartelPosicion*> bala_cartel;
        Personaje _player;
        std::vector<Bullet*> _bullets;
        std::vector<EnemyBullet*> _enemyBullets;
        Enemy enemigo1;
        std::vector<Enemy*> _enemies;
        int _timerReload;
        Player _juego;
        Explosion _explosion;
        float _frameExplosion;
        bool _isExplosionActive;
        int _frames;
        std::vector <EnemyB*> _vEnemiesB;
        std::vector<Bullet*> _bullets_vEnemyB;
};

