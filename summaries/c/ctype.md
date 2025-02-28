# ctype
Fornece macros para a manipulação e verificação de caracteres da **Tabela ASCII**.

||Funções||
|:-:|:-:|:-:|
|[isalnum](#1)|[islower](#6) |[isxdigit](#11)|
|[isalpha](#2)|[isprint](#7) |[toupper](#12) |
|[iscntrl](#3)|[ispunct](#8) |[tolower](#13) |
|[isdigit](#4)|[isspace](#9) ||
|[isgraph](#5)|[isupper](#10)||

---

### int isalnum(int)
###### 1

* Comportamento: verifica se `int` é um alfanumérico.
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.

---

### int isalpha(int)
###### 2

* Comportamento: verifica se `int` é uma letra (e se é maiúscula ou minúscula) ou não.
* Retorno: `1` caso seja uma letra maiúscula, `2` caso seja minúscula ou `0` caso não seja
uma letra.
	
---

### int iscntrl(int)
###### 3

* Comportamento: verifica se `int` é um caractere de controle (0-31 em ASCII).
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.

---

### int isdigit(int)
###### 4

* Comportamento: verifica se `int` é um dígito numérico (0-9).
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.

---

### int isgraph(int)
###### 5

* Comportamento: verifica se `int` tem uma representação gráfica (exceto espaços; 33-126).
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.
	
---

### int islower(int)
###### 6

* Comportamento: verifica se `int` é uma letra minúscula.
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.

---

### int isprint(int)
###### 7

* Comportamento: verifica se `int` é imprímível (incluindo espaços; 32-126).
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.

---

### int ispunct(int)
###### 8

* Comportamento: verifica se `int` é um sinal de pontuação (qualquer caractere imprimível
que não seja o espaço ou um alfanúmerico).
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.
	
---

### int isspace(int)
###### 9

* Comportamento: verifica se `int` é um espaço, `\n` (quebra de linha), `\r` (retorno de
transporte/carro), `\f` (mudança de página), `\t` (tabulação horizontal) ou `\v` (tabulação
vertical).
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.

---

### int isupper(int)
###### 10

* Comportamento: verifica se `int` seja uma letra maiúscula.
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.

---

### int isxdigit(int)
###### 11

* Comportamento: verifica se `int` um dígito hexadecimal.
* Retorno: um valor diferente de zero caso verdadeiro ou `0` caso falso.

---

### int tolower(int)
###### 12

* Comportamento: verifica se `int` é uma letra maiúscula.
* Retorno: caso verdadeiro, retornará sua versão minúsula, caso falso, retornará `int`.
	
---

### int toupper(int)
###### 13

* Comportamento: verifica se `int` é uma letra minúscula.
* Retorno: caso verdadeiro, retornará sua versão maiúsula, caso falso, retorna `int`.
	
---

#### Fontes:
* [petbccufscar: ctype.h](https://petbcc.ufscar.br/ctype/ )
* [wikipedia: what is ascii table?](https://en.m.wikipedia.org/wiki/ascii )
* [ascii-code: ascii-code full list](https://www.ascii-code.com/ )

---
