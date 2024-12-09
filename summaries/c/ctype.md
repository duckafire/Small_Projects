# ctype
Fornece funções para a manipulação e verificação de caracteres, usando/baseando-se na **Tabela ASCII**.

<br>

> [!IMPORTANT]
> **TODAS** as funções desta biblioteca solicitam um código ASCII.

<br>

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
<hr>
<br>

<h3>int isalnum(int);</h3>
	* Uso: Verifica se `int` é um alfanumérico.
	* Retorno: Um valor diferente de zero caso verdadeiro ou `0` caso falso.

<br>
<hr>
<br>

<h3>int isalpha(int);</h3>
	* Uso: Verifica se `int` é uma letra (e se é maiúscula ou minúscula) ou não.
	* Retorno: `1` caso seja uma letra maiúscula, `2` caso seja minúscula ou `0` caso não seja uma letra.
	
<br>
<hr>
<br>

<h3>int iscntrl(int);</h3>
	* Uso: Verifica se `int` é um caractere de controle (0-31 em ASCII).
	* Retorno: Um valor diferente de zero caso verdadeiro ou `0` caso falso.

<br>
<hr>
<br>

<h3>int isdigit(int);</h3>
	* Uso: Verifica se `int` é um dígito numérico (0-9).
	* Retorno: Um valor diferente de zero caso verdadeiro ou `0` caso falso.

<br>
<hr>
<br>

<h3>int isgraph(int);</h3>
	* Uso: Verifica se `int` tem uma representação gráfica (exceto espaços; 33-126).
	* Retorno: Um valor diferente de zero caso verdadeiro ou `0` caso falso.
	
<br>
<hr>
<br>

<h3>int islower(int);</h3>
	* Uso: Verifica se `int` é uma letra minúscula.
	* Retorno: Um valor diferente de zero caso verdadeiro ou `0` caso falso.

<br>
<hr>
<br>

<h3>int isprint(int);</h3>
	* Uso: Verifica se `int` é imprímível (incluindo espaços; 32-126).
	* Retorno: Um valor diferente de zero caso verdadeiro ou `0` caso falso.

<br>
<hr>
<br>

<h3>int ispunct(int);</h3>
	* Uso: Verifica se `int` é um sinal de pontuação (qualquer caractere imprimível que não seja o espaço ou um alfanúmerico).
	* Retorno: Um valor diferente de zero caso verdadeiro ou `0` caso falso.
	
<br>
<hr>
<br>

<h3>int isspace(int);</h3>
	* Uso: Verifica se `int` é um espaço, `\n` (quebra de linha), `\r` (retorno de transporte/carro), `\f` (mudança de página), `\t` (tabulação horizontal) ou `\v` (tabulação vertical).
	* Retorno: Um valor diferente de zero caso verdadeiro ou `0` caso falso.

<br>
<hr>
<br>

<h3>int isupper(int);</h3>
	* Uso: Verifica se `int` seja uma letra maiúscula.
	* Retorno: Um valor diferente de zero caso verdadeiro ou `0` caso falso.

<br>
<hr>
<br>

<h3>int isxdigit(int);</h3>
	* Uso: Verifica se `int` um dígito hexadecimal.
	* Retorno: Um valor diferente de zero caso verdadeiro ou `0` caso falso.

<br>
<hr>
<br>

<h3>int tolower(int);</h3>
	* Uso: Verifica se `int` é uma letra maiúscula.
	* Retorno: Caso verdadeiro, retornará sua versão minúsula, caso falso, retornará `int`.
	
<br>
<hr>
<br>

<h3>int toupper(int);</h3>
	* Uso: Verifica se `int` é uma letra minúscula.
	* Retorno: Caso verdadeiro, retornará sua versão maiúsula, caso falso, retorna `int`.
	
<br>
<hr>
<br>

#### Fontes:
* https://petbcc.ufscar.br/ctype/
* https://en.m.wikipedia.org/wiki/ASCII
* https://www.ascii-code.com/

<br>
<hr>
