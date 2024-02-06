# ctype (13)
Fornece funções para a manipulação e teste de caracteres ASCII.

1. int **isalnum**(int c)
	* c: Um argumento inteiro, cujo valor possa ser represetado como um `usingned char` (caractere) ou `EOF`.
	* Retorno: Um valor diferente de zero caso seu parâemtro seja um alfanúmerico ou 0 caso contrário.
	
``` c
int main(){
	
	isalnum(9));   // 0
    isalnum(255)); // 0
    isalnum('1')); // random number
    isalnum('a')); // random number
	
	return 0;
}
```

2. int **isalpha**(int c)
	* c: Um caractere. Caso um inteiro seja passado, ele será convertido para caractere (ASCII).
	* Retorno: 1 caso seja uma letra maiúscula, 2 caso seja minúscula ou 0 caso não esteja no alfabeto.
	
``` c
int main(){
	
	isalpha('@'); // 0
	isalpha('A'); // 1
	isalpha('a'); // 2
	
	return 0;
}
```

3. int **iscntrl**(int c)
	* c: Um caractere. Caso receba um inteiro, ele será convertido para caractere (ASCII).
	* Retorno: Um valor diferente de zero caso seu argumento seja um caractere de controle (0-31 em ASCII) ou 0 caso contrário.
	
``` c
int main(){
	
	iscntrl(); //
	
	return 0;
}

```

4. int **isdigit**(int c)
	* c: Um caractere. Caso seja um inteiro, ele será convertido para caractere (ASCII).
	* Retorno: Um valor diferente de zero caso seu argumento seja um digito de 0-9 ou 0 caso contrário.
	
``` c
int main(){
	
	isdigit(); //
	
	return 0;
}

```

5. int **isgraph**(int c)
	* c: Um caractere. Caso seja um inteiro, ele será convertido para caractere (ASCII).
	* Retorno: Um valor diferente de zero caso seu argumento seja um caractere que possa ser imprimido (exceto o espaço) ou 0 caso contrário.
	
``` c
int main(){
	
	isgraph(); //
	
	return 0;
}

```

6. int **islower**(int c)
	* c: Um caractere. Caso seja um inteiro, ele será convertido para caractere (ASCII).
	* Retorno: Um valor diferente de zero caso seu argumento seja uma letra minúscula ou 0 caso contrário.
	
``` c
int main(){
	
	islower(); //
	
	return 0;
}

```

7. int **isprint**(int c)
	* c: Um caractere. Caso seja um inteiro, ele será convertido para caractere (ASCII).
	* Retorno: Um valor diferente de zero caso seu argumento seja uma letra imprimível (incluindo o espaço) ou 0 zero caso contrário.
	
``` c
int main(){
	
	isprint(); //
	
	return 0;
}

```

8. int **ispunct**(int c)
	* c: Um caractere.  Caso seja um inteiro, ele será convertido para caractere (ASCII).
	* Retorno: Um valor diferente de zero caso seja um sinal de pontuação (qualquer caractere imprimível que não seja sepaço ou alfanúmerico) ou 0 caso contrário.
	
``` c
int main(){
	
	ispunct(); //
	
	return 0;
}

```

9. int **isspace**(int c)
	* c: Um caractere.  Caso seja um inteiro, ele será convertido para caractere (ASCII).
	* Retorno: Um valor diferente de zero caso seu argumento seja um espaço, um caractere de mudança de linha (\n), retorno de transporte/carro (\r), de mudança de página (\f),
	ou de tabulação horizontal (\t) ou vertical (\v) ou 0 caso contrário.
	
``` c
int main(){
	
	isspace(); //
	
	return 0;
}

```

10. int **isupper**(int c)
	* c: Um caractere.  Caso seja um inteiro, ele será convertido para caractere (ASCII).
	* Retorno: Um valor diferente de zero caso seu argumento seja uma letra maiúscula ou 0 caso contrário.
	
``` c
int main(){
	
	isupper(); //
	
	return 0;
}

```

11. int **isxdigit**(int c)
	* c: Um caractere.  Caso seja um inteiro, ele será convertido para caractere (ASCII).
	* Retorno: Um valor diferente de zero caso seu argumento seja um dígito de um número hexadecimal ou 0 caso contrário.
	
``` c
int main(){
	
	isxdigit(); //
	
	return 0;
}

```

12. int **tolower**(int c)
	* c: Um caractere.  Caso seja um inteiro, ele será convertido para caractere (ASCII).
	* Retorno: Caso seu argumento seja uma letra maiúscula, sua versão minúscula será retornada, caso contrário retornará o próprio argumento.
	
``` c
int main(){

	tolower(); //
	
	return 0;
}

```

13. int **toupper**(int c)
	* c: Um caractere.  Caso seja um inteiro, ele será convertido para caractere (ASCII).
	* Retorno: Caso seu argumento seja uma letra minúscula, sua versão maiúscula será retornada, caso contrário retornará o próprio argumento.
	
``` c
int main(){

	toupper(); //
	
	return 0;
}

```

###### Fonte: https://petbcc.ufscar.br/ctype/
	