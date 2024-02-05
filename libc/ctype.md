# ctype
(7) Fornece funções para a manipulação e teste de caracteres.

1. int **isalpha**(int c);
	* c: Caractere.
	* *isalpha('b');*
	* Retorna um valor diferente de zero se o parâmetro for uma letra alfabética, caso contrário, retorna zero.

2. int **isdigit**(int c);
	* c: Caractere.
	* *isdigit('7');*
	* Retorna um valor diferente de zero se o parâmetro for um dígito numérico, caso contrário, retorna zero.

3. int **isalnum**(int c);
	* c: Caractere.
	* *isalnum('H');*
	* Retorna um valor diferente de zero se o parâmetro for uma letra alfabética ou um dígito numérico, caso contrário, retorna zero.

4. int **islower**(int c);
	* c: Caractere.
	* *islower('s');*
	* Retorna um valor diferente de zero se o parâmetro for uma letra minúscula, caso contrário, retorna zero.

5. int **isupper**(int c);
	* c: Caractere.
	* *isupper('K');*
	* Retorna um valor diferente de zero se o parâmetro for uma letra maiúscula, caso contrário, retorna zero.

6. int **tolower**(int c);
	* c: Caractere.
	* *tolower('Q');*
	* Se aplicável, retorna a conversão do parâmetro para minúsculo.

7. int **toupper**(int c);
	* c: Caractere.
	* *toupper('r');*
	* Se aplicável, converte o parâmetro para maiúsculo.
	