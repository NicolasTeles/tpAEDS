#include "../bibliotecas/update.h"
#include <stdlib.h>

void initGame(Game *g){
    g->mapaAtual = 0;
    
    g->numeroMapas = 10;

    g->alturaTela = 720;
    g->larguraTela = 1360;

    g->quadrado.direcaoQuadrado = 'r';
    g->quadrado.velocidade = STD_SPEED;

    g->projectile.tiro.width = STD_SHOT_WIDTH;
    g->projectile.tiro.height = STD_SHOT_HEIGHT;
    g->projectile.ativo = false;
    g->projectile.velocidadeTiro = STD_SHOT_SPEED;

    g->quadrado.player.height = STD_QUADRADO_SIZE;
    g->quadrado.player.width = STD_QUADRADO_SIZE;
    g->quadrado.player.x = 10;
    g->quadrado.player.y = 200;

    g->gameover = false;
    g->venceu = false;

    mapa0Setup(g);
    mapa1Setup(g);
    mapa2Setup(g);
    mapa3Setup(g);
    mapa4Setup(g);
    mapa5Setup(g);
    mapa6Setup(g);
    //mapa7Setup(g);
}

void mapa0Setup(Game *g){
    g->mapas[0].numeroParedes = 2;
    g->mapas[0].paredes[0] = (Rectangle){1.15 *g->larguraTela / 4, 0, 10, 0.75 * g->alturaTela};
    g->mapas[0].paredes[1] = (Rectangle){5.7 * (g->larguraTela) / 8, 0.35 * g->alturaTela, 10, 0.8 * g->alturaTela};
    g->mapas[0].porta = (Rectangle){g->larguraTela - (BORDA+5), 2 * g->alturaTela / 3, STD_DOOR_WIDTH, STD_DOOR_HEIGHT};
    g->mapas[0].portaTrancada = true;
    g->mapas[0].chave = (Rectangle){2 * g->larguraTela / 3, 20, STD_KEY_SIZE, STD_KEY_SIZE};
    g->mapas[0].desenhaChave = true;
    g->mapas[0].numInimigos = 2;
    g->mapas[0].numTorretas = 0;
    g->mapas[0].startPosition[0] = 10;
    g->mapas[0].startPosition[1] = 200;
    g->mapas[0].backPosition[0] = g->larguraTela - (BORDA + 5)-60;
    g->mapas[0].backPosition[1] = 2 * g->alturaTela / 3;
    g->mapas[0].tamanhoQuadrado = STD_QUADRADO_SIZE;
    g->mapas[0].voltouMapa = false;

    
    for (int i = 0; i < g->mapas[0].numInimigos; i++){
        //Inicializando o inimigo
        g->mapas[0].inimigos[i].inimigo = (Rectangle){2 * g->larguraTela / 3, 2 * g->alturaTela / 3, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};
        g->mapas[0].inimigos[i].cor = BLACK;
        g->mapas[0].inimigos[i].velocidade = STD_SPEED;
        g->mapas[0].inimigos[i].direcao = KEY_RIGHT + (rand() % 4);
        g->mapas[0].inimigos[i].desenhaInimigo = true;
        //Inicializando o tiro do inimigo
        g->mapas[0].inimigos[i].projetilInimigo.ativo = false;
        g->mapas[0].inimigos[i].projetilInimigo.direcaoTiro = ' ';
        g->mapas[0].inimigos[i].projetilInimigo.qtdeTiros = 1;
        g->mapas[0].inimigos[i].projetilInimigo.velocidadeTiro = STD_SHOT_SPEED;
        g->mapas[0].inimigos[i].projetilInimigo.tiro.height = STD_SHOT_WIDTH;
        g->mapas[0].inimigos[i].projetilInimigo.tiro.width = STD_SHOT_HEIGHT;
    }
    
}

