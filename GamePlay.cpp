#include "GamePlay.h"
#include <iostream>


GamePlay::GamePlay()
{
  _timerReload = 0;
  _frameExplosion = 0.f;
  _isExplosionActive = false;
  _frames = 0;
  _isExplosionActiveBoss= false;
}

void GamePlay::iniciarBalasVector()
{
  ////////////////////////////////////////////////////////////////////////
  /// CREAMOS EL VECTOR DE ENEMIGOS: CON UN CONTADOR ...
  if (_frames % 120 == 0) {
    if (_vEnemiesB.size() < 2) {
      _vEnemiesB.push_back(new EnemyB());
    }
  }


  if (_player.Shoot()) {
    if (_bullets.size() < 5 && _timerReload <= 0) {
      /// INSTANCIAMOS UNA BALA DEL PERSONAJE.
      _bullets.push_back(new Bullet({_player.getBulletOrigin().x, _player.getBulletOrigin().y,}));
      /// CADA 10MS PODEMOS DISPARAR.
      _timerReload = 15 * 1;
    }
  }

  for (int i = 0; i < _vEnemiesB.size(); i++) {
    if (_vEnemiesB[i]->shot()) {
      _bullets_vEnemyB.push_back(
              new Bullet(_vEnemiesB[i]->getPosition().x - 50, _vEnemiesB[i]->getPosition().y - 30, 7));
    }
  }


  if (_frames % 120 == 0) {
    // Calcula dirección normalizada de EnemyBullet hacia el jugador
    sf::Vector2f direccion = _player.getPosition() - enemigo1.getPosition();
    float magnitud = sqrt(direccion.x * direccion.x + direccion.y * direccion.y);

    if (magnitud != 0) {
      direccion /= magnitud;  // Normaliza el vector
    }

    _enemyBullets.push_back(new EnemyBullet(enemigo1.getBulletOrigin(), direccion, 3.5f));
  } // Dispara EnemyBullet hacia el jugador
}

void GamePlay::cmd()
{

  _player.cmd();
  enemigo1.cmd();
  _boss.cmd();



  for (int i = 0; i < _vEnemiesB.size(); i++) {
    _vEnemiesB[i]->cmd();
  }
}

void GamePlay::update()
{

  iniciarBalasVector();




  /// ACTUALIZAMOS LOS COMANDOS
  for (int i = 0; i < _vEnemiesB.size(); i++) {
    _vEnemiesB[i]->update();
  }

  /// DIBUJAMOS LAS BALAS DEL ENEMIGO
  for (int i = 0; i < _bullets_vEnemyB.size(); i++) {
    _bullets_vEnemyB[i]->update();
  }


  if (_frames % (60*14) == 0.f) {
    _powerUp = new PowerUp();
    _powerUp->respawn();
  }


  /// DIBUJAMOS EL POWER UP
//  if (_frames % 60 * 12 == 0.f) {
//    _powerUp->respawn();
//  }




  /// DEPENDIENDO DE CUANTO DISPARE, VAMOS A MOVER
  for (int i = 0; i < _bullets.size(); i++)// de esta manera suben las balas disparadas
  {
    _bullets[i]->update();
  }
  /// DEPENDIENDO DE CUANTO DISPARE, VAMOS A ELIMINAR
  for (int i = 0; i < _enemyBullets.size(); i++) // de esta manera bajan las balas enemigas
  {
    _enemyBullets[i]->update();
  }


  if (_isExplosionActive) {
    _explosion.smallExplosion(_frameExplosion);

    if (_frameExplosion >= 8.f) {
      _isExplosionActive = false;
      _frameExplosion = 0.0f;
    }
  }


  if (_isExplosionActiveBoss) {
    _explosion.bigExplosion(_frameExplosion);

    if (_frameExplosion >= 8.f) {
      _isExplosionActiveBoss = false;
      _frameExplosion = 0.0f;
    }
  }

  /// RECORREMOS LAS EXPLOSIONES DINAMICAS
  for (int i = 0; i < _vec_isExplosiveActive.size(); i++) {
    if (*_vec_isExplosiveActive[i] == true) {

      _vExplosiones[i]->smallExplosion(*_vec_frameExplosive[i]);

      if (*_vec_frameExplosive[i] >= 8.f) {

        delete _vec_isExplosiveActive[i];
        _vec_isExplosiveActive.erase(_vec_isExplosiveActive.begin() + i);

        delete _vec_frameExplosive[i];
        _vec_frameExplosive.erase(_vec_frameExplosive.begin() + i);

        delete _vExplosiones[i];
        _vExplosiones.erase(_vExplosiones.begin() + i);

      }
    }
  }


  if (isCollisionWithPersonaje() ||
      (isCollision_vBullestEnemyB_whitPersonaje())) {
    _juego.changeVidas();
    _player.respawn();
  } //  COLISION PLAYER-BULLETS B

  if (isCollisionWithEnemy() ||
      (isCollision_bullets_whitEnemyB())) {
    _juego.changePuntos(100);
  } // DESTRUYO ENEMIGOS

  if (isCollision_vEnemyB_withPersonaje()) {
    _juego.changeVidas();
    _player.respawn();
  } // COLISION PLAYER-ENEMYB

  _powerUp->update();
  _player.update();
  enemigo1.update();
  _boss.update();


  if(isCollisionWithBoss()||
      (isCollision_bullets_whitEnemyB())) {
    _juego.changePuntos(100);
  } // DESTRUYO ENEMIGOS


  if (checkCollision(enemigo1)) {
    _juego.changeVidas();
    enemigo1.respawn();
    _player.respawn();
  } // COLISION PLAYER-ENEMY A



  if (_player.isCollision(*_powerUp)) {
    _juego.addVidas();
    _powerUp->hidePowerUp();
    std::cout << "entra aca o no? " << std::endl;
  }


  _timerReload--;
  _frames++;
}

