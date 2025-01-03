#include "DesertEagle.h"

DesertEagle::DesertEagle(const int damagePerRound, const int clipSize, const int remainingAmmo)
        : Pistol(damagePerRound, clipSize, remainingAmmo) 
        {}

        bool DesertEagle::fire(PlayerVitalData & enemyPlayerData) {
            return true;
        }