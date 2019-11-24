#include "bullet.h"

USING_NS_CC;

bool Bullet::initWithFile(const std::string& filename) {

	if (!Sprite::initWithFile(filename))
		return false;

	_speed = 100;

	setVisible(false);
	schedule(schedule_selector(Bullet::update));

	return true;
}

Bullet* Bullet::createPlayerBullet() {
	Bullet* sprite = new (std::nothrow) Bullet();

	if (sprite && sprite->initWithFile("disparo_nave.png")) {
		sprite->_type = PLAYER_BULLET;
		sprite->autorelease();
		sprite->direccion = Vec2(0, 1);
		return sprite;
	}

	CC_SAFE_DELETE(sprite);
	return nullptr;
}

Bullet* Bullet::createEnemyBullet() {
	Bullet* sprite = new (std::nothrow) Bullet();
	if (sprite && sprite->initWithFile("disparo_enemigo.png")) {
		sprite->_type = ENEMY_BULLET;
		sprite->autorelease();
		sprite->direccion = Vec2(0, -1);
		return sprite;
	}

	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void Bullet::colision() {
	activa = false;
	setVisible(false);
}

void Bullet::update(float dt) {
	if (!this->isVisible()) return;
	auto scene = Director::getInstance()->getRunningScene();
	if (_type == PLAYER_BULLET) {
		//para arriba
		setAnchorPoint(Point(0.5, 0));
		setPosition(getPositionX() + direccion.x * _speed * dt, getPositionY() + direccion.y * _speed * dt); 
		if (getPositionY() > Director::getInstance()->getVisibleSize().height || getPositionX() > Director::getInstance()->getVisibleSize().width || getPositionX() < 0 || getPositionY() < 0) {
			setVisible(false);
			activa = false;
		}
	}
	else if (_type == ENEMY_BULLET) {
		//para abajo
		setAnchorPoint(Point(0.5, 1));
		setPosition(getPositionX() + direccion.x * _speed * dt, getPositionY() + direccion.y * _speed * dt);
		if (getPositionY() > Director::getInstance()->getVisibleSize().height || getPositionX() > Director::getInstance()->getVisibleSize().width || getPositionX() < 0 || getPositionY() < 0) {
			setVisible(false);
			activa = false;
		}
	}
}