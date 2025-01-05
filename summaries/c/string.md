# string
Simplifica a manipulação de cadeias de dados, com foco em cadeias de caracteres.

## Funções
|<a href="1">memchr</a> |<a href="9">strcmp</a>   |<a href="17">strpbrk</a>|
|<a href="2">memcmp</a> |<a href="10">strncmp</a> |<a href="18">strrchr</a>|
|<a href="3">memcpy</a> |<a href="11">strcoll</a> |<a href="19">strspn</a> |
|<a href="4">memmove</a>|<a href="12">strcpy</a>  |<a href="20">strstr</a> |
|<a href="5">memset</a> |<a href="13">strncpy</a> |<a href="21">strtok</a> |
|<a href="6">strcat</a> |<a href="14">strcspn</a> |<a href="22">strxfrm</a>|
|<a href="7">strncat</a>|<a href="15">strerror</a>||
|<a href="8">strchr</a> |<a href="16">strlen</a>  ||

<br>

> [!TIP]
> Funções iniciadas com `str` (comor `strcmp` e `strlen`) "leem" cada sua(s) cadeia(s) de caracteres até a primeira ocorrência de `\0`.

<br>
<hr>
<br>

<h3 id="1">void* memchr(const void*, int, size_t);</h3>
* Comportamento: compara os primeiros `size_t` valores de `const void*` com `int`.
* Retorno: caso seja encontrado um valor igual a `int`, retornará um ponteiro para uma cadeia que irá da primeira ocorrência dele até o final de `const void*`, do contrário `NULL`.

<br>
<hr>
<br>

<h3 id="2">int memcmp(const void 0*, const void 1*, size_t);</h3>
* Comportamento: compara o valor em *byte* dos primeiros `size_t` caracteres de `const void 0*` e `const void 1*`.
* Retorno: `0` se forem iguais, valor negativo se `const void 0*` for menor que `const void 1*`, ou valor positivo se `const void 0*` for maior que `const void 1*`.

<br>
<hr>
<br>

<h3 id="3">void* memcpy(void*, const void*, size_t);</h3>
* Comportamento: copia os primeira `size_t` caracteres de `void*` pelos primeiros `size_t` caracteres de `const void*`
* Retorno: `void*`

<br>

