# ctype
Fornece macros para a manipulação e verificação de caracteres, usando/baseando-se na **Tabela ASCII**.

<br>

> [!IMPORTANT]
> **TODAS** as funções desta biblioteca solicitam um código ASCII.

<br>

||Funções||
|:-:|:-:|:-:|
|<a href="#1">isalnum</a>|<a href="#6">islower</a> |<a href="#11">isxdigit</a>|
|<a href="#2">isalpha</a>|<a href="#7">isprint</a> |<a href="#12">toupper</a> |
|<a href="#3">iscntrl</a>|<a href="#8">ispunct</a> |<a href="#13">tolower</a> |
|<a href="#4">isdigit</a>|<a href="#9">isspace</a> ||
|<a href="#5">isgraph</a>|<a href="#10">isupper</a>||

<hr>

<h3 id="1">int isalnum(int)</h3>

* Comportamento: verifica se `int` é um alfanumérico.
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.

<hr>

<h3 id="2">int isalpha(int)</h3>

* Comportamento: verifica se `int` é uma letra (e se é maiúscula ou minúscula) ou não.
* Retorno: `1` caso seja uma letra maiúscula, `2` caso seja minúscula ou `0` caso não seja uma letra.
	
<hr>

<h3 id="3">int iscntrl(int)</h3>

* Comportamento: verifica se `int` é um caractere de controle (0-31 em ASCII).
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.

<hr>

<h3 id="4">int isdigit(int)</h3>

* Comportamento: verifica se `int` é um dígito numérico (0-9).
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.

<hr>

<h3 id="5">int isgraph(int)</h3>

* Comportamento: verifica se `int` tem uma representação gráfica (exceto espaços; 33-126).
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.
	
<hr>

<h3 id="6">int islower(int)</h3>

* Comportamento: verifica se `int` é uma letra minúscula.
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.

<hr>

<h3 id="7">int isprint(int)</h3>

* Comportamento: verifica se `int` é imprímível (incluindo espaços; 32-126).
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.

<hr>

<h3 id="8">int ispunct(int)</h3>

* Comportamento: verifica se `int` é um sinal de pontuação (qualquer caractere imprimível que não seja o espaço ou um alfanúmerico).
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.
	
<hr>

<h3 id="9">int isspace(int)</h3>

* Comportamento: verifica se `int` é um espaço, `\n` (quebra de linha), `\r` (retorno de transporte/carro), `\f` (mudança de página), `\t` (tabulação horizontal) ou `\v` (tabulação vertical).
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.

<hr>

<h3 id="10">int isupper(int)</h3>

* Comportamento: verifica se `int` seja uma letra maiúscula.
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.

<hr>

<h3 id="11">int isxdigit(int)</h3>

* Comportamento: verifica se `int` um dígito hexadecimal.
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.

<hr>

<h3 id="12">int tolower(int)</h3>

* Comportamento: verifica se `int` é uma letra maiúscula.
* Retorno: caso verdadeiro, retornará sua versão minúsula, caso falso, retornará `int`.
	
<hr>

<h3 id="13">int toupper(int)</h3>

* Comportamento: verifica se `int` é uma letra minúscula.
* Retorno: caso verdadeiro, retornará sua versão maiúsula, caso falso, retorna `int`.
	
<hr>

#### Fontes:
* [petbccufscar: ctype.h](https://petbcc.ufscar.br/ctype/ )
* [wikipedia: what is ascii table?](https://en.m.wikipedia.org/wiki/ascii )
* [ascii-code: ascii-code full list](https://www.ascii-code.com/ )

<hr>
