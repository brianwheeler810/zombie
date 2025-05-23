#include "Zombie.h"
#include "TextureHolder.h"
#include <cstdlib>
#include <ctime>

using namespace std;

bool Zombie::hit() {
	m_Health--;
	if (m_Health <= 0) {
		m_Alive = false;
		m_Sprite.setTexture(TextureHolder::GetTexture("graphics/blood.png"));
		return true;
	}
}

bool Zombie::isAlive() {
	return m_Alive;
}

void Zombie::spawn(float startX, float startY, int type) {
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

	srand((int)time(0));
	float modifier = (rand() % MAX_VARIANCE) + OFFSET; 
	modifier /= 100;
	m_Speed *= modifier;
	m_position.x = startX;
	m_position.y = startY;
	m_Sprite.setOrigin(25, 25);
	m_Sprite.setPosition(m_position);
}

FloatRect Zombie::getPosition() {
	return m_Sprite.getLocalBounds();
}

Sprite Zombie::getSprite() {
	return m_Sprite;
}

void Zombie::update(float elapsedTime, Vector2f playerLocation) {
	float playerX = playerLocation.x;
	float playerY = playerLocation.y;

	if (playerX > m_position.x) {
		m_position.x = m_Speed * elapsedTime;
	}
	if (playerY > m_position.y) {
		m_position.y = m_Speed * elapsedTime;
	}
	if (playerX < m_position.x) {
		m_position.x = m_Speed * elapsedTime;
	}
	if (playerY < m_position.y) {
		m_position.y = m_Speed * elapsedTime;
	}

	m_Sprite.setPosition(m_position);
	float angle = (atan2(playerY - m_position.y, playerX - m_position.x) * 180) / 3.141;
	m_Sprite.setRotation(angle);
}
