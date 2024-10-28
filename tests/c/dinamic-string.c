#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////
#define dstring char*
#define TOCHAR (char*)
#define UNINT unsigned int

dstring dstr_init(void);
void dstr_addc(dstring *dstr, char c);
void dstr_copy(dstring dest, const char *src);
void dstr_merge(dstring *dest, const char *src);
void dstr_end(dstring *dstr);
////////////////////////////

dstring dstr_init(void){
	dstring temp;

	temp = malloc(1);
	temp[0] = '\0';

	return temp;
}

void dstr_addc(dstring *dstr, char c){
	UNINT len = strlen(TOCHAR *dstr) + 3;

	dstring temp;
	temp = malloc(len);

	memset(temp, '\0', len);
	strcpy(TOCHAR temp, TOCHAR *dstr);
	temp[len - 3] = c;

	free(*dstr);
	*dstr = temp;
}

void dstr_copy(dstring dest, const char *src){
	free(dest);

	dest = malloc(strlen(src) + 1);

	strcpy(TOCHAR dest, src);
}

void dstr_merge(dstring *dest, const char *src){
	UNINT len = strlen(TOCHAR *dest) + 1;
	UNINT totalLen = len + strlen(src);

	dstring old;
	old = malloc(len);
	memset(old, '\0', len);
	strcpy(TOCHAR old, TOCHAR *dest);

	dstring new;
	new = malloc(totalLen);
	memset(new, '\0', totalLen);

	UNINT id = 0;
	for(short i = 0; i < totalLen; i++){
		if(i < len - 1){
			new[i] = old[i];
			continue;
		}
		new[i] = src[id++];
	}

	free(old);
	free(*dest);
	*dest = new;
}

void dstr_end(dstring *dstr){
	free(*dstr);
	*dstr = NULL;
}

// TEST
int main(){
	dstring test = dstr_init();

	for(char c = 'A'; c < 'D'; c++){
		dstr_addc(&test, c);
		printf("%s\n", test);
	}

	putchar('\n');

	dstr_copy(test, "Hello world");
	printf("%s\n", test);

	dstr_addc(&test, '!');
	printf("%s\n", test);

	dstr_merge(&test, " Parte II");
	printf("%s\n", test);

	dstr_end(&test);
	return 0;
}
