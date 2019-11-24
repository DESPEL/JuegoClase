#include "DebugScene.h"

USING_NS_CC;

Scene* DebugScene::createScene() {
	auto scene = Scene::create();
	auto layer = DebugScene::create();
	scene->addChild(layer);


	return scene;
}

bool DebugScene::init() {

	if (!Layer::init())
		return false;

	auto _visibleSize = Director::getInstance()->getWinSize();

	_bg = Background::create();
	addChild(_bg, -1);

	_player = Player::create();
	_player->setPosition(_visibleSize.width / 2, _visibleSize.height / 2 - 100);
	_player->setScale(2);
	addChild(_player);

	auto enemy = BasicEnemy::create();
	enemy->setPosition(_visibleSize.width /2, _visibleSize.height /2 + 100);
	enemy->setScale(2);
	_enemyPool.pushBack(enemy);
	addChild(enemy);
	

	this->schedule(schedule_selector(DebugScene::update));

	//Aparece enemigos de manera aleatoria y automatica
	DelayTime* delayAction = DelayTime::create(5.0f);
	CallFunc* callSelectorAction = CallFunc::create(CC_CALLBACK_0(DebugScene::createEnemy, this));
	auto shootSequence = Sequence::create(delayAction, callSelectorAction, NULL);
	runAction(RepeatForever::create(shootSequence));

	return true;
}

void DebugScene::createEnemy() {
	auto _visibleSize = Director::getInstance()->getWinSize();

	auto enemy = BasicEnemy::create();
	float maxX = _visibleSize.width - 40;
	float minX = 40;
	float maxY = _visibleSize.height - 20;
	float minY = _visibleSize.height/2;
	enemy->setPosition(random(minX, maxX),random(minY, maxY));
	enemy->setScale(2);
	_enemyPool.pushBack(enemy);
	addChild(enemy);
};

void DebugScene::update(float delta) {
	if (_player->isVisible())
		_bg->update(delta);

	_player->update(delta);

	for (auto e : _enemyPool) {
		
		// Colision Enemigo vs Balas
		for (auto b : _player->Balas) {
			if (b->activa) {
				if (b->getBoundingBox().intersectsRect(e->getBoundingBox())) {
					e->explode();
					b->colision();
					_player->kills++;
				}
			}
		}

		// Colision Enemigo - Jugador
		if (!e->exploded) {
			if (e->getBoundingBox().intersectsRect(_player->getBoundingBox())) {
				_player->setCurrentAnimation(Player::EXPLOSION);
				e->explode();
			}
		}
		

		// Colision balas enemigo vs Jugador
		for (auto b : e->Balas) {
			if (b->activa) {
				if (b->getBoundingBox().intersectsRect(_player->getBoundingBox())) {
					_player->setCurrentAnimation(Player::EXPLOSION);
				}
			}
		}
	}

	if (_player->get_currentAnimation() == Player::EXPLOSION) {
		for (auto e : _enemyPool) {
			e->stopActionByTag(20);
		}
	}
}
