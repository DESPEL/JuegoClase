#include "Player\Changuito.h"

USING_NS_CC;
/*
void Changuito::createIdleAnimation() {
	Vector<SpriteFrame*> animFrames;
	auto sprite1 = Sprite::create("Changuito.png");
	auto size = sprite1->getContentSize();
	//for (int i = 0; i < 4; i++) {
	auto frame = SpriteFrame::create("Changuito.png", Rect(Vec2(size.width, 0), size));
	animFrames.pushBack(frame);
	//}

	this->setSpriteFrame(animFrames.at(0));

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.25f);

	auto animate = Animate::create(animation);

	_idleAnimation = RepeatForever::create(animate);

	_idleAnimation->setTag(Player::Animations::IDLE);

	_idleAnimation->retain();
}

void Changuito::createExplosionAnimation() {
	Vector<SpriteFrame*> animFrames;
	auto sprite1 = Sprite::create("Changuito.png");
	auto size = sprite1->getContentSize();
	//for (int i = 0; i < 4; i++) {
	auto frame = SpriteFrame::create("Changuito.png", Rect(Vec2(size.width, 0), size));
	animFrames.pushBack(frame);
	//}

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.15f);

	_explosionAnimation = Animate::create(animation);

	_explosionAnimation->setTag(Player::Animations::EXPLOSION);

	_explosionAnimation->retain();
}*/

bool Changuito::init() {

	if (!Sprite::init())
		return false;

	_speed = 150;
	Changuito::set_currentAnimation(Player::Animations::IDLE);

	createIdleAnimation();

	createExplosionAnimation();

	runAction(_idleAnimation);

	_control = KeyBoard::create();
	addChild(_control);

	for (int i = 0; i < _numbullets; i++) {
		Balas.pushBack(Bullet::createPlayerBullet());
	}

	this->scheduleUpdate();


	return true;
}

void Changuito::createIdleAnimation() {
	Vector<SpriteFrame*> animFrames;
	auto sprite1 = Sprite::create("Changuito.png");
	auto size = sprite1->getContentSize();
	for (int i = 0; i < 4; i++) {
		auto frame = SpriteFrame::create("Changuito.png", Rect(Vec2(0, 0), size));
		animFrames.pushBack(frame);
	}

	this->setSpriteFrame(animFrames.at(0));

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.25f);

	auto animate = Animate::create(animation);

	_idleAnimation = RepeatForever::create(animate);

	_idleAnimation->setTag(Changuito::Animations::IDLE);

	_idleAnimation->retain();
}

void Changuito::createExplosionAnimation() {
	Vector<SpriteFrame*> animFrames;
	auto sprite1 = Sprite::create("Changuito.png");
	auto size = sprite1->getContentSize();
	for (int i = 0; i < 4; i++) {
		auto frame = SpriteFrame::create("Changuito.png", Rect(Vec2(0, 0), size));
		animFrames.pushBack(frame);
	}

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.15f);

	_explosionAnimation = Animate::create(animation);

	_explosionAnimation->setTag(Changuito::Animations::EXPLOSION);

	_explosionAnimation->retain();
}

void Changuito::setCurrentAnimation(Animations anim) {
	/*if (_currentAnimation == anim) return;
	_currentAnimation = anim;
	if (_currentAnimation == IDLE) {
		stopActionByTag(EXPLOSION);
		runAction(_idleAnimation);
	}
	if (_currentAnimation == EXPLOSION) {
		stopActionByTag(IDLE);
		runAction(_explosionAnimation);
	}*/
}
