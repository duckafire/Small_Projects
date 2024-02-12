# string
Simplifica a manipulação de cadeias de caracteres (`strings`).

## Funções
* [memchr](#1)
* [memcmp](#2)
* [memcpy](#3)
* [memmove](#4)
* [memset](#5)
* [strcat](#6)
* [strncat](#7)
* [strchr](#8)
* [strcmp](#9)
* [strncmp](#10)
* [strcoll](#11)
* [strcpy](#12)
* [strncpy](#13)
* [strcspn](#14)
* [strerror](#15)
* [strlen](#16)
* [strpbrk](#17)
* [strrchr](#18)
* [strspn](#19)
* [strstr](#20)
* [strtok](#21)
* [strxfrm](#22)

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

##### 1
* void *memchr(const void *str, int c, size_t n);
	* *str: Um vetor de caracteres ou uma string. | c: Um caractere para "pesquisa/buscar". | n: A quantidade máxima de caracteres que serão verificados.
	* Usos: Compara todos os caracteres dentro do `*str` com `c`. NÃO irá parar ao encontrar um `\0`.
	* Retorno: Caso seja encontrado um caracter igual a `c`, retornará um ponteiro para uma string que irá da primeira ocorrência deste caracter até o final da string, caso não seja, retornará ´NULL´.
	
``` c
int main(){
	
	char str[13] = "Hello World!";
	memchr(str, 'W', 13); // pointer ("World!")
	
	char str[14] = "Hello\0 World";
	memchr(str, 'W', 14); // pointer ("World!")
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

##### 2
* int memcmp(const void *str1, const void *str2, size_t n);
	* *str1: Um vetor de caracteres ou uma string. | *str2: Um vetor de caracteres ou um string. | n: A quantidade máxima de caracteres que serão comparados.
	* Usos: Compara o valor em byte dos primeiros `n` caracteres de duas cadeiras de caracteres. A comparação NÃO é encerada quando um terminador da string (`\0`) é encontrado.
	* Retorno: 0 se forem iguais, valor negativo se `str1` for menor que `str2`, ou valor positivo se `str1` for maior que `str2`.
	
``` c
int main(){
	
	char str[6][4] = {"AAu", "bbv", "ccw", "aax", "bby", "CCz"};
	memcmp(str[0], str[3], 2); // (65+65 <  97+97) - <0
	memcmp(str[1], str[4], 2); // (98+98 == 98+98) -  0
	memcmp(str[2], str[5], 2); // (99+99 >  67+67) - >0
	// u = 117 ; ... ; z = 122
	
	char lmt[6][5] = {"AA\0!", "BB\0!", "CC\0!", "AA\0z", "BB\0z", "CC\0z"}; // stop in "\0"
	memcmp(lmt[0], lmt[3], 5); // (97+97+\0+32 < 97+97+\0+122) - <0
	memcmp(lmt[1], lmt[4], 5); // (98+98+\0+32 < 98+98+\0+122) - <0
	memcmp(lmt[2], lmt[5], 5); // (99+99+\0+32 < 99+99+\0+122) - <0
	// ! = 33
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

##### 3
* void *memcpy(void *dest, const void *src, size_t n);
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
* ###### [Para o topo](#string)
-----
<br>

##### 4
* void *memmove(void *dest, const void *src, size_t n);
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
* ###### [Para o topo](#string)
-----
<br>

##### 5
* void *memset(void *str, int c, size_t n);
	* *str: Um vetor de caracteres. | c: Um caractere para implantar no vetor. | n: O número de caracteres que será alterado/substituído.
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
* ###### [Para o topo](#string)
-----
<br>

##### 6
* char *strcat(char *dest, const char *src);
	* *dest: Um vetor de caracteres. | *src: Uma string ou um vetor de caracteres.
	* Usos: Concatena o segundo vetor (ou string) com o primeiro.
	* Retorno: Um ponteiro para a nova string presente no primeiro vetor.
	
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
* ###### [Para o topo](#string)
-----
<br>

##### 7
* char *strncat(char *dest, const char *src, size_t n)
	* *dest: Um vetor de caracteres. | *src: Uma string ou um vetor de caracteres. | n: A quantidade de caracteres.
	* Usos: Concatena o segundo vetor (ou string) com o primeiro.
	* Retorno: Um ponteiro para a nova string presente no primeiro vetor.
	
``` c
int main(){
	
	char str1[7] = "Numbers: ";
	strncat(str1, "123456789", 4); // str1 = "Numbers: 1234"
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

##### 8
* char *strchr(const char *str, int c);
	* *str: Um vetor de caracteres ou uma string. | c: Um caractere para "pesquisa/buscar".
	* Usos: Compara todos os caracteres dentro do `*str` com `c`. Irá parar ao encontrar um `\0`.
	* Retorno: Caso seja encontrado um caracter igual a `c`, retornará um ponteiro para uma string que irá da primeira ocorrência deste caracter até o final da string, caso não seja, retornará ´NULL´.
	
``` c
int main(){
	
	char str1[13] = "Hello World!";
	strchr(str1, 'W');   // pointer ("World!")
	
	char str2[14] = "Hello\0 World!";
	strchr(str2, 'W');   // pointer (NULL)
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

##### 9
* int strcmp(const char *str1, const char *str2);
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
* ###### [Para o topo](#string)
-----
<br>

##### 10
* int strncmp(const char *str1, const char *str2, size_t);
	* *str1: Um vetor de caracteres ou uma string. | *str2: Um vetor de caracteres ou uma string. | n: A quantidade máxima de caracteres que serão comparados.
	* Usos: Compara o valor ASCII dos primeiros `n` caracteres de duas cadeiras de caracteres. A comparação é encerada quando um terminador da string (`\0`) é encontrado.
	* Retorno: 0 se forem iguais, <0 se `str1` for menor que `str2`, ou 0> se `str1` for maior que `str2`.
	
``` c
int main(){
	
	char str[6][4] = {"AAu", "bbv", "ccw", "aax", "bby", "CCz"};
	strncmp(str[0], str[3], 2); // (65+65 <  97+97) - <0
	strncmp(str[1], str[4], 2); // (98+98 == 98+98) -  0
	strncmp(str[2], str[5], 2); // (99+99 >  67+67) - >0
	// u = 117 ; ... ; z = 122
	
	char lmt[6][5] = {"AA\0!", "BB\0!", "CC\0!", "AA\0z", "BB\0z", "CC\0z"}; // stop in "\0"
	strncmp(lmt[0], lmt[3], 5); // (97+97 == 97+97) - 0
	strncmp(lmt[1], lmt[4], 5); // (98+98 == 98+98) - 0
	strncmp(lmt[2], lmt[5], 5); // (99+99 == 99+99) - 0
	// ! = 33
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

##### 11
* int strcoll(const char *str1, const char *str2);
	* *str1: Um vetor de caracteres ou uma string. | *str2: Um vetor de caracteres ou uma string.
	* Usos: Compara o valor ASCII de duas cadeiras de caracteres. Seu resultado depende da configuração `LC_COLLATE` do local.
	* Retorno: 0 se forem iguais, valor negativo se `str1` for menor que `str2`, ou valor positivo se `str1` for maior que `str2`.
	
``` c
int main(){
	
	strcoll("A", "a"); // (65 <  97) - <0
	strcoll("b", "b"); // (98 == 98) -  0
	strcoll("c", "C"); // (99 >  67) - >0
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

##### 12
* char *strcpy(char *dest, const char *src);
	* *dest: Um vetor de caracteres. | *src: Uma string ou um vetor de caracteres.
	* Usos: Copia todo o conteúdo do segundo vetor (ou string) para dentro do primeiro vetor, substituindo todo o seu conteúdo anterior no processo.
	* Função: Um ponteiro para a nova string presente no primeiro vetor.
	
``` c
int main(){
	
	char str[4] = "One";
	strcpy(str, "Two");  // str = "Two"
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

##### 13
* char *strncpy(char *dest, const char *src, size_t n);
	* *dest: Um vetor de caracteres. | *src: Uma string ou um vetor de caracteres | n: A quantidade máxima de caracteres que serão copiados.
	* Usos: Copia (ou substinui) os primeira `n` caracteres do primeira vetor pelos primeiros `n` caracteres do segundo vetor (ou string). Adiciona `\0` a espaços vazios em `*dest` (caso existam) e respeita seu limite de caracteres (não o estoura).
	* Função: Um ponteiro para a nova string presente no primeiro vetor. 
	
``` c
int main(){
	
	char str[7] = "abcdef";
	strncpy(str, "ABC", 3); // str = "ABCdef"
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

##### 14
* size_t strcspn(const char *str1, const char *str2);
	* *str1: Um vetor de caracteres (ou string) cujo comprimento será retornado. | *str2: Um vetor de caracteres (ou string) para ter seus caracteres percorridos/verificados e comparados com o primeiro vetor.
	* Uso: Compara todos os caracteres presentes no segundo vetor com os caracteres presentes no primeiro vetor.
	* Retorno: Caso um caractere igual seja encontrado, todos os caracteres anteriores a ele (primeiro vetor) serão retornados, caso contrário, todos os caracteres serão retornados.
	
``` c
int main(){
	
	char str[13] = "Hello World!";
	strcsnp(str, "PM3 I98W");   // "Hello"
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

##### 15
* char *strerror(int errnum);
	* errnum: Número do erro. Geralmente `errno`.
	* Uso: Busca, em uma matriz interna, o valor numérico fornecido em `errnum`. As mensagens de erro podem variar de acordo com o OS e o compilador.
	* Retorno: Um ponteiro para uma string com infomações sobre o erro.
	
``` c
#include <stdio.h>  // fopen
#include <string.h>
#include <errno.h>  // errno

int main(){
	
	char error[35];
	FILE* file = fopen("example.txt", "r");
	
	if(file == NULL) error = strerror(errno);
	// error =  "No such file or directory"
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

##### 16
* size_t strlen(const char *str);
	* *str: Um vetor de caracteres ou uma string.
	* Usos: Calcula a quantidade de caracteres que o vetor especificado possui.
	* Retorna: A quantidade de caracteres.
	
``` c
int main(){
	
	char str[50] = "Hello World!";
	strlen(str);     // 12
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

##### 17
* char *strpbrk(const char *str1, const char str2);
	* *str: Um vetor de caracteres ou uma string. | c: Um caractere para "pesquisa/buscar".
	* Usos: Compara todos os caracteres dentro do `*str1` com todos os caracteres dentro do `str2`. Irá para ao encontrar `\0` em `*str1` e iguinorará `\0` caso encontre-o em `*str2`, não comparando ele.
	* Retorno: Caso seja encontrado um caracter igual a `c`, retornará um ponteiro para uma string que irá do deste caracter até o final da string, caso não seja, retornará ´NULL´.
	
``` c
int main(){
	
	char str[13] = "Hello World";
	strpbrk(str, "OW\0T2f");   // "World!"
	strpbrk(str, "OW\0T2e");   // "ello World!"
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

##### 18
* char *strrchr(const char *str, int c);
	* *str: Um vetor de caracteres ou uma string. | c: Um caractere para "pesquisa/buscar".
	* Usos: Compara todos os caracteres dentro do `*str` com `c`. Irá parar ao encontrar um `\0`.
	* Retorno: Caso seja encontrado um caracter igual a `c`, retornará um ponteiro para uma string que irá da última ocorrência deste caracter até o final da string, caso não seja, retornará ´NULL´.
	
``` c
int main(){
	
	char str[12] = "123-456-789";
	strrchr(str, '-');   // pointer ("-789")
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

##### 19
* size_t strspn(const char *str1, const char *str2);
	* *str1: Um vetor de caracteres ou string. | *str2: Um vetor de caracteres ou string.
	* Usos: Compara (da esquerda para a direita) cada um dos caracteres de cada string de maneira equivalente (0-0, 1-1, ..., n--n) e para quando encontra um par diferente.
	* Retorno: A quantidade de caracteres iguais.
	
``` c
int main(){
	
	strspn("123456789", "1234"); // 4
	strspn("0123456789", "123"); // 0
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

##### 20
* char *strstr(const char *haytack, const char *needle);
	* *haytack: Um vetor de caracteres ou string para efetuar uma busca. | *needle: Um vetor ou string para ser buscado dentro de `*haytack`.
	* Usos: Busca em `*haystack` um fragmento/sub-string que seja igual a `*needle`.
	* Retorno: Caso seja encontrado um caracter igual a `c`, retornará um ponteiro para a primeira ocorrência deste fragmento/sub-string, caso não seja, retornará ´NULL´.
	
``` c
int main(){
	
	strstr("bike-car-bus", "car"); // pointer ("car")
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

##### 21
* char *strtok(char *str, const char *delim);
	* *str: Um vetor de caracteres ou string para ser dividido (use `NULL` caso queira continuar dividindo o vetor dividido anteriormente). | *delim: Um vetor ou string para delimitar as divisões de `*str` (quando ele será dividido).
	* Usos: Divide `*str` sempre que um caracter igual a `delim` é encontrado nele.
	* Retorno: Caso seja encontrado um caracter igual a `c`, retornará um ponteiro para esse fragmento retirado, caso não seja, retornará ´NULL´.
	
``` c
int main(){
	
	char str[13] = "car-bike-bus";
	char *token;
	
	token = strtok(str,  "-e6y"); // pointer ("car")
	token = strtok(NULL, "-e6y"); // pointer ("bik")
	token = strtok(NULL, "-e6y"); // pointer ("bus")
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

##### 22
* size_t strxfrm(char *dest, const char *src, size_t n);
	* *dest: Um vetor de caracteres. | *src: Um vetor 
	* Usos: Transforma os primeiros `n` caracteres de `*src` em localidade atual e os coloca em `*dest`.
	* Retorno: O comprimento da nova cadeia de caracteres.
	
``` c
int main(){
	
	char str[6] = "abcde";
	strxfrm(str, "12345", 3); // 5
	// str = "123de"
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#string)
-----
<br>

#### Fontes:
* https://linguagemc.com.br/a-biblioteca-string-h/
* https://www.tutorialspoint.com/c_standard_library/string_h.htm
* https://bytes.com/topic/c/answers/485925-difference-between-memcmp-strncmp-functions
* https://stackoverflow.com/questions/38687630/the-use-of-strncmp-and-memcmp
* https://www.equestionanswers.com/c/memcpy-vs-memmove.php
* https://www.delftstack.com/pt/howto/c/strtok-in-c/

<br>

-----
* ###### [Para o topo](#string)
-----