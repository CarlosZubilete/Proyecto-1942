#include "GamePlay.h"
#include <iostream>


GamePlay::GamePlay() {
    _timerReload = 0;
    _frameExplosion  = 0.f;
    _isExplosionActive = false;
    _frames = 0;


}

void GamePlay::inicioEnemyB()
{
    ////////////////////////////////////////////////////////////////////////
    /// CREAMOS EL VECTOR DE ENEMIGOS: CON UN CONTADOR ...
    if (_frames%120 == 0)
    {
        if ( _vEnemiesB.size() < 2)
        {
            _vEnemiesB.push_back(new EnemyB());
            std::cout << " TAMANIO DE VECTOR -> ENEMY B" << _vEnemiesB.size() << std::endl;
        }
    }
}

void GamePlay::cmd() {
    _player.cmd();
    enemigo1.cmd();

    for ( int i = 0 ; i < _vEnemiesB.size() ;  i++)
    {
        _vEnemiesB[i]->cmd();
    }

}

void GamePlay::update()
{
    inicioEnemyB();

    if(_player.Shoot())
    {
        if (_bullets.size() < 5  &&  _timerReload <= 0)
        {
            /// INSTANCIAMOS UNA BALA DEL PERSONAJE.
          _bullets.push_back(new Bullet( {_player.getBulletOrigin().x , _player.getBulletOrigin().y }));

            /// CADA 10MS PODEMOS DISPARAR.
            _timerReload = 15*1;
        }
    }

    /// CREAMOS LAS BALAS DE VECTOR DEL ENEMIGO
    for ( int i = 0; i < _vEnemiesB.size() ; i++)
    {
        if(_vEnemiesB[i]->shot())
        {
            _bullets_vEnemyB.push_back(new Bullet(_vEnemiesB[i]->getPosition().x -50,_vEnemiesB[i]->getPosition().y - 30,7));
        }
    }

    /// ACTUALIZAMOS LOS COMANDOS
    for ( int i = 0 ; i < _vEnemiesB.size() ;  i++)
    {
        _vEnemiesB[i]->update();
    }

    /// DIBUJAMOS LAS BALAS DEL ENEMIGO
    for ( int i = 0 ; i < _bullets_vEnemyB.size() ; i++)
    {
        _bullets_vEnemyB[i]->update();
    }

    /// ELIMINAMOS DE LA PANTALLA
    for ( int i = 0 ;  i < _bullets_vEnemyB.size() ; i++ )
    {
        if(_bullets_vEnemyB[i]->getBounds().top + _bullets_vEnemyB[i]->getBounds().height > 800)
        {
            std::cout<<"TAMANIO DE BALAS V-ENEMIGOS" <<_bullets_vEnemyB.size()<<std::endl;
            delete _bullets_vEnemyB[i];
            _bullets_vEnemyB.erase(_bullets_vEnemyB.begin()+i);
        }
    }


    if (_frames%60 == 0.f)
    {
        sf::Vector2f direccion;
        float direccion_relacion;
        direccion.x = _player.getPosition().x - enemigo1.getPosition().x;
        direccion.y = _player.getPosition().y - enemigo1.getPosition().y;
        direccion_relacion = direccion.x / direccion.y;
        (direccion.x < 0 ) ?  direccion.x = -3.7f : direccion.x= 3.7f;
        (direccion.y < 0 ) ?  direccion.y = - 3.7f * std::abs(direccion_relacion) : direccion.y =  3.7f * std::abs(direccion_relacion);

        _enemyBullets.push_back(new EnemyBullet( enemigo1.getBulletOrigin().x, enemigo1.getBulletOrigin().y, direccion.x, direccion.y));

    }



    /// DEPENDIENDO DE CUANTO DISPARE, VAMOS A MOVER
    for(int i=0; i<_bullets.size(); i++)// de esta manera suben las balas disparadas
    {
        _bullets[i]->update();
    }
    /// DEPENDIENDO DE CUANTO DISPARE, VAMOS A ELIMINAR

    for(int i=0; i < _enemyBullets.size(); i++) // de esta manera bajan las balas enemigas
    {
      _enemyBullets[i]->update();
    }


    for(int i=0; i < _bullets.size(); i++)
    {
        if(_bullets[i]->getBounds().top + _bullets[i]->getBounds().height < 0)
        {
            delete _bullets[i];
            _bullets.erase(_bullets.begin()+i, _bullets.begin()+i+1);
        }
    }

    for(int i=0; i < _enemyBullets.size(); i++)
    {
        if (_enemyBullets[i]->getBounds().top +_enemyBullets[i]->getBounds().height > 800)
        {
            delete _enemyBullets[i];
          _enemyBullets.erase(_enemyBullets.begin()+i);
        }
    }


    if(_isExplosionActive)
    {
        _explosion.smallExplosion();
        _frameExplosion += 0.2f;

            if (_frameExplosion >= 6.f)
            {
                _isExplosionActive = false;
                _frameExplosion = 0.0f;
            }
    }


  if (isCollisionWithPersonaje() ||
      (isCollision_vBullestEnemyB_whitPersonaje())) {
    _juego.changeVidas();
    _player.respawn();
  }

  if (isCollisionWithEnemy() ||
    (isCollision_bullets_whitEnemyB())){
    _juego.changePuntos(100);
  }


  _player.update();
  enemigo1.update();



//  for(Enemy *enemy: _enemies)
//  {
//    enemy->update();
//  }
  _timerReload--;

  if(checkCollision(enemigo1)){
    _juego.changeVidas();
    _player.respawn();
    enemigo1.respawn();
  }

  _frames++;
}