void mapa1Setup(Game *g){
    g->mapas[1].numeroParedes = 3;
    g->mapas[1].paredes[0] = (Rectangle){280, 0, 10, 429};
    g->mapas[1].paredes[1] = (Rectangle){655, 66, 10, 560};
    g->mapas[1].paredes[2] = (Rectangle){1020, 0, 10, 525};
    g->mapas[1].porta = (Rectangle){g->larguraTela - (BORDA + 5), 100, STD_DOOR_WIDTH, STD_DOOR_HEIGHT};
    g->mapas[1].portaAnterior = (Rectangle){(BORDA), 100, STD_DOOR_WIDTH, STD_DOOR_HEIGHT};
    g->mapas[1].portaTrancada = true;
    g->mapas[1].chave = (Rectangle){850, 61, STD_KEY_SIZE, STD_KEY_SIZE};
    g->mapas[1].desenhaChave = true;
    g->mapas[1].numInimigos = 3;
    g->mapas[1].numTorretas = 0;
    g->mapas[1].startPosition[0] = (BORDA + 5) + 50;
    g->mapas[1].startPosition[1] = 100;
    g->mapas[1].backPosition[0] =  g->larguraTela - BORDA + 5 - 60;
    g->mapas[1].backPosition[1] = 120;
    g->mapas[1].tamanhoQuadrado = STD_QUADRADO_SIZE;

    for (int i = 0; i < g->mapas[1].numInimigos; i++){
        //Inicializando o inimigo
        if(i==2)
            g->mapas[1].inimigos[i].inimigo = (Rectangle){131, 550, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};
        else
            g->mapas[1].inimigos[i].inimigo = (Rectangle){880, 115, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};

        g->mapas[1].inimigos[i].cor = BLACK;
        g->mapas[1].inimigos[i].velocidade = STD_SPEED;
        g->mapas[1].inimigos[i].direcao = KEY_RIGHT + (rand() % 4);
        g->mapas[1].inimigos[i].desenhaInimigo = true;
        //Inicializando o tiro do inimigo
        g->mapas[1].inimigos[i].projetilInimigo.ativo = false;
        g->mapas[1].inimigos[i].projetilInimigo.direcaoTiro = ' ';
        g->mapas[1].inimigos[i].projetilInimigo.qtdeTiros = 1;
        g->mapas[1].inimigos[i].projetilInimigo.velocidadeTiro = STD_SHOT_SPEED;
        g->mapas[1].inimigos[i].projetilInimigo.tiro.height = STD_SHOT_WIDTH;
        g->mapas[1].inimigos[i].projetilInimigo.tiro.width = STD_SHOT_HEIGHT;
    }
}

void mapa2Setup(Game *g){
    g->mapas[2].numeroParedes = 4;
    g->mapas[2].paredes[0] = (Rectangle){0, 319, 423, 10};
    g->mapas[2].paredes[1] = (Rectangle){670, 0, 10, 296};
    g->mapas[2].paredes[2] = (Rectangle){835, 320, 10, 404};
    g->mapas[2].paredes[3] = (Rectangle){1094, 425, 271, 10};
    g->mapas[2].porta = (Rectangle){g->larguraTela - (BORDA + 5), 527, STD_DOOR_WIDTH, STD_DOOR_HEIGHT};
    g->mapas[2].portaAnterior = (Rectangle){(BORDA), 50, STD_DOOR_WIDTH, STD_DOOR_HEIGHT};
    g->mapas[2].portaTrancada = true;
    g->mapas[2].chave = (Rectangle){108, 618, STD_KEY_SIZE, STD_KEY_SIZE};
    g->mapas[2].desenhaChave = true;
    g->mapas[2].numInimigos = 3;
    g->mapas[2].numTorretas = 0;
    g->mapas[2].startPosition[0] = (BORDA + 5) + 60;
    g->mapas[2].startPosition[1] = 50;
    g->mapas[2].backPosition[0] =  g->larguraTela - BORDA + 5 - 60;
    g->mapas[2].backPosition[1] = 527;
    g->mapas[2].tamanhoQuadrado = STD_QUADRADO_SIZE;

    for (int i = 0; i < g->mapas[2].numInimigos; i++){
        //Inicializando o inimigo
        if(i==2)
            g->mapas[2].inimigos[i].inimigo = (Rectangle){1045, 176, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};
        else
            g->mapas[2].inimigos[i].inimigo = (Rectangle){400, 560, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};

        g->mapas[2].inimigos[i].cor = BLACK;
        g->mapas[2].inimigos[i].velocidade = STD_SPEED;
        g->mapas[2].inimigos[i].direcao = KEY_RIGHT + (rand() % 4);
        g->mapas[2].inimigos[i].desenhaInimigo = true;
        //Inicializando o tiro do inimigo
        g->mapas[2].inimigos[i].projetilInimigo.ativo = false;
        g->mapas[2].inimigos[i].projetilInimigo.direcaoTiro = ' ';
        g->mapas[2].inimigos[i].projetilInimigo.qtdeTiros = 1;
        g->mapas[2].inimigos[i].projetilInimigo.velocidadeTiro = STD_SHOT_SPEED;
        g->mapas[2].inimigos[i].projetilInimigo.tiro.height = STD_SHOT_WIDTH;
        g->mapas[2].inimigos[i].projetilInimigo.tiro.width = STD_SHOT_HEIGHT;
    }
}

