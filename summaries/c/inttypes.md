# inttypes
**Disponibiliza todo o conteúdo do cabeçalho `stdint.h`**, em adjunto a uma série de macros para manipulações dos tipos herdados, de `stdint.h`, em funções de entrada (`scanf`, `fscanf`, ...) e saída (`printf`, `fprintf`, `...`). Além de uma estrutura (`imaxdiv_t`) e funções para a manipulação de valores `intmax_t`.

<br>

> [!TIP]
> Veja mais sobre o cabeçalho [`stdint.h`](https://github.com/duckafire/Small_Projects/blob/main/summaries/c/stdint.md "Small_Projects/summaries").

<br>

> [!TIP]
> Diferença entre [`inttypes.h` e `stdint.h`](https://stackoverflow.com/questions/7597025/difference-between-stdint-h-and-inttypes-h "Stackoverflow")

<br>

## Índice
* <a href="#1">Macros</a>
* <a href="#2"><code>imaxdiv_t</code> (estrutura)</a>
* <a href="#3">Funções</a>
	* <a href="#3-1"><code>imaxabs</code></a>
	* <a href="#3-2"><code>imaxdiv</code></a>
	* <a href="#3-3"><code>strtoimax</code></a>
	* <a href="#3-4"><code>strtoumax</code></a>
	* <a href="#3-5"><code>wcstoimax</code></a>
	* <a href="#3-6"><code>wcstoumax</code></a>

<br>

<h3 id="1">Macros</h3>

* As macros de manipulações desse cabeçalho seguem o seguinte padrão:
	* Primeiros três caracteres:
		* `SCN` para funções de entrada.
		* `PRI` para funções de saída.
	* Quatro caractere:
		* `x` para hexadeciaml.
		* `o` para octal.
		* `u` para inteiros não assinados.
		* `i` para inteiros.
	* Caracteres remanecentes:
		* **N** para inteiros com exatos 8, 16, 32 ou 64 *bytes* de largura.
		* <code>PTR<strong  >N</strong></code> para `intptr_t`.
		* <code>MAX<strong  >N</strong></code> para `intmax_t`.
		* <code>LEAST<strong>N</strong></code> para `int_least_t`.
		* <code>FAST<strong >N</strong></code> para `int_fast_t`.
	
<br>

> Exemplos: `PRIx16`; `SCNuMAX`; `SCNoFAST64`.

<hr>

<h3 id="2">imaxdiv_t</h3>

* Intuito: armazenar o quociente e o resto da divisão de um `intmax_t`.
* Membros: `intmax_t quocient`, `intmax_t remainder`.

<hr>

<h3 id="3">Funções</h3>

<h4 id="3-1">intmax_t imaxabs(intmax_t)</h4>
* Comportamento: obtém o valor absoluto do `intmax_t`.
* Retorno: valor obtido.

<br>

<h4 id="3-2">imaxdiv_t imaxdiv(intmax_t-0, intmax_t-1)</h4>
* Comportamento: calcula a divisão de `intmax_t-0` por `intmax_t-1`.
* Retorno: uma estrutura contento o quociente e o resto da divisão.

<br>

<h4 id="3-3">intmax_t strtoimax(const char*, char**, int)</h4>
* Comportamento: converte `const char*` em um inteiro de base `int` (`0` para detecção automática ou valores de `2` até `36`).
* Retorno: o valor inteiro obtido.

<br>

<h4 id="3-4">uintmax_t strtoumax(const char *, char **, int)</h4>
* Comportamento: converte `const char*` em um **inteiro não assinado** de base `int` (`0` para detecção automática ou valores de `2` até `36`).
* Retorno: o valor **inteiro não assinado** obtido.

<br>

<h4 id="3-5">intmax_t wcstoimax(const wchar_t *, wchar_t **, int)</h4>
* Comportamento: converte `const wchar_t*` em um **inteiro não assinado** de base `int` (`0` para detecção automática ou valores de `2` até `36`).
* Retorno: o valor **inteiro não assinado** obtido.

<br>

<h4 id="3-6">uintmax_t wcstoumax(const wchar_t *restrict, wchar_t **restrict, int)</h4>
* Comportamento: converte `const wchar_t*` em um **inteiro não assinado** de base `int` (`0` para detecção automática ou valores de `2` até `36`).
* Retorno: o valor **inteiro não assinado** obtido.

<br>

> [!NOTE]
> `char**` (e `wchar_t**`) receberá o endereço do primeiro caractere inválido (que não pode ser convertido para inteiro) de `const char *` (`const wchar_t`).

<br>

> [!TIP]
> Use `char**==NULL` (`wchar_t**==NULL`), caso este seja irrelevante.

<br>

> [!TIP]
> Veja também: <a href="https://en.cppreference.com/w/c/string/byte/strtoimax"><u>strtoimax x strutomax</u></a>; <a href="https://en.cppreference.com/w/c/string/wide/wcstoimax"><u>wcstoimax x wcstoumax</u></a>.

<hr>

#### Fontes:
* [wikibooks](https://en.wikibooks.org/wiki/c_programming/inttypes.h)
* [cplusplus](https://cplusplus.com/reference/cinttypes/)
* [pubs.openground](https://pubs.opengroup.org/onlinepubs/009695399/basedefs/inttypes.h.html)

<hr>
