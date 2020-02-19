#include "Background.h"
#include "Game.h"

Background::Background()
{
	TheTextureManager::Instance()->load("../Assets/textures/board.png", "background",
		TheGame::Instance()->getRenderer());
}

Background::~Background()
{
}

void Background::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("background", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, false);
}

void Background::update()
{
}

void Background::clean()
{
}