void mapa3Setup(Game *g){
    g->mapas[3].numeroParedes = 6;
    g->mapas[3].paredes[0] = (Rectangle){180, 100, 10, 520};
    g->mapas[3].paredes[1] = (Rectangle){320, 280, 480, 10};
    g->mapas[3].paredes[2] = (Rectangle){320, 370, 480, 10};
    g->mapas[3].paredes[3] = (Rectangle){990, 0, 10, 330};
    g->mapas[3].paredes[4] = (Rectangle){990, 420, 10, 330};
    g->mapas[3].paredes[5] = (Rectangle){1190, 189, 10, 335};
    g->mapas[3].porta = (Rectangle){g->larguraTela - (BORDA + 5), 280, STD_DOOR_WIDTH, STD_DOOR_HEIGHT};
    g->mapas[3].portaAnterior = (Rectangle){BORDA, 290, STD_DOOR_WIDTH, STD_DOOR_HEIGHT};
    g->mapas[3].portaTrancada = true;
    g->mapas[3].chave = (Rectangle){550, 320, STD_KEY_SIZE, STD_KEY_SIZE};
    g->mapas[3].desenhaChave = true;
    g->mapas[3].numInimigos = 4;
    g->mapas[3].numTorretas = 0;
    g->mapas[3].startPosition[0] = (BORDA + 5) + 60;
    g->mapas[3].startPosition[1] = 300;
    g->mapas[3].backPosition[0] = (g->larguraTela - BORDA + 5) - 50 ;
    g->mapas[3].backPosition[1] = 290;
    g->mapas[3].tamanhoQuadrado = STD_QUADRADO_SIZE;

    for (int i = 0; i < g->mapas[3].numInimigos; i++){
        //Inicializando o inimigo
        g->mapas[3].inimigos[0].inimigo = (Rectangle){110, 660, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};
        g->mapas[3].inimigos[1].inimigo = (Rectangle){550, 330, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};
        g->mapas[3].inimigos[2].inimigo = (Rectangle){550, 160, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};
        g->mapas[3].inimigos[3].inimigo = (Rectangle){1110, 330, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};

        g->mapas[3].inimigos[i].cor = BLACK;
        g->mapas[3].inimigos[i].velocidade = STD_SPEED;
        g->mapas[3].inimigos[i].direcao = KEY_RIGHT + (rand() % 4);
        g->mapas[3].inimigos[i].desenhaInimigo = true;
        //Inicializando o tiro do inimigo
        g->mapas[3].inimigos[i].projetilInimigo.ativo = false;
        g->mapas[3].inimigos[i].projetilInimigo.direcaoTiro = ' ';
        g->mapas[3].inimigos[i].projetilInimigo.qtdeTiros = 1;
        g->mapas[3].inimigos[i].projetilInimigo.velocidadeTiro = STD_SHOT_SPEED;
        g->mapas[3].inimigos[i].projetilInimigo.tiro.height = STD_SHOT_WIDTH;
        g->mapas[3].inimigos[i].projetilInimigo.tiro.width = STD_SHOT_HEIGHT;
    }
}

