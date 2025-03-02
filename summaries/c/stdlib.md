# stdlib.h
Disponibilizar uma série de funções de uso geral, incluindo tratamento de memória dinâmica
e geração de números pseudoaleatórios.

[tmpfile]: https://github.com/duckafire/small_projects/blob/main/summaries/c/stdio.md#3
[memset]: https://github.com/duckafire/small_projects/blob/main/summaries/c/string.md#5
[locale]: https://github.com/duckafire/small_projects/blob/main/summaries/c/locale.md "Resumo de locale.h"
[env-var]: https://superuser.com/questions/284342/what-are-path-and-other-environment-variables-and-how-can-i-set-or-use-them "O que é uma 'variável de ambiente'?"
[bsearch]: https://en.wikipedia.org/wiki/Binary_search "Wikipédia"

---

* `EXIT_FAILURE`: valor, dependendo do sistema, que indica que o programa foi encerrado com
falha.
* `EXIT_SUCCESS`: valor, dependendo do sistema, que indica que o programa foi encerrado com
sucesso.
* `MB_CUR_MAX`: número máximo de *bytes* que podem compor um caractere *multibyte* no
"idioma" atual (veja [`locale.h`][locale]).
* `RAND_MAX`: valor máximo retornável pela função [`rand`](#12).

> [!IMPORTANT]
> `EXIT_FAILURE` e `EXIT_PROCESS` são destinados para uso como argumento na função [`rexit`](#21).

---

* `div_t` - `ldiv\_t` - `lldiv\_t`: estruturas com dois membros destinados a armazenar o
quociente e o resto de uma divisão. Seus membros possuem o mesmo tipo, porém este varia
entre as estruturas, sendo respectivamente: `int` - `long` - `long long`.

---

|               |            |              | Funções            |              |            |             |               |
| :-:           | :-:        | :-:          | :-:                | :-:          | :-:        | :-:         | :-:           |
| Conv. cadeias |N. p.aleató.|Memória dinâm.| Ambiente           |Busca e organ.|Ma. com int.|Cara. multib.|Cadeias multib.|
|[atof](#1)     |[rand](#12) |[calloc](#14) |[abort](#18)        |[bsearch](#26)|[abs](#28)  |[mblen](#34) |[mbstowcs](#37)|
|[atoi](#2)     |[srand](#13)|[free](#15)   |[atexit](#19)       |[qsort](#27)  |[div](#29)  |[mbtowc](#35)|[wcstombs](#38)|
|[atol](#3)     |            |[malloc](#16) |[at_quick_exit](#20)|              |[labs](#30) |[wctomb](#36)|               |
|[atoll](#4)    |            |[realloc](#17)|[exit](#21)         |              |[ldiv](#31) |             |               |
|[strtod](#5)   |            |              |[getenv](#22)       |              |[llabs](#32)|             |               |
|[strtof](#6)   |            |              |[quick_exit](#23)   |              |[lldiv](#33)|             |               |
|[strtol](#7)   |            |              |[system](#24)       |              |            |             |               |
|[strtold](#8)  |            |              |[_Exit](#25)        |              |            |             |               |
|[strtoll](#9)  |            |              |                    |              |            |             |               |
|[strtoul](#10) |            |              |                    |              |            |             |               |
|[strtoull](#11)|            |              |                    |              |            |             |               |

### Conversção de cadeias

> [!NOTE]
> Todas estas funções ignorarão espaço em branco posicionados no início de `const char*`,
> analisarão todos os caracteres válidos e pararão ao encontrar um caractere inválido.

> [!TIP]
> Funções que possuem `char*\*` armazenarão nele o endereço do primeiro caractere inválido
> encontrado em `const char*`, a menos que `char*\*==NULL`.

> [!TIP]
> A base (`int`) de um número pode ser qualquer valor entre dois e trinta e seis.

#### double atof(const char\*)
###### 1

* Comportamento: converte `const char*` em `double`.
* Retorno: o valor convertido ou `0.0` em caso de erro.

> [!NOTE]
> Se o resultado da conversão exceder o valor mínimo ou máximo suportado por um `double`,
> o comportamento será indefinido.

> [!TIP]
> Use [`strtod`](#5), para uma abordagem multiplataforma mais robusta, quando possível.

---

#### int atoi(const char\*)
###### 2

* Comportamento: converte `const char*` em `int`.
* Retorno: o valor convertido ou `0` em caso de erro.

---

#### long atol(const char\*)
###### 3

* Comportamento: converte `const char*` em `long`.
* Retorno: o valor convertido ou `0` em caso de erro.

---

#### long long atoll(const char\*)
###### 4

* Comportamento: converte `const char*` em `long long`.
* Retorno: o valor convertido ou `0` em caso de erro.

---

#### double strtod(const char\*, char\*\*)
###### 5

* Comportamento: converte `const char*` em `double`.
* Retorno: o valor convertido ou `0.0` em caso de erro.

---

#### float strtof(const char\*, char\*\*)
###### 6

* Comportamento: converte `const char*` em `float`.
* Retorno: o valor convertido ou `0.0` em caso de erro.

---

#### long strtol(const char\*, char\*\*, int)
###### 7

* Comportamento: converte `const char*` em `long` de base numeral `int`.
* Retorno: o valor convertido ou `0` em caso de erro.

---

#### long double strtold(const char\*, char\*\*)
###### 8

* Comportamento: converte `const char*` em `long float`.
* Retorno: o valor convertido ou `0.0` em caso de erro.

---

#### long long strtoll(const char\*, char\*\*, int)
###### 9

* Comportamento: converte `const char*` em `long long` de base numeral `int`.
* Retorno: o valor convertido ou `0` em caso de erro.

---

#### unsigned long strtoul(const char\*, char\*\*, int)
###### 10

* Comportamento: converte `const char*` em `unsigned long` de base numeral `int`.
* Retorno: o valor convertido ou `0` em caso de erro.

---

#### unsigned long long strtoull(const char\*, char\*\*, int)
###### 11

* Comportamento: converte `const char*` em `unsigned long long` de base numeral `int`.
* Retorno: o valor convertido ou `0` em caso de erro.

---

### Geração de números pseudoaleatórios

#### int rand(void)
###### 12

* Comportamento: obtém um valor inteiro pseudoaleatório, com base em um algoritmo cuja
*semente* é definida por [`srand`](#14).
* Retorno: um valor entre `0` e `RAND_MAX`.

> [!TIP]
> O operador `%` pode ser usado para reduzir o intervalo entre os valores retornados:
> 
> * `rand() % 100` gerará um valor entre `0-99`
> * `50 + (rand() % 50)` gerará um valor entre `50-99`.

---

#### void srand(unsigned int)
###### 13

* Comportamento: define a *semente* que será usada pelo algoritmo de geração de número
pseudoaleatórios, o qual é utilizado pela função [`rand`](#13).
* Retorno: nenhum.

> [!IMPORTANT]
> Uma mesma *semente* gerará a mesma sequência de valores.

> [!NOTE]
> Redefinir a mesmo *semente* irá reiniciar a "sequência de valores" retornada pelo
> algoritmo.

> [!TIP]
> Use `srand(`[`time`](https://github.com/duckafire/small_projects/blob/main/summaries/c/time.md#8)`(NULL))`
> para garantir uma *semente* diferente a cada nova inicialização do programa.

---

### Gerenciamento de memórias dinâmicas

#### void\* calloc(size\_t0, size\_t1)
###### 14

* Comportamento: aloca um bloco de memória para um vetor com `size_t0` elementos, com
`size_t1` de tamanho cada.
* Retorno: o endereço do bloco de memória alocado ou `NULL`, em caso de falha.

> [!NOTE]
> Se `size_t1` for igual a `0`, o retorno dependerá da implementação da biblioteca
> (geralmente é `NULL`); esta função preenche a memória alocada com zeros.

---

#### void free(void\*)
###### 15

* Comportamento: libera a memória alocada pelas funções [`calloc`](#14), [`malloc`](#16) e
[`realloc`](#17).
* Retorno: nenhum.

> [!CAUTION]
> Após o processo, recomenda-se fortemente que `NULL` seja atribuído ao ponteiro que
> guardava o endereço dado a `void*`, pois seu uso subsequente gerará comportamentos
> indefinidos.

> [!WARNING]
> Caso `void*` não seja um endereço alocado pelas funções antes listadas, o comportamento
> será indefinido.

> [!NOTE]
> Caso `void*==NULL`, nada ocorrerá.

---

#### void\* malloc(size\_t)
###### 16

* Comportamento: aloca um bloco de memória com `size_t` de tamanho.
* Retorno: o endereço do bloco de memória alocado ou `NULL`, em caso de falha.

> [!TIP]
> `sizeof` pode ser usado para obter o tamanho de uma estrutura e alocar memória para a
> mesma: `foo = malloc( sizeof( struct Foo ) )`.

---

#### void\* realloc(void\*, size\_t)
###### 17

* Comportamento: redimensiona o espaço de memória alocado em `void*` se:
	1. `size_t` for menor que o comprimento de `void*`, seu tamanho será contraído e o
	espaço excedente liberado.
	2. `size_t` for maior que o comprimento de `void*`, seu tamanho será expandido, caso
	sua posição impossibilite essa alteração, sua localização será alterada para um local
	que a permita.
* Retorno: caso não seja necessário mover o bloco de memória, retornará o endereço de
`void*`, do contrário retornará um novo endereço de memória (nesse caso, o endereço
original será automaticamente liberado).

o endereço de memória da memória alocada (que pode ser `void*` ou outro) ou, em
caso de falha, `NULL` (o endereço de `void*` permanecerá inalterado).

> [!NOTE]
> Se `void*==NULL`, esta função se comportará da mesma forma que [calloc](#14).

> [!TIP]
> `sizeof` pode ser usado para obter o tamanho de uma estrutura e alocar memória para a
> mesma: `foo = malloc( sizeof( struct Foo ) )`.

---

### Ambiente

#### void abort(void)
###### 18

* Comportamento: encerra o programa de maneira abrupta.
* Retorno: nenhum.

> [!CAUTION]
> *Fluxos* gerados por [`tmpfile`](tmpfile) não serão liberados após essa função ser
> executada.

> [!NOTE]
> O código que será retornado pelo programa dependerá da plataforma em questão.

---

#### int atexit(void (\*foo)(void))
###### 19

* Comportamento: adiciona `void (*foo)(void)` a uma **pilha** de funções, para execução
após o programa ser encerrado com êxito.
* Retorno: `0`, caso a função seja registrada com sucesso, ou um valor diferente de `0`, em
caso de falha.

> [!IMPORTANT]
> Diferentes implementações desta biblioteca impõem limites distintos para o número máximo
> de funções registráveis na **pilha**, com a quantidade mínima de `32` funções.

> [!TIP]
> **É possível registrar um número ilimitado de funções**, basta adicionar todas a uma
> *função de contêiner* e registrá-la na **pilha**.
> 
> ``` c
> void foo(void){
> 	free_foo();
> 	destroy_foo();
> 	clear_foo()
> }
> 
> int main(void){
> 	atexit(foo);
> 	// ...
> ```
> 
> Alie essa função a [`exit`](#21) para efetuar saídas seguras a qualquer momento durante
> a execução do programa.

---

#### int at\_quick\_exit(void (\*foo)(void))
###### 20

* Comportamento: adiciona `void (*foo)(void)` a uma **pilha** de funções, para execução
**após** [**quick_exit**](#23) **ser chamada**.
* Retorno: `0`, caso a função seja registrada com sucesso, ou um valor diferente de `0`, em
caso de falha.

> [!IMPORTANT]
> Diferentes implementações desta biblioteca impõem limites distintos para o número máximo
> de funções registráveis na **pilha**, com a quantidade mínima de `32` funções.

> [!TIP]
> **É possível registrar um número ilimitado de funções**, basta adicionar todas a uma
> *função de contêiner* e registrá-la na **pilha**.
> 
> ``` c
> void foo(void){
> 	free_foo();
> 	destroy_foo();
> 	clear_foo()
> }
> 
> int main(void){
> 	atexit(foo);
> 	// ...
> ```

---

#### void exit(int)
###### 21

* Comportamento: encerra o programa **normalmente**, fazendo-o retornar `int`.
* Retorno: nenhum.

---

#### char\* getenv(const char\*)
###### 22

* Comportamento: obtém o conteúdo de uma [*variável de ambiente*][env-var], cujo
nome/identificador é igual a `const char*`.
* Retorno: o conteúdo da [*variável de ambiente*][env-var] ou `NULL`, caso ela não exista.

> [!NOTE]
> Alguns sistemas e implementações desta biblioteca permitem alterar o conteúdo das
> [*variável de ambiente*][env-var], **entretanto** esse comportamento não é portável.

---

#### \_Noreturn void quick\_exit(int)
###### 23

* Comportamento: executa a **pilha** de funções criada por [`at_quick_exit`](#20) e
encerra o programa com êxito (fazendo-o retornar `int`).
* Retorno: nenhum.

> [!CAUTION]
> A liberação de *fluxos* gerados por [`tmpfile`](tmpfile) dependerá do sistema e da
> implementação desta biblioteca.

> [!TIP]
> Veja mais sobre [`_Noreturn`](https://github.com/duckafire/small_projects/blob/main/summaries/c/stdnoreturn.md "Resumo de 'stdnoreturn.h'").

---

#### int system(const char\*)
###### 24

* Comportamento: se `const char*==NULL`, verificará se há algum *processador de comandos*
está disponível para a função, do contrário, tentará executar o *comando* de nome
`const char*`.
* Retorno: se `const char*==NULL`, retornará um valor diferente de zero (caso haja algum
*processador de comandos* disponível) ou `0` (caso não), do contrário, seu retorno
dependerá do sistema e da implementação da biblioteca.

> [!NOTE]
> Caso `const char*!=NULL`, ele deverá ser igual a um comando do sistema.

---

#### void \_Exit(int)
###### 25

* Comportamento: encerra o programa **normalmente**, fazendo-o retornar `int`, **sem**
chamar as funções da **pilha** de [`atexit`](#19).
* Retorno: nenhum.

> [!CAUTION]
> A liberação de *fluxos* gerados por [`tmpfile`](tmpfile) dependerá do sistema e da
> implementação desta biblioteca.
---

### Busca e organização

#### void\* bsearch(const void\*0, const void\*1, size\_t0, size\_t1, int (\*foo)(const void\*, const void\*))
###### 26

* Comportamento: executa uma [*busca binária*][bsearch] no vetor `const void*1` (que deve
possuir `size_t0` elementos com `size_t1` de largura cada), em busca de `const void*`,
usando `int (*foo)` para efetuar as comparações.
* Retorno: caso `const void*0` seja encontrado, um ponteiro para sua posição em
`const void*1`, do contrário, NULL.

> [!CAUTION]
> Dado que está se trata de uma [*busca binária*][bsearch], `const void*1` deve estar
> ordenado. Veja [`qsort`](#27).

> [!WARNING]
> **Sobre `int (*foo)`**:
> 
> Seu primeiro argumento SEMPRE será `const void*0`, já o segundo será o "item atual" do
> vetor. Seu retorno deve consistir em:
> 
> 1. Em valor negativo caso `first_arg < second_arg`.
> 2. `0` caso ambos seja iguais.
> 3. Um valor positivo caso `first_arg > second_arg`.

> [!IMPORTANT]
> Caso múltiplos elementos iguais a `const void*0` sejam encontrados, qualquer um deles
> poderá ser retornado.

---

#### void qsort(const void\*, size\_t0, size\_t1, int (\*foo)(const void\*, const void\*)
###### 27

* Comportamento: executa uma [*ordenação rápida (quick sort)*](https://en.wikipedia.org/wiki/Quicksort "Wikipédia")
para o conteúdo de `const void*` (que deve possuir `size_t0` elementos com `size_t1` de
largura cada).
* Retorno: nenhum.

> [!WARNING]
> **Sobre `int (*foo)`**:
> 
> Seu retorno deve consistir em:
> 
> 1. Em valor negativo caso `first_arg < second_arg`.
> 2. `0` caso ambos seja iguais.
> 3. Um valor positivo caso `first_arg > second_arg`.

---

### Matemática com inteiros

#### int abs(int)
###### 28

* Comportamento: obtém o valor absoluto de `int`.
* Retorno: o valor obtido.

---

#### div\_t div(int0, int1)
###### 29

* Comportamento: calcula a divisão de `int0` por `int1`.
* Retorno: uma estrutura contento o quociente e o resto da divisão.

---

#### long labs(long)
###### 30

* Comportamento: obtém o valor absoluto de `long`.
* Retorno: o valor obtido.

---

#### ldiv\_t ldiv(long0, long1)
###### 31

* Comportamento: calcula a divisão de `long0` por `long1`.
* Retorno: uma estrutura contento o quociente e o resto da divisão.

---

#### long long llabs(long long)
###### 32

* Comportamento: obtém o valor absoluto de `long long`.
* Retorno: o valor obtido.

---

#### lldiv\_t lldiv(long long0, long long1)
###### 33

* Comportamento: calcula a divisão de `long long0` por `long long1`.
* Retorno: uma estrutura contento o quociente e o resto da divisão.

---

### Caracteres *multibyte*

> [!IMPORTANT]
> Estas funções possuem seu próprio *estado de mudança* (*shift state*), responsável por
> armazenar informações relacionadas ao estados dos caracteres *multibyte* presentes em uma
> cadeia. Chamá-la com `const char*==NULL` redefinirá esse estado.

> [!NOTE]
> O comportamento dessas funções depende da configuração de [`LC_CTYPE`][locale].

> [!TIP]
> Antes de utilizar estas funções, chame-as com `const char*==NULL`, para que seu
> *estado de mudança* seja corretamente reiniciado.

#### int mblen(const char\*, size\_t)
###### 34

* Comportamento: calcula o tamanho de `const char*`, que deve ser **um** caractere
*multibyte* com no máximo `size_t` de comprimento.
* Retorno: se `const char*!=NULL` retornará o comprimento do caractere; se
`const char*==NULL` retornará `0`; se o caractere for inválido retornará `-1`.

---

#### int mbtowc(wchar\_t\*, const char\*, size\_t)
###### 35

* Comportamento: converte um caractere *multibyte*, armazenado em `const char*` (com no
máximo `size_t` de comprimento), em um *caractere largo* e o armazena em `wchar_t*`.
* Retorno: se `const char*!=NULL` retornará o comprimento do caractere; se
`const char*==NULL` retornará `0`; se o caractere for inválido retornará `-1`.

---

#### int wctomb(char\*, wchar\_t)
###### 36

* Comportamento: converte um *caractere largo*, armazenado em `wchar_t`, em um caractere
*multibyte* e o armazena em `char*`.
* Retorno: se `const char*!=NULL` retornará o comprimento do caracteres ou `-1`, se o
caractere for inválido; se `const char*==NULL` retornará um valor diferente de `0`, caso
as codificações de caracteres *multibyte* forem dependentes do *estado de mudança*, ou `0`,
caso contrário.

---

### Cadeias de caracteres *multibyte*

> [WARNING]
> Se o total de caracteres escritos for igual a `size_t`, `wchat_t*` não contará com um
> caractere de terminação (`'\0'`).

> [!NOTE]
> O comportamento dessas funções depende da configuração de [`LC_CTYPE`][locale].

#### size\_t mbstowcs(wchar\_t\*, const char\*, size\_t)
###### 37

* Comportamento: converte uma cadeia de caracteres *multibyte* em uma
*cadeia de caracteres largos*, que tenha, no máximo, `size_t` de comprimento.
* Retorno: o número total de *caracteres largos* escritos em `wchar_t` ou `-1`, caso algum
caractere inválido seja encontrado.

---

#### size\_t wcstombs(char\*, wchar\_t\*, size\_t)
###### 38

* Comportamento: converte uma *cadeia de caracteres largos* em uma cadeia de caracteres
*multibyte*, que tenha, no máximo, `size_t` de comprimento.
* Retorno: o número total de *bytes* escritos em `char*` ou `-1`, caso algum caractere
inválido seja encontrado.

---

### Fontes:
* [cplusplus: stdlib.h](https://cplusplus.com/reference/cstdlib/ )

---
