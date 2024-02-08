# ctype
Fornece funções para a manipulação e teste de caracteres ASCII.

<br>

-----
<br>

1. int **isalnum**(int c)
	* c: Um caractere ou <ins>um número (código em ASCII).
	* Retorno: Um valor diferente de zero caso seu parâemtro seja um alfanúmerico ou 0 caso contrário.
	
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
<br>

2. int **isalpha**(int c)
	* c: Um caractere ou um <ins>um número (código em ASCII).
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
<br>

3. int **iscntrl**(int c)
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Retorno: Um valor diferente de zero caso seu argumento seja um caractere de controle (0-31 em ASCII) ou 0 caso contrário.
	
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
<br>

4. int **isdigit**(int c)
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Retorno: Um valor diferente de zero caso seu argumento seja um digito de 0-9 ou 0 caso contrário.
	
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
<br>

5. int **isgraph**(int c)
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Retorno: Um valor diferente de zero caso seu argumento tenha uma representação gráfica (exceto o espaço; 33-126) ou 0 caso contrário.
	
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
<br>

6. int **islower**(int c)
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Retorno: Um valor diferente de zero caso seu argumento seja uma letra minúscula ou 0 caso contrário.
	
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
<br>

7. int **isprint**(int c)
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Retorno: Um valor diferente de zero caso seu argumento seja imprimível (incluindo o espaço; 32-126) ou 0 zero caso contrário.
	
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

8. int **ispunct**(int c)
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Retorno: Um valor diferente de zero caso seja um sinal de pontuação (qualquer caractere imprimível que não seja espaço ou alfanúmerico) ou 0 caso contrário.
	
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

9. int **isspace**(int c)
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Retorno: Um valor diferente de zero caso seu argumento seja um espaço, um caractere de mudança de linha (\n), retorno de transporte/carro (\r), de mudança de página (\f),
	ou de tabulação horizontal (\t) ou vertical (\v) ou 0 caso contrário.
	
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

10. int **isupper**(int c)
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Retorno: Um valor diferente de zero caso seu argumento seja uma letra maiúscula ou 0 caso contrário.
	
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

11. int **isxdigit**(int c)
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Retorno: Um valor diferente de zero caso seu argumento seja um dígito de um número hexadecimal ou 0 caso contrário.
	
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

12. int **tolower**(int c)
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Retorno: Caso seu argumento seja uma letra maiúscula, sua versão minúscula será retornada, caso contrário retornará o próprio argumento.
	
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

13. int **toupper**(int c)
	* c: Um caractere ou um <ins>um número (código em ASCII).
	* Retorno: Caso seu argumento seja uma letra minúscula, sua versão maiúscula será retornada, caso contrário retornará o próprio argumento.
	
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
<br>

#### Fonte:
* https://petbcc.ufscar.br/ctype/
* https://en.m.wikipedia.org/wiki/ASCII
* https://www.ascii-code.com/

<br>

-----
