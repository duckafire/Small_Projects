# stdlib.h
Disponibilizar uma série de funções de uso geral, incluindo tratamento de memória dinâmica, geração de números pseudo-aleatórios e **mais**.

<hr>

* `EXIT\_FAILURE`: valor, dependendo do sistema, que indica que o programa foi encerrado com falha.
* `EXIT\_SUCCESS`: valor, dependendo do sistema, que indica que o programa foi encerrado com sucesso.
* `MB\_CUR\_MAX`: número máximo de *bytes* que podem compor um caractere *multibyte* no "idioma" atual (veja [`locale.h`](https://github.com/duckafire/small_projects/blob/main/summaries/c/locale.md "Resumo de locale.h")).
* `RAND\_MAX`: valor máximo retornável pela função <a href="#12"><code>rand</code></a>.

<br>

> [!IMPORTANT]
> `EXIT_FAILURE` e `EXIT_PROCESS` são destinados para uso como argumento na função <a href="#21"><code>rexit</code></a>.

<br>

<hr>

* `div\_t` - `ldiv\_t` - `lldiv\_t`: estruturas com dois membros destinados a armazenar o quociente e o resto de uma divisão. Seus membros possuem o mesmo tipo, porém este varia entre as estruturas, sendo respectivamente: `int` - `long` - `long long`.

<hr>

|                            |                         |                           | Funções                         |                           |                         |                          |                            |
| :-:                        | :-:                     | :-:                       | :-:                             | :-:                       | :-:                     | :-:                      | :-:                        |
| **Conversção de cadeias**  | **Núm. ps.-aleatórios** | **Memória dinâmica**      | **Ambiente**                    | **Busca e organização**   | **Matem. com inteiros** | **Caracteres multibyte** | **Cadeias multibyte**      |
| <a href="#1">atof</a>      | <a href="#12">rand</a>  | <a href="#14">calloc</a>  | <a href="#18">abort</a>         | <a href="#26">bsearch</a> | <a href="#28">abs</a>   | <a href="#34">mblen</a>  | <a href="#37">mbstowcs</a> |
| <a href="#2">atoi</a>      | <a href="#13">srand</a> | <a href="#15">free</a>    | <a href="#19">atexit</a>        | <a href="#27">qsort</a>   | <a href="#29">div</a>   | <a href="#35">mbtowc</a> | <a href="#38">wcstombs</a> |
| <a href="#3">atol</a>      |                         | <a href="#16">malloc</a>  | <a href="#20">at_quick_exit</a> |                           | <a href="#30">labs</a>  | <a href="#36">wctomb</a> |                            |
| <a href="#4">atoll</a>     |                         | <a href="#17">realloc</a> | <a href="#21">exit</a>          |                           | <a href="#31">ldiv</a>  |                          |                            |
| <a href="#5">strtod</a>    |                         |                           | <a href="#22">getenv</a>        |                           | <a href="#32">llabs</a> |                          |                            |
| <a href="#6">strtof</a>    |                         |                           | <a href="#23">quick_exit</a>    |                           | <a href="#33">lldiv</a> |                          |                            |
| <a href="#7">strtol</a>    |                         |                           | <a href="#24">system</a>        |                           |                         |                          |                            |
| <a href="#8">strtold</a>   |                         |                           | <a href="#25">_Exit</a>         |                           |                         |                          |                            |
| <a href="#9">strtoll</a>   |                         |                           |                                 |                           |                         |                          |                            |
| <a href="#10">strtoul</a>  |                         |                           |                                 |                           |                         |                          |                            |
| <a href="#11">strtoull</a> |                         |                           |                                 |                           |                         |                          |                            |

<br>

### Conversção de cadeias

<br>

> [!NOTE]
> Todas estas funções ignorarão espaço em branco posicionados no início de `const char*`, analizarão todos os caracteres válidos e pararão ao encontrar um caractere inválido.

<br>

> [!TIP]
> Funções que possuem `char**` armazenarão nele o endereço do primeiro caractere inválido encontrado em `const char*`, a menos que `char**==NULL`.

<br>

> [!TIP]
> A base (`int`) de um número pode ser qualquer valor entre dois e trinta e seis.

<br>

<h4 id="1">double atof(const char*)</h4>

* Comportamento: converte `const char*` em `double`.
* Retorno: o valor convertido ou `0.0` em caso de erro.

<br>

> [!NOTE]
> Se o resultado da conversão excerder o valor mínimo ou máximo suportado por um `double`, o comportamento será indefinido.

<br>

> [!TIP]
> Use <a href="#5"><code>strtod</code></a> para uma abordagem multiplataforma mais robusta quando possível.

<br>

<hr>

<h4 id="2">int atoi(const char*)</h4>

* Comportamento: converte `const char*` em `int`.
* Retorno: o valor convertido ou `0` em caso de erro.

<hr>

<h4 id="3">long atol(const char*)</h4>

* Comportamento: converte `const char*` em `long`.
* Retorno: o valor convertido ou `0` em caso de erro.

<hr>

<h4 id="4">long long atoll(const char*)</h4>

* Comportamento: converte `const char*` em `long long`.
* Retorno: o valor convertido ou `0` em caso de erro.

<hr>

<h4 id="5">double strtod(const char*, char**)</h4>

* Comportamento: converte `const char*` em `double`.
* Retorno: o valor convertido ou `0.0` em caso de erro.

<hr>

<h4 id="6">float strtof(const char*, char**)</h4>

* Comportamento: converte `const char*` em `float`.
* Retorno: o valor convertido ou `0.0` em caso de erro.

<hr>

<h4 id="7">long strtol(const char*, char**, int)</h4>

* Comportamento: converte `const char*` em `long` de base numeral `int`.
* Retorno: o valor convertido ou `0` em caso de erro.

<hr>

<h4 id="8">long double strtold(const char*, char**)</h4>

* Comportamento: converte `const char*` em `long float`.
* Retorno: o valor convertido ou `0.0` em caso de erro.

<hr>

<h4 id="9">long long strtoll(const char*, char**, int)</h4>

* Comportamento: converte `const char*` em `long long` de base numeral `int`.
* Retorno: o valor convertido ou `0` em caso de erro.

<hr>

<h4 id="10">unsigned long strtoul(const char*, char**, int)</h4>

* Comportamento: converte `const char*` em `unsigned long` de base numeral `int`.
* Retorno: o valor convertido ou `0` em caso de erro.

<hr>

<h4 id="11">unsigned long long strtoull(const char*, char**, int)</h4>

* Comportamento: converte `const char*` em `unsigned long long` de base numeral `int`.
* Retorno: o valor convertido ou `0` em caso de erro.

<hr>

<br>

### Geração de números pseudo-aleatórios

<h4 id="12">int rand(void)</h4>

* Comportamento: obtém um valor inteiro pseudo-aleatório, com base em um algoritmo cuja *semente* é definida por <a href="#14"><code>srand</code></a>.
* Retorno: um valor entre `0` e `RAND_MAX`.

<br>

> [!TIP]
> O operador `%` pode ser usado para reduzir o intervalo entre os valores retornados: `rand() % 100` gera um valor entre `0` e `99`; `50 + (rand() % 50)` gera um valor entre `50` e `99`.

<br>

<hr>

<h4 id="13">void srand(unsigned int)</h4>

* Comportamento: define a *semente* que será usada pelo algoritmo de geração de número pseudo-aleatórios, o qual é utilizado pela função <a href="#13"><code>rand</code></a>.
* Retorno: nenhum.

<br>

> [!IMPORTANT]
> Uma mesma *semente* gerará a mesma sequência de valores.

<br>

> [!NOTE]
> Redefinir a mesmo *semente* irá reiniciar a "sequência de valores" retornada pelo algoritmo.

<br>

> [!TIP]
> Use <code>srand( <a href="https://github.com/duckafire/small_projects/blob/main/summaries/c/time.md#8" target="_blank">time</a>( NULL ) )</code> para garantir uma *semente* diferente a cada nova inicialização do programa.

<br>

<hr>

<br>

### Gerenciamento de memórias dinâmicas

<h4 id="14">void* calloc(size_t0, size_t1)</h4>

* Comportamento: aloca um bloco de memória para um vetor com `size_t0` elementos, com `size_t1` de tamanho cada.
* Retorno: o endereço do bloco de memória alocado ou `NULL`, em caso de falha.

<br>

> [!NOTE]
> Se `size_t1` for igual a `0`, o retorno dependerá da implementação da biblioteca (geralmente é `NULL`).

<br>

> [!NOTE]
> Esta função "limpa" o espaço alocado com zeros.

<br>

<hr>

<h4 id="15">void free(void*)</h4>

* Comportamento: libera a memória alocada pelas funções <a href="#14"><code>calloc</code></a>, <a href="#16"><code>malloc</code></a> e <a href="#17"><code>realloc</code></a>.
* Retorno: nenhum.

<br>

> [!CAUTION]
> Após o processo, recomenda-se fortemente que `NULL` seja atribuído ao ponteiro que guardava o endereço passado para `void*`, pois o uso deste enereço resultará em comportamentos indefinidos.

<br>

> [!WARNING]
> Caso `void*` não seja um endereço alocado pelas funções antes listadas, o comportamento será indefinido.

<br>

> [!NOTE]
> Caso `void*==NULL`, nada ocorrerá.

<br>

<hr>

<h4 id="16">void* malloc(size_t)</h4>

* Comportamento: aloca um bloco de memória com `size_t` de tamanho.
* Retorno: o endereço do bloco de memória alocado ou `NULL`, em caso de falha.

<br>

> [!IMPORTANT]
> Está função não "limpa" o endereço de memória alocado, logo *lixo* pode estar presente no mesmo. A função <a href="https://github.com/duckafire/small_projects/blob/main/summaries/c/string.md#5"><code>memset</code></a> pode ser usada para limpar essa memória (`memset(pointer, 0, sizeof(struct Foo))`);

<br>

> [!TIP]
> `sizeof` pode ser usado para obter o tamanho de uma estrutura e alocar memória para a mesma (`foo = malloc( sizeof( struct Foo ) )`).

<br>

<hr>

<h4 id="17">void* realloc(void*, size_t)</h4>

* Comportamento: redimensiona o espaço de memória alocado em `void*` se: `size_t` for menor, `void*` é contraído e a memória desassociada é liberada (o endereço de `void*` será retornado); `size_t` for maior, `void*` será expandido, mas caso essa expansão não seja possível, o bloco será movido para outra localização que a possibilite (nesse caso, o ponteiro original é automaticamente liberado e outro será retornado).
* Retorno: o endereço de memória da memória alocada (que pode ser `void*` ou outro) ou, em caso de falha, `NULL` (o endereço de `void*` permanecerá inalterado).

<br>

> [!IMPORTANT]
> Está função não "limpa" o endereço de memória alocado, logo *lixo* pode estar presente no mesmo. A função <a href="https://github.com/duckafire/small_projects/blob/main/summaries/c/string.md#5"><code>memset</code></a> pode ser usada para limpar essa memória (`memset(pointer, 0, sizeof(struct Foo))`);

<br>

> [!NOTE]
> Se `void*==NULL`, esta função comportará-se da mesma forma que <a href="#14"><code></code></a>.

<br>

> [!TIP]
> `sizeof` pode ser usado para obter o tamanho de uma estrutura e alocar memória para a mesma (`foo = malloc( sizeof( struct Foo ) )`).

<br>

<hr>

<br>

### Ambiente

<h4 id="18">void abort(void)</h4>

* Comportamento: encerra o programa de maneira abrupta.
* Retorno: nenhum.

<br>

> [!WARNING]
> <a href="#19"><code>atexit</code></a>, *destruidores de objetos (*__*apenas em C++*__*)* e *fluxos* retornados por <a href="https://github.com/duckafire/small_projects/blob/main/summaries/c/stdio.md#3" target="_blank"><code>tmpfile</code></a> não serão chamados e/ou liberados após essa função ser executada.

<br>

> [!NOTE]
> O código que será retornado pelo programa dependerá da plataforma em questão.

<br>

<hr>

<h4 id="19">int atexit(void (*foo)(void))</h4>

* Comportamento: adiciona `void (*foo)(void)` a uma **pilha** de funções, para execução **após uma saída normal** do programa.
* Retorno: `0`, caso a função seja registrada com sucesso, ou um valor diferente de `0`, em caso de falha.

<br>

> [!WARNING]
> As funções da **pilha** só serão executadas caso o programa encerre com êxito.

<br>

> [!IMPORTANT]
> Diferentes implementações desta biblioteca impõem limites distintos para o número máximo de funções resgistráveis na **pilha**, com a quantidade mínima de `32` funções.

<br>

> [!TIP]
> **É possível registrar um número ilimitado de funções**, basta adicionar todas a uma *função de contêiner* e registrá-la na **pilha**.

<br>

> [!TIP]
> Alie essa função com <a href="#21"><code>exit</code></a> para efetuar saídas seguras a qualquer momento durante a execução do programa.

<br>

<hr>

<h4 id="20">int at_quick_exit(void (*foo)(void))</h4>

* Comportamento: adiciona `void (*foo)(void)` a uma **pilha** de funções, para execução <strong>após <a href="#23"><code>quick_exit</code></a> ser chamada</strong>.
* Retorno: `0`, caso a função seja registrada com sucesso, ou um valor diferente de `0`, em caso de falha.

<br>

> [!IMPORTANT]
> Diferentes implementações desta biblioteca impõem limites distintos para o número máximo de funções resgistráveis na **pilha**, com a quantidade mínima de `32` funções.

<br>

> [!TIP]
> **É possível registrar um número ilimitado de funções**, basta adicionar todas a uma *função de contêiner* e registrá-la na **pilha**.

<br>

<hr>

<h4 id="21">void exit(int)</h4>

* Comportamento: encerra o programa **normalmente**, fazendo-o retornar `int`.
* Retorno: nenhum.

<hr>

<h4 id="22">char* getenv(const char*)</h4>

* Comportamento: obtém o conteúdo de uma [*variável de ambiente*](https://superuser.com/questions/284342/what-are-path-and-other-environment-variables-and-how-can-i-set-or-use-them "O que é uma 'variável de ambiente'?"), cujo nome/identificador é igual a `const char*`.
* Retorno: o conteúdo da [*variável de ambiente*](https://superuser.com/questions/284342/what-are-path-and-other-environment-variables-and-how-can-i-set-or-use-them "O que é uma 'variável de ambiente'?") ou `NULL`, caso ela não exista.

<br>

> [!NOTE]
> Alguns sistemas e implementações desta biblioteca permitem alterar o conteúdo das [*variável de ambiente*](https://superuser.com/questions/284342/what-are-path-and-other-environment-variables-and-how-can-i-set-or-use-them "O que é uma 'variável de ambiente'?"), **entretanto** esse comportamento não é portável.

<br>

<hr>

<h4 id="23">_Noreturn void quick_exit(int)</h4>

* Comportamento: executa o **pilha** de funções definida por <a href="#20"><code>at_quick_exit</code></a> e encerra o programa com êxito (fazendo-o retornar `int`).
* Retorno: nenhum.

<br>

> [!WARNING]
> *Destuidores de objetos (*__*apenas em C++*__*)* não serão chamados após o uso desta função.

<br>

> [!IMPORTANT]
> A "liberação" de *fluxos* abertos com <a href="https://github.com/duckafire/small_projects/blob/main/summaries/c/stdio.md#3" target="_blank"><code>tmpfile</code></a> dependerá do sistema e da implementação desta biblioteca.

<br>

> [!TIP]
> Veja mais sobre [`_Noreturn`](https://github.com/duckafire/small_projects/blob/main/summaries/c/stdnoreturn.md "Resumo de 'stdnoreturn.h'").

<br>

<hr>

<h4 id="24">int system(const char*)</h4>

* Comportamento: se `const char*==NULL`, verificará se há algum *processador de comandos* está disponível para a função, do contrário, tentará executar o *comando* de nome `const char*`.
* Retorno: se `const char*==NULL`, retornará um valor diferente de zero (caso haja algum *processador de comandos* disponível) ou `0` (caso não), do contrário, seu retorno dependerá do sistem e da implementação da biblioteca.

<hr>

<h4 id="25">void _Exit(int)</h4>

* Comportamento: encerra o programa **normalmente**, fazendo-o retornar `int`, **sem** chamar os *destruidores de objetos (*__*apenas em C++*__*)* e as funções da **pilha** de <a href="#"><code>atexit</code></a>.
* Retorno: nenhum.

<br>

> [!IMPORTANT]
> A "liberação" de *fluxos* abertos com <a href="https://github.com/duckafire/small_projects/blob/main/summaries/c/stdio.md#3" target="_blank"><code>tmpfile</code></a> dependerá do sistema e da implementação desta biblioteca.
<br>

<br>

<hr>

<br>

### Busca e organização

<h4 id="26">void* bsearch(const void 0*, const void 1*, size_t0, size_t1, int (*foo)(const void*, const void*))</h4>

* Comportamento: executa uma [*busca binária*](https://en.wikipedia.org/wiki/Binary_search "Wikipédia") no vetor `const void 1*` (que deve possuir `size_t0` elementos com `size_t1` de largura cada), em busca de `const void*`, usando `int (*foo)` para efetuar as comparações.
* Retorno: caso `const void 0*` seja encontrado, um ponteiro para sua posição em `const void 1*`, do contrário, NULL.

<br>

> [!CAUTION]
> Dado que está se trata de uma [*busca binária*](https://en.wikipedia.org/wiki/Binary_search "Wikipédia"), `const void 1*` deve estar ordenado. Veja <a href="#27"><code>qsort</code></a>.

<br>

> [!WARNING]
> **Sobre `int (*foo)`**: seu primeiro argumento SEMPRE será `const void 0*`, já o segundo será o "item atual" do vetor. Seu retorno deve consistir em: um valor negativo caso o primeiro argumento seja menor que o segundo, `0` caso ambos seja iguais ou um valor positivo caso o primeiro argumento seja maior que o segundo argumento.

<br>

> [!IMPORTANT]
> Caso multíplos elementos iguais a `const void 0*` sejam encontrados, qualquer um deles poderá ser retornado.

<br>

<hr>

<h4 id="27">void qsort(const void*, size_t0, size_t1, int (*foo)(const void*, const void*)</h4>

* Comportamento: executa uma [*ordenação rápida (quick sort)*](https://en.wikipedia.org/wiki/Quicksort "Wikipédia") para o conteúdo de `const void*` (que deve possuir `size_t0` elementos com `size_t1` de largura cada).
* Retorno: nenhum.

<br>

> [!WARNING]
> **Sobre `int (*foo)`**: seu retorno deve consistir em: um valor negativo caso o primeiro argumento seja menor que o segundo, `0` caso ambos seja iguais ou um valor positivo caso o primeiro argumento seja maior que o segundo argumento.

<br>

<hr>

<br>

### Matemática com inteiros

<h4 id="28">int abs(int)</h4>

* Comportamento: obtém o valor absoluto de `int`.
* Retorno: o valor obtido.

<hr>

<h4 id="29">div_t div(int0, int1)</h4>

* Comportamento: calcula a divisão de `int0` por `int1`.
* Retorno: uma estrutura contento o quociente e o resto da divisão.

<hr>

<h4 id="30">long labs(long)</h4>

* Comportamento: obtém o valor absoluto de `long`.
* Retorno: o valor obtido.

<hr>

<h4 id="31">ldiv_t ldiv(long0, long1)</h4>

* Comportamento: calcula a divisão de `long0` por `long1`.
* Retorno: uma estrutura contento o quociente e o resto da divisão.

<hr>

<h4 id="32">long long llabs(long long)</h4>

* Comportamento: obtém o valor absoluto de `long long`.
* Retorno: o valor obtido.

<hr>

<h4 id="33">lldiv_t lldiv(long long0, long long1)</h4>

* Comportamento: calcula a divisão de `long long0` por `long long1`.
* Retorno: uma estrutura contento o quociente e o resto da divisão.

<hr>

<br>

### Caracteres *multibyte*

<br>

> [!IMPORTANT]
> Estas funções possuem seu próprio *estado de mudança* (*shift state*), responsável por armazenar informações relacionadas ao estados dos caracteres *multibyte* presente em uma cadeia. Chama-la com `const char*==NULL` redefinirá esse estado.

<br>

> [!NOTE]
> O comportamento dessas funções depende da configuração de [`LC_CTYPE`](https://github.com/duckafire/small_projects/blob/main/summaries/c/locale.md "Resumo de locale.h").

<br>

> [!TIP]
> Antes de utilizar estas funções, chame-as com `const char*==NULL`, para que seu *estado de mudança* seja corretamente reiniciado.

<br>

<h4 id="34">int mblen(const char*, size_t)</h4>

* Comportamento: calcula o tamanho de `const char*`, que deve ser **um** caractere *multibyte* com no máximo `size_t` de comprimento.
* Retorno: se `const char*!=NULL` retornará o comprimento do caractere; se `const char*==NULL` retornará `0`; se o caractere for inválido retornará `-1`.

<hr>

<h4 id="35">int mbtowc(wchar_t*, const char*, size_t)</h4>

* Comportamento: converte um caractere *multibyte*, armazenado em `const char*` (com no máximo `size_t` de comprimento), em um *caractere largo* e o armazena em `wchar_t*`.
* Retorno: se `const char*!=NULL` retornará o comprimento do caractere; se `const char*==NULL` retornará `0`; se o caractere for inválido retornará `-1`.

<br>

> [!NOTE]
> `wchar_t*` **não** deve ser o endereço de uma *cadeias de caracteres largos*.

<br>

<hr>

<h4 id="36">int wctomb(char*, wchar_t)</h4>

* Comportamento: converte um *caractere largo*, armazenado em `wchar_t`, em um caractere *multibyte* e o armazena em `char*`.
* Retorno: se `const char*!=NULL` retornará o comprimento do caracteres ou `-1`, se o caractere for inválido; se `const char*==NULL` retornará um valor diferente de `0`, caso as codificações de caracteres *multibyte* forem dependentes do *estado de mudança*, ou `0`, caso contrário.

<hr>

<br>

### Cadeias de caracteres *multibyte*

<br>

> [WARNING]
> Se o total de caracteres escritos for igual a `size_t`, `wchat_t*` não contará com um caractere de terminação (`'\0'`).

<br>

> [!NOTE]
> O comportamento dessas funções depende da configuração de [`LC_CTYPE`](https://github.com/duckafire/small_projects/blob/main/summaries/c/locale.md "Resumo de locale.h").

<br>

<h4 id="37">size_t mbstowcs(wchar_t*, const char*, size_t)</h4>

* Comportamento: converte uma cadeia de caracteres *multibyte* em uma *cadeia de caracteres largos*, que tenha, no máximo, `size_t` de comprimento.
* Retorno: o número total de *caracteres largos* escritos em `wchar_t` ou `-1`, caso algum caractere inválido seja encontrado.

<hr>

<h4 id="38">size_t wcstombs(char*, wchar_t*, size_t)</h4>

* Comportamento: converte uma *cadeia de caracteres largos* em uma cadeia de caracteres *multibyte*, que tenha, no máximo, `size_t` de comprimento.
* Retorno: o número total de *bytes* escritos em `char*` ou `-1`, caso algum caractere inválido seja encontrado.

<hr>

### Fontes:
* [cplusplus: stdlib.h](https://cplusplus.com/reference/cstdlib/ )

<hr>
