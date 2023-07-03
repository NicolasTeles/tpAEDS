#include "../bibliotecas/update.h"
#include <stdlib.h>

void updateGame(Game *g){
    g->mapas[g->mapaAtual].voltouMapa = false;
    movimentoPlayer(g);
    atira(g);
    destroiInimigo(g);
}

void destroiInimigo(Game *g){
    Rectangle *player = &g->quadrado.player;
    Mapa *mapa = &g->mapas[g->mapaAtual];
    
    if(mapa->numTorretas > 0) {
        for(int i = 0; i < mapa->numTorretas; i++){
            atiraTorreta(g, &mapa->torretas[i]);
        }
    }
    
    for (int i = 0; i < mapa->numInimigos; i++){
        if (!mapa->inimigos[i].desenhaInimigo)
            continue;
        movimentoInimigo(g, &mapa->inimigos[i]);
        atiraInimigo(g, &mapa->inimigos[i]);

        if (CheckCollisionRecs(g->projectile.tiro, mapa->inimigos[i].inimigo) && g->projectile.ativo){
            mapa->inimigos[i].desenhaInimigo = false;
            g->projectile.ativo = false;
            continue;
        }

        if(!CheckCollisionRecs(g->quadrado.player, mapa->inimigos[i].inimigo))
            continue;

        if(!mapa->portaTrancada){
            mapa->inimigos[i].desenhaInimigo = false;
            continue;
        }

        if(g->mapaAtual == 7)
            g->gameover = true;

        switch(g->mapaAtual){
            case 0:
                mapa0Setup(g);
                g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                break;
            case 1:
                mapa1Setup(g);
                g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                break;
            case 2:
                mapa2Setup(g);
                g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                break;
            case 3:
                mapa3Setup(g);
                g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                break;
            case 4:
                mapa4Setup(g);
                g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                break;
            case 5:
                mapa5Setup(g);
                g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                break;
            case 6:
                mapa6Setup(g);
                g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                break;
            default:
                break;
        }
    }
}


void movimentoPlayer(Game *g){
    char direcao;
    Rectangle *player = &g->quadrado.player;
    Mapa *mapa = &g->mapas[g->mapaAtual];
    //Setando o tamanho do player para o definido no mapa
    player->width = mapa->tamanhoQuadrado;
    player->height = mapa->tamanhoQuadrado;

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
        if(player->x + player->width < g->larguraTela - BORDA){
            player->x += g->quadrado.velocidade;
            g->quadrado.direcaoQuadrado = 'r';
        }

        if(colisaoParede(mapa, player)){
            player->x -= g->quadrado.velocidade;
        }
        if(colisaoTorreta(mapa, player)){
            player->x -= g->quadrado.velocidade;
        }
    }

    else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){
        if(player->x > BORDA){
            player->x -= g->quadrado.velocidade;
            g->quadrado.direcaoQuadrado = 'l';
        }


        if(colisaoParede(mapa, player)){
            player->x += g->quadrado.velocidade;
           
        }
        if(colisaoTorreta(mapa, player)){
            player->x += g->quadrado.velocidade;
        }
    }

    else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)){
        if(player->y > BORDA){
            player->y -= g->quadrado.velocidade;
            g->quadrado.direcaoQuadrado = 'u';
        }


        if(colisaoParede(mapa, player)){
            player->y +=g->quadrado.velocidade;
        }
        if(colisaoTorreta(mapa, player)){
            player->y += g->quadrado.velocidade;
        }
    }

    else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)){
        if(player->y + player->height < g->alturaTela - BORDA){
            player->y += g->quadrado.velocidade;
            g->quadrado.direcaoQuadrado = 'd';
        }

        if(colisaoParede(mapa, player)){
            player->y-= g->quadrado.velocidade;
        }

        if(colisaoTorreta(mapa, player)){
            player->y-= g->quadrado.velocidade;
        }
    }

    if(CheckCollisionRecs(*player, mapa->chave) && mapa->desenhaChave ){
        mapa->tamanhoQuadrado += 11;
        mapa->portaTrancada = false;
        mapa->desenhaChave = false;
    } 

    if(CheckCollisionRecs(*player, mapa->porta) && !mapa->portaTrancada){
        if(g->mapaAtual == 6){
            g->venceu = true;
        }

        g->mapaAtual++;
        player->x = g->mapas[g->mapaAtual].startPosition[0];
        player->y = g->mapas[g->mapaAtual].startPosition[1];
    }

    if(CheckCollisionRecs(*player, mapa->portaAnterior)){
        g->mapaAtual--;
        player->x = g->mapas[g->mapaAtual].backPosition[0];
        player->y = g->mapas[g->mapaAtual].backPosition[1];
        g->mapas[g->mapaAtual].voltouMapa = true;
    }
}

