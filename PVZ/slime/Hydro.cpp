#include "Hydro.h"

Hydro::Hydro()
{
    hp = hp_BucketZombie;
    atk = atk_Zombie;
    speed = speed_zombie_1;
    setMovie(":/images/BucketZombieWalk.gif");
}


void Hydro::advance(int phase)
SLIME_ADVANCE(
        ":/images/ZombieDie.gif",
        ":/images/ZombieHead.gif",
        ":/images/BucketZombieAttack.gif",
        ":/images/BucketZombieWalk.gif")
