#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene() {
	auto scene = Scene::create();
	auto layer = HelloWorld::create();
	scene->addChild(layer);


	return scene;
}

bool HelloWorld::init() {

	if (!Layer::init())
		return false;

	Size visibleSize = Director::getInstance()->getWinSize();

	_bg = Background::create();
	addChild(_bg, -1);

	_player = Player::create();
	_player->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 100);
	_player->setScale(2);
	addChild(_player);

	//for (int i = 0; i < _numEnemies; i++) {
	auto enemy = BasicEnemy::create();
		//damos informacion a los enemigos acerca del jugador
		//enemy->setTarget(_player);
		//enemy->setVisible(false);
	enemy->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 100);
	enemy->setScale(2);
		//_enemyPool.pushBack(enemy);
	addChild(enemy);
	//}

	this->schedule(schedule_selector(HelloWorld::update));

	return true;
}

void HelloWorld::update(float delta) {
	if (_player->isVisible())
		_bg->update(delta);

	_player->update(delta);

}
