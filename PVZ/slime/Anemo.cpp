#include "Anemo.h"

Anemo::Anemo()
{
    hp = hp_FootballZombie;
    atk = atk_Zombie;
    speed = speed_zombie_2;
    setMovie(":/images/FootballZombieWalk.gif");
}

void Anemo::advance(int phase)
SLIME_ADVANCE(
        ":/images/FootballZombieDie.gif",
        ":/images/ZombieHead.gif",
        ":/images/FootballZombieAttack.gif",
        ":/images/FootballZombieWalk.gif")
