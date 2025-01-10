# time
Este arquivo de cabeçalho declara uma macro, dois tipos, uma estrutura e diversas funções destinadas ao controle e gerenciamento de tempo.

<hr>

* CLOCKS\_PER\_SEC: quatidade de *ticks* que ocorrem em um intervalo de um segundo.

<hr>

* clock\_t: tipo responsável pelo armazenamento do tempo de processamento usado por um processo.
* time\_t: "tipo" encarregado de armazenar o tempo decorrido, com base no calendário do sistema.

<hr>

<h3>struct tm</h3>

* Intuito: armazenar informações relacionadas a data e hora.
* Mebros:
	* `int tm_sec`: segundos (0-60)
	* `int tm_min`: minutos (0-59)
	* `int tm_hour`: horas (0-23)
	* `int tm_mday`: dias (1-31)
	* `int tm_mon`: mês (0-11)
	* `int tm_year`: ano (a partir de 1900)
	* `int tm_wday`: dia do mês (0-6)
	* `int tm_yday`: dia do ano (0-365)
	* `int tm_isdst`: "horário de verão" (-1/0/1) - [Daylight saving time - (DST)](https://en.wikipedia.org/wiki/Daylight_saving_time "Wikipédia")

<br>

> [!TIP]
> [Por que `tm_sec` possui *0-60s* ao invés de *0-59s*?](https://stackoverflow.com/questions/765778/why-does-tm-sec-range-from-0-60-instead-of-0-59-in-time-h#765780 "Stackoverflow")

<br>

<hr>

| Funções ||
|:-:|:-:|
| <a href="#1">asctime</a>  | <a href="#6">localtime</a>   |
| <a href="#2">clock</a>    | <a href="#7">mktime</a>      |
| <a href="#3">ctime</a>    | <a href="#8">time</a>        |
| <a href="#4">difftime</a> | <a href="#9">strftime</a>    |
| <a href="#5">gmtime</a>   ||

<hr>

<h3 id="1">char *asctime(const struct tm*)</h3>

* Comportamento: converte `const struct tm*` em um cadeia de caracteres de formato `"Dom Jan 01 12:00:00 2000\n\0"` (conteúdo exemplar).
* Retorno: o endereço de uma cadeia de caracteres estátca.

<br>

> [!NOTE]
> A cadeia de caracteres é alocada estaticamente e compartilhada entre `ctime` e `asctime`, sendo atualizada a cada nova chamada de qualquer uma destas funções.

<br>

<hr>

<h3 id="2">clock_t clock(void)</h3>

* Comportamento: obtém o tempo decorrido, em milissegundos, desde o início do programa.
* Retorno: tempo decorrido.

<hr>

<h3 id="3">char* ctime(const time_t*)</h3>

* Comportamento: calcula o tempo decorrido (`const time_t`) desde *Jan 00:00:00am 1970* (baseado no [Coordinated Universal Time - UTC](https://en.wikipedia.org/wiki/UTC "Wikipédia")) e constrói uma cadeia de caracteres com o mesmo formato do retorno de <a href="#1"><code>asctime</code></a>.
* Retorno: o endereço de uma cadeia de caracteres estátca.

<br>

> [!TIP]
> Tal função tem acesso a uma estrutura estática (`struct tm`) compartilhada entre <a href="#5"><code>gmtime</code></a> e <a href="#7"><code>localtime</code></a>, logo chamadas de ambas estas funções poderão alterar seus valores.

<br>

<hr>

<h3 id="4">double difftime(time_t-0, time_t-1)</h3>

* Comportamento: calcula a diferença entre dois espaços de tempo.
* Retorno: a diferença.

<hr>

<h3 id="5">struct tm* gmtime(const time_t*)</h3>

* Comportamento: Converte `const time_t` em uma estrutura `struct tm`, baseado no formato [Coordinated Universal Time - UTC](https://en.wikipedia.org/wiki/UTC "Wikipédia").
* Retorno: o endereço para uma estrutura estática.

<br>

> [!TIP]
> A estrutura, cujo endereço é retornado, é compartilhada entre <a href="#3"><code>ctime</code></a>, <a href="#5"><code>gmtime</code></a> e <a href="#7"><code>localtime</code></a>, logo chamadas de ambas estas funções poderão alterar seus valores.

<br>

> [!TIP]
> Por compartilhar uma estrutura estática, essa função tende a não ser muito *segura*, principalmente para trabalhar-se com *threads*, por causa disso o padrão [`POSIX`](https://en.wikipedia.org/wiki/POSIX "Wikipédia") e o padrão [`Microsoft/Windows CRT`](https://learn.microsoft.com/en-us/cpp/c-runtime-library/windows-platforms-crt?view=msvc-170 "Microsoft") criaram suas próprias versões desta função, sendo elas, respectivamente, <a href="https://pubs.opengroup.org/onlinepubs/9799919799/functions/gmtime_r.html" title="Pubs.opengroun"><code>struct tm* gmtime_r(const time_t*, struct tm*)</code></a> e <a href="https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s?view=msvc-170" title="Microsoft"><code>errno_t gmtime_s(struct tm*, const time_t*)</code></a> O que as difere é o fato de que os valores são atribuidos a uma estrutura passado pelo usuário (`struct tm*`), ao invés de uma estrutura estática. A versão POSIX retorna o argumento `struct tm*` ou `NULL` em caso de falha, já a versão `CRT` retorná `0` ou um cógigo de erro.

<br>

<hr>

<h3 id="6">struct tm* localtime(const time_t*)</h3>

* Comportamento: Converte `const time_t` em uma estrutura `struct tm`, baseado no horário local e levando em conta o "horário de verão".
* Retorno: o endereço para uma estrutura estática.

<br>

> [!TIP]
> A estrutura, cujo endereço é retornado, é compartilhada entre <a href="#3"><code>ctime</code></a>, <a href="#5"><code>gmtime</code></a> e <a href="#7"><code>localtime</code></a>, logo chamadas de ambas estas funções poderão alterar seus valores.

<br>

> [!TIP]
> Por compartilhar uma estrutura estática, essa função tende a não ser muito *segura*, principalmente para trabalhar-se com *threads*, por causa disso o padrão [`POSIX`](https://en.wikipedia.org/wiki/POSIX "Wikipédia") e o padrão [`Microsoft/Windows CRT`](https://learn.microsoft.com/en-us/cpp/c-runtime-library/windows-platforms-crt?view=msvc-170 "Microsoft") criaram suas próprias versões desta função, sendo elas, respectivamente, <a href="https://pubs.opengroup.org/onlinepubs/9699919799/functions/localtime.html" title="Pubs.opengroun"><code>struct tm* localtime_r(const time_t*, struct tm*)</code></a> e <a href="https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s?view=msvc-170&viewFallbackFrom=vs-2019" title="Microsoft"><code>errno_t localtime_s(struct tm*, const time_t*)</code></a> O que as difere é o fato de que os valores são atribuidos a uma estrutura passado pelo usuário (`struct tm*`), ao invés de uma estrutura estática. A versão POSIX retorna o argumento `struct tm*` ou `NULL` em caso de falha, já a versão `CRT` retorná `0` ou um cógigo de erro.

<br>

<hr>

<h3 id="7">time_t mktime(struct tm*)</h3>

* Comportamento: converte `struct tm*` para `time_t`.
* Retorno: o valor convertido ou `-1` em caso de erro.

<hr>

<h3 id="8">time_t time(time_t*)</h3>

* Comportamento: obtém o tempo decorrido desde *01 Jan 1970 00:00:00am* ([Relógio Unix](https://en.wikipedia.org/wiki/Unix_time "Wikipédia")), baseado no relógio do sistema. Caso `time_t*` seja diferente de `NULL`, seu retorno lhe será atribuído;
* Retorno: o tempo decorrido, em segundos.

<hr>

<h3 id="9">size_t strftime(char*, size_t, const char*, const struct tm*)</h3>

* Comportamento: constrói uma cadeia de caracteres com formato `const char*`, usando os valores presente em `const struct tm*`, e armazena-a em caracteres de `char*`, que possui `size_t` de comprimento total.
* Retorno: a quantidade de caracteres que foram escritos em `char*` menor um (`'\0'`).

<hr>

### Fontes:
* [wikipedia: time.h](https://pt.wikipedia.org/wiki/Time.h )
* [geekforgeeks: struct tm members](https://www.geeksforgeeks.org/time-h-header-file-in-c-with-examples/ )
* [cppreference: clock\_t](https://en.cppreference.com/w/c/chrono/clock_t )
* [wikipedia: time\_t](https://en.wikipedia.org/w/index.php?title=Time_t&oldid=450752800 )

<hr>
