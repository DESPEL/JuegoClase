#include "BasicEnemy.h"

USING_NS_CC;

bool BasicEnemy::init() {
	if (!Sprite::init())
		return false;

	_speed = 150;
	_currentAnimation = IDLE;
	createIdleAnimation();

	createExplosionAnimation();

	runAction(_idleAnimation);

	return true;
}

void BasicEnemy::createIdleAnimation() {
	Vector<SpriteFrame*> animFrames;
	auto sprite1 = Sprite::create("enemigo1.png");
	auto size = sprite1->getContentSize();
	for (int i = 0; i < 4; i++) {
		auto frame = SpriteFrame::create("animacion_enemigo.png", Rect(Vec2(size.width * i, 0), size));
		animFrames.pushBack(frame);
	}

	this->setSpriteFrame(animFrames.at(0));

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.25f);

	auto animate = Animate::create(animation);

	_idleAnimation = RepeatForever::create(animate);

	_idleAnimation->setTag(BasicEnemy::Animations::IDLE);
}

void BasicEnemy::createExplosionAnimation() {
	Vector<SpriteFrame*> animFrames;
	auto sprite1 = Sprite::create("enemigo1.png");
	auto size = sprite1->getContentSize();
	for (int i = 0; i < 6; i++) {
		auto frame = SpriteFrame::create("animacion_enemigo_explotar.png", Rect(Vec2(size.width * i, 0), size));
		animFrames.pushBack(frame);
	}

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.15f);

	_explosionAnimation = Animate::create(animation);

	_explosionAnimation->setTag(BasicEnemy::Animations::EXPLOSION);
}

void BasicEnemy::update(float delta) {

}
