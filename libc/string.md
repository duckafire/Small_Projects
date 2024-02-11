# string
Simplifica a manipulação de cadeias de caracteres (`strings`).

<br>

-----
<br>

1. void *memchr(const void *str, int c, size_t n);
	* *str: Um vetor de caracteres ou uma string. | c: Um caractere para "pesquisa/buscar". | n: A quantidade máxima de caracteres que serão verificados.
	* Usos: Compara todos os caracteres dentro do `*str` com `c`.
	* Retorno: Caso seja encontrado um caracter igual, retornará um ponteiro para uma string que irá do caracter igual até o último caracter da string, caso não seja, retornará ´NULL´.
	
``` c
int main(){
	
	char str[13] = "Hello World";
	char *p = memchr(str, 'W', 10); // pointer (p = "World")
	
	return 0;
}
```

<br>

-----
<br>

2. int memcmp(const void *str1, const void *str2, size_t n);
	* *str1: Um vetor de caracteres ou uma string. | *str2: Um vetor de caracteres ou um string. | n: A quantidade máxima de caracteres que serão comparados.
	* Usos: Compara o valor em byte dos primeiros `n` caracteres de duas cadeiras de caracteres. A comparação NÃO é encerada quando um terminador da string (`\0`) é encontrado.
	* Retorno: 0 se forem iguais, valor negativo se `str1` for menor que `str2`, ou valor positivo se `str1` for maior que `str2`.
	
``` c
int main(){
	
	char str[6][4] = {"AAu", "bbv", "ccw", "aax", "bby", "CCz"};
	printf("%d\n", memcmp(str[0], str[3], 2)); // (65+65 <  97+97) - <0
	printf("%d\n", memcmp(str[1], str[4], 2)); // (98+98 == 98+98) -  0
	printf("%d\n", memcmp(str[2], str[5], 2)); // (99+99 >  67+67) - >0
	// u = 117 ; ... ; z = 122
	
	char lmt[6][5] = {"AA\0!", "BB\0!", "CC\0!", "AA\0z", "BB\0z", "CC\0z"}; // stop in "\0"
	printf("%d\n", memcmp(lmt[0], lmt[3], 5)); // (97+97+\0+32 < 97+97+\0+122) - <0
	printf("%d\n", memcmp(lmt[1], lmt[4], 5)); // (98+98+\0+32 < 98+98+\0+122) - <0
	printf("%d\n", memcmp(lmt[2], lmt[5], 5)); // (99+99+\0+32 < 99+99+\0+122) - <0
	// ! = 33
	
	return 0;
}
```

<br>

-----
<br>

3. void *memcpy(void *dest, const void *src, size_t n);
	* *dest: Um vetor de caracteres. | *src: Uma string ou um vetor de caracteres | n: A quantidade máxima de caracteres que serão copiados.
	* Usos: Copia (ou substinui) os primeira `n` caracteres do primeira vetor pelos primeiros `n` caracteres do segundo vetor (ou string). Não trata corretamente caracteres nulos e pode estourar o limite de caracteres de `*dest`. É incapaz de evitar a sobreposição de memória.
	* Função: A nova string presente no primeiro vetor. 
	
``` c
int main(){
	
	char str[7] = "abcdef";
	memcpy(str, "ABC", 3); // str = "ABCdef"
	
	return 0;
}
```

<br>

-----
<br>

4. void *memmove(void *dest, const void *src, size_t n);
	* *dest: Um vetor de caracteres. | *src: Uma string ou um vetor de caracteres | n: A quantidade máxima de caracteres que serão copiados.
	* Usos: Copia (ou substinui) os primeira `n` caracteres do primeira vetor pelos primeiros `n` caracteres do segundo vetor (ou string). Não trata corretamente caracteres nulos e pode estourar o limite de caracteres de `*dest`. Consegue evitar a sobreposição de memória.
	* Função: A nova string presente no primeiro vetor. 
	
``` c
int main(){
	
	char str[7] = "abcdef";
	memmove(str, "ABC", 3); // str = "ABCdef"
	
	return 0;
}
```

<br>

-----
<br>

5. void *memset(void *str, int c, size_t n);
	* *str: Um vetor de caracteres. | c: Um caractere implantar no vetor. | n: O número de caracteres que será alterado/substituído.
	* Uso: Substitui os primeiros `n` caracteres por `c`.
	* Retorno: A nova string presente no primeiro vetor. 
	
``` c
int main(){
	
	char str[13] = "Hello World!";
	memset(str, 'X', 5);           // str = "XXXXX World!"
	
	return 0;
}
```

<br>

-----
<br>

6. char *strcat(char *dest, const char *src);
	* *dest: Um vetor de caracteres. | *src: Uma string ou um vetor de caracteres.
	* Usos: Concatena o segundo vetor (ou string) com o primeiro.
	* Retorno: A nova string presente no primeiro vetor.
	
``` c
int main(){
	
	char str1[7] = "Hello ";
	char str2[7] = "World!";
	strcat(str1, str2);      // str1 = "Hello World!"
	
	return 0;
}
```

<br>

-----
<br>

7. char *strncat(char *dest, const char *src, size_t n)
	* *dest: Um vetor de caracteres. | *src: Uma string ou um vetor de caracteres. | n: A quantidade de caracteres.
	* Usos: Concatena o segundo vetor (ou string) com o primeiro.
	* Retorno:  A nova string presente no primeiro vetor.
	
``` c
int main(){
	
	char str1[7] = "Numbers: ";
	strncat(str1, "123456789", 4); // str1 = "Numbers: 1234"
	
	return 0;
}
```

<br>

-----
<br>

8. char *strchr(const char *str, int c);
	* 0
	* 0
	
``` c
int main(){
	
	return 0;
}
```

<br>

-----
<br>