bool colisaoParede(Mapa *mapa, Rectangle *alvo){
    for (int i = 0; i < mapa->numeroParedes; i++)
    {
        if(CheckCollisionRecs(mapa->paredes[i], *alvo)){
            return true;
        } 
    }
    return false;
}

bool colisaoTorreta(Mapa *mapa, Rectangle *alvo){
    for (int i = 0; i < mapa->numTorretas; i++){
        if (CheckCollisionRecs(mapa->torretas[i].torreta, *alvo)){
            return true;
        }
        
    }
    return false;
    
}

bool checkCollision(Game *g, Rectangle *r){
    if(r->x > g->larguraTela - r->width){
        return true;
    }
    if(r->x < 0){
        return true;
    }
    if(r->y > g->alturaTela - r->height){
        return true;
    }
    if(r->y < 0){
        return true;
    }
    return false;
}

void atira(Game *g){

    if(IsKeyPressed(KEY_SPACE) && !g->projectile.ativo){
        g->projectile.ativo = true;
        g->projectile.tiro.x = g->quadrado.player.x;
        g->projectile.tiro.y = g->quadrado.player.y;
        g->projectile.direcaoTiro = g->quadrado.direcaoQuadrado;
        DrawRectangle(g->projectile.tiro.x+(2*g->quadrado.player.width/5), g->projectile.tiro.y+(2*g->quadrado.player.height/5), g->projectile.tiro.width, g->projectile.tiro.height, ORANGE);
    }
    if(colisaoParede(&g->mapas[g->mapaAtual], &g->projectile.tiro)){
        g->projectile.ativo = false;
        return;
    }

    if(colisaoTorreta(&g->mapas[g->mapaAtual], &g->projectile.tiro)){
        g->projectile.ativo = false;
        return;
    }

    if(g->projectile.ativo){
        switch (g->projectile.direcaoTiro){
            case 'r':
                g->projectile.tiro.x += g->projectile.velocidadeTiro;
                g->projectile.tiro.width = STD_SHOT_WIDTH;
                g->projectile.tiro.height= STD_SHOT_HEIGHT;
                break;

            case 'l':
                g->projectile.tiro.x -= g->projectile.velocidadeTiro;
                g->projectile.tiro.width = STD_SHOT_WIDTH;
                g->projectile.tiro.height= STD_SHOT_HEIGHT;
                break;

            case 'u':
                g->projectile.tiro.y -= g->projectile.velocidadeTiro;
                g->projectile.tiro.width= STD_SHOT_HEIGHT;
                g->projectile.tiro.height = STD_SHOT_WIDTH;
                break;

            case 'd':
                g->projectile.tiro.y +=g->projectile.velocidadeTiro;
                g->projectile.tiro.width = STD_SHOT_HEIGHT;
                g->projectile.tiro.height= STD_SHOT_WIDTH;
                break;
            
            default:
                break;
        }
        
       DrawRectangle(g->projectile.tiro.x+(2*g->quadrado.player.width/5), g->projectile.tiro.y+(2*g->quadrado.player.height/5), g->projectile.tiro.width, g->projectile.tiro.height, ORANGE);
    
        
        if(checkCollision(g, &g->projectile.tiro)){
            g->projectile.ativo = false;
        }
    }
}

