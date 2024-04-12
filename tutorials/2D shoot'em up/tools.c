#include <SDL.h>
#include <string.h>

#include "defs.h"
#include "struct.h"

int aabb(Bull *bul, Ship *ship){
	return MAX(bul->x, ship->x) < MIN(bul->x + bul->dim, ship->x + ship->dim) &&
		   MAX(bul->y, ship->y) < MIN(bul->y + bul->dim, ship->y + ship->dim);
}

int hitShip(Bull *bul){
	Ship *ene;
	
	for(ene = head.ship.next; ene != NULL; ene = ene->next){
		if(ene->isEnemy != bul->isEnemy && aabb(bul, ene)){
			ene->hp = (ene->hp - 1 > 0 ? ene->hp - 1 : 0);
			return 1;
		}
	}
	
	return 0;
}

void memAlloc(Ship **ship, Bull **bull){
	// alloc space in memory to the adress of the pointer used like argument
	// update the last object pointed by TAIL (1th is HEAD)
	// update TAIL value (adress)
	// clear memory trash in space allocated
	
	if(ship != NULL){
		*ship = malloc(sizeof(Ship));
		memset(*ship, 0, sizeof(Ship));
		tail.ship->next = *ship;
		tail.ship = *ship;
		
	}else{
		*bull = malloc(sizeof(Bull));
		memset(*bull, 0, sizeof(Bull));
		tail.bull->next = *bull;
		tail.bull = *bull;
	}
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

