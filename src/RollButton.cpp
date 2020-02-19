#include "RollButton.h"
#include "GameManager.h"
#include "SoundManager.h"

RollButton::RollButton() : Button(
	                           "../Assets/textures/rollButton.png", 
	                           "rollButton", ROLL_BUTTON,
	                           glm::vec2(100, 100)), m_isClicked(false)
{
}

RollButton::~RollButton()
= default;

bool RollButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			TheSoundManager::Instance()->playMusic("button", 0);
			// Call roll dice, get a random number and store in two variable different numbers
			TheGameManager::Instance()->diceOneResult = TheGameManager::Instance()->RollDice(); 
			TheGameManager::Instance()->diceTwoResult = TheGameManager::Instance()->RollDice();
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}
	return false;
}
