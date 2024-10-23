#include "raylib.h"
#include "MainMenu.h"
#include "Game/Game.h"

void MainMenu::Draw() {
    constexpr int titleFontSize = 40;
    constexpr int subtitleFontSize = 20;

    const char* titleText = "Pong";
    const char* subtitleText = "Press enter to start";

    const int titleWidth = MeasureText(titleText, titleFontSize);
    const int subtitleWidth = MeasureText(subtitleText, subtitleFontSize);

    DrawText(titleText, SCREEN_WIDTH / 2 - (titleWidth / 2), SCREEN_HEIGHT / 2, titleFontSize, RAYWHITE);
    DrawText(subtitleText, SCREEN_WIDTH / 2 - (subtitleWidth / 2), SCREEN_HEIGHT / 2 + titleFontSize, subtitleFontSize, RAYWHITE);
}