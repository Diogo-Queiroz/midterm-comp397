#include "DiceImage.h"
#include "Game.h"

DiceImage* DiceImage::s_pInstance;

DiceImage::DiceImage(std::string imageStr, glm::vec2 position, int id)
{
	m_id = id;
	m_fruits = std::move(imageStr);
	m_position = position;
	TheTextureManager::Instance()->load("../Assets/textures/diceSequence.png",
		"diceImage-" + std::to_string(m_id), TheGame::Instance()->getRenderer());
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("diceImage-" + std::to_string(id));
	setWidth(size.x);
	setHeight(size.y);
	setPosition(position);
}

DiceImage::~DiceImage()
= default;

void DiceImage::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	/**
	 * The Draw frame is responsible for using an specific frame in a sequence of images
	 */
	TheTextureManager::Instance()->drawFrame(
		"diceImage-" + std::to_string(m_id), m_position.x, m_position.y - 45,
		210, 200, 0, item,
		TheGame::Instance()->getRenderer(), 0, 255, SDL_FLIP_NONE);
}

void DiceImage::update()
{
}

void DiceImage::clean()
{
}

void DiceImage::setImage(std::string imageStr)
{
}

int DiceImage::getItem()
{
	return item;
}

void DiceImage::setItem(int itemIndex)
{
	item = itemIndex - 1;
}
