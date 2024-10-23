#include "raylib.h"

#include "Input.h"
#include "Entity/Player.h"
#include "Game.h"

void Input::HandleWS(Player& player)
{
    if (IsKeyDown(KEY_W) && (player.Speed + player.Position.y > 0))
    {
        player.Position.y -= player.Speed;
    }

    if (IsKeyDown(KEY_S) && (player.Speed + player.Position.y + player.Size.y < SCREEN_HEIGHT))
    {
        player.Position.y += player.Speed;
    }
}

void Input::HandleUpDown(Player& player)
{
    if (IsKeyDown(KEY_UP) && (player.Speed + player.Position.y > 0))
    {
        player.Position.y -= player.Speed;
    }

    if (IsKeyDown(KEY_DOWN) && (player.Speed + player.Position.y + player.Size.y < SCREEN_HEIGHT))
    {
        player.Position.y += player.Speed;
    }
}
