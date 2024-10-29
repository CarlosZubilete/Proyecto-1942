#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Scene: public sf::Drawable
{
    public:
        Scene();
        void update();
        void draw(sf::RenderTarget &target, sf::RenderStates states)const override;
    private:
        Player *_player;
        std::vector<Bullet*> _bullet;
        Enemy _enemy;
        bool _bulletActive;
};


