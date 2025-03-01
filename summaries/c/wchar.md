# wchar
Esse cabeçalho disponibiliza algumas poucas macros, tipos e funções de conversão destinadas
a manipulação de *caracteres largos/estendidos* (*wide characteres*). Nele também estão
disponíveis versões de funções nativas de outras bibliotecas do *Padrão C*
(`strcpy => wcscpy`), devidamente modificadas para suportar *caracteres largos*.

---

* `WCHAR_MIN`: tamanho mínimo de um *caractere largo*.
* `WCHAR_MAX`: tamanho máximo de um *caractere largo*.
* `WEOF`: *caractere largo* de final de arquivo.

---

* `wchar_t`: tipo para armazenar *caracteres largos*
* `wint_t`: tipo inteiro para códigos de *caracteres largos* e *multibyte*.
* `mbstate_t`: estrutura encarregada de armazenar as informações necessárias para manter o
estado dos caracteres de uma cadeia, durante conversões de cadeias de caracteres
*multibytes* para cadeias de *caracteres largos* (`mbstowcs`) ou o inverso (`wcsrtobms`),
além de outras operações envolvendo caracteres *multibyte*.

---

| Funções      |
| :-:          |
| [btowc](#1)  |
| [mbsinit](#2)|
| [wctob](#3)  |

* Funções derivadas de:
	* [stdio.h](#4)
	* [stdlib.h](#5)
	* [string.h](#6)
	* [time.h](#7)

---

### wint\_t btowc(int)
###### 1

* Comportamento: converte `int` em um *multibyte* com um *byte* de comprimento.
* Retorno: o caractere convertido ou `WEOF`, se `int` não possuir uma representação
*multibyte* com um *byte* de comprimento ou for igual a `EOF`.

---

### int mbsinit(const mbstate\_t*)
###### 2

* Comportamento: verifica se `const mbstate_t*` está armazenando algum valor de conversão.
* Retorno: um valor diferente de `0` caso `const mbstate_t*` esteja armazenando algum valor
de conversão, do contrário um valor diferente de `0`.

> [!NOTE]
> "Valor de conversão" refere-se a qualquer valor diferente de `0` que esteja armazenado em
> qualquer um dos membros de `const mbstate_t*`, os quais podem recebê-los após serem
> usados em funções desta biblioteca, como `mbrtowc`.

---

### int wctob(wint\_t)
###### 3

* Comportamento: converte `wint_t`, um caractere *multibyte* com um *byte* de comprimento,
em um caractere de *byte único*.
* Retorno: o caractere convertido ou `EOF`, se `wint_t` não possuir uma representação
*byte único* ou for igual a `WEOF`.

---

#### Versões derivadas de [`stdio.h`](https://github.com/duckafire/Small_Projects/blob/main/summaries/c/stdio.md)
###### 4

| stdio.h   | wchar.h   |   | stdio.h   | stdio.h   |   | stdio.h   | stdio.h   |
| :-:       | :-:       |:-:| :-:       | :-:       |:-:| :-:       | :-:       |
| fgetc     | fgetwc    |   | getchar   | getwchar  |   | vfscanf   | vfwscanf  |
| fgets     | fgetws    |   | putc      | putwc     |   | vsnprintf | vswprintf |
| fputc     | fputwc    |   | putchar   | putwchar  |   | vsscanf   | vswscanf  |
| fputs     | fputws    |   | snprintf  | swprintf  |   | vprintf   | vwprintf  |
| fprintf   | fwprintf  |   | sscanf    | swscanf   |   | vscanf    | vwscanf   |
| fscanf    | fwscanf   |   | ungetc    | ungetwc   |   |           |           |
| getc      | getwc     |   | vfprintf  | vfwprintf |   |           |           |

> ##### Retorno, identificador e parâmetros
> 
> | stdio.h                                           | wchar.h                                                     |
> | :--                                               | :--                                                         |
> | int fgetc(FILE\*)                                 | wint\_t fgetwc(FILE\*)                                      |
> | char\* fgets(char\*, int, FILE\*)                 | wchar\_t\* fgetws(wchar\_t\*, int, FILE\*)                  |
> | int fputc(int, FILE\*)                            | wint\_t fputwc(wint\_t, FILE\*)                             |
> | int fputs(const char\*, FILE\*)                   | int fputws(const wchar\_t\*, FILE\*)                        |
> | int fprintf(FILE\*, const char\*, ...)            | int fwprintf(FILE\*, const wchar\_t\*, ...)                 |
> | int fscanf(FILE\*, const char\*, ...)             | int fwscanf(FILE\*, const wchar\_t\*, ...)                  |
> | int getc(FILE\*)                                  | wint\_t getwc(FILE\*)                                       |
> | int getchar(void)                                 | wint\_t getwchar(void)                                      |
> | int putc(int, FILE\*)                             | wint\_t putwc(wint\_t, FILE\*)                              |
> | int putchar(int)                                  | int putwchar(wint\_t)                                       |
> | int snprintf(char\*, size\_t, const char\*, ...)  | int swprintf(wchar\_t\*, const wchar\_t\*, ...)             |
> | int sscanf(const char\*, const char\*, ...)       | int swscanf(const wchar\_t\*, const wchar\_t\*, ...)        |
> | int ungetc(int, FILE\*)                           | int ungetwc(wint\_t, FILE\*)                                |
> | int vfprintf(FILE\*, const char\*, va\_list)      | int vfwprintf(FILE\*, const wchar\_t\*, va\_list)           |
> | int vfscanf(FILE\*, const char\*, va\_list)       | int vfwscanf(FILE\*, const wchar\_t\*, va\_list)            |
> | int vsnprintf(char\*, size\_t, const char\*, ...) | int vswprintf(wchar\_t\*, size\_t, const wchar\_t\*, ...)   |
> | int vsscanf(const char\*, const char\*, va\_list) | int vswscanf(const wchar\_t\*, const wchar\_t\*, va\_list)  |
> | int vprintf(const char\*, ...)                    | int vwprintf(const wchar\_t\*, ...)                         |
> | int vscanf(const char \*, ...)                    | int vwscanf(const wchar\_t \*, ...)                         |

---

#### Versões derivadas de [`stdlib.h`](https://github.com/duckafire/Small_Projects/blob/main/summaries/c/stdlib.md)
###### 5

> Utilidades gerais

| stdlib.h | wchar.h  |
| :-:      | :-:      |
| strtod   | wcstod   |
| strtof   | wcstof   |
| strtol   | wcstol   |
| strtold  | wcstold  |
| strtoll  | wcstoll  |
| strtoul  | wcstoul  |
| strtoull | wcstoull |

> Conversão

| stdlib.h | wchar.h   |
| :-:      | :-:       |
| mblen    | mbrlen    |
| mbtowc   | mbrtowc   |
| mbstowcs | mbsrtowcs |
| wctomb   | wcrtomb   |
| wcstombs | wcsrtombs |

> ##### Retorno, identificador e parâmetros
> 
> | stdlib.h                                                 | wchar.h                                                          |
> | :--                                                      | :--                                                              |
> | double strtod(const char\*, char\*\*)                    | double wcstod(const wchar\_t\*, wchar\_t\*\*)                    |
> | float strtof(const char\*, char\*\*)                     | float wcstof(const wchar\_t\*, wchar\_t\*\*)                     |
> | long strtol(const char\*, char\*\*, int)                 | long wcstol(const wchar\_t\*, wchar\_t\*\*, int)                 |
> | long double strtold(const char\*, char\*\*)              | long double wcstold(const wchar\_t\*, wchar\_t\*\*)              |
> | long long strtoll(const char\*, char\*\*, int)           | long long wcstoll(const wchar\_t\*, wchar\_t\*\*, int)           |
> | unsigned long strtoul(const char\*, char\*\*, int)       | unsigned long wcstoul(const wchar\_t\*, wchar\_t\*\*, int)       |
> | unsigned long long strtoull(const char\*, char\*\*, int) | unsigned long long wcstoull(const wchar\_t\*, wchar\_t\*\*, int) |
> 
> | stdlib.h                                            | wchar.h                                                              |
> | :--                                                 | :--                                                                  |
> | int mblen(const char\*, size\_t)                    | size\_t mbrlen(const char\*, size\_t, mbstate\_t\*)                  |
> | int mbtowc(wchar\_t\*, const char\*, size\_t)       | size\_t mbrtowc(wchar\_t, const char\*, size\_t, mbstate\_t\*)       |
> | size\_t mbstowcs(wchar\_t\*, const char\*, size\_t) | size\_t mbsrtowcs(wchar\_t\*, const char\*\*, size\_t, mbstage\_t\*) |
> | int wctomb(char\*, wchar\_t\*)                      | size\_t wcrtomb(char\*, wchar\_t, mbstate\_t\*)                      |
> | size\_t wcstombs(char\*, const wchar\_t\*, size\_t) | size\_t wcsrtombs(char\*, const wchar\_t\*\*, size\_t, mbstate\_t\*) |

---

#### Versões derivadas de [`string.h`](https://github.com/duckafire/Small_Projects/blob/main/summaries/c/string.md)
###### 6

| string.h | wchar.h |   | string.h | wchar.h |   | string.h | wchar.h |
| :-:      | :-:     |:-:| :-:      | :-:     |:-:| :-:      | :-:     |
| memchr   | wmemchr |   | strchr   | wcschr  |   | strlen   | wcslen  |
| memcmp   | wmemcmp |   | strcmp   | wcscmp  |   | strpbrk  | wcspbrk |
| memcpy   | wmemcpy |   | strncmp  | wcsncmp |   | strrchr  | wcsrchr |
| memmove  | wmemmove|   | strcoll  | wcscoll |   | strspn   | wcsspn  |
| memset   | wmemset |   | strcpy   | wcscpy  |   | strstr   | wcsstr  |
| strcat   | wcscat  |   | strncpy  | wcsncpy |   | strtok   | wcstok  |
| strncat  | wcsncat |   | strcspn  | wcscspn |   | strxfrm  | wcsxfrm |

> ##### Retorno, identificador e parâmetros
> 
> | string.h                                          | wchar.h                                                    |
> | :--                                               | :--                                                        |
> | void\* memchr (const void\*, int)                 | wchar\_t\* wmemchr (const wchar\_t\*, wchar\_t)            |
> | int memcmp (const void\*, const void\*, size\_t)  | int wmemcmp (const wchar\_t\*, const wchar\_t\*, size\_t)  |
> | void\* memcpy (void\*, const void\*, size\_t)     | wchar\_t\* wmemcpy (wchar\_t\*, const wchar\_t\*, size\_t) |
> | void\* memmove (void\*, const void\*, size\_t)    | wchar\_t\* wmemmove (wchar\_t\*, const wchar\_t\*, size\_t)|
> | void\* memset (void\*, int, size\_t)              | wchar\_t\* wmemset (wchar\_t\*, wchar\_t, size\_t)         |
> | char\* strcat (char\*, const char\*)              | wchar\_t\* wcscat (wchar\_t\*, const wchar\_t\*)           |
> | char\* strncat (char\*, const char\*, size\_t)    | wchar\_t\* wcsncat (wchar\_t\*, const wchar\_t\*, size\_t) |
> | char\* strchr (const char\*, int)                 | wchar\_t\* wcschr (const wchar\_t\*, wchar\_t)             |
> | int strcmp (const char\*, const char\*)           | int wcscmp (const wchar\_t\*, const wchar\_t\*)            |
> | int strncmp (const char\*, const char\*, size\_t) | int wcsncmp (const wchar\_t\*, const wchar\_t\*, size\_t)  |
> | int strcoll (const char\*, const char\*)          | int wcscoll (const wchar\_t\*, const wchar\_t\*)           |
> | char\* strcpy (char\*, const char\*)              | wchar\_t\* wcscpy (wchar\_t\*, const wchar\_t\*)           |
> | char\* strncpy (char\*, const char\*, size\_t)    | wchar\_t\* wcsncpy (wchar\_t\*, const wchar\_t\*, size\_t) |
> | size\_t strcspn (const char\*, const char\*)      | size\_t wcscspn (const wchar\_t\*, const wchar\_t\*)       |
> | size\_t strlen (const char\*)                     | size\_t wcslen (const wchar\_t\*)                          |
> | char\* strpbrk (const char\*, const char\*)       | wchar\_t\* wcspbrk (const wchar\_t\*, const wchar\_t\*)    |
> | char\* strrchr (const char\*, int)                | wchar\_t\* wcsrchr (const wchar\_t\*, wchar\_t)            |
> | size\_t strspn (const char\*, const char\*)       | size\_t wcsspn (const wchar\_t\*, const wchar\_t\*)        |
> | char\* strstr (const char\*, const char\*)        | wchar\_t\* wcsstr (const wchar\_t\*, const wchar\_t\*)     |
> | char\* strtok (char\*, const char\*)              | wchar\_t\* wcstok (wchar\_t\*, const wchar\_t\*)           |
> | size\_t strxfrm (char\*, const char\*)            | size\_t wcsxfrm (wchar\_t\*, const wchar\_t\*)             |

---

#### Versões derivadas de [`time.h`](https://github.com/duckafire/Small_Projects/blob/main/summaries/c/time.md)
###### 7

| time.h   | wchar.h  |
| :-:      | :-:      |
| strftime | wcsftime |

> ##### Retorno, identificador e parâmetros
> 
> | time.h | wchar.h |
> | :--    | :--     |
> | size\_t strftime(char\*, size\_t, const char\*, const struct tm\*) | size\_t wcsftime (wchar\_t\*, size\_t, const wchar\_t\*, const struct tm\*) |

---

### Fonte:
* [cplusplus: derivated function list](https://cplusplus.com/reference/cwchar/ )
* [archlinux: btowc](https://man.archlinux.org/man/extra/man-pages-pt_br/btowc.3.pt_BR )
* [cppreference: mbsinit](https://en.cppreference.com/w/c/string/multibyte/mbsinit )

---
