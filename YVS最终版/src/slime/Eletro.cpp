#include "Eletro.h"

Eletro::Eletro()
{
    hp = hp_Eletro;
    atk = atk_Slime;
    speed = speed_slime_1;
    now = ElementState::THUNDER;
    setMovie(":/images/leislm.gif");
}

void Eletro::advance(int phase)
SLIME_ADVANCE(
        ":/images/leislm.gif",
        ":/images/leislm.gif")
