#include <SDL.h>
#include <string.h>

#include "defs.h"
#include "struct.h"

int aabb(Bull *bul, Ship *ship, Ship *ene){
	if(bul != NULL){
		return MAX(bul->x, ship->x) < MIN(bul->x + bul->dim, ship->x + ship->dim) &&
			   MAX(bul->y, ship->y) < MIN(bul->y + bul->dim, ship->y + ship->dim);
	}
	return MAX(ene->x, ship->x) < MIN(ene->x + ene->dim, ship->x + ship->dim) &&
		   MAX(ene->y, ship->y) < MIN(ene->y + ene->dim, ship->y + ship->dim);
}

int hitShip(Bull *bul){
	Ship *ship;
	
	for(ship = head.ship.next; ship != NULL; ship = ship->next){
		if(ship->isEnemy != bul->isEnemy && aabb(bul, ship, NULL) && ship->hp > 0){
			
			if(ship->hp - 1 > 0){
				ship->hp -= 1;
				newExplosion(ship->x, ship->y, rand() % 3 + 2);
				return 1;
			}
			
			ship->hp = 0;
			newDebris(ship);
			newExplosion(ship->x, ship->y, rand() % 10 + 6);
			return 1;
		}
	}
	
	return 0;
}

int movePlayer(int nPos, int dir, int mm){
	// update parameter value
	nPos += player->spd * dir;
	
	// lessing position (top or left)
	if(mm != 0 && mm != GAME_UI_HEIGHT) return (nPos + player->dim <= mm ? nPos : mm - player->dim);
	
	// adding position (below or right)
	return (nPos >= mm ? nPos : mm);
}

void setLifebar(Ship *ship){
	ship->lifebar.x = ship->x;
	ship->lifebar.y = ship->y - 8;
	ship->lifebar.w = ship->dim;
	ship->lifebar.h = 5;
}