bool GamePlay::checkCollision(const Enemy& col) const
{
    return _player.getBounds().intersects(col.getBounds());
}


/// SI LA BALA DEL VECTOR ENEMIGOS B COLISIONA CON EL PERSONAJE.
bool GamePlay::isCollision_vBullestEnemyB_whitPersonaje()
{
    bool result = false;

    for ( int i = 0 ; i < _bullets_vEnemyB.size() ; i++)
    {
        if (_bullets_vEnemyB[i]->isCollision(_player))
        {
            std::cout << "COLIION , VECTOR BALAS B CON PERSONAJE " << std::endl;
            delete _bullets_vEnemyB[i];
            _bullets_vEnemyB.erase(_bullets_vEnemyB.begin()+i);
            result = true;
        }
    }

    return result;
}


bool GamePlay::isCollisionWithPersonaje() // cuando te disparan
{
    bool result = false;
    for(int i=0; i<_enemyBullets.size(); i++)
    {
        if (_enemyBullets[i]->isCollision(_player))
        {
          delete _enemyBullets[i];
          _enemyBullets.erase(_enemyBullets.begin()+i);
            result = true;
        }
    }
    return result;
}

bool GamePlay::isCollisionWithEnemy() // cuando destruis aviones enemigos
{
    bool result = false;
    for ( int i = 0 ; i < _bullets.size() ; i++ )
    {
        if(_bullets[i]->isCollision(enemigo1))
        {
            _juego.changePuntos(100);
            delete _bullets[i];
            _bullets.erase(_bullets.begin()+i);

            _explosion =  Explosion(enemigo1.getPosition().x,enemigo1.getPosition().y);
            _isExplosionActive = true;  // Activa la animaci�n
            _frameExplosion = 0.0f;     // Reinicia el frame

            enemigo1.respawn();
            result = true;
        }
    }
    return result;
}

bool GamePlay::isCollision_bullets_whitEnemyB()
{

    /// RECORRO LAS BALAS QUE DISPARO EL PERSONAJE
    for ( int i = 0 ; i < _bullets.size() ; i++ )
    {
        /// RECORREMOS TODOS LOS ENEMIGOS B EN PANTALLA
        for ( int j = 0 ; j < _vEnemiesB.size() ; j++ )
        {
            if (_bullets[i]->isCollision(*_vEnemiesB[j]))
            {
                std::cout << "COLLISION -> BULLEST PERSONAJE CON ENEMIGO B" << std::endl;
                delete _bullets[i];
                _bullets.erase(_bullets.begin()+i);

                _vEnemiesB[j]->respawn();
                return true;

            }
        }
    }

    return false;

}


void GamePlay::draw(sf::RenderTarget &target, sf::RenderStates states)const
{

    for(int i=0; i < _bullets.size(); i++)
    {
        target.draw(*_bullets[i], states);
//        target.draw(*bala_cartel[i], states);
    }

    for(int i=0; i<_enemyBullets.size(); i++)
    {
        target.draw(*_enemyBullets[i], states);
    }


    for ( int i = 0 ; i<_vEnemiesB.size() ; i++)
    {
        target.draw(*_vEnemiesB[i],states);
    }

    for (int i = 0; i < _bullets_vEnemyB.size(); i++)
    {
        target.draw(*_bullets_vEnemyB[i],states);
    }


    target.draw(_player,states);
    target.draw(_explosion,states);
    target.draw(enemigo1,states);
//    target.draw(enemigo1_cartel,states);
//    target.draw(player_cartel,states);

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

int GamePlay::getFrames() const
{
  return _frames;
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



