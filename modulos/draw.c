#include "../bibliotecas/update.h"

void drawBorder(Game *g){
    DrawRectangle(0, 0, g->larguraTela, BORDA, BLACK);
    DrawRectangle(0, 0, BORDA, g->alturaTela, BLACK);
    DrawRectangle(0, g->alturaTela-BORDA, g->larguraTela, BORDA, BLACK);
    DrawRectangle(g->larguraTela-BORDA, 0, BORDA, g->alturaTela, BLACK);
}

void drawMap(Game *g){
    Mapa *mapa = &g->mapas[g->mapaAtual];
    for(int i = 0; i < mapa->numeroParedes; i++){
        DrawRectangleRec(mapa->paredes[i], BLUE);
    }

    if(g->mapaAtual-1 > -1){
        DrawRectangleRec(mapa->portaAnterior, GREEN);
    }

    if(mapa->portaTrancada){
        DrawRectangleRec(mapa->porta, RED);
    }else{
        DrawRectangleRec(mapa->porta, GREEN);
    }
    
    if (mapa->desenhaChave){        
        DrawRectangleRec(mapa->chave, PURPLE);
    }
    
    for (int i = 0; i < mapa->numInimigos; i++){
        if (!mapa->inimigos[i].desenhaInimigo)
            continue;
        DrawRectangleRec(mapa->inimigos[i].inimigo, PINK);

    }

    for (int i = 0; i < mapa->numTorretas; i++){
        DrawRectangleRec(mapa->torretas[i].torreta, ORANGE);
    }

    if (g->mapaAtual == 7){
        DrawRectangleRec(mapa->chefe.chefe,MAROON);
    }
    
    
}

void drawGame(Game *g){
    BeginDrawing();
        ClearBackground(GRAY);
        drawMap(g);
        DrawRectangleRec(g->quadrado.player, BLACK);
        drawBorder(g);
    EndDrawing();
}