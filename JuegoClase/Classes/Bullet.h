#pragma once

#include "cocos2d.h"
#include "BasicEnemy.h"
#include "Player.h"

class Bullet : public cocos2d::Sprite {
public:
	CC_SYNTHESIZE(float, _speed, Speed);
	virtual void update(float);

	static Bullet* createEnemyBullet();
	static Bullet* createPlayerBullet();

	bool activa = false;
	cocos2d::Vec2 direccion;


	virtual bool initWithFile(const std::string&);

	void colision();

private:
	enum Type { ENEMY_BULLET = 0, PLAYER_BULLET = 1 };
	CC_SYNTHESIZE(Type, _type, Type);

};

