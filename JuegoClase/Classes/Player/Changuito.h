#pragma once

#include "Player.h"
/*
class Changuito : public Player {
protected:
	cocos2d::Action* _idleAnimation;
	cocos2d::Action* _explosionAnimation;

	// Controlador
	KeyBoard* _control;

	// Balas
	cocos2d::Vector<Bullet*> Balas;
	int _numbullets = 100000;
	//void shoot();
	float delay = 0;
	float delayvalue = 0.25;
	int change = 4;


	void createIdleAnimation();
	void createExplosionAnimation();

public:
	CC_SYNTHESIZE(Animations, _currentAnimation, _currentAnimation);
	CC_SYNTHESIZE(float, _speed, Speed);
	CREATE_FUNC(Changuito);
};
*/

class Changuito : public Player {
private:

	// Balas
	int _numbullets = 1000;
	float delay = 0;
	float delayvalue = 0.25;
	int change = 4;


	void createIdleAnimation();
	void createExplosionAnimation();

public:
	enum Animations {
		IDLE = 0, EXPLOSION = 1
	};

	CC_SYNTHESIZE(float, _speed, Speed);
	CREATE_FUNC(Changuito);
	//Player();

	// Colision
	void setCurrentAnimation(Animations anim);

	virtual bool init();
	//void update(float);

	// Variables para disparos
	int bulletsact = 0;
	bool vuelta = 0;
};
