# time
Este arquivo de cabeçalho declara uma macro, dois tipos, uma estrutura e diversas funções destinadas ao controle e gerenciamento de tempo.

<hr>

* `CLOCKS\_PER\_SEC`: quatidade de *ticks* que ocorrem em um intervalo de um segundo.

<hr>

* `clock\_t`: tipo responsável pelo armazenamento do tempo de processamento usado por um processo.
* `time\_t`: "tipo" encarregado de armazenar o tempo decorrido, com base no calendário do sistema.

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

* Comportamento: constrói uma cadeia de caracteres com formato `const char*`, usando os valores presente em `const struct tm*`, e armazena-a em caracteres de `char*`, que possui `size_t` de comprimento total (com `'\0'` incluso na contagem).
* Retorno: a quantidade de caracteres que foram escritos em `char*` menor um (`'\0'`).

<br>

##### Formatos (para `const char*`)

| Código | Descrição                                      | Exemplo |
| :-:    | :--                                            | :-:     |
| a      | Nome do dia da semana abreviado                | Thu |
| A      | Nome do dia da semana                          | Thursday |
| b      | Nome do mês abreriado                          | Aug |
| B      | Nome do mês                                    | August |
| c      | Data e hora                                    | Thu Aug 18 13:58:09 2025 |
| C      | Ano dividido por 100 e convertido para inteiro | 56 |
| d      | Dia do mês (`01-31`)`                          | 04 |
| D      | Mês/Dia/Ano                                    | 07/29/2025 |
| e      | Dia do mês (`1-31`)                            | 22 |
| F      | Ano-Mês-Dia                                    | 07-29-2025 |
| g      | Ano baseado em semanas, últimos dois digitos   | 23 |
| G      | Ano baseado em semanas                         | 2023 |
| h      | Nome do mês abreviado (o mesmo que `"%b"`)     | Aug |
| H      | Horas em formato de 24h                        | 13 |
| I      | Horas em formato de 12h                        | 01 |
| j      | Dias do ano (`001-365`)                        | 271 |
| m      | *Índice* dos meses do ano (`01-12`)            | 11 |
| M      | Minutos (`00-59`)                              | 34 |
| n      | Quebra de linha (`'\n'`)                       |  |
| p      | Indicador *AM* ou *PM*                         | AM |
| r      | Horário em formato de 12h                      | 01:58:09 pm |
| R      | Horário em formato de 24h                      | 13:58 |
| s      | Segundos (`00-61`)                             | 19 |
| t      | Tabulação horizontal (`'\t'`)                  |  |
| T      | Hora:Minutos:Segundos (baseado na [ISO 8601](https://en.wikipedia.org/wiki/ISO_8601 ))               | 13:58:09 |
| u      | *Índices* dos dias da semana (baseado na [ISO 8601](https://en.wikipedia.org/wiki/ISO_8601 ); `1-7`) | 2 |
| U      | *Índices* das semanas cujo primeiro dia é o Domingo (`00-53`))                                       | 52 |
| V      | *Índices* das semanas (baseado na [ISO 8601](https://en.wikipedia.org/wiki/ISO_8601 ); `01-53`)      | 35 |
| w      | *Índices* dos dias da semana (`0-6`)                                                                 | 5 |
| W      | *Índices* das semandas cujo primeiro dia é Segunda-Feira (`00-53`)                                   | 17 |
| x      | Mês/Dia/Dois últimos digitos do ano                                                                  | 07/29/25 |
| X      | Hora:Minutos:Segundos                                                                                | 13:58:09 |
| y      | Últimos dois digitos do ano                                                                          | 25 |
| Y      | Ano                                                                                                  | 2025 |
| z      | Deslocamento (baseado na [ISO 8601](https://en.wikipedia.org/wiki/ISO_8601 )) do fuso-horário do [Coordinated Universal Time (UTC)](https://en.wikipedia.org/wiki/UTC "Wikipédia")) (`1min = 1`; `1h = 100`). Se o fuso-horário não puder ser determinado, nada será imprimido | +100 |
| Z      | Nome do fuso-horário abreviado. Se o fuso-horário não puder ser determinado, nada será imprimido | CDT |
| %      | O caractere `%`                                                                                  | "%" |

<br>

> [!NOTE]
> Todos devem ser prefixados por `"%"` (`"%a"`; `"%A"`; ...).

<br>

<hr>

### Fontes:
* [wikipedia: time.h](https://pt.wikipedia.org/wiki/Time.h )
* [geekforgeeks: struct tm members](https://www.geeksforgeeks.org/time-h-header-file-in-c-with-examples/ )
* [cppreference: clock\_t](https://en.cppreference.com/w/c/chrono/clock_t )
* [wikipedia: time\_t](https://en.wikipedia.org/w/index.php?title=Time_t&oldid=450752800 )
* [cplusplus: strftime formats](https://cplusplus.com/reference/ctime/strftime/ )

<hr>
