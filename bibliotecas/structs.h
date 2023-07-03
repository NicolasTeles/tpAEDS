#include "../raylib.h"
#include "STD_DEFINES.h"

typedef struct quadrado{
    /*int tamanho;
    int posi_x;
    int posi_y;*/
    char direcaoQuadrado;
    short int velocidade;
    Rectangle player;
} Quadrado;

typedef struct projectile{
    Rectangle tiro;
    /*int tamanho_x;
    int tamanho_y;
    int posi_x;
    int posi_y;*/
    bool ativo;
    int qtdeTiros;
    char direcaoTiro;
    short int velocidadeTiro;
} Projectile;

typedef struct projetilInimigo{
    Rectangle tiro;
    /*int tamanho_x;
    int tamanho_y;
    int posi_x;
    int posi_y;*/
    bool ativo;
    int qtdeTiros;
    char direcaoTiro;
    short int velocidadeTiro;
} ProjetilInimigo;

typedef struct enemy{
    Rectangle inimigo;
    Color cor;
    int velocidade;
    int direcao;
    bool desenhaInimigo;
    char direcaoTiroInimigo;
    ProjetilInimigo projetilInimigo;
} Enemy;

typedef struct turret{
    Rectangle torreta;
    Color cor;
    int direcaoTiro;
    int timeFrames;
    ProjetilInimigo projetilTorreta;
}Turret;

typedef struct boss
{
    Rectangle chefe;
    Color cor;
    int velocidade;
    bool desenhaChefe;
    int direcao;
    int vida;

} Boss;


typedef struct mapa{
    short int numeroParedes;
    Rectangle paredes[15];

    Color cor;
    
    Rectangle portaAnterior;
    Rectangle porta;
    bool portaTrancada;
    Rectangle chave;
    bool desenhaChave;

    Enemy inimigos[10];
    int numInimigos;
    
    Turret torretas[10];
    int numTorretas;

    Boss chefe;

    //pos 0 do vetor = x, pos 1 = y
    int startPosition[2];
    int backPosition[2];

    int tamanhoQuadrado;
    bool voltouMapa;
}Mapa;

typedef struct game{
    short int numeroMapas;
    Mapa mapas[10];
    short int mapaAtual;
    
    int larguraTela;
    int alturaTela;   
     
    Quadrado quadrado;
    Projectile projectile;
    Rectangle parede;

    bool gameover;
    bool venceu;
} Game;