/// SI PLAYER COLISIONA ENEMIGO A
bool GamePlay::checkCollision(const Enemy &col) const
{
  return _player.getBounds().intersects(col.getBounds());
}


/// SI LA BALA DEL VECTOR ENEMIGOS B COLISIONA CON EL PERSONAJE.
bool GamePlay::isCollision_vBullestEnemyB_whitPersonaje()
{
  bool result = false;

  for (int i = 0; i < _bullets_vEnemyB.size(); i++) {
    if (_bullets_vEnemyB[i]->isCollision(_player)) {
      delete _bullets_vEnemyB[i];
      _bullets_vEnemyB.erase(_bullets_vEnemyB.begin() + i);
      result = true;
    } else {
      if (_bullets_vEnemyB[i]->getBounds().top + _bullets_vEnemyB[i]->getBounds().height > 800) {
        delete _bullets_vEnemyB[i];
        _bullets_vEnemyB.erase(_bullets_vEnemyB.begin() + i);
      }
    }
  }
  return result;
}

/// SI VECTOR ENEMIGOS B COLISIONA CON EL PERSONAJE.
bool GamePlay::isCollision_vEnemyB_withPersonaje()
{
  bool result = false;

  for (int i = 0; i < _vEnemiesB.size(); i++) {
    if (_vEnemiesB[i]->isCollision(_player)) {
      delete _vEnemiesB[i];
      _vEnemiesB.erase(_vEnemiesB.begin() + i);
      result = true;
    } else {
      if (_vEnemiesB[i]->getBounds().top + _vEnemiesB[i]->getBounds().height > 800) {
        delete _vEnemiesB[i];
        _vEnemiesB.erase(_vEnemiesB.begin() + i);
      }
    }
  }

  return result;
}


bool GamePlay::isCollisionWithPersonaje() // cuando te disparan
{
  bool result = false;

  for (int i = 0; i < _enemyBullets.size(); i++) {/// COLISION CON PLAYER
    if (_enemyBullets[i]->isCollision(_player)) {
      delete _enemyBullets[i];
      _enemyBullets.erase(_enemyBullets.begin() + i);
      result = true;
    } else {/// ELIMINAMOS DE LA PANTALLA
      if (_enemyBullets[i]->getBounds().top + _enemyBullets[i]->getBounds().height > 800) {
        delete _enemyBullets[i];
        _enemyBullets.erase(_enemyBullets.begin() + i);
      }
    }
  }

  return result;
}

