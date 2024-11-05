#include "GamePlay.h"
#include <iostream>


GamePlay::GamePlay()
{
    _timerReload = 0;
    _frameExplosion  = 0.f;
    _isExplosionActive = false;


}

void GamePlay::cmd()
{
    _player.cmd();
    enemigo1.cmd();
//    for(Enemy *enemy: _enemies)
//    {
//      enemy->cmd();
//    }
}

void GamePlay::update()
{
    if(_player.Shoot())
    {
        _bulletActive = true;
        if (_bullets.size() < 5  &&  _timerReload <= 0)
        {
            /// INSTANCIAMOS UNA BALA DEL PERSONAJE.
//            _bullets.push_back(new Bullet(_player.getPosition().x-_player.getBounds().width-48/2+1,_player.getPosition().y-_player.getBounds().height-48,-7));
          _bullets.push_back(new Bullet( {_player.getBulletOrigin().x , _player.getBulletOrigin().y }));
//

            /// CADA 10MS PODEMOS DISPARAR.
            _timerReload = 15*1;
        }

//      _enemyBullets.push_back(new EnemyBullet(_enemy.getPosition().x  ,_enemy.getPosition().y + 35 , 7));
//        std::cout << "BALA ENEMIGA ->" << std::endl;
    }




    /// DEPENDIENDO DE CUANTO DISPARE, VAMOS A MOVER
    for(int i=0; i<_bullets.size(); i++)// de esta manera suben las balas disparadas
    {
        _bullets[i]->update();
    }
    /// DEPENDIENDO DE CUANTO DISPARE, VAMOS A ELIMINAR

//    for(int i=0; i < _enemyBullets.size(); i++) // de esta manera bajan las balas enemigas
//    {
//      _enemyBullets[i]->update();
//    }


    for(int i=0; i < _bullets.size(); i++)
    {
        if(_bullets[i]->getBounds().top + _bullets[i]->getBounds().height < 0)
        {
//            std::cout<<_bullets.size()<<std::endl;
            delete _bullets[i];
            _bullets.erase(_bullets.begin()+i, _bullets.begin()+i+1);
        }
    }

//    for(int i=0; i < _enemyBullets.size(); i++)
//    {
//        if (_enemyBullets[i]->getBounds().top +_enemyBullets[i]->getBounds().height > 800)
//        {
////            std::cout<<"DELETE BALAS ENEMIGA " << std::endl;
//            delete _enemyBullets[i];
//          _enemyBullets.erase(_enemyBullets.begin()+i, _enemyBullets.begin()+i+1);
//        }
//    }

    if(_isExplosionActive)
    {
        _explosion.smallExplosion();
        _frameExplosion += 0.2f;

        if (_frameExplosion >= 5.f)
        {
            _isExplosionActive = false;
            _frameExplosion = 0.0f;
        }
//        std::cout << "frame: " << _frameExplosion  << std::endl;
//        std::cout << "_isExplosionActive...." << _isExplosionActive <<std::endl;
    }



//  if (isCollisionWithPersonaje()) {
//    std::cout << "resta vidas" << std::endl;
//    _juego.changeVidas();
//  }
//
  if (isCollisionWithEnemy()) {
//    _juego.changePuntos(100);
//  _juego.changePuntos(100);

  }

//  for(int i = 0; i<4; i++) {

//    _bullets.push_back(new Bullet( {_player.getBulletOrigin().x , _player.getBulletOrigin().y }));

//  }

  _player.update();
  enemigo1.update();

  enemigo1_cartel.showPositionOnScreen("Enemigo1",{enemigo1.getPosition().x+enemigo1.getBounds().width,enemigo1.getPosition().y-50},{enemigo1.getPosition().x,enemigo1.getPosition().y});
  player_cartel.showPositionOnScreen("Player",{_player.getPosition().x+_player.getBounds().width,_player.getPosition().y-50},{_player.getPosition().x,_player.getPosition().y});


//  for(Enemy *enemy: _enemies)
//  {
//    enemy->update();
//  }
  _timerReload--;
}

bool GamePlay::isCollisionWithPersonaje()
{
//    bool result = false;
//    for(int i=0; i<_enemyBullets.size(); i++)
//    {
//        if (_enemyBullets[i]->isCollision(_player))
//        {
//          std::cout << "COLLISION CON PLAYER: "
//                    << "Bala en (" << _enemyBullets[i]->getBounds().left << ", " << _enemyBullets[i]->getBounds().top << "), "
//                    << "Jugador en (" << _player.getBounds().left << ", " << _player.getBounds().top << ")\n";
//
//          delete _enemyBullets[i];
//          _enemyBullets.erase(_enemyBullets.begin()+i);
//            result = true;
//        }
//    }
//    return result;
  return true;
}

bool GamePlay::isCollisionWithEnemy()
{
    bool result = false;
    for ( int i = 0 ; i < _bullets.size() ; i++ )
    {
        if(_bullets[i]->isCollision(enemigo1))
        {

//            std::cout<< "COLLISION CON ENEMIGO" << std::endl;
            delete _bullets[i];
            _bullets.erase(_bullets.begin()+i);

            _explosion =  Explosion(enemigo1.getPosition().x,enemigo1.getPosition().y);
            _isExplosionActive = true;  // Activa la animaci�n
            _frameExplosion = 0.0f;     // Reinicia el frame

//            std::cout << "_isExplosionActive...." << _isExplosionActive <<std::endl;
            enemigo1.respawn();
            result = true;
        }
    }
    return result;
  return true;
}

void GamePlay::draw(sf::RenderTarget &target, sf::RenderStates states)const
{

    for(int i=0; i < _bullets.size(); i++)
    {
        target.draw(*_bullets[i], states);
    }

//    for(int i=0; i<_enemyBullets.size(); i++)
//    {
//        target.draw(*_enemyBullets[i], states);
//    }

    target.draw(_player,states);
    target.draw(_explosion,states);
    target.draw(enemigo1,states);
    target.draw(enemigo1_cartel,states);
    target.draw(player_cartel,states);

//    for(Enemy *enemy: _enemies)
//    {
//      target.draw(_enemy);
//    }

}

int GamePlay::getPuntos() const
{
  return _juego.getPuntos();
}

int GamePlay::getVidas() const
{
  return _juego.getVida();
}


//int GamePlay::getPuntos(Player _juego) const
//{
//  return _juego.getPuntos();
//}
//
//int GamePlay::getVidas(Player _juego) const
//{
//  return _juego.getVida();;
//}