void mapa4Setup(Game *g){
    g->mapas[4].numeroParedes = 9;
    g->mapas[4].paredes[0] = (Rectangle){100, 429, 10, 220};
    g->mapas[4].paredes[1] = (Rectangle){100, 71, 10, 220};
    g->mapas[4].paredes[2] = (Rectangle){100, 283, 1300, 10};
    g->mapas[4].paredes[3] = (Rectangle){100, 429, 500, 10};
    g->mapas[4].paredes[4] = (Rectangle){300, 0, 300, 175};
    g->mapas[4].paredes[5] = (Rectangle){700, 0, 300, 100};
    g->mapas[4].paredes[6] = (Rectangle){700, 185, 300, 100};
    g->mapas[4].paredes[7] = (Rectangle){1125, 90, 120, 120};  
    g->mapas[4].paredes[8] = (Rectangle){600, 290, 10, 149};   
    g->mapas[4].porta = (Rectangle){g->larguraTela - (BORDA + 5), 420, STD_DOOR_WIDTH, STD_DOOR_HEIGHT};
    g->mapas[4].portaAnterior = (Rectangle){BORDA, 290, STD_DOOR_WIDTH, STD_DOOR_HEIGHT};
    g->mapas[4].portaTrancada = true;
    g->mapas[4].chave = (Rectangle){1300, 150, STD_KEY_SIZE, STD_KEY_SIZE};
    g->mapas[4].desenhaChave = true;
    g->mapas[4].startPosition[0] = (BORDA + 5) + 60;
    g->mapas[4].startPosition[1] = 320;
    g->mapas[4].backPosition[0] = g->larguraTela - BORDA + 5 -50;
    g->mapas[4].backPosition[1] = 450;
    g->mapas[4].tamanhoQuadrado = STD_QUADRADO_SIZE;

    g->mapas[4].numTorretas = 3;
    for (int i = 0; i < g->mapas[4].numTorretas; i++){
        g->mapas[4].torretas[0].torreta = (Rectangle){615,295,STD_TURRET_SIZE,STD_TURRET_SIZE};
        g->mapas[4].torretas[0].direcaoTiro = 'd';

        g->mapas[4].torretas[1].torreta = (Rectangle){850,580,STD_TURRET_SIZE,STD_TURRET_SIZE};
        g->mapas[4].torretas[1].direcaoTiro = 'u';

        g->mapas[4].torretas[2].torreta = (Rectangle){1100,295,STD_TURRET_SIZE,STD_TURRET_SIZE};
        g->mapas[4].torretas[2].direcaoTiro = 'd';

        g->mapas[4].torretas[i].cor = BLACK;
        g->mapas[4].torretas[i].timeFrames = 5;
        g->mapas[4].torretas[i].projetilTorreta.ativo = false;
        g->mapas[4].torretas[i].projetilTorreta.direcaoTiro = g->mapas[4].torretas[i].direcaoTiro;
        g->mapas[4].torretas[i].projetilTorreta.qtdeTiros = 1;
        g->mapas[4].torretas[i].projetilTorreta.velocidadeTiro = STD_SHOT_SPEED;
        g->mapas[4].torretas[i].projetilTorreta.tiro.height = STD_TURRET_SHOT_HEIGHT;
        g->mapas[4].torretas[i].projetilTorreta.tiro.width = STD_TURRET_SHOT_WIDTH;
    }
    
    
    
    g->mapas[4].numInimigos = 3;    
    for (int i = 0; i < g->mapas[4].numInimigos; i++){
        //Inicializando o inimigo
        g->mapas[4].inimigos[0].inimigo = (Rectangle){110, 660, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};
        g->mapas[4].inimigos[1].inimigo = (Rectangle){550, 330, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};
        g->mapas[4].inimigos[2].inimigo = (Rectangle){1300, 150, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};

        g->mapas[4].inimigos[i].cor = BLACK;
        g->mapas[4].inimigos[i].velocidade = STD_SPEED;
        g->mapas[4].inimigos[i].direcao = KEY_RIGHT + (rand() % 4);
        g->mapas[4].inimigos[i].desenhaInimigo = true;
        //Inicializando o tiro do inimigo
        g->mapas[4].inimigos[i].projetilInimigo.ativo = false;
        g->mapas[4].inimigos[i].projetilInimigo.direcaoTiro = ' ';
        g->mapas[4].inimigos[i].projetilInimigo.qtdeTiros = 1;
        g->mapas[4].inimigos[i].projetilInimigo.velocidadeTiro = STD_SHOT_SPEED;
        g->mapas[4].inimigos[i].projetilInimigo.tiro.height = STD_SHOT_WIDTH;
        g->mapas[4].inimigos[i].projetilInimigo.tiro.width = STD_SHOT_HEIGHT;
    }
}