bool GamePlay::isCollisionWithEnemy() // cuando destruis aviones enemigos
{
  bool result = false;
  for (int i = 0; i < _bullets.size(); i++) {
    if (_bullets[i]->isCollision(enemigo1)) {
      _sound.playExplosionSmall();
      _juego.changePuntos(100);
      delete _bullets[i];
      _bullets.erase(_bullets.begin() + i);

      _explosion = Explosion(enemigo1.getPosition().x, enemigo1.getPosition().y);
      _isExplosionActive = true;  // ACTIVA LA ANIMACION
      _frameExplosion = 0.0f;     // ESTAMOS EN EL PRIMER FRAME

      enemigo1.respawn();
      result = true;
    } else {
      if (_bullets[i]->getBounds().top + _bullets[i]->getBounds().height < 0) {
        delete _bullets[i];
        _bullets.erase(_bullets.begin() + i, _bullets.begin() + i + 1);
      }
    }
  }
  return result;
}




bool GamePlay::isCollisionWithBoss(){

  bool result = false;
  for (int i = 0; i < _bullets.size(); i++) {
    if (_bullets[i]->isCollision(_boss)) {
      _sound.playExplosionSmall();
      _juego.changePuntos(1000);
      delete _bullets[i];
      _bullets.erase(_bullets.begin() + i);

      _explosion = Explosion(_boss.getPosition().x, _boss.getPosition().y);
      _isExplosionActiveBoss = true;  // ACTIVA LA ANIMACION
      _frameExplosion = 0.0f;     // ESTAMOS EN EL PRIMER FRAME

      _boss.respawn();
      result = true;
    } else {
      if (_bullets[i]->getBounds().top + _bullets[i]->getBounds().height < 0) {
        delete _bullets[i];
        _bullets.erase(_bullets.begin() + i, _bullets.begin() + i + 1);
      }
    }
  }
  return result;
}


bool GamePlay::isCollision_bullets_whitEnemyB()
{

  /// RECORRO LAS BALAS QUE DISPARO EL PERSONAJE
  for (int i = 0; i < _bullets.size(); i++) {
    /// RECORREMOS TODOS LOS ENEMIGOS B EN PANTALLA
    for (int j = 0; j < _vEnemiesB.size(); j++) {
      if (_bullets[i]->isCollision(*_vEnemiesB[j])) {
        delete _bullets[i];
        _bullets.erase(_bullets.begin() + i);

        _vExplosiones.push_back(
                new Explosion(_vEnemiesB[j]->getPosition().x - 50, _vEnemiesB[j]->getPosition().y - 50));
        _vec_isExplosiveActive.push_back(new bool(true));
        _vec_frameExplosive.push_back(new float(0.0f));

        _vEnemiesB[j]->respawn();/// TODO: SE TIENE QUE ELIMINAR.

        return true;

      }
    }
  }

  return false;

}


bool GamePlay::isCollision_withPowerUp()
{
  return true;
}

void GamePlay::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(*_powerUp, states);

  for (int i = 0; i < _bullets.size(); i++) {
    target.draw(*_bullets[i], states);
//        target.draw(*bala_cartel[i], states);
  }

  for (int i = 0; i < _enemyBullets.size(); i++) {
    target.draw(*_enemyBullets[i], states);
  }


  for (int i = 0; i < _vEnemiesB.size(); i++) {
    target.draw(*_vEnemiesB[i], states);
  }

  for (int i = 0; i < _bullets_vEnemyB.size(); i++) {
    target.draw(*_bullets_vEnemyB[i], states);
  }


  for (int i = 0; i < _vExplosiones.size(); i++) {
    target.draw(*_vExplosiones[i], states);
  }

  target.draw(_player, states);
  target.draw(_explosion, states);
  target.draw(enemigo1, states);
  target.draw(_boss,states);

}

int GamePlay::getPuntos() const
{
  return _juego.getPuntos();
}

int GamePlay::getVidas() const
{
  return _juego.getVida();
}

void GamePlay::restartVidas()
{
  for ( int i = 0 ; i<3 ; i++)
  {
    _juego.addVidas();
  }
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



