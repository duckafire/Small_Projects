#include <SDL.h>
#include <string.h>

#include "defs.h"
#include "struct.h"

int aabb(Bull *bul, Ship *ship){
	return MAX(bul->x, ship->x) < MIN(bul->x + bul->dim, ship->x + ship->dim) &&
		   MAX(bul->y, ship->y) < MIN(bul->y + bul->dim, ship->y + ship->dim);
}

int hitShip(Bull *bul){
	Ship *ship;
	
	for(ship = head.ship.next; ship != NULL; ship = ship->next){
		if(ship->isEnemy != bul->isEnemy && aabb(bul, ship)){
			
			ship->hp = (ship->hp - 1 > 0 ? ship->hp - 1 : 0);
			
			if(ship != player) newExplosion(ship->x, ship->y, rand() % 3 + 1);
			
			return 1;
		}
	}
	
	return 0;
}

int movePlayer(int nPos, int dir, int mm){
	// update parameter value
	nPos += player->spd * dir;
	
	// lessing position (top or left)
	if(mm != 0) return (nPos + player->dim <= mm ? nPos : mm - player->dim);
	
	// adding position (below or right)
	return (nPos >= mm ? nPos : mm);
}

void setLifebar(Ship *ship){
	ship->lifebar.x = ship->x;
	ship->lifebar.y = ship->y - 15;
	ship->lifebar.w = ship->dim;
	ship->lifebar.h = 8;
}