void movimentoInimigo(Game *g, Enemy *e){
    Mapa *m = &g->mapas[g->mapaAtual];

    if (e->direcao == KEY_LEFT){
        e->direcaoTiroInimigo = 'l';
        if (e->inimigo.x > BORDA)
            e->inimigo.x -= e->velocidade;
        else
        {
            e->direcao = KEY_RIGHT + (rand() % 4);
        }
        if (colisaoParede(m, &e->inimigo) || colisaoTorreta(m, &e->inimigo))
        {
            e->inimigo.x += e->velocidade;
            e->direcao = KEY_RIGHT + (rand() % 4);
        }
    }
    else if (e->direcao == KEY_RIGHT){
        e->direcaoTiroInimigo = 'r';
        if (e->inimigo.x + e->inimigo.width < g->larguraTela - BORDA)
            e->inimigo.x += e->velocidade;
        else
            e->direcao = KEY_RIGHT + (rand() % 4);

        if (colisaoParede(m, &e->inimigo) || colisaoTorreta(m, &e->inimigo))
        {
            e->inimigo.x -= e->velocidade;
            e->direcao = KEY_RIGHT + (rand() % 4);
        }
    }
    else if (e->direcao == KEY_UP){
        e->direcaoTiroInimigo = 'u';
        if (e->inimigo.y > BORDA)
            e->inimigo.y -= e->velocidade;
        else
            e->direcao = KEY_RIGHT + (rand() % 4);

        if (colisaoParede(m, &e->inimigo) || colisaoTorreta(m, &e->inimigo))
        {
            e->inimigo.y += e->velocidade;
            e->direcao = KEY_RIGHT + (rand() % 4);
        }
    }
    else if (e->direcao == KEY_DOWN){
        e->direcaoTiroInimigo = 'd';
        if (e->inimigo.y + e->inimigo.height < g->alturaTela - BORDA)
            e->inimigo.y += e->velocidade;
        else
            e->direcao = KEY_RIGHT + (rand() % 4);

        if (colisaoParede(m, &e->inimigo) || colisaoTorreta(m, &e->inimigo)){
            e->inimigo.y -= e->velocidade;
            e->direcao = KEY_RIGHT + (rand() % 4);
        }
    }
    if (rand() % 100 == 1) // 1% de chance do inimigo mudar de direcao
        e->direcao = KEY_RIGHT + (rand() % 4);
}

