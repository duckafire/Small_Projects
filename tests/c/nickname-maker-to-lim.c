#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *nick = NULL;

void nick_init(void);
static void nick_upChar(long id);
static void nick_upAll(long last);
void nick_up(void);
char *nick_get(void);
void nick_end(void);

void nick_init(void){
	nick = malloc(sizeof(char) * 2);
	nick[0] = 'A';
	nick[1] = '\0';
}

static void nick_upChar(long id){
	if(nick[id] == '_'){
		nick[id] = 'M';
		return;
	}

	nick[id] += 1;

	if(nick[id] == 'L')
		nick[id] = '_';
}

static void nick_upAll(long last){
	if(last > -1){
		if(nick[last] == 'Z'){
			nick[last] = 'A';
			nick_upAll(last - 1);
			return;
		}

		nick_upChar(last);
		return;
	}

	char *buf;
	buf = nick;

	last = strlen(nick) + 1;
	nick = malloc(last);
	
	nick[0] = 'A';
	strcat(nick, buf);
	free(buf);
}

void nick_up(void){
	nick_upAll( strlen(nick) - 1 );
}

char *nick_get(void){
	return nick;
}

void nick_end(void){
	free(nick);
	nick = NULL;
}

int main(void){
	nick_init();
	for(short i = 0; i < 1000; i++){
		printf("%s\n", nick_get());
		nick_up();
	}

	printf("\n%s\n", nick_get());
	nick_end();
	return 0;
}
