# stdlib.h
Disponibilizar uma série de funções de uso geral, incluindo tratamento de memória dinâmica, geração de números pseudo-aleatórios e **mais**.

<hr>

> EXIT\_FAILURE: valor, dependendo do sistema, que indica que o programa foi encerrado com falha. <br>
> EXIT\_SUCCESS: valor, dependendo do sistema, que indica que o programa foi encerrado com sucesso. <br>
> MB\_CUR\_MAX: número máximo de *bytes* que podem compor um caractere *multibyte* no "idioma" atual (veja [`locale.h`](https://github.com/duckafire/small_projects/blob/main/summaries/c/locale.md "Resumo de locale.h")). <br>
> RAND\_MAX: valor máximo retornável pela função <a href="#12"><code>rand</code></a>. <br>

<br>

> [!IMPORTANT]
> `EXIT_FAILURE` e `EXIT_PROCESS` são destinados para uso como argumento na função <a href="#21"><code>rexit</code></a>.

<br>

<hr>

> `div\_t` - `ldiv\_t` - `lldiv\_t`: estruturas com dois membros destinados a armazenar o quociente e o resto de uma divisão. Seus membros possuem o mesmo tipo, porém este varia entre as estruturas, sendo respectivamente: `int` - `long` - `long long`.

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

<h4 id="1">double atof(const char*)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="2">int atoi(const char*)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="3">long atol(const char*)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="4">long long atoll(const char*)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="5">double strtod(const char*, char**)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="6">float strtof(const char*, char**)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="7">long strtol(const char*, char**, int)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="8">long double strtold(const char*, char**)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="9">long long strtoll(const char*, char**, int)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="10">unsigned long strtoul(const char*, char**, int)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="11">unsigned long long strtoull(const char*, char**, int)</h4>

* Comportamento:
* Retorno:

<hr>

<br>

### Geração de números pseudo-aleatórios

<h4 id="12">int rand(void)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="13">void srand(unsigned int)</h4>

* Comportamento:
* Retorno:

<hr>

<br>

### Gerenciamento de memórias dinâmicas

<h4 id="14">void* calloc(size_t0, size_t1)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="15">void free(void*)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="16">void* malloc(size_t)</h4>

* Comportamento:
* Retorno:

<hr>

<h4 id="17">void* realloc(void*, size_t)</h4>

* Comportamento:
* Retorno:

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
