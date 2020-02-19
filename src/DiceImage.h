#pragma once
#ifndef __DICE_IMAGE__
#define __DICE_IMAGE__

#include "DisplayObject.h"
#include <sstream>

class DiceImage : public DisplayObject
{
public:
    static DiceImage* Instance()
    {
        if (s_pInstance == nullptr)
        {
            s_pInstance = new DiceImage("blank", glm::vec2(0, 0), 0);
            return s_pInstance;
        }
        return s_pInstance;
    }

    DiceImage(std::string imageStr, glm::vec2 position, int id);
    ~DiceImage();

    void draw() override;
    void update() override;
    void clean() override;

    std::string m_fruits = "";
    glm::vec2 m_position;
    int m_id = 1;

    void setImage(std::string imageStr);
    int getItem();
    void setItem(int itemIndex);

    int item;

protected:

    static DiceImage* s_pInstance;
};

typedef DiceImage TheDiceImage;

#endif /* defined (__DICE_IMAGE__) */