void atiraInimigo(Game *g, Enemy *e){

    if((rand() % 200 < 7) && !e->projetilInimigo.ativo){
        e->projetilInimigo.ativo = true;
        e->projetilInimigo.tiro.x = e->inimigo.x;
        e->projetilInimigo.tiro.y = e->inimigo.y;
        e->projetilInimigo.direcaoTiro = e->direcaoTiroInimigo;
        DrawRectangle(e->projetilInimigo.tiro.x+10, e->projetilInimigo.tiro.y+10, e->projetilInimigo.tiro.width, e->projetilInimigo.tiro.height, RED);
    }

    if(colisaoParede(&g->mapas[g->mapaAtual], &e->projetilInimigo.tiro)){
        e->projetilInimigo.ativo = false;
        return;
    }

    if(colisaoTorreta(&g->mapas[g->mapaAtual], &e->projetilInimigo.tiro)){
        e->projetilInimigo.ativo = false;
        return;
    }
    
    if (g->mapas[g->mapaAtual].voltouMapa){
        e->projetilInimigo.ativo = false;
    }
    
    if(e->projetilInimigo.ativo){
        switch (e->projetilInimigo.direcaoTiro){
            case 'r':
                e->projetilInimigo.tiro.x += e->projetilInimigo.velocidadeTiro;
                e->projetilInimigo.tiro.width = STD_SHOT_WIDTH;
                e->projetilInimigo.tiro.height= STD_SHOT_HEIGHT;
                break;

            case 'l':
                e->projetilInimigo.tiro.x -= e->projetilInimigo.velocidadeTiro;
                e->projetilInimigo.tiro.width = STD_SHOT_WIDTH;
                e->projetilInimigo.tiro.height= STD_SHOT_HEIGHT;
                break;

            case 'u':
                e->projetilInimigo.tiro.y -= e->projetilInimigo.velocidadeTiro;
                e->projetilInimigo.tiro.width= STD_SHOT_HEIGHT;
                e->projetilInimigo.tiro.height = STD_SHOT_WIDTH;
                break;

            case 'd':
                e->projetilInimigo.tiro.y += e->projetilInimigo.velocidadeTiro;
                e->projetilInimigo.tiro.width = STD_SHOT_HEIGHT;
                e->projetilInimigo.tiro.height= STD_SHOT_WIDTH;
                break;
            
            default:
                break;
        }

        DrawRectangle(e->projetilInimigo.tiro.x+10, e->projetilInimigo.tiro.y+10,e->projetilInimigo.tiro.width,e->projetilInimigo.tiro.height, RED);
        
        if(checkCollision(g, &e->projetilInimigo.tiro)){
            e->projetilInimigo.ativo = false;
        }
        if (CheckCollisionRecs(g->quadrado.player, e->projetilInimigo.tiro)){
            if(g->mapaAtual == 7)
                g->gameover = true;

            switch(g->mapaAtual){
                case 0:
                    mapa0Setup(g);
                    g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                    g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                    break;
                case 1:
                    mapa1Setup(g);
                    g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                    g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                    break;
                case 2:
                    mapa2Setup(g);
                    g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                    g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                    break;
                case 3:
                    mapa3Setup(g);
                    g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                    g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                    break;
                case 4:
                    mapa4Setup(g);
                    g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                    g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                    break;
                case 5:
                    mapa5Setup(g);
                    g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                    g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                    break;
                case 6:
                    mapa6Setup(g);
                    g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                    g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                    break;
                default:
                    break;
            }
        }
        
    }
}

void atiraTorreta(Game *g, Turret *t){
    if(!t->projetilTorreta.ativo){
        t->timeFrames--;
    }
    if(t->timeFrames == 0){
        t->projetilTorreta.ativo = true;
        t->projetilTorreta.tiro.x = t->torreta.x + (2 * STD_TURRET_SIZE/5);
        t->projetilTorreta.tiro.y = t->torreta.y + (2 * STD_TURRET_SIZE/5);
        t->projetilTorreta.direcaoTiro = t->direcaoTiro;
        t->timeFrames = 5;
        if (g->mapaAtual == 5){
            t->timeFrames = 20;
        }
        
        DrawRectangle(t->projetilTorreta.tiro.x, t->projetilTorreta.tiro.y, t->projetilTorreta.tiro.width, t->projetilTorreta.tiro.height, RED);
    }

    if(t->projetilTorreta.ativo){
        switch (t->projetilTorreta.direcaoTiro){
            case 'r':
                t->projetilTorreta.tiro.x += t->projetilTorreta.velocidadeTiro;
                t->projetilTorreta.tiro.width = STD_TURRET_SHOT_WIDTH;
                t->projetilTorreta.tiro.height= STD_TURRET_SHOT_HEIGHT;
                break;

            case 'l':
                t->projetilTorreta.tiro.x -= t->projetilTorreta.velocidadeTiro;
                t->projetilTorreta.tiro.width = STD_TURRET_SHOT_WIDTH;
                t->projetilTorreta.tiro.height= STD_TURRET_SHOT_HEIGHT;
                break;

            case 'u':
                t->projetilTorreta.tiro.y -= t->projetilTorreta.velocidadeTiro;
                t->projetilTorreta.tiro.width= STD_TURRET_SHOT_HEIGHT;
                t->projetilTorreta.tiro.height = STD_TURRET_SHOT_WIDTH;
                break;

            case 'd':
                t->projetilTorreta.tiro.y += t->projetilTorreta.velocidadeTiro;
                t->projetilTorreta.tiro.width = STD_TURRET_SHOT_HEIGHT;
                t->projetilTorreta.tiro.height= STD_TURRET_SHOT_WIDTH;
                break;
            
            default:
                break;
        }

        DrawRectangle(t->projetilTorreta.tiro.x, t->projetilTorreta.tiro.y, t->projetilTorreta.tiro.width, t->projetilTorreta.tiro.height, RED);

        if(colisaoParede(&g->mapas[g->mapaAtual], &t->projetilTorreta.tiro))
            t->projetilTorreta.ativo = false;
        
        if (g->mapas[g->mapaAtual].voltouMapa)
            t->projetilTorreta.ativo = false;
        
        if(checkCollision(g, &t->projetilTorreta.tiro))
            t->projetilTorreta.ativo = false;
        
        if(CheckCollisionRecs(t->projetilTorreta.tiro, g->quadrado.player)){
            if(g->mapaAtual == 7)
                g->gameover = true;

            switch(g->mapaAtual){
                case 0:
                    mapa0Setup(g);
                    g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                    g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                    break;
                case 1:
                    mapa1Setup(g);
                    g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                    g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                    break;
                case 2:
                    mapa2Setup(g);
                    g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                    g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                    break;
                case 3:
                    mapa3Setup(g);
                    g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                    g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                    break;
                case 4:
                    mapa4Setup(g);
                    g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                    g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                    break;
                case 5:
                    mapa5Setup(g);
                    g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                    g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                    break;
                case 6:
                    mapa6Setup(g);
                    g->quadrado.player.x = g->mapas[g->mapaAtual].startPosition[0];
                    g->quadrado.player.y = g->mapas[g->mapaAtual].startPosition[1];
                    break;
                default:
                    break;
            }
        }
    }
}

