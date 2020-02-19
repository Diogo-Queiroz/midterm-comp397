#pragma once
#ifndef __RollButton__
#define __RollButton__

#include "Button.h"

class RollButton : public Button
{
public:
	RollButton();
	~RollButton();
	bool ButtonClick() override;
	
private:
	bool m_isClicked;
};

#endif /* define (__RollButton__) */