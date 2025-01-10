# wchar
Esse cabeçalho disponibiliza macros, tipos e funções destinadas a manipulação de *caracteres largos/extendidos* (*wide characteres*). Nele também estão disponíveis versões de funções nativas de outras bibliotecas do *Padrão C* (`strcpy => wcscpy`), devidamente modificadas para suportar *caracteres largos*.

<hr>

| Funções |
| :-:     |
| -       |

<br>

* Funções derivadas de:
	* [stdio.h](#stdio.h)
	* [stdlib.h](#stdlib.h)
	* [string.h](#string.h)
	* [time.h](#time.h)

<br>

<hr>

<h3 id="stdio.h">Versões derivadas de <code>stdio.h</code></h3>

| stdio.h   | wchar.h   |   | stdio.h   | stdio.h   |   | stdio.h   | stdio.h   |
| :-:       | :-:       |:-:| :-:       | :-:       |:-:| :-:       | :-:       |
| fgetc     | fgetwc    |   | getchar   | getwchar  |   | vfscanf   | vfwscanf  |
| fgets     | fgetws    |   | putc      | putwc     |   | vsnprintf | vswprintf |
| fputc     | fputwc    |   | putchar   | putwchar  |   | vsscanf   | vswscanf  |
| fputs     | fputws    |   | snprintf  | swprintf  |   | vprintf   | vwprintf  |
| fprintf   | fwprintf  |   | sscanf    | swscanf   |   | vscanf    | vwscanf   |
| fscanf    | fwscanf   |   | ungetc    | ungetwc   |   |           |           |
| getc      | getwc     |   | vfprintf  | vfwprintf |   |           |           |

<details><summary>Retorno, identificador e parâmetros</summary>

| stdio.h                                           | wchar.h                                                     |
| :--                                               | :--                                                         |
| int fgetc(FILE\*)                                 | wint\_t fgetwc(FILE\*)                                      |
| char\* fgets(char\*, int, FILE\*)                 | wchar\_t\* fgetws(wchar\_t\*, int, FILE\*)                  |
| int fputc(int, FILE\*)                            | wint\_t fputwc(wint\_t, FILE\*)                             |
| int fputs(const char\*, FILE\*)                   | int fputws(const wchar\_t\*, FILE\*)                        |
| int fprintf(FILE\*, const char\*, ...)            | int fwprintf(FILE\*, const wchar\_t\*, ...)                 |
| int fscanf(FILE\*, const char\*, ...)             | int fwscanf(FILE\*, const wchar\_t\*, ...)                  |
| int getc(FILE\*)                                  | wint\_t getwc(FILE\*)                                       |
| int getchar(void)                                 | wint\_t getwchar(void)                                      |
| int putc(int, FILE\*)                             | wint\_t putwc(wint\_t, FILE\*)                              |
| int putchar(int)                                  | int putwchar(wint\_t)                                       |
| int snprintf(char\*, size\_t, const char\*, ...)  | int swprintf(wchar\_t\*, const wchar\_t\*, ...)             |
| int sscanf(const char\*, const char\*, ...)       | int swscanf(const wchar\_t\*, const wchar\_t\*, ...)        |
| int ungetc(int, FILE\*)                           | int ungetwc(wint\_t, FILE\*)                                |
| int vfprintf(FILE\*, const char\*, va\_list)      | int vfwprintf(FILE\*, const wchar\_t\*, va\_list)           |
| int vfscanf(FILE\*, const char\*, va\_list)       | int vfwscanf(FILE\*, const wchar\_t\*, va\_list)            |
| int vsnprintf(char\*, size\_t, const char\*, ...) | int vswprintf(wchar\_t\*, size\_t, const wchar\_t\*, ...)   |
| int vsscanf(const char\*, const char\*, va\_list) | int vswscanf(const wchar\_t\*, const wchar\_t\*, va\_list)  |
| int vprintf(const char\*, ...)                    | int vwprintf(const wchar\_t\*, ...)                         |
| int vscanf(const char \*, ...)                    | int vwscanf(const wchar\_t \*, ...)                         |

</details>

<br>

<h3 id="stdlib.h">Versões derivadas de <code>stdlib.h</code></h3>

| stdlib.h | wchar.h  |
| :--      | :--      |
| strtod   | wcstod   |
| strtof   | wcstof   |
| strtol   | wcstol   |
| strtold  | wcstold  |
| strtoll  | wcstoll  |
| strtoul  | wcstoul  |
| strtoull | wcstoull |

<details><summary>Retorno, identificador e parâmetros</summary>

| stdlib.h                                                 | wchar.h                                                          |
| :--                                                      | :--                                                              |
| double strtod(const char\*, char\*\*)                    | double wcstod(const wchar\_t\*, wchar\_t\*\*)                    |
| float strtof(const char\*, char\*\*)                     | float wcstof(const wchar\_t\*, wchar\_t\*\*)                     |
| long strtol(const char\*, char\*\*, int)                 | long wcstol(const wchar\_t\*, wchar\_t\*\*, int)                 |
| long double strtold(const char\*, char\*\*)              | long double wcstold(const wchar\_t\*, wchar\_t\*\*)              |
| long long strtoll(const char\*, char\*\*, int)           | long long wcstoll(const wchar\_t\*, wchar\_t\*\*, int)           |
| unsigned long strtoul(const char\*, char\*\*, int)       | unsigned long wcstoul(const wchar\_t\*, wchar\_t\*\*, int)       |
| unsigned long long strtoull(const char\*, char\*\*, int) | unsigned long long wcstoull(const wchar\_t\*, wchar\_t\*\*, int) |

</details>

<br>

<h3 id="string.h">Versões derivadas de <code>string.h</code></h3>

| string.h | wchar.h |   | string.h | wchar.h |   | string.h | wchar.h |
| :-:      | :-:     |:-:| :-:      | :-:     |:-:| :-:      | :-:     |
| memchr   | wmemchr |   | strchr   | wcschr  |   | strlen   | wcslen  |
| memcmp   | wmemcmp |   | strcmp   | wcscmp  |   | strpbrk  | wcspbrk |
| memcpy   | wmemcpy |   | strncmp  | wcsncmp |   | strrchr  | wcsrchr |
| memmove  | wmemmove|   | strcoll  | wcscoll |   | strspn   | wcsspn  |
| memset   | wmemset |   | strcpy   | wcscpy  |   | strstr   | wcsstr  |
| strcat   | wcscat  |   | strncpy  | wcsncpy |   | strtok   | wcstok  |
| strncat  | wcsncat |   | strcspn  | wcscspn |   | strxfrm  | wcsxfrm |

<details><summary>Retorno, identificador e parâmetros</summary>

| string.h                                          | wchar.h                                                    |
| :--                                               | :--                                                        |
| void\* memchr (const void\*, int)                 | wchar\_t\* wmemchr (const wchar\_t\*, wchar\_t)            |
| int memcmp (const void\*, const void\*, size\_t)  | int wmemcmp (const wchar\_t\*, const wchar\_t\*, size\_t)  |
| void\* memcpy (void\*, const void\*, size\_t)     | wchar\_t\* wmemcpy (wchar\_t\*, const wchar\_t\*, size\_t) |
| void\* memmove (void\*, const void\*, size\_t)    | wchar\_t\* wmemmove (wchar\_t\*, const wchar\_t\*, size\_t)|
| void\* memset (void\*, int, size\_t)              | wchar\_t\* wmemset (wchar\_t\*, wchar\_t, size\_t)         |
| char\* strcat (char\*, const char\*)              | wchar\_t\* wcscat (wchar\_t\*, const wchar\_t\*)           |
| char\* strncat (char\*, const char\*, size\_t)    | wchar\_t\* wcsncat (wchar\_t\*, const wchar\_t\*, size\_t) |
| char\* strchr (const char\*, int)                 | wchar\_t\* wcschr (const wchar\_t\*, wchar\_t)             |
| int strcmp (const char\*, const char\*)           | int wcscmp (const wchar\_t\*, const wchar\_t\*)            |
| int strncmp (const char\*, const char\*, size\_t) | int wcsncmp (const wchar\_t\*, const wchar\_t\*, size\_t)  |
| int strcoll (const char\*, const char\*)          | int wcscoll (const wchar\_t\*, const wchar\_t\*)           |
| char\* strcpy (char\*, const char\*)              | wchar\_t\* wcscpy (wchar\_t\*, const wchar\_t\*)           |
| char\* strncpy (char\*, const char\*, size\_t)    | wchar\_t\* wcsncpy (wchar\_t\*, const wchar\_t\*, size\_t) |
| size\_t strcspn (const char\*, const char\*)      | size\_t wcscspn (const wchar\_t\*, const wchar\_t\*)       |
| size\_t strlen (const char\*)                     | size\_t wcslen (const wchar\_t\*)                          |
| char\* strpbrk (const char\*, const char\*)       | wchar\_t\* wcspbrk (const wchar\_t\*, const wchar\_t\*)    |
| char\* strrchr (const char\*, int)                | wchar\_t\* wcsrchr (const wchar\_t\*, wchar\_t)            |
| size\_t strspn (const char\*, const char\*)       | size\_t wcsspn (const wchar\_t\*, const wchar\_t\*)        |
| char\* strstr (const char\*, const char\*)        | wchar\_t\* wcsstr (const wchar\_t\*, const wchar\_t\*)     |
| char\* strtok (char\*, const char\*)              | wchar\_t\* wcstok (wchar\_t\*, const wchar\_t\*)           |
| size\_t strxfrm (char\*, const char\*)            | size\_t wcsxfrm (wchar\_t\*, const wchar\_t\*)             |

</details>

<br>

<h3 id="time.h">Versões derivadas de <code>time.h</code></h3>

| time.h   | wchar.h  |
| :-:      | :-:      |
| strftime | wcsftime |

<details><summary>Retorno, identificador e parâmetros</summary>

| time.h | wchar.h |
| :--    | :--     |
| size\_t strftime(char\*, size\_t, const char\*, const struct tm\*) | size\_t wcsftime (wchar\_t\*, size\_t, const wchar\_t\*, const struct tm\*) |

</details>

<br>

<hr>

### Fonte:
* [cplusplus: wchar.h](https://en.wikibooks.org/wiki/C_Programming/wchar.h )

<hr>