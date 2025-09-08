# time
Este arquivo de cabeçalho trás consigo uma série de *ferramentas* voltadas ao controle e
gerenciamento do tempo.

[dst]: https://en.wikipedia.org/wiki/Daylight_saving_time "Wikipédia"
[utc]: https://en.wikipedia.org/wiki/UTC "Wikipédia"
[posix]: https://en.wikipedia.org/wiki/POSIX "Wikipédia"
[ms-crt]: https://learn.microsoft.com/en-us/cpp/c-runtime-library/windows-platforms-crt?view=msvc-170 "Microsoft"
[tm-sec]: https://stackoverflow.com/questions/765778/why-does-tm-sec-range-from-0-60-instead-of-0-59-in-time-h#765780 "Stackoverflow"
[unix-time]: https://en.wikipedia.org/wiki/Unix_time "Wikipédia"
[iso-8601]: https://en.wikipedia.org/wiki/ISO_8601 
[gmtime_r]: https://pubs.opengroup.org/onlinepubs/9799919799/functions/gmtime_r.html "Pubs.opengrounp"
[gmtime_s]: https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s?view=msvc-170 "Microsoft"
[localtime_r]: https://pubs.opengroup.org/onlinepubs/9699919799/functions/localtime.html "Pubs.opengrounp"
[localtime_s]: https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s?view=msvc-170&viewFallbackFrom=vs-2019 "Microsoft"

---

* `CLOCKS_PER_SEC`: quantidade de *ticks* que ocorrem em um intervalo de um segundo.

---

* `clock_t`: tipo capaz de armazenar o tempo de processamento usado.
* `time_t`: tipo capaz de armazenar o tempo decorrido, com base no calendário do sistema.

---

### struct tm
###### 

* Intuito: armazenar informações relacionadas a data e hora.
* Membros:
	* `int tm_sec`: segundos (0-60)
	* `int tm_min`: minutos (0-59)
	* `int tm_hour`: horas (0-23)
	* `int tm_mday`: dias (1-31)
	* `int tm_mon`: mês (0-11)
	* `int tm_year`: ano (a partir de 1900)
	* `int tm_wday`: dia do mês (0-6)
	* `int tm_yday`: dia do ano (0-365)
	* `int tm_isdst`: fuso horário (-1/0/1) - [Daylight saving time - (DST)][dst]

> [!TIP]
> [Por que `tm_sec` possui *0-60s* ao invés de *0-59s*?][tm-sec]

---

