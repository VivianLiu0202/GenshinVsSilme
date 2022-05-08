#include "Grass.h"

Grass::Grass()
{
    hp = hp_Grass;
    atk = atk_Slime;
    speed = speed_slime_1;
    now = ElementState::GRASS;
    setMovie(":/images/caoslm.gif");
}


void Grass::advance(int phase)
SLIME_ADVANCE(
        ":/images/caoslm.gif",
        ":/images/caoslm.gif")
