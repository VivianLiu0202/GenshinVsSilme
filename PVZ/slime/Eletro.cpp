#include "Eletro.h"

Eletro::Eletro()
{
    hp = hp_ConeZombie;
    atk = atk_Zombie;
    speed = speed_zombie_1;
    setMovie(":/images/ConeZombieWalk.gif");
}

void Eletro::advance(int phase)
SLIME_ADVANCE(
        ":/images/ZombieDie.gif",
        ":/images/ZombieHead.gif",
        ":/images/ConeZombieAttack.gif",
        ":/images/ConeZombieWalk.gif")
