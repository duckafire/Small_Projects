#include <stdio.h> // printf ; getchar
#include <stddef.h>

int main(){
	
	union     dog{ int age; float height; char name[25]; };
	typedef union{ int age; float height; char name[25]; }defDog;
	
	struct     man{ int age; float height; char name[25]; union dog pet; };
	typedef struct{ int age; float height; char name[25];    defDog pet; }defMan;
	
	typedef struct{ int age; float height; char name[25]; struct pet{ int age; float height; char name[25]; }pet; }finalMan;
	
	printf("[ CONSOLE ]\n\n");
	
	printf("%d - ", offsetof(defDog,     name));
	printf("%d\n\n", offsetof(union dog,  name));
	
	printf("%d - ", offsetof(struct man, name));
	printf("%d\n\n", offsetof(defMan,     name));
	
	printf("%d - ", offsetof(struct man, pet.name ));
	printf("%d\n\n", offsetof(defMan,     pet.name));
	
	printf("%d\n", offsetof(finalMan,   pet.name));
	
	printf("\n\n[ Press ENTER ]"); // paused
	getchar();
	return 0;
}