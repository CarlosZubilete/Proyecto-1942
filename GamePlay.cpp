#include "GamePlay.h"
#include <iostream>

GamePlay::GamePlay()
{
    _timerReload = 0;
    std::string namePng = "assets/sprites/1942-sprites-enemy.png";
    _enemy = Enemy(namePng,sf::IntRect(59,56,16,16),3.0f,3.0f);
    _frameExplosion  = 0.f;
    _isExplosionActive = false;
}

void GamePlay::update()
{

    _player.cmd();
    _enemy.cmd();
    _player.update();

    if(_player.Shoot())
    {
        _bulletActive = true;

        if (_bullets.size() < 5  &&  _timerReload <= 0)
        {
            /// INSTANCIAMOS UNA BALA DEL PERSONAJE.
            _bullets.push_back(new Bullet(_player.getPosition().x-_player.getBounds().width-48/2+1,_player.getPosition().y-_player.getBounds().height-48,-7));
            std::cout << _player.getPosition().x << std::endl;
            /// CADA 10MS PODEMOS DISPARAR.
            _timerReload = 15*1;
        }

        _bulletEnemy.push_back(new Bullet(_enemy.getPosition().x  ,_enemy.getPosition().y + 35 , 7));
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

    for(int i=0; i<_bulletEnemy.size(); i++)
    {
        _bulletEnemy[i]->Update();
    }


    for(int i=0; i<_bullets.size(); i++)
    {
        if(_bullets[i]->getBounds().top + _bullets[i]->getBounds().height < 0)
        {
            std::cout<<_bullets.size()<<std::endl;
            delete _bullets[i];
            _bullets.erase(_bullets.begin()+i, _bullets.begin()+i+1);
        }
    }

    for(int i=0; i<_bulletEnemy.size(); i++)
    {
        if (_bulletEnemy[i]->getBounds().top +_bulletEnemy[i]->getBounds().height > 800)
        {
            std::cout<<"DELETE BALAS ENEMIGA " << std::endl;
            delete _bulletEnemy[i];
            _bulletEnemy.erase(_bulletEnemy.begin()+i, _bulletEnemy.begin()+i+1);
        }
    }

    if(_isExplosionActive)
    {
        _explosion.smallExplosion();
        _frameExplosion += 0.2f;

        if (_frameExplosion >= 5.f)
        {
            _isExplosionActive = false;
            _frameExplosion = 0.0f;
        }
        std::cout << "frame: " << _frameExplosion  << std::endl;
        std::cout << "_isExplosionActive...." << _isExplosionActive <<std::endl;
    }

}

bool GamePlay::isCollisionWithPersonaje()
{
    bool result = false;

    for(int i=0; i<_bulletEnemy.size(); i++)
    {
        if (_bulletEnemy[i]->isCollision(_player))
        {
            std::cout<<"COLLISION CON PLAYER" << std::endl;
            delete _bulletEnemy[i];
            _bulletEnemy.erase(_bulletEnemy.begin()+i);
            result = true;
        }
    }

    return result;
}


bool GamePlay::isCollisionWithEnemy()
{
    bool result = false;
    for ( int i = 0 ; i < _bullets.size() ; i++ )
    {
        if(_bullets[i]->isCollision(_enemy))
        {
            std::cout<< "COLLISION CON ENEMIGO" << std::endl;
            delete _bullets[i];
            _bullets.erase(_bullets.begin()+i);

            _explosion =  Explosion(_enemy.getPosition().x,_enemy.getPosition().y);
            _isExplosionActive = true;  // Activa la animaci�n
            _frameExplosion = 0.0f;     // Reinicia el frame

            std::cout << "_isExplosionActive...." << _isExplosionActive <<std::endl;
            _enemy.respawn();
            result = true;
        }
    }

    return result;
}

void GamePlay::draw(sf::RenderTarget &target, sf::RenderStates states)const
{

    for(int i=0; i<_bullets.size(); i++)
    {
        target.draw(*_bullets[i],states);
    }

    for(int i=0; i<_bulletEnemy.size(); i++)
    {
        target.draw(*_bulletEnemy[i],states);
    }


    target.draw(_explosion,states);
    target.draw(_player,states);
    target.draw(_enemy,states);

}

