#include "raylib.h"

#include "src/Game/Game.h"
#include "src/Game/Input.h"
#include "src/Entity/Ball.h"
#include "src/Entity/Player.h"
#include "src/Menu/MainMenu.h"

int PLAYER_1_SCORE = 0;
int PLAYER_2_SCORE = 0;
const char *ScoreFormat = "%01i - %01i";

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    bool bGameplay = false;
    MainMenu mainMenu;
    Input input;
    Ball ball = Ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 20, 20, 0.0f);
    Player player1 = Player(0, SCREEN_HEIGHT / 2, 10, 100, 5.0f);
    Player player2 = Player(SCREEN_WIDTH - 10, SCREEN_HEIGHT / 2, 10, 100, 5.0f);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        input.HandleWS(player1);
        input.HandleUpDown(player2);
        ball.Update();

        if (CheckCollisionRecs(ball.GetCollisionRect(), player1.GetCollisionRect())
            or CheckCollisionRecs(ball.GetCollisionRect(), player2.GetCollisionRect()))
        {
            ball.Speed.x = -ball.Speed.x;
        }
        //----------------------------------------------------------------------------------


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        if (!bGameplay) {
            mainMenu.Draw();
            if (IsKeyDown(KEY_ENTER)) {
                bGameplay = true;
                ball.Speed = { 8.0f, 2.0f };
            }
        }

        if (bGameplay) {
            ClearBackground(BLACK);
            DrawText(
                TextFormat(ScoreFormat, PLAYER_1_SCORE, PLAYER_2_SCORE),
                (SCREEN_WIDTH / 2) - (MeasureText(ScoreFormat, 20) / 5),
                20,
                20,
                YELLOW);
            ball.Draw();
            player1.Draw();
            player2.Draw();
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();
    //--------------------------------------------------------------------------------------

}