void mapa5Setup(Game *g){
    g->mapas[5].numeroParedes = 6;
    g->mapas[5].paredes[0] = (Rectangle){0, 330, 500, 10};
    g->mapas[5].paredes[1] = (Rectangle){500, 330, 10, 285};
    g->mapas[5].paredes[2] = (Rectangle){110, 610, 400, 10};
    g->mapas[5].paredes[3] = (Rectangle){120, 150, 570, 10};
    g->mapas[5].paredes[4] = (Rectangle){690, 150, 10, 580};
    g->mapas[5].paredes[5] = (Rectangle){810, 0, 10, 580};

    g->mapas[5].porta = (Rectangle){g->larguraTela - (BORDA + 5), 110, STD_DOOR_WIDTH, STD_DOOR_HEIGHT};
    g->mapas[5].portaAnterior = (Rectangle){BORDA, 190, STD_DOOR_WIDTH, STD_DOOR_HEIGHT};
    g->mapas[5].portaTrancada = true;
    g->mapas[5].chave = (Rectangle){70, 400, STD_KEY_SIZE, STD_KEY_SIZE};
    g->mapas[5].desenhaChave = true;
    g->mapas[5].startPosition[0] = (BORDA + 5) + 60;
    g->mapas[5].startPosition[1] = 190;
    g->mapas[5].backPosition[0] = g->larguraTela-BORDA + 5 - 60;
    g->mapas[5].backPosition[1] = 100;
    g->mapas[5].tamanhoQuadrado = STD_QUADRADO_SIZE;

    g->mapas[5].numTorretas = 3;
    for (int i = 0; i < g->mapas[5].numTorretas; i++){
        g->mapas[5].torretas[0].torreta = (Rectangle){350,435,STD_TURRET_SIZE,STD_TURRET_SIZE};
        g->mapas[5].torretas[0].direcaoTiro = 'l';

        g->mapas[5].torretas[1].torreta = (Rectangle){820,0,STD_TURRET_SIZE,STD_TURRET_SIZE};
        g->mapas[5].torretas[1].direcaoTiro = 'd';

        g->mapas[5].torretas[2].torreta = (Rectangle){1040,0,STD_TURRET_SIZE,STD_TURRET_SIZE};
        g->mapas[5].torretas[2].direcaoTiro = 'd';

        g->mapas[5].torretas[i].cor = BLACK;
        g->mapas[5].torretas[i].timeFrames = 5;
        g->mapas[5].torretas[i].projetilTorreta.ativo = false;
        g->mapas[5].torretas[i].projetilTorreta.direcaoTiro = g->mapas[4].torretas[i].direcaoTiro;
        g->mapas[5].torretas[i].projetilTorreta.qtdeTiros = 1;
        g->mapas[5].torretas[i].projetilTorreta.velocidadeTiro = STD_SHOT_SPEED;
        g->mapas[5].torretas[i].projetilTorreta.tiro.height = STD_TURRET_SHOT_HEIGHT;
        g->mapas[5].torretas[i].projetilTorreta.tiro.width = STD_TURRET_SHOT_WIDTH;
    }
    
    
    
    g->mapas[5].numInimigos = 5;    
    for (int i = 0; i < g->mapas[5].numInimigos; i++){
        //Inicializando o inimigo
        g->mapas[5].inimigos[0].inimigo = (Rectangle){515, 440, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};
        g->mapas[5].inimigos[1].inimigo = (Rectangle){345, 80, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};
        g->mapas[5].inimigos[2].inimigo = (Rectangle){1300, 150, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};
        g->mapas[5].inimigos[3].inimigo = (Rectangle){1300, 150, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};
        g->mapas[5].inimigos[4].inimigo = (Rectangle){1300, 400, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};


        g->mapas[5].inimigos[i].cor = BLACK;
        g->mapas[5].inimigos[i].velocidade = STD_SPEED;
        g->mapas[5].inimigos[i].direcao = KEY_RIGHT + (rand() % 4);
        g->mapas[5].inimigos[i].desenhaInimigo = true;
        //Inicializando o tiro do inimigo
        g->mapas[5].inimigos[i].projetilInimigo.ativo = false;
        g->mapas[5].inimigos[i].projetilInimigo.direcaoTiro = ' ';
        g->mapas[5].inimigos[i].projetilInimigo.qtdeTiros = 1;
        g->mapas[5].inimigos[i].projetilInimigo.velocidadeTiro = STD_SHOT_SPEED;
        g->mapas[5].inimigos[i].projetilInimigo.tiro.height = STD_SHOT_WIDTH;
        g->mapas[5].inimigos[i].projetilInimigo.tiro.width = STD_SHOT_HEIGHT;
    }
}

