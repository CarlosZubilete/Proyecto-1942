#include "GamePlay.h"
#include <iostream>

GamePlay::GamePlay()
{
    _timerReload = 0;
    _player =  Player();

    std::string namePng = "assets/sprites/1942-sprites-enemy.png";
    _enemy = Enemy(namePng,sf::IntRect(223,229,27,25),3.0f,3.0f);
}

void GamePlay::update()
{
    _enemy.cmd();
    _player.update();

    if(_player.Shoot())
    {
            _bulletActive = true;
            //_bullets.push_back(new Bullet(_player->getPosicion().x-80,_player->getPosicion().y - 110,-7));
            if (_bullets.size() < 3 &&  _timerReload <= 0)
            {
                _bullets.push_back(new Bullet(_player.getPosicion().x-80,_player.getPosicion().y - 110,-7));
                _timerReload = 30*1;
            }

        _bulletEnemy.push_back(new Bullet(_enemy.getPosition().x + 35 ,_enemy.getPosition().y + 70 , 7));
        std::cout << "BALA ENEMIGA ->" << std::endl;
    }


    _enemy.update();

    _timerReload--;


    /// DEPENDIENDO DE CUANTO DISPARE, VAMOS A MOVER
    for(int i=0; i<_bullets.size(); i++)
    {
        _bullets[i]->Update();
    }
    /// DEPENDIENDO DE CUANTO DISPARE, VAMOS A ELIMINAR
    for(int i=0; i<_bullets.size(); i++)
    {
        if(_bullets[i]->isCollision(_enemy))
        {
            std::cout<<"Colision"<<std::endl;
            delete _bullets[i];
            _bullets.erase(_bullets.begin()+i, _bullets.begin()+i+1);
            _enemy.respawn();
        }
        else
        {
            /// ELIMINAMOS DESDE LA PANTALLA  DESDE LA PANTALLA
            if(_bullets[i]->getBounds().top + _bullets[i]->getBounds().height < 0){
                std::cout<<_bullets.size()<<std::endl;

                delete _bullets[i];
                _bullets.erase(_bullets.begin()+i, _bullets.begin()+i+1);
            }
        }

    }


    for(int i=0; i<_bulletEnemy.size(); i++)
    {
        _bulletEnemy[i]->Update();
    }

    for(int i=0; i<_bulletEnemy.size(); i++)
    {
        if (_bulletEnemy[i]->isCollision(_player))
        {
            std::cout<<"COLLISION CON PLAYER" << std::endl;
            delete _bulletEnemy[i];
            _bulletEnemy.erase(_bulletEnemy.begin()+i, _bulletEnemy.begin()+i+1);
            /// TODO: bajamos vida , restamos puntos ...
        }
        else
        {
            if (_bulletEnemy[i]->getBounds().top +_bulletEnemy[i]->getBounds().height > 800)
            {
                std::cout<<"DELETE BALAS ENEMIGA " << std::endl;
                delete _bulletEnemy[i];
                _bulletEnemy.erase(_bulletEnemy.begin()+i, _bulletEnemy.begin()+i+1);
            }
        }
    }


}

void GamePlay::draw(sf::RenderTarget &target, sf::RenderStates states)const
{

    target.draw(_player,states);
    target.draw(_enemy,states);

    for(int i=0; i<_bullets.size(); i++)
    {
        target.draw(*_bullets[i],states);
    }

    for(int i=0; i<_bulletEnemy.size(); i++)
    {
        target.draw(*_bulletEnemy[i],states);

    }

}

