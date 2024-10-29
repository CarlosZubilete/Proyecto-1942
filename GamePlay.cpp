#include "GamePlay.h"
#include <iostream>

GamePlay::GamePlay()
{
    _player = new Player();
    _bulletActive = false;

//    _enemy.setPosition(sf::Vector2f(300,100));
    /// 1 SOLA BALA.
    //Bullet balaDefault(0,0,0);
    //_bullet = Bullet(0,0,0);
//    _bullet = nullptr;
}

void GamePlay::update()
{
    _player->update();

    if(_player->Shoot())
    {
    //    if (!_bulletActive)
    //    {
            _bulletActive = true;
            _bullets.push_back(new Bullet(_player->getPosicion().x-80,_player->getPosicion().y - 110,-7));
    //    }
    }

    /// DEPENDIENDO DE CUANTO DISPARE, VAMOS A MOVER
    if(_bulletActive)
    {
        for(int i=0; i<_bullets.size(); i++)
        _bullets[i]->Update();
    }
    /// DEPENDIENDO DE CUANTO DISPARE, VAMOS A ELIMINAR
    for(int i=0; i<_bullets.size(); i++)
    {
        if(_bullets[i]->getBounds().top+_bullets[i]->getBounds().height < 0){
            std::cout<<_bullets.size()<<std::endl;
            delete _bullets[i];
            _bullets.erase(_bullets.begin()+i, _bullets.begin()+i+1);
        }
    }
}

void GamePlay::draw(sf::RenderTarget &target, sf::RenderStates states)const
{
    target.draw(*_player,states);

    if(_bulletActive)
    {
        for(int i=0; i<_bullets.size(); i++)
        target.draw(*_bullets[i],states);
    }

    //_bulletActive =false;

}

