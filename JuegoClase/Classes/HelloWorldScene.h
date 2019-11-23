#pragma once
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "background.h"
#include "Player.h"
#include "BasicEnemy.h"
#include "Tipos.h"

class HelloWorld : public cocos2d::Layer
{
private:
	//Enemys
	int _numEnemies = 10;
	int _enemyIndex = 0;

	Background* _bg;
	Player* _player;
	//cocos2d::Vector<BasicEnemy*>& _enemyPool;

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void update(float);

	// implement the "static create()" method manually
	//HelloWorld();
	CREATE_FUNC(HelloWorld);
	
};