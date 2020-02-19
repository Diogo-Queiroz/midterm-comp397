#include "GameManager.h"
#include "Util.h"

GameManager* GameManager::s_pInstance;

GameManager::GameManager()
{
}

GameManager::~GameManager()
= default;

void GameManager::draw()
{
}

void GameManager::update()
{
}

void GameManager::clean()
{
}

int GameManager::RollDice()
{
	return Util::RandomRange(1, 6);
}
