# inttypes
**Disponibiliza todo o conteúdo do cabeçalho `stdint.h`**, em adjunto a uma série de macros
para manipulações dos tipos herdados (de `stdint.h`), em funções de entrada (`scanf`,
`fscanf`, ...) e saída (`printf`, `fprintf`, `...`). Além de uma estrutura (`imaxdiv_t`) e
funções para a manipulação de valores `intmax_t`.

> [!TIP]
> Veja mais sobre o cabeçalho [`stdint.h`](https://github.com/duckafire/Small_Projects/blob/main/summaries/c/stdint.md "Small_Projects/summaries").

## Índice

* [Macros](#1)
* [`imaxdiv_t` (estrutura)](#2)
* [Funções](#3)
	* [`imaxabs`](#3-1)
	* [`imaxdiv`](#3-2)
	* [`strtoimax`](#3-3)
	* [`strtoumax`](#3-4)
	* [`wcstoimax`](#3-5)
	* [`wcstoumax`](#3-6)

### Macros
###### 1

* As macros de manipulações desse cabeçalho seguem o seguinte padrão:
	* Primeiros três caracteres:
		* `SCN` para funções de entradas.
		* `PRI` para funções de saídas.
	* Quatro caractere:
		* `x` para hexadecimal.
		* `o` para octal.
		* `u` para inteiros não assinados.
		* `i` para inteiros.
	* Caracteres remanescentes:
		* **N** para inteiros com exatos 8, 16, 32 ou 64 *bytes* de largura.
		* `PTR`  **`N`** para `intptr_t`.
		* `MAX`  **`N`** para `intmax_t`.
		* `LEAST`**`N`** para `int_least_t`.
		* `FAST` **`N`** para `int_fast_t`.
	
> Exemplos: `PRIx16`; `SCNuMAX`; `SCNoFAST64`.

---

### imaxdiv\_t
###### 2

* Intuito: armazenar o quociente e o resto da divisão de um `intmax_t`.
* Membros:
	* `intmax_t` quociente.
	* `intmax_t` resto.

> Nomes fantasia.

---

### Funções
###### 3

#### intmax\_t imaxabs(intmax\_t)
###### 3-1

* Comportamento: obtém o valor absoluto do `intmax_t`.
* Retorno: valor obtido.

#### imaxdiv\_t imaxdiv(intmax\_t0, intmax\_t1)
###### 3-2

* Comportamento: calcula a divisão de `intmax_t0` por `intmax_t1`.
* Retorno: uma estrutura contento o quociente e o resto da divisão.

#### intmax\_t strtoimax(const char\*, char\*\*, int)
###### 3-3

* Comportamento: converte `const char*` em um inteiro de base `int`.
* Retorno: valor obtido.

#### uintmax\_t strtoumax(const char \*, char \*\*, int)
###### 3-4

* Comportamento: converte `const char*` em um inteiro não assinado de base `int`.
* Retorno: valor obtido.

#### intmax\_t wcstoimax(const wchar\_t \*, wchar\_t \*\*, int)
###### 3-5

* Comportamento: converte `const wchar_t*` em um inteiro de base `int`.
* Retorno: valor obtido.

#### uintmax\_t wcstoumax(const wchar\_t\*, wchar\_t\*\*, int)
###### 3-6

* Comportamento: converte `const wchar_t*` em um inteiro não assinado de base `int`.
* Retorno: valor obtido.

> [!NOTE]
> `char**` (e `wchar_t**`) receberá o endereço do primeiro caractere inválido (que não pode
> ser convertido para inteiro) de `const char *` (`const wchar_t`).
> 
> `int` pode ser um valor entre `2-36` ou `0`, para detecção automática (da base).

> [!TIP]
> Use `char**==NULL` (`wchar_t**==NULL`), caso este seja irrelevante.
---

#### Fontes:
* [cplusplus: inttypes.h](https://cplusplus.com/reference/cinttypes/ )
* [pubs.openground: macros full list](https://pubs.opengroup.org/onlinepubs/009695399/basedefs/inttypes.h.html )

---
