#include "Level1Scene.h"
#include "Game.h"
#include <iostream>
#include "GameManager.h"

Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	m_pRollButton->draw();
	m_pDice1->draw();
	m_pDice2->draw();
	m_pDiceImage1->draw();
	m_pDiceImage2->draw();
}

void Level1Scene::updateLabels() const
{
	m_pDice1->setText(std::to_string(TheGameManager::Instance()->diceOneResult));
	m_pDice2->setText(std::to_string(TheGameManager::Instance()->diceTwoResult));
}

void Level1Scene::update()
{
	m_pRollButton->setMousePosition(m_mousePosition);
	m_pRollButton->ButtonClick();

	m_pDiceImage1->setItem(TheGameManager::Instance()->diceOneResult);
	m_pDiceImage2->setItem(TheGameManager::Instance()->diceTwoResult);
}

void Level1Scene::clean()
{
}

void Level1Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(true);
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollButton->setMouseButtonClicked(false);

				updateLabels();
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			

				/************************************************************************/
			case SDLK_w:
				
				break;
			case SDLK_s:
				
				break;
			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				
				break;

			case SDLK_s:
				
				break;

			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{
	m_pRollButton = new RollButton();
	m_pRollButton->setPosition(
		glm::vec2(Config::SCREEN_WIDTH * 0.5, Config::SCREEN_HEIGHT * 0.8));

	m_pDice1 = new Label("Dice One");
	m_pDice1->setPosition(glm::vec2(150, 300));
	m_pDice2 = new Label("Dice Two");
	m_pDice2->setPosition(glm::vec2(450, 300));

	m_pDiceImage1 = new DiceImage("blank", glm::vec2(50, 100), 1);
	m_pDiceImage1->setItem(0);

	m_pDiceImage2 = new DiceImage("blank", glm::vec2(350, 100), 2);
	m_pDiceImage2->setItem(0);
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

