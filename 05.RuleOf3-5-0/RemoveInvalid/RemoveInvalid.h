#ifndef REMOVE_INVALID_H
#define REMOVE_INVALID_H

void removeInvalid(std::list<Company*>& companies) {
    auto it = companies.begin();

    while (it != companies.end()) {
        if ((*it)->getId() < 0){
            it = companies.erase(it);
        }
        else {
            it++;
        }
    }
}
#endif