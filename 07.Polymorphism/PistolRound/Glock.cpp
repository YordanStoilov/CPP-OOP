#include "Glock.h"

Glock::Glock(const int damagePerRound, const int clipSize, const int remainingAmmo) 
        : Pistol(damagePerRound, clipSize, remainingAmmo)
        {}

bool Glock::fire(PlayerVitalData & enemyPlayerData) {
    return true;
}