# ctype
Fornece funções para a manipulação e teste de caracteres ASCII.

## Funções
* [isalnum](#1)
* [isalpha](#2)
* [iscntrl](#3)
* [isdigit](#4)
* [isgraph](#5)
* [islower](#6)
* [isprint](#7)
* [ispunct](#8)
* [isspace](#9)
* [isupper](#10)
* [isxdigit](#11)
* [tolower](#12)
* [toupper](#13)

<br>

-----
* ###### [Para o topo](#ctype)
-----
<br>

##### 1
* int isalnum(int c);
	* c: Um caractere ou <ins>um número (código em ASCII).
	* Uso: Verifica se seu argumento é um alfanúmerico.
	* Retorno: Um valor diferente de zero caso verdadeiro ou 0 caso falso.
	
``` c
int main(){
	
    isalnum('$'); // 0
    isalnum('1'); // random number
    isalnum(97);  // random number
	// 97 = a (in ASCII)
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#ctype)
-----
<br>

##### 2
* int isalpha(int c);
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Uso: Verifica se seu argumento é uma letra (E se é maiúscula ou minúscula) ou não.
	* Retorno: 1 caso seja uma letra maiúscula, 2 caso seja minúscula ou 0 caso não esteja no alfabeto.
	
``` c
int main(){
	
	isalpha('&'); // 0
	isalpha('E'); // 1
	isalpha(101); // 2
	// 101 = e (in ASCII)
	
	return 0;
}
```

<br>

-----
* ###### [Para o topo](#ctype)
-----
<br>

##### 3
* int iscntrl(int c);
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Uso: Verifica se seu argumento é um caractere de controle (0-31 em ASCII).
	* Retorno: Um valor diferente de zero caso verdadeiro ou 0 caso falso.
	
``` c
int main(){
	
	iscntrl('c'); // 0
	iscntrl('3'); // 0
	iscntrl(4);   // random number
	// 4 = EOT (End Of Transmision; in ASCII)
	
	return 0;
}

```

<br>

-----
* ###### [Para o topo](#ctype)
-----
<br>

##### 4
* int isdigit(int c);
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Uso: Verifica se seu argumento é um dígito numérico (0-9).
	* Retorno: Um valor diferente de zero caso verdadeiro ou 0 caso falso.
	
``` c
int main(){
	
	isdigit('7'); // random number
	isdigit('#'); // 0
	isdigit(50);  // random number
	// 50 = 2 (in ASCII)
	
	return 0;
}

```

<br>

-----
* ###### [Para o topo](#ctype)
-----
<br>

##### 5
* int isgraph(int c);
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Uso: Verifica se seu argumento tem uma representação gráfica (exceto espaços; 33-126).
	* Retorno: Um valor diferente de zero caso verdadeiro ou 0 caso falso.
	
``` c
int main(){
	
	isgraph(' '); // 0
	isgraph('h'); // random number
	isgraph(127); // 0
	// 127 = DEL (DELete; in ASCII)
	
	return 0;
}

```

<br>

-----
* ###### [Para o topo](#ctype)
-----
<br>

##### 6
* int islower(int c);
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Uso: Verifica se seu argumento é uma letra minúscula.
	* Retorno: Um valor diferente de zero caso verdadeiro ou 0 caso falso.
	
``` c
int main(){
	
	islower('t'); // random number
	islower('8'); // 0
	islower(109); // random number
	// 109 = m (in ASCII)
	
	return 0;
}

```

<br>

-----
* ###### [Para o topo](#ctype)
-----
<br>

##### 7
* int isprint(int c);
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Uso: Verifica se seu argumento é imprímível (incluindo espaços; 32-126).
	* Retorno: Um valor diferente de zero caso verdadeiro ou 0 caso falso.
	
``` c
int main(){
	
	isprint(' '); // random number
	isprint('?'); // random number
	isprint(0);   // 0
	// 0 = NUL (NULl; in ASCII)
	
	return 0;
}

```

-----
* ###### [Para o topo](#ctype)
-----

##### 8
* int ispunct(int c);
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Uso: Verifica se seu argumento é um sinal de pontuação (qualquer caractere imprimível que não seja espaço ou alfanúmerico).
	* Retorno: Um valor diferente de zero caso verdadeiro ou 0 caso falso.
	
``` c
int main(){
	
	ispunct('!'); // random number
	ispunct('"'); // random number
	ispunct(66);  // 0
	// 66 = B (in ASCII)
	
	return 0;
}

```

-----
* ###### [Para o topo](#ctype)
-----

##### 9
* int isspace(int c);
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Uso: Verifica se seu argumento é um espaço, `\n` (quebra de linha), `\r` (retorno de transporte/carro), `\f` (mudança de página), ou `\t` (tabulação horizontal) ou `\v` (vertical).
	* Retorno: Um valor diferente de zero caso verdadeiro ou 0 caso falso.
	
``` c
int main(){
	
	isspace('\t'); // random number
	isspace(' ');  // random number
	isspace(90);   // 0
	// 90 = Z (in ASCII)
	
	return 0;
}

```

-----
* ###### [Para o topo](#ctype)
-----

##### 10
* int isupper(int c);
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Uso: Verifica se seu argumento seja uma letra maiúscula.
	* Retorno: Um valor diferente de zero caso verdadeiro ou 0 caso falso.
	
``` c
int main(){
	
	isupper('n'); // 0
	isupper('U'); // random number
	isupper(43);  // 0
	// 43 = + (in ASCII)
	
	return 0;
}

```

-----
* ###### [Para o topo](#ctype)
-----

##### 11
* int isxdigit(int c);
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Uso: Verifica se seu argumento um dígito hexadecimal.
	* Retorno: Um valor diferente de zero caso verdadeiro ou 0 caso falso.
	
``` c
int main(){
	
	isxdigit('a'); // random number
	isxdigit('B'); // random number
	isxdigit(67);  // random number
	// 67 = C (in ASCII)
	
	return 0;
}

```

-----
* ###### [Para o topo](#ctype)
-----

##### 12
* int tolower(int c);
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Uso: Verifica se seu argumento é uma letra maiúscula.
	* Retorno: Caso verdadeiro, retorna sua versão minúsula, caso falso, retorna ele mesmo.
	
``` c
int main(){

	tolower('w'); // W
	tolower('4'); // 4
	tolower(86);  // V
	// 86 = V (is ASCII)
	
	return 0;
}

```

-----
* ###### [Para o topo](#ctype)
-----

##### 13
* int toupper(int c);
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Uso: Verifica se seu argumento é uma letra minúscula.
	* Retorno: Caso verdadeiro, retorna sua versão maiúsula, caso falso, retorna ele mesmo.
	
``` c
int main(){

	toupper('0'); // 0
	toupper('P'); // P
	toupper(107); // K
	// 107 = k (in ASCII)
	
	return 0;
}

```

<br>

-----
* ###### [Para o topo](#ctype)
-----
<br>

#### Fontes:
* https://petbcc.ufscar.br/ctype/
* https://en.m.wikipedia.org/wiki/ASCII
* https://www.ascii-code.com/

<br>

-----
* ###### [Para o topo](#ctype)
-----
