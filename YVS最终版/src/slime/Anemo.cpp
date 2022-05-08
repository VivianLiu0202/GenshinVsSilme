#include "Anemo.h"

Anemo::Anemo()
{
    hp = hp_Anemo;
    atk = atk_Slime;
    speed = speed_slime_2;
    now = ElementState::WIND;
    setMovie(":/images/fengslm.gif");
}

void Anemo::advance(int phase)
SLIME_ADVANCE(
        ":/images/fengslm.gif",
        ":/images/fengslm.gif")
