# string
Fornece funções para a manipulação de vetores, com foco em cadeias de caracteres.

|| Funções ||
|:-:|:-:|:-:|
|[memchr](#1) |[strcmp](#9)   |[strpbrk](#17)|
|[memcmp](#2) |[strncmp](#10) |[strrchr](#18)|
|[memcpy](#3) |[strcoll](#11) |[strspn](#19) |
|[memmove](#4)|[strcpy](#12)  |[strstr](#20) |
|[memset](#5) |[strncpy](#13) |[strtok](#21) |
|[strcat](#6) |[strcspn](#14) |[strxfrm](#22)|
|[strncat](#7)|[strerror](#15)||
|[strchr](#8) |[strlen](#16)  ||

> [!TIP]
> Função `str`: que geram cadeias tentarão adicionar `'\0'` ao final delas; que leem 
> cadeias pararão ao encontrar `'\0'`.

### void\* memchr(const void\*, int, size\_t)
###### 1

* Comportamento: compara os primeiros `size_t` valores de `const void*` com `int`.
* Retorno: o endereço do primeiro valor idêntico a `int`, todavia caso ele não esteja
presente em `const void*`, retornará `NULL`.

---

### int memcmp(const void\*0, const void \*1, size\_t)
###### 2

* Comportamento: compara o valor em *byte* dos primeiros `size_t` caracteres de
`const void*0` e `const void*1`.
* Retorno: `0` se forem iguais, valor negativo se `const void*0<const void\*1`, ou valor
positivo se `const void*0>const void\*1`.

---

### void\* memcpy(void\*, const void\*, size\_t)
###### 3

* Comportamento: copia os primeira `size_t` índices de `const void*` para os primeiros
`size_t` índices de `const void*`
* Retorno: `void*`

> [!TIP]
> [memcpy vs memmove](https://www.equestionanswers.com/c/memcpy-vs-memmove.php)

---

### void\* memmove(void\*, const void\*, size\_t)
###### 4

* Comportamento: copia os primeira `size_t` índices de `const void*` para os primeiros
`size_t` índices de `const void*`
* Retorno: `void*`

> [!TIP]
> [memcpy vs memmove](https://www.equestionanswers.com/c/memcpy-vs-memmove.php)

---

### void\* memset(void\*, int, size\_t)
###### 5

* Comportamento: substitui os primeiros `size_t` caracteres de `void*` por `int`.
* Retorno: `void*`.

---

### char\* strcat(char\*, const char\*)
###### 6

* Comportamento: incrementa o conteúdo de `char*` com o conteúdo de `const char*`.
* Retorno: `char*`.

> [!IMPORTANT]
> `char*` deve possuir espaço suficiente para comportar todos os caracteres de
> `const char*`, incluindo `'\0'`.

---

### char\* strncat(char\*, const char\*, size\_t)
###### 7

* Comportamento: incrementa o conteúdo de `char*` com os primeiros `size_t` caracteres do
conteúdo de `const char*`.
* Retorno: `char*`.

---

### char\* strchr(const char\*, int)
###### 8

* Comportamento: compara todos os caracteres dentro de `const char*` com `int`.
* Retorno: o endereço do primeiro caractere idêntico a `int`, todavia caso ele não esteja
presente em `const char*`, retornará `NULL`.

---

### int strcmp(const char\*0, const char\*1)
###### 9

* Comportamento: compara o valor **ASCII** do conteúdo de duas cadeiras de caracteres.
* Retorno: `0` se forem iguais, valor negativo se `const char*0<const char\*1`, ou valor
positivo se `const char*0>const char\*1`.

---

### int strncmp(const char\*0, const char\*1, size\_t)
###### 10

* Comportamento: compara o valor **ASCII** dos primeiros `size_t` caracteres de duas
cadeiras de caracteres.
* Retorno: `0` se forem iguais, valor negativo se `const char*0<const char\*1`, ou valor
positivo se `const char*0>const char\*1`.

---

### int strcoll(const char\*0, const char\*1)
###### 11

* Comportamento: compara o valor [**`LC_COLLATE`**](https://github.com/duckafire/small_projects/blob/main/summaries/c/ "Resumo de locale.h")
do conteúdo de duas cadeiras de caracteres.
* Retorno: `0` se forem iguais, valor negativo se `const char*0<const char\*1`, ou valor
positivo se `const char*0>const char\*1`.

---

### char\* strcpy(char\*, const char\*)
###### 12

* Comportamento: copia todo o conteúdo de `const char*` para `char*`.
* Retorno: `char*`.

> [!IMPORTANT]
> `char*` deve possuir espaço suficiente para comportar todos os caracteres de
> `const char*`, incluindo `'\0'`.

---

### char\* strncpy(char\*, const char\*, size\_t)
###### 13

* Comportamento: copia os primeiros `size_t` caracteres de `const char*` para `char*`.
* Retorno: `char*`.

---

### size\_t strcspn(const char\*0, const char\*1)
###### 14

* Comportamento: busca por uma subcadeia de caracteres em `const char*0`, a qual deve ser
formada por caracteres **não** pertencentes à `const char*1`.
* Retorno: comprimento da subcadeia.

---

### char\* strerror(int)
###### 15

* Comportamento: converte um código de erro em uma mensagem de erro.
* Retorno: uma mensagem de erro.

> [!NOTE]
> Tais mensagens podem variar entre compiladores e sistemas operacionais.

---

### size\_t strlen(const char\*)
###### 16

* Comportamento: calcula comprimento de `const char*`.
* Retorna: comprimento.

> [!NOTE]
> Desconsidera o caractere de terminação (`'\0'`).

---

### char\* strpbrk(const char\*0, const char\*1)
###### 17

* Comportamento: busca pela primeira ocorrência de qualquer um dos caracteres de
`const char*1` em `const char*0`.
* Retorno: caso seja encontrado um valor igual a `int`, retornará um ponteiro para uma cadeia que irá da primeira ocorrência dele até o final de `const char*`, do contrário `NULL`.

---

### char\* strrchr(const char\*, int)
###### 18

* Comportamento: compara todos os caracteres dentro de `const char*` com `int`.
* Retorno: caso seja encontrado um valor igual a `int`, retornará um ponteiro para uma cadeia que irá da primeira ocorrência dele até o final de `const char*`, do contrário `NULL`.

---

### size\_t strspn(const char\*0, const char\*1)
###### 19

* Comportamento: busca por uma subcadeia de caracteres em `const char*0`, a qual deve ser
formada por caracteres **pertencentes** à `const char*1`.
* Retorno: comprimento da subcadeia.

---

### char\* strstr(const char\*0, const char\*1)
###### 20

* Comportamento: busca pela subcadeia `const char*1` em `const char*0`.
* Retorno: um endereço para o trecho ou `NULL`, caso eles não seja encontrado.

> [!IMPORTANT]
> O trecho retornado irá do início da subcadeia até o final de `const char*0`, logo:
> 
> ``` c
> const char *str = "Hello world!";
> 
> printf("%s\n", strstr(str, "wor"));
> ```
> 
> ```
> # return
> world!
> ```

---

### char\* strtok(char\*, const char\*)
###### 21

* Comportamento: divide `char*` (em *tokens*) sempre que um caractere de `const char*` é
encontrado nela.
* Retorno: um trecho de `char*`, que vai do índice `0` até a primeira ocorrência de
qualquer um dos caracteres de `char char*`, ou `NULL`, caso nenhum caractere semelhante
seja encontrado.

> [!TIP]
> Para prosseguir com a análise de uma cadeia, basta utilizar `char*==NULL` em chamadas
> posteriores de `strtok`.
> 
> ``` c
> char str[] = "num = 0;";
> 
> strtok(str, "=;");  // "num "
> strtok(NULL, "=;"); // " 0"
> strtok(NULL, "=;"); // NULL
> ```

---

### size\_t strxfrm(char\*, const char\*, size\_t)
###### 22

* Comportamento: copia os primeiros `size_t` caracteres de `const char*` para `char*`.
baseado no valor de [`LC_COLLATE`](https://github.com/duckafire/small_projects/blob/main/summaries/c/locale.md "Resumo de locale.h").
* Retorno: comprimento de `char*`.

---

#### Fontes:
* [tutorialspoint: string.h](https://www.tutorialspoint.com/c_standard_library/string_h.htm )
* [equestionanswers: memcpy vs mommove](https://www.equestionanswers.com/c/memcpy-vs-memmove.php )
* [delfstack: strtok](https://www.delftstack.com/pt/howto/c/strtok-in-c/ )
* [microsoft: strxfrm](https://learn.microsoft.com/pt-br/cpp/c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l?view=msvc-170 )

---
