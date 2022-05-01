#include "Pyro.h"

Pyro::Pyro()
{
    hp = hp_ScreenZombie;
    atk = atk_Zombie;
    speed = speed_zombie_1;
    setMovie(":/images/ScreenZombieWalk.gif");
}

void Pyro::advance(int phase)
SLIME_ADVANCE(
        ":/images/ZombieDie.gif",
        ":/images/ZombieHead.gif",
        ":/images/ScreenZombieAttack.gif",
        ":/images/ScreenZombieWalk.gif")
