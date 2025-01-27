# stdlib.h
Disponibilizar uma série de funções de uso geral, incluindo tratamento de memória dinâmica, geração de números pseudo-aleatórios e **mais**.

<hr>

* EXIT\_FAILURE: valor, dependendo do sistema, que indica que o programa foi encerrado com falha.
* EXIT\_SUCCESS: valor, dependendo do sistema, que indica que o programa foi encerrado com sucesso.
* MB\_CUR\_MAX: número máximo de *bytes* que podem compor um caractere *multibyte* no "idioma" atual (veja [`locale.h`](https://github.com/duckafire/small_projects/blob/main/summaries/c/locale.md "Resumo de locale.h")).
* RAND\_MAX: valor máximo retornável pela função <a href="#12"><code>rand</code></a>.

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

* Comportamento:
* Retorno:

<hr>

<h4 id="19">int atexit(void (*foo)(void))</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="20">int at_quick_exit(void (*foo)(void))</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="21">void exit(int)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="22">char* getenv(const char*)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="23">_Noreturn void quick_exit(void)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="24">int system(const char*)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="25">void _Exit(int)</h4>

* Comportamento:
* Retorno:

<hr>

<br>

### Busca e organização

<h4 id="26">void* bsearch(const void 0*, const void 1*, size_t0, size_t1, int (*foo)(const void*, const void*))</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="27">void qsort(const void*, size_t0, size_t1, int (*foo)(const void*, const void*)</h4>

* Comportamento:
* Retorno:

<hr>

<br>

### Matemática com inteiros

<h4 id="28">int abs(int)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="29">div_t div(int0, int1)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="30">long labs(long)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="31">ldiv_t ldiv(long0, long1)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="32">long long llabs(long long)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="33">lldiv_t lldiv(long long0, long long1)</h4>

* Comportamento:
* Retorno:

<hr>

<br>

### Caracteres *multibyte*

<h4 id="34">int mblen(const char*, size_t)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="35">int mbtowc(wchar_t*, const char*, size_t)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="36">int wctomb(char*, wchar_t)</h4>

* Comportamento:
* Retorno:

<hr>

<br>

### Cadeias de caracteres *multibyte*

<h4 id="37">size_t mbstowcs(wchar_t*, const char*, size_t)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="38">size_t wcstombs(char*, wchar_t*, size_t)</h4>

* Comportamento:
* Retorno:

<hr>

### Fontes:
* [cplusplus: stdlib.h](https://cplusplus.com/reference/cstdlib/ )

<hr>
