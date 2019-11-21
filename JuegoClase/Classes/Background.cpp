#include "background.h"

USING_NS_CC;

Background::Background() :_speed(150) {
	_screen = Director::getInstance()->getOpenGLView()->getFrameSize();
	_bgPart1 = Sprite::create("fondo.png");
	_bgPart1->setContentSize(_screen);
	_bgPart2 = Sprite::create("fondo.png");
	_bgPart2->setContentSize(_screen);
	_bgPart1->setPosition(_screen.width / 2, _screen.height / 2);
	_bgPart2->setPosition(_screen.width / 2, _screen.height / 2 + _screen.height);
	addChild(_bgPart1);
	addChild(_bgPart2);
}

void Background::update(float delta) {
	Background::_bgPart1->setPositionY(_bgPart1->getPositionY() - _speed * delta);
	Background::_bgPart2->setPositionY(_bgPart2->getPositionY() - _speed * delta);
	if (_bgPart1->getPositionY() <= -(_screen.height / 2)) {
		_bgPart1->setPosition(_screen.width / 2, _screen.height / 2);
		_bgPart2->setPosition(_screen.width / 2, _screen.height / 2 + _screen.height);
	}
}

Background::~Background() {
}