> [!TIP]
> [memcpy vs memmove](https://www.equestionanswers.com/c/memcpy-vs-memmove.php)


<br>
<hr>
<br>

<h3 id="4">void* memmove(void*, const void*, size_t);</h3>
* Comportamento: copia os primeira `size_t` caracteres de `void*` pelos primeiros `size_t` caracteres de `const void*`
* Retorno: `void*`

<br>

> [!TIP]
> [memcpy vs memmove](https://www.equestionanswers.com/c/memcpy-vs-memmove.php)

<br>
<hr>
<br>

<h3 id="5">void* memset(void*, int, size_t);</h3>
* Comportamento: substitui os primeiros `size_t` caracteres de `void*` por `int`.
* Retorno: `void*`.

<br>
<hr>
<br>

<h3 id="6">char* strcat(char*, const char*);</h3>
* Comportamento: concatena `char*` com `const char*`.
* Retorno: `char*`.

<br>
<hr>
<br>

<h3 id="7">char* strncat(char*, const char*, size_t)</h3>
* Comportamento: concatena os primeiros `size_t` caracteres de `char*` com `*const char*`.
* Retorno: `char*`.

<br>
<hr>
<br>

<h3 id="8">char* strchr(const char*, int);</h3>
* Comportamento: compara todos os caracteres dentro de `const char*` com `int`.
* Retorno: caso seja encontrado um caracter igual a `int`, retornará um ponteiro para uma cadeia de caracteres que irá da primeira ocorrência deste caracter até o final da cadeia de caracteres, caso não seja, retornará `NULL`.

<br>
<hr>
<br>

<h3 id="9">int strcmp(const char 0*, const char 1*);</h3>
* Comportamento: compara o valor **ASCII** de duas cadeiras de caracteres.
* Retorno: `0` se forem iguais, valor negativo se `const char 0*` for menor que `const char 1*`, ou valor positivo se `const char 0*` for maior que `const char 1*`.

<br>
<hr>
<br>

<h3 id="10">int strncmp(const char 0*, const char 1*, size_t);</h3>
* Comportamento: compara o valor **ASCII** dos primeiros `size_t` caracteres de duas cadeiras de caracteres.
* Retorno: `0` se forem iguais, valor negativo se `const char 0*` for menor que `const char 1*`, ou valor positivo se `const char 0*` for maior que `const char 1*`.

<br>
<hr>
<br>

<h3 id="11">int strcoll(const char 0*, const char 1*);</h3>
* Comportamento: compara o valor **ASCII** de duas cadeiras de caracteres. Seu resultado depende da configuração `LC_COLLATE` do local.
* Retorno: `0` se forem iguais, valor negativo se `const char 0*` for menor que `const char 1*`, ou valor positivo se `const char 0*` for maior que `const char 1*`.

<br>
<hr>
<br>

<h3 id="12">char* strcpy(char*, const char*);</h3>
* Comportamento: copia todo o conteúdo de `char*` para `const char*`.
* Retorno: `char*`.

<br>

> [!IMPORTANT]
> `char*` deve possuir espaço suficiente para comportar todos os caracteres de `const char*`.

<br>
<hr>
<br>

<h3 id="13">char* strncpy(char*, const char*, size_t);</h3>
* Comportamento: copia os primeira `size_t` caracteres de `char*` pelos primeiros `size_t` caracteres de `const char*`.
* Retorno: `char*`.

<br>
<hr>
<br>

<h3 id="14">size_t strcspn(const char 0*, const char 1*);</h3>
* Comportamento: compara todos os caracteres presentes em `const char 0*` com os caracteres presentes em `const char 1*`, um a um.
* Retorno: caso um caractere igual seja encontrado, todos os caracteres anteriores a ele serão retornados, caso contrário, todos os caracteres serão retornados.

<br>
<hr>
<br>

<h3 id="15">char* strerror(int);</h3>
* Comportamento: busca, em uma matriz interna, o valor numérico fornecido em `int`. As mensagens de erro podem variar de acordo com o OS e o compilador.
* Retorno: um ponteiro para uma cadeia de caracteres com infomações sobre o erro.

<br>
<hr>
<br>

<h3 id="16">size_t strlen(const char*);</h3>
* Comportamento: calcula comprimento de `const char*`.
* Retorna: comprimento.

<br>
<hr>
<br>

<h3 id="17">char* strpbrk(const char 0*, const char 1*);</h3>
* Comportamento: compara todos os caracteres dentro de `const char 0*` com todos os caracteres dentro de `const char 1*`. Irá para ao encontrar `\0` em `const char 0*`; ignorará `\0` caso encontre-o em `const char 1*`, assim não comparando-o e não interrompendo a operação.
* Retorno: caso seja encontrado um valor igual a `int`, retornará um ponteiro para uma cadeia que irá da primeira ocorrência dele até o final de `const char 0*`, do contrário `NULL`.

<br>
<hr>
<br>

<h3 id="18">char* strrchr(const char*, int);</h3>
* Comportamento: compara todos os caracteres dentro de `const char*` com `int`.
* Retorno: caso seja encontrado um valor igual a `int`, retornará um ponteiro para uma cadeia que irá da primeira ocorrência dele até o final de `const char*`, do contrário `NULL`.

<br>
<hr>
<br>

<h3 id="19">size_t strspn(const char 0*, const char 1*);</h3>
* Comportamento: compara (da esquerda para a direita) cada um dos caracteres de `const char 0*` e `const char 1*` (0-0, 1-1, ..., n-n), parando ao encontrar um par diferente.
* Retorno: a quantidade de caracteres iguais.

<br>
<hr>
<br>

<h3 id="20">char* strstr(const char 0*, const char 1*);</h3>
* Comportamento: busca por `const char 1*` (sub-cadeia de caracteres) em `const char 0*`.
* Retorno: caso `const char 1` seja encontrada, retornará um ponteiro para uma cadeia que irá de sua primeira ocorrência até o final de `const char 0*`, do contrário `NULL`.

<br>
<hr>
<br>

<h3 id="21">char* strtok(char*, const char*);</h3>
* Comportamento: divide `char*` sempre que um caracter presente em `const char*` é encontrado nela.
* Retorno: um ponteiro para o primeiro trecho ou `NULL` caso nenhum delimitador de `const char*` seja encontrado.

<br>

> [!TIP]
> **Após a primeira chamada de `strtok`**, o uso de `NULL`, como `char*`, dará continuidade a busca por delimitadores, de `const char*`, na última cadeia de caracteres **não nula** usada em `strtok`.

<br>
<hr>
<br>

<h3 id="22">size_t strxfrm(char*, const char*, size_t);</h3>
* Comportamento: copia os primeiros `size_t` caracteres de `char*` para `const char*`, convertendo-os para o formato definido para `LC_COLLATE` durante o processo.
* Retorno: comprimento de `char*`.

<br>
<hr>
<br>

#### Fontes:
* https://www.tutorialspoint.com/c\_standard\_library/string\_h.htm
* https://www.equestionanswers.com/c/memcpy-vs-memmove.php
* https://www.delftstack.com/pt/howto/c/strtok-in-c/
* https://learn.microsoft.com/pt-br/cpp/c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l?view=msvc-170

<br>
<hr>
