#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class GamePlay: public sf::Drawable
{
    public:
        GamePlay();
        void update();
        void draw(sf::RenderTarget &target, sf::RenderStates states)const override;

    private:

        Player _player;
        std::vector<Bullet*> _bullets;
         std::vector<Bullet*> _bulletEnemy;
        Enemy _enemy;
        Scene _scene;
        bool _bulletActive;
        int _timerReload;

};

