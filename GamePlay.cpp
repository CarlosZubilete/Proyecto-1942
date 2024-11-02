#include "GamePlay.h"
#include <iostream>

GamePlay::GamePlay()
{
    _timerReload = 0;
    std::string namePng = "assets/sprites/1942-sprites-enemy.png";
    _enemy = Enemy(namePng,sf::IntRect(223,229,27,25),3.0f,3.0f);

    /**
    _font.loadFromFile("assets/fonts/MONOCOQUE_FUENTE.ttf");
    _textPuntos.setFont(_font);
    _textPuntos.setCharacterSize(24); /// SETEMOS LOS PIXELES DEL TEXTO
    _textPuntos.setPosition({0,0});
    _textPuntos.setFillColor(sf::Color::Black);
    */

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
            _bullets.push_back(new Bullet(_player.getPosition().x-80,_player.getPosition().y - 110,-7));
            /// CADA 10MS PODEMOS DISPARAR.
            _timerReload = 15*1;
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


    //_textPuntos.setString("PUNTOS: " + std::to_string(_player.getPuntos()));

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
            result = true;
            _enemy.respawn();
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

    target.draw(_player,states);
    target.draw(_enemy,states);

}

