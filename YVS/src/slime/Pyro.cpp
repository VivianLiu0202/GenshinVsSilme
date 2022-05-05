#include "Pyro.h"

Pyro::Pyro()
{
    hp = hp_Pyro;
    atk = atk_Slime;
    speed = speed_slime_1;
    now = ElementState::FIRE;
    setMovie(":/images/huoslm.gif");
}

void Pyro::advance(int phase)
SLIME_ADVANCE(
        ":/images/huoslm.gif",
        ":/images/huoslm.gif")