void mapa6Setup(Game *g){
    g->mapas[6].numeroParedes = 15;
    g->mapas[6].paredes[0] = (Rectangle){0, 120, 220, 10};
    g->mapas[6].paredes[1] = (Rectangle){0, 260, 200, 10};
    g->mapas[6].paredes[2] = (Rectangle){360, 0, 10, 640};
    g->mapas[6].paredes[3] = (Rectangle){0, 260, 175, 500};
    g->mapas[6].paredes[4] = (Rectangle){175, 260, 80, 80};
    g->mapas[6].paredes[5] = (Rectangle){175, 440, 80, 80};
    g->mapas[6].paredes[6] = (Rectangle){175, 610, 80, 180};
    g->mapas[6].paredes[7] = (Rectangle){325, 260, 35, 380};
    g->mapas[6].paredes[8] = (Rectangle){605, 260, 10, 520};
    g->mapas[6].paredes[9] = (Rectangle){370, 360, 80, 50};
    g->mapas[6].paredes[10] = (Rectangle){530, 360, 80, 50};
    g->mapas[6].paredes[11] = (Rectangle){955, 260, 10, 520};
    g->mapas[6].paredes[12] = (Rectangle){360, 0, 70, 150};
    g->mapas[6].paredes[13] = (Rectangle){540, 0, 200, 150};


    g->mapas[6].porta = (Rectangle){g->larguraTela - (BORDA + 5), 455, STD_DOOR_WIDTH, STD_DOOR_HEIGHT};
    g->mapas[6].portaAnterior = (Rectangle){BORDA, 140, STD_DOOR_WIDTH, STD_DOOR_HEIGHT};
    g->mapas[6].portaTrancada = true;
    g->mapas[6].chave = (Rectangle){800, 600, STD_KEY_SIZE, STD_KEY_SIZE};
    g->mapas[6].desenhaChave = true;
    g->mapas[6].startPosition[0] = (BORDA + 5) + 60;
    g->mapas[6].startPosition[1] = 150;
    g->mapas[6].backPosition[0] = g->larguraTela-BORDA + 5 - 60;
    g->mapas[6].backPosition[1] = 460;
    g->mapas[6].tamanhoQuadrado = STD_QUADRADO_SIZE;

    g->mapas[6].numTorretas = 3;
    for (int i = 0; i < g->mapas[5].numTorretas; i++){
        g->mapas[6].torretas[0].torreta = (Rectangle){210,0,STD_TURRET_SIZE,STD_TURRET_SIZE};
        g->mapas[6].torretas[0].direcaoTiro = 'd';

        g->mapas[6].torretas[1].torreta = (Rectangle){430,0,STD_TURRET_SIZE,STD_TURRET_SIZE};
        g->mapas[6].torretas[1].direcaoTiro = 'd';

        g->mapas[6].torretas[2].torreta = (Rectangle){730,0,STD_TURRET_SIZE,STD_TURRET_SIZE};
        g->mapas[6].torretas[2].direcaoTiro = 'd';

        g->mapas[6].torretas[i].cor = BLACK;
        g->mapas[6].torretas[i].timeFrames = 5;
        g->mapas[6].torretas[i].projetilTorreta.ativo = false;
        g->mapas[6].torretas[i].projetilTorreta.direcaoTiro = g->mapas[4].torretas[i].direcaoTiro;
        g->mapas[6].torretas[i].projetilTorreta.qtdeTiros = 1;
        g->mapas[6].torretas[i].projetilTorreta.velocidadeTiro = STD_SHOT_SPEED;
        g->mapas[6].torretas[i].projetilTorreta.tiro.height = STD_TURRET_SHOT_HEIGHT;
        g->mapas[6].torretas[i].projetilTorreta.tiro.width = STD_TURRET_SHOT_WIDTH;
    }
    
    
    
    g->mapas[6].numInimigos = 5;    
    for (int i = 0; i < g->mapas[6].numInimigos; i++){
        //Inicializando o inimigo
        g->mapas[6].inimigos[0].inimigo = (Rectangle){330, 640, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};
        g->mapas[6].inimigos[1].inimigo = (Rectangle){615, 400, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};
        g->mapas[6].inimigos[2].inimigo = (Rectangle){650, 650, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};
        g->mapas[6].inimigos[3].inimigo = (Rectangle){1200, 190, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};
        g->mapas[6].inimigos[4].inimigo = (Rectangle){1200, 500, STD_QUADRADO_SIZE,STD_QUADRADO_SIZE};

        g->mapas[6].inimigos[i].cor = BLACK;
        g->mapas[6].inimigos[i].velocidade = STD_SPEED;
        g->mapas[6].inimigos[i].direcao = KEY_RIGHT + (rand() % 4);
        g->mapas[6].inimigos[i].desenhaInimigo = true;
        //Inicializando o tiro do inimigo
        g->mapas[6].inimigos[i].projetilInimigo.ativo = false;
        g->mapas[6].inimigos[i].projetilInimigo.direcaoTiro = ' ';
        g->mapas[6].inimigos[i].projetilInimigo.qtdeTiros = 1;
        g->mapas[6].inimigos[i].projetilInimigo.velocidadeTiro = STD_SHOT_SPEED;
        g->mapas[6].inimigos[i].projetilInimigo.tiro.height = STD_SHOT_WIDTH;
        g->mapas[6].inimigos[i].projetilInimigo.tiro.width = STD_SHOT_HEIGHT;
    }
}


/*void mapa7Setup(Game *g){
    g->mapas[7].portaAnterior = (Rectangle){BORDA, 250, STD_DOOR_WIDTH, STD_DOOR_HEIGHT};
    g->mapas[7].startPosition[0] = (BORDA + 5) + 60;
    g->mapas[7].startPosition[1] = 50;
    g->mapas[7].tamanhoQuadrado = STD_QUADRADO_SIZE;

    g->mapas[7].chefe.chefe = (Rectangle){1100,360,50,50};
    g->mapas[7].chefe.cor = BLACK;
    g->mapas[7].chefe.velocidade = STD_SPEED;
    g->mapas[7].chefe.velocidade = KEY_RIGHT + (rand() % 4);
    g->mapas[7].chefe.desenhaChefe = true;
    g->mapas[7].chefe.vida = 0;

}*/