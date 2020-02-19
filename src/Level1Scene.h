#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "Label.h"
#include "RollButton.h"
#include "DiceImage.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void updateLabels() const;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// game objects
	Label* m_pDice1;
	Label* m_pDice2;

	RollButton* m_pRollButton;

	DiceImage* m_pDiceImage1;
	DiceImage* m_pDiceImage2;


	// private data member
	glm::vec2 m_mousePosition;
	
	
};

#endif /* defined (__LEVEL_1_SCENE__) */
