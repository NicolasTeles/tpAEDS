#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/update.h"

int main(){ 
    Quadrado quad;
    Projectile projectile;
    Game game;
    game.quadrado = quad;
    game.projectile = projectile;

    initGame(&game);
    InitWindow(game.larguraTela, game.alturaTela, "AEDSzinho's quest");
    SetTargetFPS(60);

    while (!WindowShouldClose()){
        updateGame(&game);
        drawGame(&game);
        if(game.gameover || game.venceu)
            break;
    }
    if(game.gameover){
        while (!IsKeyDown(KEY_ENTER) && !WindowShouldClose()){
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("GAME OVER", GetScreenWidth() / 2 - MeasureText("GAME OVER", 20) / 2, GetScreenHeight() / 2 - 50, 20, BLACK);
            EndDrawing();
        }
    }
    if(game.venceu){
        while (!IsKeyDown(KEY_ENTER) && !WindowShouldClose()){
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("VOCÊ VENCEU", GetScreenWidth() / 2 - MeasureText("VOCÊ VENCEU", 20) / 2, GetScreenHeight() / 2 - 50, 20, RAYWHITE);
            EndDrawing();
        }
    }
    CloseWindow();
    return 0;
}