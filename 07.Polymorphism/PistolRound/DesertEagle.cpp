#include "DesertEagle.h"

DesertEagle::DesertEagle(const int damagePerRound, const int clipSize, const int remainingAmmo)
        : Pistol(damagePerRound, clipSize, remainingAmmo) 
        {}

bool DesertEagle::fire(PlayerVitalData & enemyPlayerData) {
    if (_currClipBullets > 0) {
        if (_damagePerRound <= enemyPlayerData.armor) {
            // Not sure about that!
            enemyPlayerData.armor -= _damagePerRound * 0.25;
            enemyPlayerData.health -= _damagePerRound * 0.75;
        }
        else if (_damagePerRound > enemyPlayerData.armor) {
            enemyPlayerData.armor = 0;
            int diff = _damagePerRound - enemyPlayerData.armor;
            enemyPlayerData.health -= diff;
        }

        std::cout << "Enemy left with: " << enemyPlayerData.health << " health and " 
                << enemyPlayerData.armor << " armor";
        
        _currClipBullets--;

        if (enemyPlayerData.health <= 0) {
            return true;
        }
        return false;
    }
    else {
        _currClipBullets = (_clipSize <= _remainingAmmo) ? _clipSize : _remainingAmmo;
        _remainingAmmo -= _currClipBullets;
        
        std::cout << "Reloading...\n" << "currClipBullets: " << _currClipBullets
        << ", remainingAmmo: " << _remainingAmmo;

        return false;
    }

}