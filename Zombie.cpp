#include "Zombie.h"
#include "TextureHolder.h"
#include <cstdlib>
#include <ctime>

using namespace std;

bool Zombie::hit() {

}

bool Zombie::isAlive() {

}

void Zombie::spawn(float startX, float startY, int type, int seed) {
	switch (type) {
	case 0:
		m_Sprite = Sprite(TextureHolder::GetTexture("graphics/bloater.png"));
		m_Speed = BLOATER_SPEED;
		m_Health = BLOATER_HEALTH;
		break;
	case 1:
		m_Sprite = Sprite(TextureHolder::GetTexture("graphics/chaser.png"));
		m_Speed = CHASER_SPEED;
		m_Health = CHASER_HEALTH;
		break;
	case 2:
		m_Sprite = Sprite(TextureHolder::GetTexture("graphics/crawler.png"));
		m_Speed = CRAWLER_SPEED;
		m_Health = CRAWLER_HEALTH;
		break;
	}

	srand((int)time(0) * seed);
	float modifier = (rand() % MAX_VARIANCE) + OFFSET; 
	modifier /= 100;
	m_Speed *= modifier;
	m_position.x = startX;
	m_position.y = startY;
	m_Sprite.setOrigin(25, 25);
	m_Sprite.setPosition(m_position);
}

FloatRect Zombie::getPosition() {

}

Sprite Zombie::getSprite() {

}

void Zombie::update(float elapsedTime, Vector2f playerLocation) {

}
