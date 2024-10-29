#include "Scene.h"
#include <iostream>

Scene::Scene()
{
    _player = new Player();
    _bulletActive = false;
//    _enemy.setPosition(sf::Vector2f(300,100));
    /// 1 SOLA BALA.
    //Bullet balaDefault(0,0,0);
    //_bullet = Bullet(0,0,0);
//    _bullet = nullptr;
}

void Scene::update()
{
    _player->update();

    if(_player->Shoot())
    {
    //    if (!_bulletActive)
    //    {
            _bulletActive = true;
            _bullet.push_back(new Bullet(_player->getPosicion().x-80,_player->getPosicion().y - 110,-5));
        }
    //}

    if(_bulletActive)
    {
        for(int i=0; i<_bullet.size(); i++)
        _bullet[i]->Update();
    }

    for(int i=0; i<_bullet.size(); i++)
    {
        if(_bullet[i]->getBounds().top+_bullet[i]->getBounds().height < 0){
            std::cout<<_bullet.size()<<std::endl;
            delete _bullet[i];
            _bullet.erase(_bullet.begin()+i, _bullet.begin()+i+1);
        }
    }
}

void Scene::draw(sf::RenderTarget &target, sf::RenderStates states)const
{
    target.draw(*_player,states);

    if(_bulletActive)
    {
        for(int i=0; i<_bullet.size(); i++)
        target.draw(*_bullet[i],states);
        ///_bulletActive=false;
    }

}




