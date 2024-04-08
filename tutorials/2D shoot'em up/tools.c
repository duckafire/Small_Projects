#include <SDL.h>
#include <string.h>

#include "defs.h"
#include "struct.h"

int aabb(struct Entity *bul, struct Entity *ship){
	return MAX(bul->x, ship->x) < MIN(bul->x + bul->dim, ship->x + ship->dim) &&
		   MAX(bul->y, ship->y) < MIN(bul->y + bul->dim, ship->y + ship->dim);
}

int hitShip(struct Entity *bul){
	struct Entity *ene;
	
	for(ene = app.shipHead.next; ene != NULL; ene = ene->next){
		if(ene->isEnemy != bul->isEnemy && aabb(bul, ene)){
			bul->hp = 0;
			ene->hp = (ene->hp - 1 > 0 ? ene->hp - 1 : 0);
			return 1;
		}
	}
	
	return 0;
}

void memAlloc(struct Entity **obj, short isShip){
	// alloc space in memory to the adress of the pointer used like argument
	*obj = malloc(sizeof(struct Entity));
	
	// clear memory trash in space allocated
	memset(*obj, 0, sizeof(struct Entity));
	
	// update the last object pointed by TAIL (1th is HEAD)
	// update TAIL value (adress)
	if(isShip){
		app.shipTail->next = *obj;
		app.shipTail = *obj;
		
	}else{
		app.projTail->next = *obj;
		app.projTail = *obj;	
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

