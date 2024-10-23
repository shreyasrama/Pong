#pragma once

#include "Entity/Player.h"

class Input
{
public:
    static void HandleWS(Player& player);
    static void HandleUpDown(Player& player);
};