void movimentoChefe(Game *g, Boss *b){

    Mapa *m = &g->mapas[g->mapaAtual];

    if (b->direcao == KEY_LEFT){
        if (b->chefe.x > BORDA)
            b->chefe.x -= b->velocidade;
        else
        {
            b->direcao = KEY_RIGHT + (rand() % 4);
        }
        if (colisaoParede(m, &b->chefe) || colisaoTorreta(m, &b->chefe))
        {
            b->chefe.x += b->velocidade;
            b->direcao = KEY_RIGHT + (rand() % 4);
        }
    }
    else if (b->direcao == KEY_RIGHT){
        if (b->chefe.x + b->chefe.width < g->larguraTela - BORDA)
            b->chefe.x += b->velocidade;
        else
            b->direcao = KEY_RIGHT + (rand() % 4);

        if (colisaoParede(m, &b->chefe) || colisaoTorreta(m, &b->chefe))
        {
            b->chefe.x -= b->velocidade;
            b->direcao = KEY_RIGHT + (rand() % 4);
        }
    }
    else if (b->direcao == KEY_UP){
        if (b->chefe.y > BORDA)
            b->chefe.y -= b->velocidade;
        else
            b->direcao = KEY_RIGHT + (rand() % 4);

        if (colisaoParede(m, &b->chefe) || colisaoTorreta(m, &b->chefe))
        {
            b->chefe.y += b->velocidade;
            b->direcao = KEY_RIGHT + (rand() % 4);
        }
    }
    else if (b->direcao == KEY_DOWN){
        if (b->chefe.y + b->chefe.height < g->alturaTela - BORDA)
            b->chefe.y += b->velocidade;
        else
            b->direcao = KEY_RIGHT + (rand() % 4);

        if (colisaoParede(m, &b->chefe) || colisaoTorreta(m, &b->chefe)){
            b->chefe.y -= b->velocidade;
            b->direcao = KEY_RIGHT + (rand() % 4);
        }
    }
    if (rand() % 100 == 1) // 1% de chance do chefe mudar de direcao
        b->direcao = KEY_RIGHT + (rand() % 4);
}