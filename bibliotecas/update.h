#include "draw.h"

void updateGame(Game *);
bool checkCollision(Game *, Rectangle *);
void atira(Game *);
void atiraInimigo(Game *, Enemy *);
bool colisaoParede(Mapa *, Rectangle *);
bool colisaoTorreta(Mapa *, Rectangle *);
void movimentoInimigo(Game *, Enemy *);
void movimentoPlayer(Game *);
void movimentoChefe(Game *, Boss *);
void destroiInimigo(Game *);
void atiraTorreta(Game *, Turret *);