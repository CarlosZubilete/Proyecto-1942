#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Avion.h"
//#include "Scene.h"
#include "Player.h"
#include "Personaje.h"
#include "Bullet.h"
#include "Enemy.h"

class GamePlay: public sf::Drawable
{
    public:
        GamePlay();
        void update();
        bool isCollisionWithPersonaje();
        bool isCollisionWithEnemy();
        void draw(sf::RenderTarget &target, sf::RenderStates states)const override;

    private:
        Personaje _player;
        std::vector<Bullet*> _bullets;
        std::vector<Bullet*> _bulletEnemy;
        Enemy _enemy;
        //Scene _scene;
        bool _bulletActive;
        int _timerReload;
        sf::Font _font;
        sf::Text _textPuntos;
        Player player;
};

