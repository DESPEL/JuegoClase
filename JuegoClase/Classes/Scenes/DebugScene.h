#pragma once

#include "HelloWorldScene.h"

class DebugScene : public cocos2d::Layer {
private:
		//Enemys
		int _numEnemies = 10;
		int _enemyIndex = 0;
		float delay = 0;

		Background* _bg;
		Player* _player;
		cocos2d::Vector<BasicEnemy*> _enemyPool;

		void createEnemy();

public:
		static cocos2d::Scene* createScene();

		virtual bool init();

		void update(float);

		// implement the "static create()" method manually
		//HelloWorld();
		CREATE_FUNC(DebugScene);

};

