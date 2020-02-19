#pragma once
#ifndef __GAME_MANAGER__
#define __GAME_MANAGER__
#include "DisplayObject.h"

class GameManager : public DisplayObject
{
public:
	static  GameManager* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new GameManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

	GameManager();
	~GameManager();

	void draw() override;
	void update() override;
	void clean() override;

	int RollDice();

	int diceOneResult;
	int diceTwoResult;
protected:
	static GameManager* s_pInstance;
};

typedef GameManager TheGameManager;

#endif /* define (__GAME_MANAGER__) */