9. int strcmp(const char *str1, const char *str2);
	* *str1: Um vetor de caracteres ou uma string. | *str2: Um vetor de caracteres ou uma string.
	* Usos: Compara o valor ASCII de duas cadeiras de caracteres.
	* Retorno: 0 se forem iguais, valor negativo se `str1` for menor que `str2`, ou valor positivo se `str1` for maior que `str2`.
	
``` c
int main(){
	
	strcmp("A", "a"); // (65 <  97) - <0
	strcmp("b", "b"); // (98 == 98) -  0
	strcmp("c", "C"); // (99 >  67) - >0
	
	return 0;
}
```

<br>

-----
<br>

10. int strncmp(const char *str1, const char *str2, size_t);
	* *str1: Um vetor de caracteres ou uma string. | *str2: Um vetor de caracteres ou uma string. | n: A quantidade máxima de caracteres que serão comparados.
	* Usos: Compara o valor ASCII dos primeiros `n` caracteres de duas cadeiras de caracteres. A comparação é encerada quando um terminador da string (`\0`) é encontrado.
	* Retorno: 0 se forem iguais, <0 se `str1` for menor que `str2`, ou 0> se `str1` for maior que `str2`.
	
``` c
int main(){
	
	char str[6][4] = {"AAu", "bbv", "ccw", "aax", "bby", "CCz"};
	printf("%d\n", strncmp(str[0], str[3], 2)); // (65+65 <  97+97) - <0
	printf("%d\n", strncmp(str[1], str[4], 2)); // (98+98 == 98+98) -  0
	printf("%d\n", strncmp(str[2], str[5], 2)); // (99+99 >  67+67) - >0
	// u = 117 ; ... ; z = 122
	
	char lmt[6][5] = {"AA\0!", "BB\0!", "CC\0!", "AA\0z", "BB\0z", "CC\0z"}; // stop in "\0"
	printf("%d\n", strncmp(lmt[0], lmt[3], 5)); // (97+97 == 97+97) - 0
	printf("%d\n", strncmp(lmt[1], lmt[4], 5)); // (98+98 == 98+98) - 0
	printf("%d\n", strncmp(lmt[2], lmt[5], 5)); // (99+99 == 99+99) - 0
	// ! = 33
	
	return 0;
}
```

<br>

-----
<br>

11. int strcoll(const char *str1, const char *str2);
	* 0
	* 0
	
``` c
int main(){
	
	return 0;
}
```

<br>

-----
<br>

12. char *strcpy(char *dest, const char *src);
	* *dest: Um vetor de caracteres. | *src: Uma string ou um vetor de caracteres.
	* Usos: Copia todo o conteúdo do segundo vetor (ou string) para dentro do primeiro vetor, substituindo todo o seu conteúdo anterior no processo.
	* Função: A nova string presente no primeiro vetor.
	
``` c
int main(){
	
	char str[4] = "One";
	strcpy(str, "Two");  // str = "Two"
	
	return 0;
}
```

<br>

-----
<br>

13. char *strncpy(char *dest, const char *src, size_t n);
	* *dest: Um vetor de caracteres. | *src: Uma string ou um vetor de caracteres | n: A quantidade máxima de caracteres que serão copiados.
	* Usos: Copia (ou substinui) os primeira `n` caracteres do primeira vetor pelos primeiros `n` caracteres do segundo vetor (ou string). Adiciona `\0` a espaços vazios em `*dest` (caso existam) e respeita seu limite de caracteres (não o estoura).
	* Função: A nova string presente no primeiro vetor. 
	
``` c
int main(){
	
	char str[7] = "abcdef";
	strncpy(str, "ABC", 3); // str = "ABCdef"
	
	return 0;
}
```

<br>

-----
<br>

14. size_t strcspn(const char *str1, const char *str2);
	* 0
	* 0
	
``` c
int main(){
	
	return 0;
}
```

<br>

-----
<br>

15. char *strerror(int errnum);
	* 0
	* 0
	
``` c
int main(){
	
	return 0;
}
```

<br>

-----
<br>

16. size_t strlen(const char *str);
	* *str: Um vetor de caracteres ou uma string.
	* Usos: Calcula a quantidade de caracteres que o vetor especificado possui.
	* Retorna: A quantidade de caracteres.
	
``` c
int main(){
	
	char str[50] = "Hello World!";
	strlen(str);				   // 12
	
	return 0;
}
```

<br>

-----
<br>

17. char strpbrk(const char *str1, const char str2);
	*
	*
	
``` c
int main(){
	
	return 0;
}
```

<br>

-----
<br>

18. char *strrchr(const char *str, int c);
	*
	*
	
``` c
int main(){
	
	return 0;
}
```

<br>

-----
<br>

19. size_t strspn(const char *str1, const char *str2);
	*
	*
	
``` c
int main(){
	
	return 0;
}
```

<br>

-----
<br>

20. char *strstr(const char *haytack, const char *needle);
	*
	*
	
``` c
int main(){
	
	return 0;
}
```

<br>

-----
<br>

21. char *strtok(char *str, const char *delim);
	*
	*
	
``` c
int main(){
	
	return 0;
}
```

<br>

-----
<br>

22. size_t strxfrm(char *dest, const char *src, size_t n);
	*
	*
	
``` c
int main(){
	
	return 0;
}
```

<br>

-----
<br>

#### Fonte:
* https://linguagemc.com.br/a-biblioteca-string-h/
* https://www.tutorialspoint.com/c_standard_library/string_h.htm
* https://bytes.com/topic/c/answers/485925-difference-between-memcmp-strncmp-functions
* https://stackoverflow.com/questions/38687630/the-use-of-strncmp-and-memcmp
* https://www.equestionanswers.com/c/memcpy-vs-memmove.php

<br>

-----