| Funções ||
|:-:|:-:|
| [asctime](#1)  | [localtime](#6)   |
| [clock](#2)    | [mktime](#7)      |
| [ctime](#3)    | [time](#8)        |
| [difftime](#4) | [strftime](#9)    |
| [gmtime](#5)   ||

---

### char\* asctime(const struct tm\*)
###### 1

* Comportamento: converte `const struct tm*` em um cadeia de caracteres de formatada.
* Retorno: o endereço de uma cadeia de caracteres estática.

> [!NOTE]
> A cadeia de caracteres é alocada estaticamente e compartilhada entre `ctime` e `asctime`,
> sendo atualizada a cada nova chamada de qualquer uma destas funções.

> [!TIP]
> Por exemplo: `"Dom Jan 01 00:00:00 1900\n\0"``

---

### clock\_t clock(void)
###### 2

* Comportamento: obtém o tempo decorrido, em milissegundos, desde o início do programa.
* Retorno: tempo decorrido.

---

### char\* ctime(const time\_t\*)
###### 3

* Comportamento: calcula o tempo decorrido (`const time_t*`) desde *Jan 00:00:00am 1970\*
(baseado no [Coordinated Universal Time - UTC][utc]) e constrói uma cadeia de caracteres
com o mesmo formato do retorno de [`asctime`](#1).
* Retorno: o endereço de uma cadeia de caracteres estática.

> [!NOTE]
> [`ctime`](#3), [`gmtime`](#5) e [`localtime`](#7) compartilham a mesma estrutura
> estática, logo chamadas de ambas estas funções poderão alterar seus valores.

> [!TIP]
> Ou seja: *Jan 00:00:00am 1970\* (em formato numérico) **menos** o conteúdo de
> `const time_t*`.

---

### double difftime(time\_t0, time\_t1)
###### 4

* Comportamento: calcula a diferença entre dois espaços de tempo.
* Retorno: a diferença.

---

### struct tm\* gmtime(const time\_t\*)
###### 5

* Comportamento: Converte `const time_t*` em uma estrutura `struct tm`, baseado no formato
[Coordinated Universal Time - UTC][utc].
* Retorno: o endereço para uma estrutura estática.

> [!NOTE]
> [`ctime`](#3), [`gmtime`](#5) e [`localtime`](#7) compartilham a mesma estrutura
> estática, logo chamadas de ambas estas funções poderão alterar seus valores.

> [!TIP]
> Por conta de compartilhar sua estrutura estática, tal função tende a não ser muito
> segura, principalmente para se trabalhar com *threads*, por conta disso, alguns *padrões*
> criaram suas próprias versões dela, as quais contém as medidas necessárias para torná-la
> segura. Ambas apresentam-se abaixo:
> 
> #### struct tm\* [gmtime\_r][gmtime_r](const time\_t\*, struct tm\*)
> ###### [`POSIX`][posix]
> 
> * Diferencial: armazena o resultado em seu segundo argumento.
> * Retorno: seu segundo argumento ou `NULL`, em caso de falha.
> 
> #### errno\_t [gmtime\_s][gmtime_s](struct tm\*, const time\_t\*)
> ###### [Microsoft CRT][ms-crt]
> 
> * Diferencial: armazena o resultado em seu primeiro argumento.
> * Retorno: `0`, em caso de sucesso, ou um valor diferente de zero.

---

### struct tm\* localtime(const time\_t\*)
###### 6

* Comportamento: Converte `const time_t` em uma estrutura `struct tm`, baseado no horário
local e levando em conta o "horário de verão".
* Retorno: o endereço para uma estrutura estática.

> [!TIP]
> A estrutura, cujo endereço é retornado, é compartilhada entre [`ctime`](#3), [`gmtime`](#5)
e [`localtime`](#7), logo chamadas de ambas estas funções poderão alterar seus valores.

> [!TIP]
> Por conta de compartilhar sua estrutura estática, tal função tende a não ser muito
> segura, principalmente para se trabalhar com *threads*, por conta disso, alguns *padrões*
> criaram suas próprias versões dela, as quais contém as medidas necessárias para torná-la
> segura. Ambas apresentam-se abaixo:
> 
> #### struct tm\* [localtime\_r][localtime_r](const time\_t\*, struct tm\*)
> ###### [`POSIX`][posix]
> 
> * Diferencial: armazena o resultado em seu segundo argumento.
> * Retorno: seu segundo argumento ou `NULL`, em caso de falha.
> 
> #### errno\_t [localtime\_s][localtime_s](struct tm\*, const time\_t\*)
> ###### [Microsoft CRT][ms-crt]
> 
> * Diferencial: armazena o resultado em seu primeiro argumento.
> * Retorno: `0`, em caso de sucesso, ou um valor diferente de zero.

---

### time\_t mktime(struct tm\*)
###### 7

* Comportamento: converte `struct tm*` para `time_t`.
* Retorno: o valor convertido ou `-1` em caso de erro.

---

### time\_t time(time\_t\*)
###### 8

* Comportamento: obtém o tempo decorrido desde *01 Jan 1970 00:00:00am*
([Relógio Unix][unix-time]), baseado no relógio do sistema. Caso `time_t*` seja diferente
de `NULL`, o retorno lhe será atribuído.
* Retorno: o tempo decorrido, em segundos.

---

### size\_t strftime(char\*, size\_t, const char\*, const struct tm\*)
###### 9

* Comportamento: constrói uma cadeia de caracteres baseado no formato especificado por
`const char*`, usando os valores presentes em `const struct tm*`, e armazena-a em
caracteres de `char*`, que possui `size_t` de comprimento total (com `'\0'` incluso na
contagem).
* Retorno: o comprimento da cadeia dada à `char*`.

##### Formatos (para `const char*`)

| Código | Descrição                                      | Exemplo |
| :-:    | :--                                            | :-:     |
| a      | Nome do dia da semana abreviado                | Thu |
| A      | Nome do dia da semana                          | Thursday |
| b      | Nome do mês abreviado                          | Aug |
| B      | Nome do mês                                    | August |
| c      | Data e hora                                    | Thu Aug 18 13:58:09 2025 |
| C      | Ano dividido por 100 e convertido para inteiro | 56 |
| d      | Dia do mês (`01-31`)`                          | 04 |
| D      | Mês/Dia/Ano                                    | 07/29/2025 |
| e      | Dia do mês (`1-31`)                            | 22 |
| F      | Ano-Mês-Dia                                    | 2025-29-07 |
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
| T      | Hora:Minutos:Segundos (baseado na [ISO 8601][iso-8601])               | 13:58:09 |
| u      | *Índices* dos dias da semana (baseado na [ISO 8601][iso-8601]; `1-7`) | 2 |
| U      | *Índices* das semanas cujo primeiro dia é o Domingo (`00-53`))                                       | 52 |
| V      | *Índices* das semanas (baseado na [ISO 8601][iso-8601]; `01-53`)      | 35 |
| w      | *Índices* dos dias da semana (`0-6`)                                                                 | 5 |
| W      | *Índices* das semanas cujo primeiro dia é Segunda-Feira (`00-53`)                                   | 17 |
| x      | Mês/Dia/Dois últimos dígitos do ano                                                                  | 07/29/25 |
| X      | Hora:Minutos:Segundos                                                                                | 13:58:09 |
| y      | Últimos dois dígitos do ano                                                                          | 25 |
| Y      | Ano                                                                                                  | 2025 |
| z      | Deslocamento (baseado na [ISO 8601][iso-8601]) do fuso horário do [Coordinated Universal Time (UTC)][utc]) (`1min = 1`; `1h = 100`). Se o fuso horário não puder ser determinado, nada será imprimido | +100 |
| Z      | Nome do fuso horário abreviado. Se o fuso horário não puder ser determinado, nada será imprimido | CDT |
| %      | O caractere `%`                                                                                  | "%" |

> [!NOTE]
> Todos devem ser prefixados por `"%"` (`"%a"`; `"%A"`; ...).

---

### Fontes:
* [wikipedia: time.h](https://pt.wikipedia.org/wiki/Time.h )
* [geekforgeeks: struct tm members](https://www.geeksforgeeks.org/time-h-header-file-in-c-with-examples/ )
* [cppreference: clock\_t](https://en.cppreference.com/w/c/chrono/clock_t )
* [wikipedia: time\_t](https://en.wikipedia.org/w/index.php?title=Time_t&oldid=450752800 )
* [cplusplus: strftime formats](https://cplusplus.com/reference/ctime/strftime/ )

---
